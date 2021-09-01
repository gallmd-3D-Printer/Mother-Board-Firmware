#ifndef SPI_H_
#define SPI_H_

#include "spi_registers.h"
#include "reg_access.h"
#include "reg_access_dynamic.h"
#include "gpio.h"
#include "gpio_config.h"
#include "stm32fxx.h"
#include "rcc_registers.h"
#include "interrupts.h"
#include "interruptable.h"
#include "misc.h"
#include "util.h"


extern interruptable * handlerPointers[sizeof(peripheralInterrupts)];
class SPIMaster : public interruptable
{

public:
  SPIMaster(SPI_MDG::SPIRegisterType baseRegister);
  int sendBytes(uint8_t * sendBuffer, uint8_t slave, uint8_t messageLength);

  void handleInterrupts(int interruptType);


private:
  //functions
  void registerInterrupt();

  SPI_MDG::SPIRegisterType controlRegister1;
  SPI_MDG::SPIRegisterType controlRegister2;
  SPI_MDG::SPIRegisterType statusRegister;
  SPI_MDG::SPIRegisterType dataRegister;
  SPI_MDG::SPIRegisterType crcPolynomialRegister;
  SPI_MDG::SPIRegisterType rxCRCRegister;
  SPI_MDG::SPIRegisterType txCRCRegister;
  SPI_MDG::SPIRegisterType i2sConfigurationRegister;
  SPI_MDG::SPIRegisterType i2sPrescalerRegister;

  //data
  uint8_t * sendBuf;
 

 };








}