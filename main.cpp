/* Includes */
#include "adc.h"
#include "circular_buffer.h"
#include "gpio.h"
#include "rcc_motherboard.h"
#include "stm32f4xx.h"
#include "usart.h"
#include "i2c_master.h"
#include "spi_master.h"


/* Private function prototypes */
void Delay(__IO uint32_t nCount);

int main() {

  Delay(0xFFF);
  util::circular_buffer<uint8_t> usartTXBuf(50);
  util::circular_buffer<uint8_t> *txPtr;
  txPtr = &usartTXBuf;

  //  RCCMotherBoard clock;
  //  clock.setClock150MHZ();

  I2CMaster i2c(I2C_MDG::BaseRegisters::I2C1Base,
      PINS::PIN8,
      GPIOxBaseRegisters::GPIO_B,
      PINS::PIN9,
      GPIOxBaseRegisters::GPIO_B);

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

  //setup i2c Display
  uint8_t LCDAddress = 0xE4U;
  uint8_t clearDisplay[2] = {0x7C, 0x2D};
  uint8_t testText[7] = {0x7C, 0x2D, 0x41, 0x41, 0x41, 0x41, 0x41};
  //  uint8_t testText[3] = {'a','b','c'};
  //  uint8_t testText3[7] = {'|', '-', 'c', 'd', 'e', 'f', 'g'};
  uint8_t setBacklight[7] = {'|', '-', '|', '+', 0xFF, 0x00, 0x00};
  uint8_t setBacklight2[7] = {'|', '-', '|', '+', 0x00, 0xFF, 0x00};
  uint8_t setBacklight3[7] = {'|', '-', '|', '+', 0x00, 0x00, 0xFF};
  uint8_t setContrast[2] = {0x18, 0x9F};

  spi.sendBytes(setBacklight, 0, 7);
  Delay(0xFFFFF);
  spi.sendBytes(setBacklight2, 0, 7);
  Delay(0xFFFFF);
  spi.sendBytes(setBacklight3, 0, 7);
  Delay(0xFFFFF);
  spi.sendBytes(testText, 0, 7);

  //inventus Battery
  uint8_t batteryAddress = 0x16U;
  //  uint8_t batteryAddress = 0b101111;
  uint8_t wakeupppppp[4] = {0x00, 0x67, 0x45, 0x51};

  Delay(0xFFF);
  i2c.sendBytes(wakeupppppp, batteryAddress, 4);

  //
  //
  //  i2c.sendBytes(setBacklight, LCDAddress, 7);
  //  Delay(0xFFFFF);
  //
  //  i2c.sendBytes(setBacklight2, LCDAddress, 7);
  //  Delay(0xFFFFF);
  //
  //  i2c.sendBytes(setBacklight3, LCDAddress, 7);
  //  Delay(0xFFFFF);

  //  i2c.sendBytes(setContrast, displayAddress2, 2);
  //  Delay(0xFFFF);

  //  i2c.sendBytes(testText, LCDAddress, 7);
  //  Delay(0xFFFFF);

  //  uint8_t displayAddress = 0xE0;
  //  uint8_t osc_on[17] = {0x21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  //  i2c.sendBytes(osc_on, displayAddress, 17);
  //
  //  Delay(0xFFFFF);
  //  uint8_t no_blink[17] = {0x81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  //  i2c.sendBytes(no_blink, displayAddress, 17);
  //
  //  Delay(0xFFFFF);
  //  uint8_t brightness[17] = {0xEF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  //  i2c.sendBytes(brightness, displayAddress, 17);
  //
  //  Delay(0xFFFFF);
  //  uint8_t all_on[17] = {0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00};
  //  i2c.sendBytes(all_on, displayAddress, 17);
  //
  //  Delay(0xFFFFF);
  //  uint8_t all_off[17] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  //  i2c.sendBytes(all_off, displayAddress, 17);

  //setup i2c Display

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