#ifndef PINS_H_
#define PINS_H_

#include "Peripherals/gpio.h"

class BoardPins {

public:
  BoardPins(){};

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


  //LED Pins
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
};

#endif