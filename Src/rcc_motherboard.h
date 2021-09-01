#ifndef RCC_MOTHERBOARD_H_
#define RCC_MOTHERBOARD_H_


#include "Registers/rcc_registers.h"
#include "Utility/reg_access.h"
#include "Utility/reg_access_dynamic.h"
#include "Peripherals/gpio_config.h"
#include "../CMSIS/Device/ST/STM32F4xx/Include/stm32f4xx.h"

class RCCMotherBoard
{

  public:
  RCCMotherBoard();
  void setClock150MHZ();

  private:
  uint32_t sysclockFreq;
  uint32_t hclockFreq;
  uint32_t APB1Freq;
  uint32_t APB2Freq;

   RCC_MDG::RCCRegisterType2 baseRegister = RCC_MDG::BaseRegisters::RCC_MDG;

   RCC_MDG::RCCRegisterType2 registerControl = baseRegister + RCC_MDG::CR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerPllConfigure = baseRegister + RCC_MDG::PLLCFGR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerRccConfigure = baseRegister + RCC_MDG::CFGR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerClockInterrupt = baseRegister + RCC_MDG::CIR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerAHB1Reset = baseRegister + RCC_MDG::AHB1RSTR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerAHB2Reset = baseRegister + RCC_MDG::AHB2RSTR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerAHB3Reset = baseRegister + RCC_MDG::AHB3RSTR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerAPB1Reset = baseRegister + RCC_MDG::APB1RSTR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerAPB2Reset = baseRegister + RCC_MDG::APB2RSTR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerAHB1Enable = baseRegister + RCC_MDG::AHB1ENR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerAHB2Enable = baseRegister + RCC_MDG::AHB2ENR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerAHB3Enable = baseRegister + RCC_MDG::AHB3ENR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerAPB1Enable = baseRegister + RCC_MDG::APB1ENR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerAPB2Enable = baseRegister + RCC_MDG::APB2ENR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerAHB1LowPwrEnable = baseRegister + RCC_MDG::AHB1LPENR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerAHB2LowPwrEnable = baseRegister + RCC_MDG::AHB2LPENR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerAHB3LowPwrEnable = baseRegister + RCC_MDG::AHB3LPENR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerAPB1LowPwrEnable = baseRegister + RCC_MDG::APB1LPENR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerAPB2LowPwrEnable = baseRegister + RCC_MDG::APB2LPENR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerRccBackupDomain = baseRegister + RCC_MDG::BDCR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerControlAndStatus = baseRegister + RCC_MDG::CSR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerSpreadSpectrumGen = baseRegister + RCC_MDG::SSCGR::registerOffset;
   RCC_MDG::RCCRegisterType2 registerPllI2sConfigure = baseRegister + RCC_MDG::PLLI2SCFGR::registerOffset;
  






};


#endif //RCC_MOTHERBOARD_H_
