#include "rcc_motherboard.h"

RCCMotherBoard::RCCMotherBoard()
{

 


}


void RCCMotherBoard::setClock150MHZ()
{
  //Assumes 25 MHz Crystal Oscillator

  //Setup Oscillator Pins
//  gpio_config::pinSetup(GPIOxBaseRegisters::GPIO_H,
//                        PINS::PIN0,
//                        GpioModes::AlternateFunction,
//                        OutputTypes::PushPull,
//                        OutputSpeed::VeryHighSpeeed,
//                        PullUpPullDown::NoPullUpPullDown,
//                        AlternateFunction::AF0);
//
//  gpio_config::pinSetup(GPIOxBaseRegisters::GPIO_H,
//                        PINS::PIN1,
//                        GpioModes::AlternateFunction,
//                        OutputTypes::PushPull,
//                        OutputSpeed::VeryHighSpeeed,
//                        PullUpPullDown::NoPullUpPullDown,
//                        AlternateFunction::AF0);

  //Enable HSE
    dynamic_access<RCC_MDG::RCCRegisterType2, RCC_MDG::RCCRegisterType2>::reg_or(RCCMotherBoard::registerRccConfigure, RCC_MDG::CFGR::MCO2Bits::PLLI2SClock);
//    RCC->CR |= (1 << 16);

  dynamic_access<RCC_MDG::RCCRegisterType2, RCC_MDG::RCCRegisterType2>::reg_or(RCCMotherBoard::registerControl, RCC_MDG::CR::HSEON);

  //Wait for oscillator to settle
  while(!(dynamic_access<RCC_MDG::RCCRegisterType2, RCC_MDG::RCCRegisterType2>::reg_get(RCCMotherBoard::registerControl) & RCC_MDG::CR::HSERDY));

  //set PLL Source Mux to HSE
  dynamic_access<RCC_MDG::RCCRegisterType2, RCC_MDG::RCCRegisterType2>::reg_or(RCCMotherBoard::registerPllConfigure, RCC_MDG::PLLCFGR::PLLSRC);

  //set /M divider to /16
  dynamic_access<RCC_MDG::RCCRegisterType2, RCC_MDG::RCCRegisterType2>::reg_or(RCCMotherBoard::registerPllConfigure, RCC_MDG::PLLCFGR::PLLM0Bits::DivBy16);


  //Setup Main PLL
  //Set N multiplier to *192
  RCC_MDG::RCCRegisterType2 nMult = 0xC0U << 6;
  dynamic_access<RCC_MDG::RCCRegisterType2, RCC_MDG::RCCRegisterType2>::reg_or(RCCMotherBoard::registerPllConfigure, nMult);
  
  //Set /P divider to /2
  dynamic_access<RCC_MDG::RCCRegisterType2, RCC_MDG::RCCRegisterType2>::reg_or(RCCMotherBoard::registerPllConfigure, RCC_MDG::PLLCFGR::PLLPxBits::DivBy4);

  
  

  //Set Peripherial CLocks
  //Set AHB prescaler to /2
  dynamic_access<RCC_MDG::RCCRegisterType2, RCC_MDG::RCCRegisterType2>::reg_or(RCCMotherBoard::registerRccConfigure, RCC_MDG::CFGR::HPREBits::DivBy2);
  //Set APB1 prescaler to /2
  dynamic_access<RCC_MDG::RCCRegisterType2, RCC_MDG::RCCRegisterType2>::reg_or(RCCMotherBoard::registerRccConfigure, RCC_MDG::CFGR::PPRE1Bits::DivBy1);
  //Set APB2 prescaler to /1
  dynamic_access<RCC_MDG::RCCRegisterType2, RCC_MDG::RCCRegisterType2>::reg_or(RCCMotherBoard::registerRccConfigure, RCC_MDG::CFGR::PPRE2Bits::DivBy1);
  //Enable PLL
  dynamic_access<RCC_MDG::RCCRegisterType2, RCC_MDG::RCCRegisterType2>::reg_or(RCCMotherBoard::registerControl, RCC_MDG::CR::PLLON);
  //Wait for PLL to settle
  while(!(dynamic_access<RCC_MDG::RCCRegisterType2, RCC_MDG::RCCRegisterType2>::reg_get(RCCMotherBoard::registerControl) & RCC_MDG::CR::PLLRDY));
  //Set system Clock mux to PLL
  dynamic_access<RCC_MDG::RCCRegisterType2, RCC_MDG::RCCRegisterType2>::reg_or(RCCMotherBoard::registerRccConfigure, RCC_MDG::CFGR::SWBits::PLLSource);


  



}