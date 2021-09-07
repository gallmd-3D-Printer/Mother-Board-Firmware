#include "spi_master.h"

using namespace SPI_MDG;

void SPIMaster::init() {

	//enable peripheral clock, set IRQ Channel
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //Preemption Priority
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;        //Sub Priority
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

	switch (periphBaseRegister) {
	case BaseRegisters::SPI1Base:
		reg_access<RCC_MDG::RCCRegisterType2, RCC_MDG::RCCRegisterType2,
				RCC_MDG::APB2ENR::registerOffset
						+ RCC_MDG::BaseRegisters::RCC_MDG,
				RCC_MDG::APB2ENR::SPI1EN>::reg_or();

		NVIC_InitStructure.NVIC_IRQChannel = SPI1_IRQn;
		  NVIC_SetPriority(SPI1_IRQn, 0);
		  NVIC_EnableIRQ(SPI1_IRQn);
		break;

	case BaseRegisters::SPI2Base:
		reg_access<RCC_MDG::RCCRegisterType2, RCC_MDG::RCCRegisterType2,
				RCC_MDG::APB1ENR::registerOffset
						+ RCC_MDG::BaseRegisters::RCC_MDG,
				RCC_MDG::APB1ENR::SPI2EN>::reg_or();

		NVIC_InitStructure.NVIC_IRQChannel = SPI2_IRQn;
		break;

	case BaseRegisters::SPI3Base:
		reg_access<RCC_MDG::RCCRegisterType2, RCC_MDG::RCCRegisterType2,
				RCC_MDG::APB1ENR::registerOffset
						+ RCC_MDG::BaseRegisters::RCC_MDG,
				RCC_MDG::APB1ENR::SPI3EN>::reg_or();

		NVIC_InitStructure.NVIC_IRQChannel = SPI3_IRQn;
		break;
	}

	//register interrupt
	//  dynamic_access<SPIRegisterType, SPIRegisterType>::reg_or(controlRegister2, (CR2::ERRIE | CR2::RXNEIE | CR2::TXEIE));
	NVIC_Init(&NVIC_InitStructure);
	SPIMaster::registerInterrupt();

	//default to MODE0
	SPIMaster::setMode(MODE3);

	//select the baud rate bits in CR1
	dynamic_access<SPIRegisterType, SPIRegisterType>::reg_or(controlRegister1,
			CR1::BRBits::FPCLKDIV8);

	//Set the DFF bit to select 8 or 16 bit data frame
	//  setDataFrameFormat(BITS8);

	//Configure the LSB bit in CR1
	//  setLSBDirection(MSBFIRST);

	//Set the ssm and SSI bits in the CR1 register
	dynamic_access<SPIRegisterType, SPIRegisterType>::reg_or(controlRegister1,
			CR1::SSM);
	dynamic_access<SPIRegisterType, SPIRegisterType>::reg_or(controlRegister1,
			CR1::SSI);

	//set the MSTR and SPE bits
	dynamic_access<SPIRegisterType, SPIRegisterType>::reg_or(controlRegister1,
			CR1::MSTR);
	dynamic_access<SPIRegisterType, SPIRegisterType>::reg_or(controlRegister1,
			CR1::SPE);

	//set slave specific delay time
	setDelayTime(0X01);
}
void SPIMaster::setMode(spiModes spiMode) {

	switch (spiMode) {
	//clear phase bit
	//clear polarity bit
	case MODE0:
		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_and(
				controlRegister1, !(CR1::CPHA));

		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_and(
				controlRegister1, !(CR1::CPOL));

		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_and(
				controlRegister2, !(CR2::FRF));

		break;

		//set phase bit
		//clear polarity bit
	case MODE1:
		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_or(
				controlRegister1, CR1::CPHA);

		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_and(
				controlRegister1, !(CR1::CPOL));

		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_and(
				controlRegister2, !(CR2::FRF));

		break;

		//clear phase bit
		//set polarity bit
	case MODE2:
		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_and(
				controlRegister1, !(CR1::CPHA));

		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_or(
				controlRegister1, CR1::CPOL);

		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_and(
				controlRegister2, !(CR2::FRF));

		break;

		//set phase bit
		//set polarity bit
	case MODE3:
		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_or(
				controlRegister1, CR1::CPHA);

		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_or(
				controlRegister1, CR1::CPOL);

		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_and(
				controlRegister2, !(CR2::FRF));

		break;

		//phase and polarity not used
		//set FRF bit to enable TI Mode
	case MODETI:
		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_or(
				controlRegister2, CR2::FRF);
		break;
	}
}

