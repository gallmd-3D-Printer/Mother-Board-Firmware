#ifndef I2C_MASTER_H_
#define I2C_MASTER_H_



#include "../Registers/i2c_registers.h"
#include "../Utility/reg_access.h"
#include "../Utility/reg_access_dynamic.h"
#include "gpio.h"
#include "gpio_config.h"
#include "../Registers/rcc_registers.h"
#include "../Utility/interrupts.h"
#include "../Utility/interruptable.h"
//#include "misc.h"
#include "../Utility/util.h"
#include "../Utility/circular_buffer.h"
#include "../CMSIS/Device/ST/STM32F4xx/Include/stm32f4xx.h"
#include "../Utility/command.h"

using namespace I2C_MDG;


enum transferType{

SEND_BYTES,
SEND_COMMAND

};

extern interruptable * handlerPointers[sizeof(peripheralInterrupts)];
class I2CMaster : public interruptable
{
public:
//  I2CMaster(I2C_MDG::I2CRegisterType baseRegister,PinType clockPin, GPIOxRegisterType clockBank, PinType dataPin,GPIOxRegisterType dataBank, util::circular_buffer<uint8_t> * rxBufferPointer);
  I2CMaster(I2C_MDG::I2CRegisterType baseRegister):rxBuffer{50}{
	  //enable Clock
	  if (baseRegister == BaseRegisters::I2C1Base) {
	    reg_access<RCC_MDG::RCCRegisterType2,
	        RCC_MDG::RCCRegisterType2,
	        RCC_MDG::BaseRegisters::RCC_MDG + RCC_MDG::APB1ENR::registerOffset,
	        RCC_MDG::APB1ENR::I2C1EN>::reg_or();
	  }

	  if (baseRegister == BaseRegisters::I2C2Base) {
	    reg_access<RCC_MDG::RCCRegisterType2,
	        RCC_MDG::RCCRegisterType2,
	        RCC_MDG::BaseRegisters::RCC_MDG + RCC_MDG::APB1ENR::registerOffset,
	        RCC_MDG::APB1ENR::I2C2EN>::reg_or();
	  }

	  if (baseRegister == BaseRegisters::I2C3Base) {
	    reg_access<RCC_MDG::RCCRegisterType2,
	        RCC_MDG::RCCRegisterType2,
	        RCC_MDG::BaseRegisters::RCC_MDG + RCC_MDG::APB1ENR::registerOffset,
	        RCC_MDG::APB1ENR::I2C3EN>::reg_or();
	  }


	  //assign register addresses
	  clockControlRegister = baseRegister + CCR::registerOffset;
	  controlRegister1 = baseRegister + CR1::registerOffset;
	  controlRegister2 = baseRegister + CR2::registerOffset;
	  dataRegister = baseRegister + DR::registerOffset;
	  ownAddressRegister1 = baseRegister + OAR1::registerOffset;
	  ownAddressRegister2 = baseRegister + OAR2::registerOffset;
	  statusRegister1 = baseRegister + SR1::registerOffset;
	  statusRegister2 = baseRegister + SR2::registerOffset;
	  timeRiseRegister = baseRegister + TRISE::registerOffset;
	  periphBaseRegister = baseRegister;

	  //enable interrupts
	  dynamic_access<I2CRegisterType, I2CRegisterType>::reg_or(controlRegister2,
	      CR2::ITBUFEN | CR2::ITERREN | CR2::ITEVTEN);

	  NVIC_SetPriority(I2C1_EV_IRQn, 0);
	  NVIC_EnableIRQ(I2C1_EV_IRQn);

	  NVIC_SetPriority(I2C1_ER_IRQn, 0);
	  NVIC_EnableIRQ(I2C1_ER_IRQn);


	  registerInterrupt();

	  //reset peripherial
	  dynamic_access<I2CRegisterType, I2CRegisterType>::reg_not(controlRegister1,
	      CR1::SWRST);

	  //set frequency bits
	  dynamic_access<I2CRegisterType, I2CRegisterType>::reg_or(controlRegister2,
	      CR2::FREQBits::FREQ16);

	  //configure clock control register
	  dynamic_access<I2CRegisterType, I2CRegisterType>::reg_or(clockControlRegister,
	      0x50U);

	  //configure rise time register
	  dynamic_access<I2CRegisterType, I2CRegisterType>::reg_or(timeRiseRegister,
	      TRISE::TRISEBits::TRISE17);

	  //Enable ACK
	  dynamic_access<I2CRegisterType, I2CRegisterType>::reg_or(controlRegister1,
	      CR1::ACK);

	  //Enable the peripheral
	  dynamic_access<I2CRegisterType, I2CRegisterType>::reg_or(controlRegister1,
	      CR1::PE);
  };

  int sendBytes(uint8_t * sendBuffer, uint8_t address, uint8_t messageLength);
  int sendCommand(Command * command);


  void handleInterrupts(int interruptType);
  void EV_handler();
  void ER_handler();

  bool commandReady;


  private:
  
  //functions
  void registerInterrupt();

  //registers
  I2C_MDG::I2CRegisterType controlRegister1;
  I2C_MDG::I2CRegisterType controlRegister2;
  I2C_MDG::I2CRegisterType ownAddressRegister1;
  I2C_MDG::I2CRegisterType ownAddressRegister2;
  I2C_MDG::I2CRegisterType dataRegister;
  I2C_MDG::I2CRegisterType statusRegister1;
  I2C_MDG::I2CRegisterType statusRegister2;
  I2C_MDG::I2CRegisterType clockControlRegister;
  I2C_MDG::I2CRegisterType timeRiseRegister;
  I2C_MDG::I2CRegisterType periphBaseRegister;
  
  //data
  uint8_t * sendBuf;
  uint8_t bytesSent;
  uint8_t bytesRecvd;
  uint8_t slaveAddress;
  uint8_t bytesToSend;
  bool dataSent;
  uint16_t status1;
  uint16_t status2;
  bool getBytesBack;
  util::circular_buffer<uint8_t> rxBuffer;
  Command * currentCommand;
  transferType currentTransferType;


};

#endif //I2C_MASTER_H_
