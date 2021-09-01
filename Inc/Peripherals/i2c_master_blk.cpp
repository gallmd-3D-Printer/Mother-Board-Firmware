#include "i2c_master_blk.h"
using namespace I2C_MDG;

I2CMasterBlk::I2CMasterBlk(I2C_MDG::I2CRegisterType baseRegister,
    PinType clockPin,
    GPIOxRegisterType clockBank,
    PinType dataPin,
    GPIOxRegisterType dataBank) {

  //enable Clock
  if (baseRegister == I2C1_BASE) {
    reg_access<RCC_MDG::RCCRegisterType2,
        RCC_MDG::RCCRegisterType2,
        RCC_MDG::BaseRegisters::RCC_MDG + RCC_MDG::APB1ENR::registerOffset,
        RCC_MDG::APB1ENR::I2C1EN>::reg_or();
  }

  if (baseRegister == I2C2_BASE) {
    reg_access<RCC_MDG::RCCRegisterType2,
        RCC_MDG::RCCRegisterType2,
        RCC_MDG::BaseRegisters::RCC_MDG + RCC_MDG::APB1ENR::registerOffset,
        RCC_MDG::APB1ENR::I2C2EN>::reg_or();
  }

  if (baseRegister == I2C3_BASE) {
    reg_access<RCC_MDG::RCCRegisterType2,
        RCC_MDG::RCCRegisterType2,
        RCC_MDG::BaseRegisters::RCC_MDG + RCC_MDG::APB1ENR::registerOffset,
        RCC_MDG::APB1ENR::I2C3EN>::reg_or();
  }

  //setup Data Pin
  gpio_config::pinSetup(dataBank,
      dataPin,
      GpioModes::AlternateFunction,
      OutputTypes::OpenDrain,
      OutputSpeed::HighSpeed,
      PullUpPullDown::NoPullUpPullDown,
      AlternateFunction::AF4);

  //setup Data Pin
  gpio_config::pinSetup(clockBank,
      clockPin,
      GpioModes::AlternateFunction,
      OutputTypes::OpenDrain,
      OutputSpeed::HighSpeed,
      PullUpPullDown::NoPullUpPullDown,
      AlternateFunction::AF4);

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
}

int I2CMasterBlk::sendBytes(uint8_t *sendBuffer, uint8_t address, uint8_t messageLength) {

  bytesSent = 0;
  dataSent = false;

  sendBuf = sendBuffer;
  slaveAddress = address;
  bytesToSend = messageLength;

  dynamic_access<I2CRegisterType, I2CRegisterType>::reg_or(controlRegister1,
      CR1::ACK);

  //Set Start Bit
  dynamic_access<I2CRegisterType, I2CRegisterType>::reg_or(controlRegister1,
      CR1::START);

  //wait for start bit
  while (dynamic_access<I2CRegisterType, I2CRegisterType>::reg_get(statusRegister1) != SR1::SB);
  

  uint16_t status1;
  uint16_t status2;

  //send address
  dynamic_access<I2CRegisterType, I2CRegisterType>::reg_set(dataRegister, slaveAddress);

  //wait for address
  while (dynamic_access<I2CRegisterType, I2CRegisterType>::reg_get(statusRegister1) != SR1::ADDR);

  //address sent, check status registers to clear ADDR bit
  status1 = dynamic_access<I2CRegisterType, I2CRegisterType>::reg_get(statusRegister1);
  status2 = dynamic_access<I2CRegisterType, I2CRegisterType>::reg_get(statusRegister2);

  //send data
  if (status1 & SR1::TxE) {

    if ((bytesSent <= bytesToSend) & (!dataSent)) {

      dynamic_access<I2CRegisterType, uint8_t>::reg_set(dataRegister, *(sendBuf + bytesSent));
      bytesSent++;
    }

    if ((bytesSent > bytesToSend) & (!dataSent)) {

      dataSent = true;
      dynamic_access<I2CRegisterType, uint16_t>::reg_or(controlRegister1, CR1::STOP);
    }
  }

  return 0;
}