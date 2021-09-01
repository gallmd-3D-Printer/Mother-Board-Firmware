#ifndef BOARD_PINS_H_
#define BOARD_PINS_H_

#include "Peripherals/gpio.h"

class BoardPins {

public:
	BoardPins() {
	}
	;

	//setup SPI
	const GPIO<GPIOxBaseRegisters::GPIO_D, PINS::PIN7, GpioModes::Output,
			OutputTypes::PushPull, OutputSpeed::MediumSpeed,
			PullUpPullDown::NoPullUpPullDown, AlternateFunction::AF0> card0CS;

	const GPIO<GPIOxBaseRegisters::GPIO_E, PINS::PIN12, GpioModes::Output,
			OutputTypes::PushPull, OutputSpeed::MediumSpeed,
			PullUpPullDown::NoPullUpPullDown, AlternateFunction::AF0> spiFlashCS;

	const GPIO<GPIOxBaseRegisters::GPIO_C, PINS::PIN10,
			GpioModes::AlternateFunction, OutputTypes::PushPull,
			OutputSpeed::VeryHighSpeeed, PullUpPullDown::NoPullUpPullDown,
			AlternateFunction::AF6> spiCLK;

	const GPIO<GPIOxBaseRegisters::GPIO_C, PINS::PIN12,
			GpioModes::AlternateFunction, OutputTypes::PushPull,
			OutputSpeed::VeryHighSpeeed, PullUpPullDown::NoPullUpPullDown,
			AlternateFunction::AF6> spiMOSI;

	const GPIO<GPIOxBaseRegisters::GPIO_C, PINS::PIN11,
			GpioModes::AlternateFunction, OutputTypes::PushPull,
			OutputSpeed::VeryHighSpeeed, PullUpPullDown::NoPullUpPullDown,
			AlternateFunction::AF6> spiMISO;

	//I2C Pins
	const GPIO<GPIOxBaseRegisters::GPIO_B, PINS::PIN8,
			GpioModes::AlternateFunction, OutputTypes::OpenDrain,
			OutputSpeed::HighSpeed, PullUpPullDown::NoPullUpPullDown,
			AlternateFunction::AF4> sdaPin;

	const GPIO<GPIOxBaseRegisters::GPIO_B, PINS::PIN9,
			GpioModes::AlternateFunction, OutputTypes::OpenDrain,
			OutputSpeed::HighSpeed, PullUpPullDown::NoPullUpPullDown,
			AlternateFunction::AF4> sclPin;

	//LED Pins
	const GPIO<GPIOxBaseRegisters::GPIO_C, PINS::PIN4, GpioModes::Output,
			OutputTypes::PushPull, OutputSpeed::MediumSpeed,
			PullUpPullDown::NoPullUpPullDown, AlternateFunction::AF0> statusLED;

	const GPIO<GPIOxBaseRegisters::GPIO_D, PINS::PIN10, GpioModes::Output,
			OutputTypes::PushPull, OutputSpeed::MediumSpeed,
			PullUpPullDown::NoPullUpPullDown, AlternateFunction::AF0> statusLED1;

	const GPIO<GPIOxBaseRegisters::GPIO_D, PINS::PIN11, GpioModes::Output,
			OutputTypes::PushPull, OutputSpeed::MediumSpeed,
			PullUpPullDown::NoPullUpPullDown, AlternateFunction::AF0> statusLED2;

	const GPIO<GPIOxBaseRegisters::GPIO_D, PINS::PIN12, GpioModes::Output,
			OutputTypes::PushPull, OutputSpeed::MediumSpeed,
			PullUpPullDown::NoPullUpPullDown, AlternateFunction::AF0> statusLED3;

	const GPIO<GPIOxBaseRegisters::GPIO_D, PINS::PIN13, GpioModes::Output,
			OutputTypes::PushPull, OutputSpeed::MediumSpeed,
			PullUpPullDown::NoPullUpPullDown, AlternateFunction::AF0> statusLED4;

	const GPIO<GPIOxBaseRegisters::GPIO_D, PINS::PIN14, GpioModes::Output,
			OutputTypes::PushPull, OutputSpeed::MediumSpeed,
			PullUpPullDown::NoPullUpPullDown, AlternateFunction::AF0> statusLED5;

	const GPIO<GPIOxBaseRegisters::GPIO_D, PINS::PIN15, GpioModes::Output,
			OutputTypes::PushPull, OutputSpeed::MediumSpeed,
			PullUpPullDown::NoPullUpPullDown, AlternateFunction::AF0> statusLED6;

	//step pin
	const GPIO<GPIOxBaseRegisters::GPIO_E, PINS::PIN10, GpioModes::Output,
			OutputTypes::PushPull, OutputSpeed::MediumSpeed,
			PullUpPullDown::NoPullUpPullDown, AlternateFunction::AF0> stepPin;

	//dir pin
	const GPIO<GPIOxBaseRegisters::GPIO_E, PINS::PIN11, GpioModes::Output,
			OutputTypes::PushPull, OutputSpeed::MediumSpeed,
			PullUpPullDown::NoPullUpPullDown, AlternateFunction::AF0> dirPin;


	const GPIO<GPIOxBaseRegisters::GPIO_A, PINS::PIN2, GpioModes::Input,
			OutputTypes::OpenDrain, OutputSpeed::HighSpeed,
			PullUpPullDown::NoPullUpPullDown, AlternateFunction::AF0> testInterrupt;
};

#endif
