
#ifndef RCC_H_
#define RCC_H_

#include "../Utility/reg_access.h"
#include "../Utility/reg_access_dynamic.h"
#include "../Utility/util.h"

namespace rcc {

typedef uint32_t RCCRegisterType; 


  namespace BaseRegisters
  {
    constexpr RCCRegisterType RccBaseRegister = 0x40023800U;
    
  }

  namespace RccClockControlRegister {

    constexpr RCCRegisterType RegisterOffset = 0x00U;
    constexpr RCCRegisterType RegisterReset = 0x00000083U;

    constexpr RCCRegisterType PLLI2SReady = Util::Bits::BIT27;
    constexpr RCCRegisterType PLLI2SON = Util::Bits::BIT26;
    constexpr RCCRegisterType MainPLLReady = Util::Bits::BIT25;
    constexpr RCCRegisterType MainPLLOn = Util::Bits::BIT24;
    constexpr RCCRegisterType ClockSecuritySystemEnable = Util::Bits::BIT19;
    constexpr RCCRegisterType HSEBypass = Util::Bits::BIT18;
    constexpr RCCRegisterType HSEReady = Util::Bits::BIT17;
    constexpr RCCRegisterType HSEOn = Util::Bits::BIT16;
    constexpr RCCRegisterType HSIReady = Util::Bits::BIT1;
    constexpr RCCRegisterType HSIOn = Util::Bits::BIT0;

  }

  namespace RccAHB1EnableRegister{

    constexpr RCCRegisterType RegisterOffset = 0x30U;
    constexpr RCCRegisterType RegisterReset = 0x00100000U;
    
    constexpr RCCRegisterType OtgHsulpi = Util::Bits::BIT30;
    constexpr RCCRegisterType OtgHSEn = Util::Bits::BIT29;
    constexpr RCCRegisterType EthernetMacPTP = Util::Bits::BIT28;
    constexpr RCCRegisterType EthernetReception = Util::Bits::BIT27;
    constexpr RCCRegisterType EthernetTransmission = Util::Bits::BIT26;
    constexpr RCCRegisterType EthernetMAC = Util::Bits::BIT25;
    constexpr RCCRegisterType DMA2DEN = Util::Bits::BIT23;
    constexpr RCCRegisterType DMA2EN = Util::Bits::BIT22;
    constexpr RCCRegisterType DMA1EN = Util::Bits::BIT21;
    constexpr RCCRegisterType CcmDataRam = Util::Bits::BIT20;
    constexpr RCCRegisterType BackupSramInterface = Util::Bits::BIT18;
    constexpr RCCRegisterType CRCEN = Util::Bits::BIT12;
    constexpr RCCRegisterType GpioK = Util::Bits::BIT10;
    constexpr RCCRegisterType GpioJ = Util::Bits::BIT9;
    constexpr RCCRegisterType GpioI = Util::Bits::BIT8;
    constexpr RCCRegisterType GpioH = Util::Bits::BIT7;
    constexpr RCCRegisterType GpioG = Util::Bits::BIT6;
    constexpr RCCRegisterType GpioF = Util::Bits::BIT5;
    constexpr RCCRegisterType GpioE = Util::Bits::BIT4;
    constexpr RCCRegisterType GpioD = Util::Bits::BIT3;
    constexpr RCCRegisterType GpioC = Util::Bits::BIT2;
    constexpr RCCRegisterType GpioB = Util::Bits::BIT1;
    constexpr RCCRegisterType GpioA = Util::Bits::BIT0;


  }

  namespace RccAPB1EnableRegister
{

  constexpr RCCRegisterType RegisterOffset = 0x40U;
  constexpr RCCRegisterType RegisterReset = 0x00U;

  constexpr RCCRegisterType UART8Enable = Util::Bits::BIT31;
  constexpr RCCRegisterType UART7Enable = Util::Bits::BIT30;

  constexpr RCCRegisterType DACEnable = Util::Bits::BIT29;

  constexpr RCCRegisterType PowerInterface = Util::Bits::BIT28;

  constexpr RCCRegisterType Can2Enable = Util::Bits::BIT26;
  constexpr RCCRegisterType Can1Enable = Util::Bits::BIT25;

  constexpr RCCRegisterType I2C3Enable = Util::Bits::BIT23;
  constexpr RCCRegisterType I2C2Enable = Util::Bits::BIT22;
  constexpr RCCRegisterType I2C1Enable = Util::Bits::BIT21;

  constexpr RCCRegisterType UART5Enable = Util::Bits::BIT20;
  constexpr RCCRegisterType UART4Enable = Util::Bits::BIT19;
  constexpr RCCRegisterType USART3Enable = Util::Bits::BIT18;
  constexpr RCCRegisterType USART2Enable = Util::Bits::BIT17;

  constexpr RCCRegisterType SPI3Enable = Util::Bits::BIT15;
  constexpr RCCRegisterType SPI2Enable = Util::Bits::BIT14;

  constexpr RCCRegisterType WindowWatchdog = Util::Bits::BIT11;

  constexpr RCCRegisterType Timer14 = Util::Bits::BIT8;
  constexpr RCCRegisterType Timer13 = Util::Bits::BIT7;
  constexpr RCCRegisterType Timer12 = Util::Bits::BIT6;
  constexpr RCCRegisterType Timer7 = Util::Bits::BIT5;
  constexpr RCCRegisterType Timer6 = Util::Bits::BIT4;
  constexpr RCCRegisterType Timer5 = Util::Bits::BIT3;
  constexpr RCCRegisterType Timer4 = Util::Bits::BIT2;
  constexpr RCCRegisterType Timer3 = Util::Bits::BIT1;
  constexpr RCCRegisterType Timer2 = Util::Bits::BIT0;


}


namespace RccAPB2EnableRegister {

  constexpr RCCRegisterType RegisterOffset = 0x44U;
  constexpr RCCRegisterType RegisterReset = 0x00U;

  constexpr RCCRegisterType Timer11 = Util::Bits::BIT18;
  constexpr RCCRegisterType Timer10 = Util::Bits::BIT17;
  constexpr RCCRegisterType Timer9 = Util::Bits::BIT16;

  constexpr RCCRegisterType SystemConfigurationController = Util::Bits::BIT14;

  constexpr RCCRegisterType SPI1Enable = Util::Bits::BIT12;

  constexpr RCCRegisterType SDIOEnable = Util::Bits::BIT11;

  constexpr RCCRegisterType ADC3Enable = Util::Bits::BIT10;
  constexpr RCCRegisterType ADC2Enable = Util::Bits::BIT9;
  constexpr RCCRegisterType ADC1Enable = Util::Bits::BIT8;

  constexpr RCCRegisterType USART6Enable = Util::Bits::BIT5;
  constexpr RCCRegisterType USART1Enable = Util::Bits::BIT4;

  constexpr RCCRegisterType Timer8 = Util::Bits::BIT1;
  constexpr RCCRegisterType Timer1 = Util::Bits::BIT0;

}

}

#endif 