void SPIMaster::setDataFrameFormat(dataFrameFormat frameFormat) {

	switch (frameFormat) {
	case BITS8:
		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_and(
				controlRegister1, !(CR1::DFF));
		break;

	case BITS16:
		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_or(
				controlRegister1, CR1::DFF);
		break;
	}
}

void SPIMaster::registerInterrupt() {

	switch (periphBaseRegister) {
	case BaseRegisters::SPI1Base:
		handlerPointers[SPI1_IDX] = this;
		break;

	case BaseRegisters::SPI2Base:
		handlerPointers[SPI2_IDX] = this;
		break;

	case BaseRegisters::SPI3Base:
		handlerPointers[SPI3_IDX] = this;
		break;
	}
}

void SPIMaster::setLSBDirection(lsbDirection direction) {

	switch (direction) {

	case LSBFIRST:
		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_or(
				controlRegister1, CR1::LSBFIRST);
		break;

	case MSBFIRST:
		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_and(
				controlRegister1, !(CR1::LSBFIRST));
		break;
	}
}

void SPIMaster::setDelayTime(uint32_t delay) {

	delayTime = delay;

}

int SPIMaster::sendBytes(uint8_t *sendBuffer, uint8_t slave,
		uint8_t messageLength) {

	bytesSent = 0;
	bytesToSend = messageLength;
	sendBuf = sendBuffer;

	//Set CS LOW
	dynamic_access<uint32_t, uint32_t>::reg_and(csODR, !(8));
	dynamic_access<SPIRegisterType, SPIRegisterType>::reg_or(controlRegister1,
			CR1::SSI);
	dynamic_access<SPIRegisterType, SPIRegisterType>::reg_set(dataRegister,
			*sendBuf);
	dynamic_access<SPIRegisterType, SPIRegisterType>::reg_or(controlRegister2,
			(CR2::ERRIE | CR2::RXNEIE | CR2::TXEIE));

	//  bytesSent++;

	return 0;
}

void SPIMaster::handleInterrupts(int interruptType) {

	switch(currentState){
	case WRITE_BYTES_SENDING:
		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_set(dataRegister, txBuffer.get());
		bytesSent++;

		if(bytesSent == bytesToSend){
			currentState = WRITE_BYTES_SENT;
		}

		break;

	case WRITE_BYTES_SENT:

		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_and(
				controlRegister2, (!(CR2::ERRIE | CR2::RXNEIE | CR2::TXEIE)));
		boardPins->spiFlashCS.set();
		currentState = READY;

		break;

	case READ_BYTES_SENDING:

		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_set(dataRegister, txBuffer.get());
		bytesSent++;

		if(bytesSent == bytesToSend){
			currentState = READ_BYTES_SENT;
		}

		break;

	case READ_BYTES_SENT:

		currentState = READ_BYTES_READING;

		break;

	case READ_BYTES_READING:
		//Clock out garbage data
		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_set(dataRegister,
				0x00U);
		//read incoming data
		uint8_t tempRXData;
		tempRXData = dynamic_access<SPIRegisterType, uint8_t>::reg_get(dataRegister);
		rxBuffer.put(tempRXData);

		bytesRecvd++;

		if(bytesRecvd == bytesToRecv){
			currentState = READ_BYTES_READ;
		}

		break;

	case READ_BYTES_READ:

		dynamic_access<SPIRegisterType, SPIRegisterType>::reg_and(
				controlRegister2, (!(CR2::ERRIE | CR2::RXNEIE | CR2::TXEIE)));
		boardPins->spiFlashCS.set();
		currentState = READY;

		break;



	}


	delayTimeCurrent = delayTime;
	while (delayTimeCurrent--) {
	}

}



void SPIMaster::startTX(){
	//Set CS LOW
	//dynamic_access<uint32_t, uint32_t>::reg_and(csODR, !(8));
	boardPins->spiFlashCS.toggle();
	dynamic_access<SPIRegisterType, SPIRegisterType>::reg_or(controlRegister1,
			CR1::SSI);
	dynamic_access<SPIRegisterType, SPIRegisterType>::reg_set(dataRegister,
			txBuffer.get());
	dynamic_access<SPIRegisterType, SPIRegisterType>::reg_or(controlRegister2,
			(CR2::ERRIE | CR2::RXNEIE | CR2::TXEIE));
}

