/* Includes */
#include "adc.h"
#include "circular_buffer.h"
#include "gpio.h"
#include "rcc_motherboard.h"
#include "stm32f4xx.h"
#include "usart.h"
#include "circular_buffer.h"
#include "i2c_master.h"
#include "spi_master.h"
#include "command.h"


/* Private function prototypes */
void Delay(__IO uint32_t nCount);

int main() {

  Delay(0xFFF);
  util::circular_buffer<uint8_t> usartTXBuf(50);
  util::circular_buffer<uint8_t> *txPtr;
  txPtr = &usartTXBuf;

  util::circular_buffer<uint8_t> i2cRXBuf(50);
  util::circular_buffer<uint8_t> *rxPtr;


  //  RCCMotherBoard clock;
  //  clock.setClock150MHZ();

  I2CMaster i2c(I2C_MDG::BaseRegisters::I2C1Base,
      PINS::PIN8,
      GPIOxBaseRegisters::GPIO_B,
      PINS::PIN9,
      GPIOxBaseRegisters::GPIO_B,
      &i2cRXBuf);

  __enable_irq();

  USART::Usart usbUsart(USART::BaseRegisters::USART3Base, txPtr);
  uint8_t data = 0;

  //setup SPI
  const GPIO<GPIOxBaseRegisters::GPIO_D,
      PINS::PIN7,
      GpioModes::Output,
      OutputTypes::PushPull,
      OutputSpeed::MediumSpeed,
      PullUpPullDown::NoPullUpPullDown,
      AlternateFunction::AF0>
      card0CS;

  const GPIO<GPIOxBaseRegisters::GPIO_C,
      PINS::PIN10,
      GpioModes::AlternateFunction,
      OutputTypes::PushPull,
      OutputSpeed::VeryHighSpeeed,
      PullUpPullDown::NoPullUpPullDown,
      AlternateFunction::AF6>
      spiCLK;

  const GPIO<GPIOxBaseRegisters::GPIO_C,
      PINS::PIN12,
      GpioModes::AlternateFunction,
      OutputTypes::PushPull,
      OutputSpeed::VeryHighSpeeed,
      PullUpPullDown::NoPullUpPullDown,
      AlternateFunction::AF6>
      spiMOSI;

  const GPIO<GPIOxBaseRegisters::GPIO_C,
      PINS::PIN11,
      GpioModes::AlternateFunction,
      OutputTypes::PushPull,
      OutputSpeed::VeryHighSpeeed,
      PullUpPullDown::NoPullUpPullDown,
      AlternateFunction::AF6>
      spiMISO;

  //Set CS Pin High
  card0CS.set();
  Delay(0xFF);
  SPIMaster spi(SPI_MDG::BaseRegisters::SPI3Base);
  Delay(0xFFFFF);

  //  ADC_INT adc(ADC_MDG::BaseRegisters::ADC1_MDG);

  //inventus Battery
//  uint8_t wakeupppppp[4] = {0x00, 0x67, 0x45, 0x51};

  uint8_t testBytes[4] = {0x01, 0x02, 0x03, 0x04};
  Delay(0xFFF);
  uint8_t card0Address = 0x02;
  card0Address = card0Address << 1;

  Command testCommand(GET_CARD_INFO, card0Address);
  testCommand.sendBytes[0] = 1;
  testCommand.sendBytes[1] = 2;
  testCommand.sendBytes[2] = 3;

  i2c.sendCommand(&testCommand);
  
//  i2c.sendBytes(testBytes, card0Address, 4);



  //PC14
  const GPIO<GPIOxBaseRegisters::GPIO_C,
      PINS::PIN4,
      GpioModes::Output,
      OutputTypes::PushPull,
      OutputSpeed::MediumSpeed,
      PullUpPullDown::NoPullUpPullDown,
      AlternateFunction::AF0>
      statusLED;

  const GPIO<GPIOxBaseRegisters::GPIO_D,
      PINS::PIN10,
      GpioModes::Output,
      OutputTypes::PushPull,
      OutputSpeed::MediumSpeed,
      PullUpPullDown::NoPullUpPullDown,
      AlternateFunction::AF0>
      statusLED1;

  const GPIO<GPIOxBaseRegisters::GPIO_D,
      PINS::PIN11,
      GpioModes::Output,
      OutputTypes::PushPull,
      OutputSpeed::MediumSpeed,
      PullUpPullDown::NoPullUpPullDown,
      AlternateFunction::AF0>
      statusLED2;

  const GPIO<GPIOxBaseRegisters::GPIO_D,
      PINS::PIN12,
      GpioModes::Output,
      OutputTypes::PushPull,
      OutputSpeed::MediumSpeed,
      PullUpPullDown::NoPullUpPullDown,
      AlternateFunction::AF0>
      statusLED3;

  const GPIO<GPIOxBaseRegisters::GPIO_D,
      PINS::PIN13,
      GpioModes::Output,
      OutputTypes::PushPull,
      OutputSpeed::MediumSpeed,
      PullUpPullDown::NoPullUpPullDown,
      AlternateFunction::AF0>
      statusLED4;

  const GPIO<GPIOxBaseRegisters::GPIO_D,
      PINS::PIN14,
      GpioModes::Output,
      OutputTypes::PushPull,
      OutputSpeed::MediumSpeed,
      PullUpPullDown::NoPullUpPullDown,
      AlternateFunction::AF0>
      statusLED5;

  const GPIO<GPIOxBaseRegisters::GPIO_D,
      PINS::PIN15,
      GpioModes::Output,
      OutputTypes::PushPull,
      OutputSpeed::MediumSpeed,
      PullUpPullDown::NoPullUpPullDown,
      AlternateFunction::AF0>
      statusLED6;

  uint8_t i2cData[3];
  i2cData[0] = 0x7CU;
  i2cData[1] = 0x2DU;

  while (1) {

    if (!usartTXBuf.empty()) {

      data = usartTXBuf.get();
      usbUsart.sendBytes(data);
      i2cData[3] = data;
      //      i2c.sendBytes(i2cData, displayAddress, 3);
    }

    Delay(0xFFFF);
    statusLED.toggle();
    statusLED1.toggle();
  }
}

void Delay(__IO uint32_t nCount) {
  while (nCount--) {
  }
}