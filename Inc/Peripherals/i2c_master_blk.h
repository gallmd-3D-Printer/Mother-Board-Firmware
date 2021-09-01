#ifndef I2C_MASTER_BLK_H_
#define I2C_MASTER_BLK_H_



#include "../Registers/i2c_registers.h"
#include "../Utility/reg_access.h"
#include "../Utility/reg_access_dynamic.h"
#include "gpio.h"
#include "gpio_config.h"
#include "../CMSIS/Device/ST/STM32F4xx/Include/stm32f4xx.h"
#include "../Registers/rcc_registers.h"
#include "../Utility/misc.h"
#include "../Utility/util.h"


class I2CMasterBlk
{
public:
  I2CMasterBlk(I2C_MDG::I2CRegisterType baseRegister,PinType clockPin, GPIOxRegisterType clockBank, PinType dataPin,GPIOxRegisterType dataBank);
  int sendBytes(uint8_t * sendBuffer, uint8_t address, uint8_t messageLength);



  private:
  
  //functions


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
  uint8_t slaveAddress;
  uint8_t bytesToSend;
  bool dataSent;





};

#endif //I2C_MASTER_H_
