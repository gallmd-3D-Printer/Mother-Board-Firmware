#include "i2c_master.h"
using namespace I2C_MDG;

void I2CMaster::registerInterrupt() {

	if (periphBaseRegister == BaseRegisters::I2C1Base) {
		handlerPointers[I2C1_IDX] = this;
	}

	if (periphBaseRegister == BaseRegisters::I2C2Base) {
		handlerPointers[I2C2_IDX] = this;
	}

	if (periphBaseRegister == BaseRegisters::I2C3Base) {
		handlerPointers[I2C3_IDX] = this;
	}
}

int I2CMaster::sendBytes(uint8_t *sendBuffer, uint8_t address,
		uint8_t messageLength) {

	bytesSent = 0;
	dataSent = false;

	sendBuf = sendBuffer;
	slaveAddress = address;
	bytesToSend = messageLength;
	currentTransferType = SEND_BYTES;

	dynamic_access<I2CRegisterType, I2CRegisterType>::reg_or(controlRegister1,
			CR1::ACK);
	dynamic_access<I2CRegisterType, uint8_t>::reg_set(dataRegister, 0x00U);

	//Set Start Bit
	dynamic_access<I2CRegisterType, I2CRegisterType>::reg_or(controlRegister1,
			CR1::START);

	return 0;
}

int I2CMaster::sendCommand(Command *command) {

	bytesSent = 0;
	bytesRecvd = 0;
	dataSent = false;
	commandReady = false;

	currentCommand = command;

	slaveAddress = command->slaveAddress;
	bytesToSend = command->masterByteCount;
	currentTransferType = SEND_COMMAND;

	if (command->recvBytes > 0) {
		getBytesBack = true;
	}
	dynamic_access<I2CRegisterType, I2CRegisterType>::reg_or(controlRegister1,
			CR1::ACK);
	dynamic_access<I2CRegisterType, uint8_t>::reg_set(dataRegister, 0x00U);

	//Set Start Bit
	dynamic_access<I2CRegisterType, I2CRegisterType>::reg_or(controlRegister1,
			CR1::START);

	return 0;

}

void I2CMaster::ER_handler() {

	status1 = dynamic_access<I2CRegisterType, I2CRegisterType>::reg_get(
			statusRegister1);
	if (status1 & SR1::AF) {

		dynamic_access<I2CRegisterType, I2CRegisterType>::reg_and(
				statusRegister1, !SR1::AF);

	}
}

void I2CMaster::EV_handler() {

	status1 = dynamic_access<I2CRegisterType, I2CRegisterType>::reg_get(
			statusRegister1);

	//send address
	if (status1 & SR1::SB) {
		if (!dataSent) {
			dynamic_access<I2CRegisterType, uint16_t>::reg_or(dataRegister,
					slaveAddress);
		}

		//this will be true if we are sending a restart to the slave
		if (dataSent) {

			//set read bit in address
			slaveAddress = slaveAddress | Util::Bits::BIT0;
			dynamic_access<I2CRegisterType, uint16_t>::reg_or(dataRegister,
					slaveAddress);

		}
	}

	//address sent, check status registers to clear ADDR bit
	if (status1 & SR1::ADDR) {

		status1 = dynamic_access<I2CRegisterType, I2CRegisterType>::reg_get(
				statusRegister1);
		status2 = dynamic_access<I2CRegisterType, I2CRegisterType>::reg_get(
				statusRegister2);
	}

	//send data
	if (status1 & SR1::TxE) {

		if (currentTransferType == SEND_BYTES) {
			if ((bytesSent <= bytesToSend) & (!dataSent)) {

				dynamic_access<I2CRegisterType, uint8_t>::reg_set(dataRegister,
						*(sendBuf + bytesSent));
				bytesSent++;
			}

			if ((bytesSent > bytesToSend) & (!dataSent)) {

				dataSent = true;
				dynamic_access<I2CRegisterType, uint16_t>::reg_or(
						controlRegister1, CR1::STOP);
			}
		}

		if (currentTransferType == SEND_COMMAND) {

			if ((bytesSent <= bytesToSend) & (!dataSent)) {

				dynamic_access<I2CRegisterType, uint8_t>::reg_set(dataRegister,
						currentCommand->sendBytes[bytesSent]);
				bytesSent++;
			}

			if ((bytesSent > bytesToSend) & (!dataSent)) {

				//we sent all of the command data to the slave
				//send a restart so the slave can start transmitting
				dataSent = true;
				dynamic_access<I2CRegisterType, uint16_t>::reg_or(
						controlRegister1, CR1::START);

			}

		}
	}

	if (status1 & SR1::RxNE) {

		currentCommand->recvBytes[bytesRecvd] = dynamic_access<I2CRegisterType,
				I2CRegisterType>::reg_get(dataRegister);
		bytesRecvd++;

		if (bytesRecvd >= currentCommand->slaveByteCount-1) {

			dynamic_access<I2CRegisterType, I2CRegisterType>::reg_and_not(
					controlRegister1, CR1::ACK);
			dynamic_access<I2CRegisterType, uint16_t>::reg_or(controlRegister1,
					CR1::STOP);
		}
	}


}

void I2CMaster::handleInterrupts(int interruptType) {
	if (interruptType == I2C_EV) {
		I2CMaster::EV_handler();
	}

	if (interruptType == I2C_ER) {
		I2CMaster::ER_handler();
	}
}
