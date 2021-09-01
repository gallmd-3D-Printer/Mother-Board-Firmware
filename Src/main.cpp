/* Includes */
#include "Peripherals/adc.h"
#include "Peripherals/gpio.h"
#include "Peripherals/i2c_master.h"
#include "Peripherals/spi_master.h"
#include "Peripherals/usart.h"
#include "Utility/circular_buffer.h"
#include "Utility/command.h"
#include "console.h"
#include "rcc_motherboard.h"
#include "../CMSIS/Device/ST/STM32F4xx/Include/stm32f4xx.h"
#include "board_pins.h"
#include "app.h"
#include "Peripherals/gpio_interruptable.h"

/* Private function prototypes */
void Delay(__IO uint32_t nCount);

int main() {

	BoardPins boardPins;
	app thisApp;
	I2CMaster i2c(I2C_MDG::BaseRegisters::I2C1Base);

	GpioInterruptable intTest(&boardPins);



	Console testConsole(&boardPins, &thisApp, &i2c);
	testConsole.printMenu();

	Delay(0xFFFFF);

	__enable_irq();


	//  RCCMotherBoard clock;
	//  clock.setClock150MHZ();


	uint8_t card0Address = 0x02;
	card0Address = card0Address << 1;
	Command testCommand(GET_CARD_INFO, card0Address);
	testCommand.sendBytes[0] = 0x00;
	testCommand.sendBytes[1] = 0x04;
	testCommand.sendBytes[2] = 0x01;

//	i2c.sendCommand(&testCommand);


	uint8_t data = 0;
	uint8_t i2cData[3];
	i2cData[0] = 0x7CU;
	i2cData[1] = 0x2DU;
	i2cData[3] = data;
//  i2c.sendBytes(i2cData, displayAddress, 3);

	//Set CS Pin High
	boardPins.spiFlashCS.set();
	Delay(0xFF);
	SPIMaster spi(SPI_MDG::BaseRegisters::SPI3Base, &boardPins);
	Delay(0xFFFFF);

	boardPins.dirPin.set();
	uint32_t delayCount = 0;

	while (1) {

		if (delayCount == 0xFF) {

			testConsole.processConsole();
			delayCount = 0;

// Playing around with stepper driver
//			for(uint8_t i=0; i<=500; i++){
//				boardPins.stepPin.toggle();
//				Delay(0xF1);
//			}
//			Delay(0xFFFF);
//			boardPins.dirPin.toggle();

		}
		delayCount++;
	}
}

void Delay(__IO uint32_t nCount) {
	while (nCount--) {
	}
}
