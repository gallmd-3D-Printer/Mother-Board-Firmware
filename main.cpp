/* Includes */
#include "Peripherals/adc.h"
#include "Utility/circular_buffer.h"
#include "Utility/command.h"
#include "Peripherals/gpio.h"
#include "Peripherals/i2c_master.h"
#include "rcc_motherboard.h"
#include "Peripherals/spi_master.h"
#include "stm32f4xx.h"
#include "Peripherals/usart.h"
#include "console.h"
#include "pins.h"

/* Private function prototypes */
void Delay(__IO uint32_t nCount);

int main() {

  BoardPins boardPins;


  Console testConsole(&boardPins);
  testConsole.sayHello();

  Delay(0xFFF);

  //  RCCMotherBoard clock;
  //  clock.setClock150MHZ();

  I2CMaster i2c(I2C_MDG::BaseRegisters::I2C1Base,
      PINS::PIN8,
      GPIOxBaseRegisters::GPIO_B,
      PINS::PIN9,
      GPIOxBaseRegisters::GPIO_B);

  __enable_irq();


  uint8_t data = 0;

  //Set CS Pin High
  boardPins.card0CS.set();
  Delay(0xFF);
  SPIMaster spi(SPI_MDG::BaseRegisters::SPI3Base);
  Delay(0xFFFFF);

  uint8_t testBytes[4] = {0x01, 0x02, 0x03, 0x04};
  Delay(0xFFF);
  uint8_t card0Address = 0x02;
  card0Address = card0Address << 1;

  Command testCommand(GET_CARD_INFO, card0Address);
  testCommand.sendBytes[0] = 1;
  testCommand.sendBytes[1] = 2;
  testCommand.sendBytes[2] = 3;

  i2c.sendCommand(&testCommand);

  uint8_t i2cData[3];
  i2cData[0] = 0x7CU;
  i2cData[1] = 0x2DU;

  uint8_t testPacket[8];
  uint8_t packetCount = 0;

  uint32_t delayCount = 0;

  while (1) {

//    if (!usartTXBuf.empty()) {
//
//      data = usartTXBuf.get();
//      usbUsart.sendBytes(data);
//
//      testPacket[packetCount] = data;
//      packetCount++;
//
//      if(packetCount == 7){
//        if(testPacket[7] == 0x40U){
//
//          statusLED2.toggle();
//         }
//          packetCount = 0;
//         }
//
//      i2cData[3] = data;
//      //      i2c.sendBytes(i2cData, displayAddress, 3);
//    }

    if (delayCount == 0xFFFFF) {
      boardPins.statusLED.toggle();
      boardPins.statusLED1.toggle();
      testConsole.processConsole();
      delayCount = 0;
    }
    delayCount++;
  }
}

void Delay(__IO uint32_t nCount) {
  while (nCount--) {
  }
}