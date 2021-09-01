#ifndef ADCREGISTERS_H_
#define ADCREGISTERS_H_

#include "../Utility/util.h"

namespace ADC_MDG
{

  typedef uint32_t ADCRegisterType;

  namespace BaseRegisters
  {

    constexpr ADCRegisterType ADC1_MDG = 0x40012000U; //Analog-to-digital converter
    constexpr ADCRegisterType ADC2_MDG = 0x40012100U; //Analog-to-digital converter
    constexpr ADCRegisterType ADC3_MDG = 0x40012200U; //Analog-to-digital converter
    constexpr ADCRegisterType C_ADC_MDG = 0x40012300U; //Common ADC registers

  } //End BaseRegisters

  namespace SR //status register
  { 

    constexpr ADCRegisterType registerOffset = 0x0U; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr ADCRegisterType OVR = Util::Bits::BIT5; //Overrun
    constexpr ADCRegisterType STRT = Util::Bits::BIT4; //Regular channel start flag
    constexpr ADCRegisterType JSTRT = Util::Bits::BIT3; //Injected channel start flag
    constexpr ADCRegisterType JEOC = Util::Bits::BIT2; //Injected channel end of conversion
    constexpr ADCRegisterType EOC = Util::Bits::BIT1; //Regular channel end of conversion
    constexpr ADCRegisterType AWD = Util::Bits::BIT0; //Analog watchdog flag

  } //End SR


  namespace CR1 //control register 1
  { 

    constexpr ADCRegisterType registerOffset = 0x4U; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr ADCRegisterType OVRIE = Util::Bits::BIT26; //Overrun interrupt enable

    namespace RESBits//Resolution
    {

      constexpr ADCRegisterType RES12BIT = 0x0U;
      constexpr ADCRegisterType RES10BIT = 0x1000000U;
      constexpr ADCRegisterType RES8BIT = 0x2000000U;
      constexpr ADCRegisterType RES6BIT = 0x3000000U;
   }

    constexpr ADCRegisterType AWDEN = Util::Bits::BIT23; //Analog watchdog enable on regular channels
    constexpr ADCRegisterType JAWDEN = Util::Bits::BIT22; //Analog watchdog enable on injected channels

    namespace DISCNUMBits//Discontinuous mode channel count
    {

      constexpr ADCRegisterType DISCNUM1 = 0x0U;
      constexpr ADCRegisterType DISCNUM2 = 0x2000U;
      constexpr ADCRegisterType DISCNUM3 = 0x4000U;
      constexpr ADCRegisterType DISCNUM4 = 0x6000U;
      constexpr ADCRegisterType DISCNUM5 = 0x8000U;
      constexpr ADCRegisterType DISCNUM6 = 0xA000U;
      constexpr ADCRegisterType DISCNUM7 = 0xC000U;
      constexpr ADCRegisterType DISCNUM8 = 0xE000U;
   }

    constexpr ADCRegisterType JDISCEN = Util::Bits::BIT12; //Discontinuous mode on injected channels
    constexpr ADCRegisterType DISCEN = Util::Bits::BIT11; //Discontinuous mode on regular channels
    constexpr ADCRegisterType JAUTO = Util::Bits::BIT10; //Automatic injected group conversion
    constexpr ADCRegisterType AWDSGL = Util::Bits::BIT9; //Enable the watchdog on a single channel in scan mode
    constexpr ADCRegisterType SCAN = Util::Bits::BIT8; //Scan mode
    constexpr ADCRegisterType JEOCIE = Util::Bits::BIT7; //Interrupt enable for injected channels
    constexpr ADCRegisterType AWDIE = Util::Bits::BIT6; //Analog watchdog interrupt enable
    constexpr ADCRegisterType EOCIE = Util::Bits::BIT5; //Interrupt enable for EOC

    namespace AWDCHBits//Analog watchdog channel select bits
    {

      constexpr ADCRegisterType AWDCH0 = 0x0U;
      constexpr ADCRegisterType AWDCH1 = 0x1U;
      constexpr ADCRegisterType AWDCH2 = 0x2U;
      constexpr ADCRegisterType AWDCH3 = 0x3U;
      constexpr ADCRegisterType AWDCH4 = 0x4U;
      constexpr ADCRegisterType AWDCH5 = 0x5U;
      constexpr ADCRegisterType AWDCH6 = 0x6U;
      constexpr ADCRegisterType AWDCH7 = 0x7U;
      constexpr ADCRegisterType AWDCH8 = 0x8U;
      constexpr ADCRegisterType AWDCH9 = 0x9U;
      constexpr ADCRegisterType AWDCH10 = 0xAU;
      constexpr ADCRegisterType AWDCH11 = 0xBU;
      constexpr ADCRegisterType AWDCH12 = 0xCU;
      constexpr ADCRegisterType AWDCH13 = 0xDU;
      constexpr ADCRegisterType AWDCH14 = 0xEU;
      constexpr ADCRegisterType AWDCH15 = 0xFU;
      constexpr ADCRegisterType AWDCH16 = 0x10U;
      constexpr ADCRegisterType AWDCH17 = 0x11U;
      constexpr ADCRegisterType AWDCH18 = 0x12U;

   }


  } //End CR1


  namespace CR2 //control register 2
  { 

    constexpr ADCRegisterType registerOffset = 0x8U; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr ADCRegisterType SWSTART = Util::Bits::BIT30; //Start conversion of regular channels

    namespace EXTENBits//External trigger enable for regular channels
    {

      constexpr ADCRegisterType DISABLED = 0x0U;
      constexpr ADCRegisterType RISINGEDGE = 0x10000000U;
      constexpr ADCRegisterType FALLINGEDGE = 0x20000000U;
      constexpr ADCRegisterType RISINGFALLING = 0x30000000U;
   }


    namespace EXTSELBits//External event select for regular group
    {

      constexpr ADCRegisterType TIM1CC1 = 0x0U;
      constexpr ADCRegisterType TIM1CC2 = 0x1000000U;
      constexpr ADCRegisterType TIM1CC3 = 0x2000000U;
      constexpr ADCRegisterType TIM2CC2 = 0x3000000U;
      constexpr ADCRegisterType TIM2CC3 = 0x4000000U;
      constexpr ADCRegisterType TIM2CC4 = 0x5000000U;
      constexpr ADCRegisterType TIM2TRGO = 0x6000000U;
      constexpr ADCRegisterType TIM3CC1 = 0x7000000U;
      constexpr ADCRegisterType TIM3TRGO = 0x8000000U;
      constexpr ADCRegisterType TIM4CC4 = 0x9000000U;
      constexpr ADCRegisterType TIM5CC1 = 0xA000000U;
      constexpr ADCRegisterType TIM5CC2 = 0xB000000U;
      constexpr ADCRegisterType TIM5CC3 = 0xC000000U;
      constexpr ADCRegisterType TIM8CC1 = 0xD000000U;
      constexpr ADCRegisterType TIM8TRGO = 0xE000000U;
      constexpr ADCRegisterType EXTILINE11 = 0xF000000U;
   }

    constexpr ADCRegisterType JSWSTART = Util::Bits::BIT22; //Start conversion of injected channels

    namespace JEXTENBits//External trigger enable for injected channels
    {

      constexpr ADCRegisterType DISABLED = 0x0U;
      constexpr ADCRegisterType RISINGEDGE = 0x100000U;
      constexpr ADCRegisterType FALLINGEDGE = 0x200000U;
      constexpr ADCRegisterType RISINGFALLING = 0x300000U;
   }


    namespace JEXTSELBits//External event select for injected group
    {

      constexpr ADCRegisterType TIM1CC4 = 0x0U;
      constexpr ADCRegisterType TIM1TRGO = 0x10000U;
      constexpr ADCRegisterType TIM2CC1 = 0x20000U;
      constexpr ADCRegisterType TIM2TRGO = 0x30000U;
      constexpr ADCRegisterType TIM3CC2 = 0x40000U;
      constexpr ADCRegisterType TIM3CC4 = 0x50000U;
      constexpr ADCRegisterType TIM4CC1 = 0x60000U;
      constexpr ADCRegisterType TIM4CC2 = 0x70000U;
      constexpr ADCRegisterType TIM4CC3 = 0x80000U;
      constexpr ADCRegisterType TIM4TRGO = 0x90000U;
      constexpr ADCRegisterType TIM5CC4 = 0xA0000U;
      constexpr ADCRegisterType TIM5TRGO = 0xB0000U;
      constexpr ADCRegisterType TIM8CC2 = 0xC0000U;
      constexpr ADCRegisterType TIM8CC3 = 0xD0000U;
      constexpr ADCRegisterType TIM8CC4 = 0xE0000U;
      constexpr ADCRegisterType EXTILINE15 = 0xF0000U;
   }

    constexpr ADCRegisterType ALIGN = Util::Bits::BIT11; //Data alignment: 0 = Right Align, 1 = Left Align
    constexpr ADCRegisterType EOCS = Util::Bits::BIT10; //End of conversion selection
    constexpr ADCRegisterType DDS = Util::Bits::BIT9; //DMA disable selection (for single ADC mode)
    constexpr ADCRegisterType DMA = Util::Bits::BIT8; //Direct memory access mode (for single ADC mode)
    constexpr ADCRegisterType CONT = Util::Bits::BIT1; //Continuous conversion
    constexpr ADCRegisterType ADON = Util::Bits::BIT0; //A/D Converter ON / OFF

  } //End CR2


  namespace SMPR1 //sample time register 1
  { 

    constexpr ADCRegisterType registerOffset = 0xCU; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value


    namespace SMP18Bits//Sample time bits
    {

      constexpr ADCRegisterType CYCLES3 = 0x0U;
      constexpr ADCRegisterType CYCLES15 = 0x1000000U;
      constexpr ADCRegisterType CYCLES28 = 0x2000000U;
      constexpr ADCRegisterType CYCLES56 = 0x3000000U;
      constexpr ADCRegisterType CYCLES84 = 0x4000000U;
      constexpr ADCRegisterType CYCLES112 = 0x5000000U;
      constexpr ADCRegisterType CYCLES144 = 0x6000000U;
      constexpr ADCRegisterType CYCLES480 = 0x7000000U;
   }


    namespace SMP17Bits//Sample time bits
    {

      constexpr ADCRegisterType CYCLES3 = 0x0U;
      constexpr ADCRegisterType CYCLES15 = 0x200000U;
      constexpr ADCRegisterType CYCLES28 = 0x400000U;
      constexpr ADCRegisterType CYCLES56 = 0x600000U;
      constexpr ADCRegisterType CYCLES84 = 0x800000U;
      constexpr ADCRegisterType CYCLES112 = 0xA00000U;
      constexpr ADCRegisterType CYCLES144 = 0xC00000U;
      constexpr ADCRegisterType CYCLES480 = 0xE00000U;
   }


    namespace SMP16Bits//Sample time bits
    {

      constexpr ADCRegisterType CYCLES3 = 0x0U;
      constexpr ADCRegisterType CYCLES15 = 0x40000U;
      constexpr ADCRegisterType CYCLES28 = 0x80000U;
      constexpr ADCRegisterType CYCLES56 = 0xC0000U;
      constexpr ADCRegisterType CYCLES84 = 0x100000U;
      constexpr ADCRegisterType CYCLES112 = 0x140000U;
      constexpr ADCRegisterType CYCLES144 = 0x180000U;
      constexpr ADCRegisterType CYCLES480 = 0x1C0000U;
   }


    namespace SMP15Bits//Sample time bits
    {

      constexpr ADCRegisterType CYCLES3 = 0x0U;
      constexpr ADCRegisterType CYCLES15 = 0x8000U;
      constexpr ADCRegisterType CYCLES28 = 0x10000U;
      constexpr ADCRegisterType CYCLES56 = 0x18000U;
      constexpr ADCRegisterType CYCLES84 = 0x20000U;
      constexpr ADCRegisterType CYCLES112 = 0x28000U;
      constexpr ADCRegisterType CYCLES144 = 0x30000U;
      constexpr ADCRegisterType CYCLES480 = 0x38000U;
   }


    namespace SMP14Bits//Sample time bits
    {

      constexpr ADCRegisterType CYCLES3 = 0x0U;
      constexpr ADCRegisterType CYCLES15 = 0x1000U;
      constexpr ADCRegisterType CYCLES28 = 0x2000U;
      constexpr ADCRegisterType CYCLES56 = 0x3000U;
      constexpr ADCRegisterType CYCLES84 = 0x4000U;
      constexpr ADCRegisterType CYCLES112 = 0x5000U;
      constexpr ADCRegisterType CYCLES144 = 0x6000U;
      constexpr ADCRegisterType CYCLES480 = 0x7000U;
   }


    namespace SMP13Bits//Sample time bits
    {

      constexpr ADCRegisterType CYCLES3 = 0x0U;
      constexpr ADCRegisterType CYCLES15 = 0x200U;
      constexpr ADCRegisterType CYCLES28 = 0x400U;
      constexpr ADCRegisterType CYCLES56 = 0x600U;
      constexpr ADCRegisterType CYCLES84 = 0x800U;
      constexpr ADCRegisterType CYCLES112 = 0xA00U;
      constexpr ADCRegisterType CYCLES144 = 0xC00U;
      constexpr ADCRegisterType CYCLES480 = 0xE00U;
   }


    namespace SMP12Bits//Sample time bits
    {

      constexpr ADCRegisterType CYCLES3 = 0x0U;
      constexpr ADCRegisterType CYCLES15 = 0x40U;
      constexpr ADCRegisterType CYCLES28 = 0x80U;
      constexpr ADCRegisterType CYCLES56 = 0xC0U;
      constexpr ADCRegisterType CYCLES84 = 0x100U;
      constexpr ADCRegisterType CYCLES112 = 0x140U;
      constexpr ADCRegisterType CYCLES144 = 0x180U;
      constexpr ADCRegisterType CYCLES480 = 0x1C0U;
   }


    namespace SMP11Bits//Sample time bits
    {

      constexpr ADCRegisterType CYCLES3 = 0x0U;
      constexpr ADCRegisterType CYCLES15 = 0x8U;
      constexpr ADCRegisterType CYCLES28 = 0x10U;
      constexpr ADCRegisterType CYCLES56 = 0x18U;
      constexpr ADCRegisterType CYCLES84 = 0x20U;
      constexpr ADCRegisterType CYCLES112 = 0x28U;
      constexpr ADCRegisterType CYCLES144 = 0x30U;
      constexpr ADCRegisterType CYCLES480 = 0x38U;
   }


    namespace SMP10Bits//Sample time bits
    {

      constexpr ADCRegisterType CYCLES3 = 0x0U;
      constexpr ADCRegisterType CYCLES15 = 0x1U;
      constexpr ADCRegisterType CYCLES28 = 0x2U;
      constexpr ADCRegisterType CYCLES56 = 0x3U;
      constexpr ADCRegisterType CYCLES84 = 0x4U;
      constexpr ADCRegisterType CYCLES112 = 0x5U;
      constexpr ADCRegisterType CYCLES144 = 0x6U;
      constexpr ADCRegisterType CYCLES480 = 0x7U;
   }


  } //End SMPR1



  namespace SMPR2 //sample time register 2
  { 

    constexpr ADCRegisterType registerOffset = 0x10U; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value


    namespace SMP9Bits//Sample time bits
    {

      constexpr ADCRegisterType CYCLES3 = 0x0U;
      constexpr ADCRegisterType CYCLES15 = 0x1000000U;
      constexpr ADCRegisterType CYCLES28 = 0x2000000U;
      constexpr ADCRegisterType CYCLES56 = 0x3000000U;
      constexpr ADCRegisterType CYCLES84 = 0x4000000U;
      constexpr ADCRegisterType CYCLES112 = 0x5000000U;
      constexpr ADCRegisterType CYCLES144 = 0x6000000U;
      constexpr ADCRegisterType CYCLES480 = 0x7000000U;
   }


    namespace SMP8Bits//Sample time bits
    {

      constexpr ADCRegisterType CYCLES3 = 0x0U;
      constexpr ADCRegisterType CYCLES15 = 0x200000U;
      constexpr ADCRegisterType CYCLES28 = 0x400000U;
      constexpr ADCRegisterType CYCLES56 = 0x600000U;
      constexpr ADCRegisterType CYCLES84 = 0x800000U;
      constexpr ADCRegisterType CYCLES112 = 0xA00000U;
      constexpr ADCRegisterType CYCLES144 = 0xC00000U;
      constexpr ADCRegisterType CYCLES480 = 0xE00000U;
   }


    namespace SMP7Bits//Sample time bits
    {

      constexpr ADCRegisterType CYCLES3 = 0x0U;
      constexpr ADCRegisterType CYCLES15 = 0x40000U;
      constexpr ADCRegisterType CYCLES28 = 0x80000U;
      constexpr ADCRegisterType CYCLES56 = 0xC0000U;
      constexpr ADCRegisterType CYCLES84 = 0x100000U;
      constexpr ADCRegisterType CYCLES112 = 0x140000U;
      constexpr ADCRegisterType CYCLES144 = 0x180000U;
      constexpr ADCRegisterType CYCLES480 = 0x1C0000U;
   }


    namespace SMP6Bits//Sample time bits
    {

      constexpr ADCRegisterType CYCLES3 = 0x0U;
      constexpr ADCRegisterType CYCLES15 = 0x8000U;
      constexpr ADCRegisterType CYCLES28 = 0x10000U;
      constexpr ADCRegisterType CYCLES56 = 0x18000U;
      constexpr ADCRegisterType CYCLES84 = 0x20000U;
      constexpr ADCRegisterType CYCLES112 = 0x28000U;
      constexpr ADCRegisterType CYCLES144 = 0x30000U;
      constexpr ADCRegisterType CYCLES480 = 0x38000U;
   }


    namespace SMP5Bits//Sample time bits
    {

      constexpr ADCRegisterType CYCLES3 = 0x0U;
      constexpr ADCRegisterType CYCLES15 = 0x1000U;
      constexpr ADCRegisterType CYCLES28 = 0x2000U;
      constexpr ADCRegisterType CYCLES56 = 0x3000U;
      constexpr ADCRegisterType CYCLES84 = 0x4000U;
      constexpr ADCRegisterType CYCLES112 = 0x5000U;
      constexpr ADCRegisterType CYCLES144 = 0x6000U;
      constexpr ADCRegisterType CYCLES480 = 0x7000U;
   }


    namespace SMP4Bits//Sample time bits
    {

      constexpr ADCRegisterType CYCLES3 = 0x0U;
      constexpr ADCRegisterType CYCLES15 = 0x200U;
      constexpr ADCRegisterType CYCLES28 = 0x400U;
      constexpr ADCRegisterType CYCLES56 = 0x600U;
      constexpr ADCRegisterType CYCLES84 = 0x800U;
      constexpr ADCRegisterType CYCLES112 = 0xA00U;
      constexpr ADCRegisterType CYCLES144 = 0xC00U;
      constexpr ADCRegisterType CYCLES480 = 0xE00U;
   }


    namespace SMP3Bits//Sample time bits
    {

      constexpr ADCRegisterType CYCLES3 = 0x0U;
      constexpr ADCRegisterType CYCLES15 = 0x40U;
      constexpr ADCRegisterType CYCLES28 = 0x80U;
      constexpr ADCRegisterType CYCLES56 = 0xC0U;
      constexpr ADCRegisterType CYCLES84 = 0x100U;
      constexpr ADCRegisterType CYCLES112 = 0x140U;
      constexpr ADCRegisterType CYCLES144 = 0x180U;
      constexpr ADCRegisterType CYCLES480 = 0x1C0U;
   }


    namespace SMP2Bits//Sample time bits
    {

      constexpr ADCRegisterType CYCLES3 = 0x0U;
      constexpr ADCRegisterType CYCLES15 = 0x8U;
      constexpr ADCRegisterType CYCLES28 = 0x10U;
      constexpr ADCRegisterType CYCLES56 = 0x18U;
      constexpr ADCRegisterType CYCLES84 = 0x20U;
      constexpr ADCRegisterType CYCLES112 = 0x28U;
      constexpr ADCRegisterType CYCLES144 = 0x30U;
      constexpr ADCRegisterType CYCLES480 = 0x38U;
   }


    namespace SMP1Bits//Sample time bits
    {

      constexpr ADCRegisterType CYCLES3 = 0x0U;
      constexpr ADCRegisterType CYCLES15 = 0x1U;
      constexpr ADCRegisterType CYCLES28 = 0x2U;
      constexpr ADCRegisterType CYCLES56 = 0x3U;
      constexpr ADCRegisterType CYCLES84 = 0x4U;
      constexpr ADCRegisterType CYCLES112 = 0x5U;
      constexpr ADCRegisterType CYCLES144 = 0x6U;
      constexpr ADCRegisterType CYCLES480 = 0x7U;
   }


  } //End SMPR2


  namespace JOFR1 //injected channel data offset register x
  { 

    constexpr ADCRegisterType registerOffset = 0x14U; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End JOFR1


  namespace JOFR2 //injected channel data offset register x
  { 

    constexpr ADCRegisterType registerOffset = 0x18U; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End JOFR2


  namespace JOFR3 //injected channel data offset register x
  { 

    constexpr ADCRegisterType registerOffset = 0x1CU; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End JOFR3


  namespace JOFR4 //injected channel data offset register x
  { 

    constexpr ADCRegisterType registerOffset = 0x20U; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End JOFR4


  namespace HTR //watchdog higher threshold register
  { 

    constexpr ADCRegisterType registerOffset = 0x24U; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End HTR


  namespace LTR //watchdog lower threshold register
  { 

    constexpr ADCRegisterType registerOffset = 0x28U; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End LTR


  namespace SQR1 //regular sequence register 1
  { 

    constexpr ADCRegisterType registerOffset = 0x2CU; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value


    namespace LBits//Regular channel sequence length
    {

      constexpr ADCRegisterType L0 = 0x0U;
      constexpr ADCRegisterType L1 = 0x100000U;
      constexpr ADCRegisterType L2 = 0x200000U;
      constexpr ADCRegisterType L3 = 0x300000U;
      constexpr ADCRegisterType L4 = 0x400000U;
      constexpr ADCRegisterType L5 = 0x500000U;
      constexpr ADCRegisterType L6 = 0x600000U;
      constexpr ADCRegisterType L7 = 0x700000U;
      constexpr ADCRegisterType L8 = 0x800000U;
      constexpr ADCRegisterType L9 = 0x900000U;
      constexpr ADCRegisterType L10 = 0xA00000U;
      constexpr ADCRegisterType L11 = 0xB00000U;
      constexpr ADCRegisterType L12 = 0xC00000U;
      constexpr ADCRegisterType L13 = 0xD00000U;
      constexpr ADCRegisterType L14 = 0xE00000U;
      constexpr ADCRegisterType L15 = 0xF00000U;
   }


    namespace SQ16Bits//16th conversion in regular sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x8000U;
      constexpr ADCRegisterType CHANNEL2 = 0x10000U;
      constexpr ADCRegisterType CHANNEL3 = 0x18000U;
      constexpr ADCRegisterType CHANNEL4 = 0x20000U;
      constexpr ADCRegisterType CHANNEL5 = 0x28000U;
      constexpr ADCRegisterType CHANNEL6 = 0x30000U;
      constexpr ADCRegisterType CHANNEL7 = 0x38000U;
      constexpr ADCRegisterType CHANNEL8 = 0x40000U;
      constexpr ADCRegisterType CHANNEL9 = 0x48000U;
      constexpr ADCRegisterType CHANNEL10 = 0x50000U;
      constexpr ADCRegisterType CHANNEL11 = 0x58000U;
      constexpr ADCRegisterType CHANNEL12 = 0x60000U;
      constexpr ADCRegisterType CHANNEL13 = 0x68000U;
      constexpr ADCRegisterType CHANNEL14 = 0x70000U;
      constexpr ADCRegisterType CHANNEL15 = 0x78000U;
      constexpr ADCRegisterType CHANNEL16 = 0x80000U;
      constexpr ADCRegisterType CHANNEL17 = 0x88000U;
      constexpr ADCRegisterType CHANNEL18 = 0x90000U;
    
   }


    namespace SQ15Bits//15th conversion in regular sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x400U;
      constexpr ADCRegisterType CHANNEL2 = 0x800U;
      constexpr ADCRegisterType CHANNEL3 = 0xC00U;
      constexpr ADCRegisterType CHANNEL4 = 0x1000U;
      constexpr ADCRegisterType CHANNEL5 = 0x1400U;
      constexpr ADCRegisterType CHANNEL6 = 0x1800U;
      constexpr ADCRegisterType CHANNEL7 = 0x1C00U;
      constexpr ADCRegisterType CHANNEL8 = 0x2000U;
      constexpr ADCRegisterType CHANNEL9 = 0x2400U;
      constexpr ADCRegisterType CHANNEL10 = 0x2800U;
      constexpr ADCRegisterType CHANNEL11 = 0x2C00U;
      constexpr ADCRegisterType CHANNEL12 = 0x3000U;
      constexpr ADCRegisterType CHANNEL13 = 0x3400U;
      constexpr ADCRegisterType CHANNEL14 = 0x3800U;
      constexpr ADCRegisterType CHANNEL15 = 0x3C00U;
      constexpr ADCRegisterType CHANNEL16 = 0x4000U;
      constexpr ADCRegisterType CHANNEL17 = 0x4400U;
      constexpr ADCRegisterType CHANNEL18 = 0x4800U;

   }


    namespace SQ14Bits//14th conversion in regular sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x20U;
      constexpr ADCRegisterType CHANNEL2 = 0x40U;
      constexpr ADCRegisterType CHANNEL3 = 0x60U;
      constexpr ADCRegisterType CHANNEL4 = 0x80U;
      constexpr ADCRegisterType CHANNEL5 = 0xA0U;
      constexpr ADCRegisterType CHANNEL6 = 0xC0U;
      constexpr ADCRegisterType CHANNEL7 = 0xE0U;
      constexpr ADCRegisterType CHANNEL8 = 0x100U;
      constexpr ADCRegisterType CHANNEL9 = 0x120U;
      constexpr ADCRegisterType CHANNEL10 = 0x140U;
      constexpr ADCRegisterType CHANNEL11 = 0x160U;
      constexpr ADCRegisterType CHANNEL12 = 0x180U;
      constexpr ADCRegisterType CHANNEL13 = 0x1A0U;
      constexpr ADCRegisterType CHANNEL14 = 0x1C0U;
      constexpr ADCRegisterType CHANNEL15 = 0x1E0U;
      constexpr ADCRegisterType CHANNEL16 = 0x200U;
      constexpr ADCRegisterType CHANNEL17 = 0x220U;
      constexpr ADCRegisterType CHANNEL18 = 0x240U;

   }


    namespace SQ13Bits//13th conversion in regular sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x1U;
      constexpr ADCRegisterType CHANNEL2 = 0x2U;
      constexpr ADCRegisterType CHANNEL3 = 0x3U;
      constexpr ADCRegisterType CHANNEL4 = 0x4U;
      constexpr ADCRegisterType CHANNEL5 = 0x5U;
      constexpr ADCRegisterType CHANNEL6 = 0x6U;
      constexpr ADCRegisterType CHANNEL7 = 0x7U;
      constexpr ADCRegisterType CHANNEL8 = 0x8U;
      constexpr ADCRegisterType CHANNEL9 = 0x9U;
      constexpr ADCRegisterType CHANNEL10 = 0xAU;
      constexpr ADCRegisterType CHANNEL11 = 0xBU;
      constexpr ADCRegisterType CHANNEL12 = 0xCU;
      constexpr ADCRegisterType CHANNEL13 = 0xDU;
      constexpr ADCRegisterType CHANNEL14 = 0xEU;
      constexpr ADCRegisterType CHANNEL15 = 0xFU;
      constexpr ADCRegisterType CHANNEL16 = 0x10U;
      constexpr ADCRegisterType CHANNEL17 = 0x11U;
      constexpr ADCRegisterType CHANNEL18 = 0x12U;

   }


  } //End SQR1


  namespace SQR2 //regular sequence register 2
  { 

    constexpr ADCRegisterType registerOffset = 0x30U; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value


    namespace SQ12Bits//12th conversion in regular sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x2000000U;
      constexpr ADCRegisterType CHANNEL2 = 0x4000000U;
      constexpr ADCRegisterType CHANNEL3 = 0x6000000U;
      constexpr ADCRegisterType CHANNEL4 = 0x8000000U;
      constexpr ADCRegisterType CHANNEL5 = 0xA000000U;
      constexpr ADCRegisterType CHANNEL6 = 0xC000000U;
      constexpr ADCRegisterType CHANNEL7 = 0xE000000U;
      constexpr ADCRegisterType CHANNEL8 = 0x10000000U;
      constexpr ADCRegisterType CHANNEL9 = 0x12000000U;
      constexpr ADCRegisterType CHANNEL10 = 0x14000000U;
      constexpr ADCRegisterType CHANNEL11 = 0x16000000U;
      constexpr ADCRegisterType CHANNEL12 = 0x18000000U;
      constexpr ADCRegisterType CHANNEL13 = 0x1A000000U;
      constexpr ADCRegisterType CHANNEL14 = 0x1C000000U;
      constexpr ADCRegisterType CHANNEL15 = 0x1E000000U;
      constexpr ADCRegisterType CHANNEL16 = 0x20000000U;
      constexpr ADCRegisterType CHANNEL17 = 0x22000000U;
      constexpr ADCRegisterType CHANNEL18 = 0x24000000U;
 
   }


    namespace SQ11Bits//11th conversion in regular sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x100000U;
      constexpr ADCRegisterType CHANNEL2 = 0x200000U;
      constexpr ADCRegisterType CHANNEL3 = 0x300000U;
      constexpr ADCRegisterType CHANNEL4 = 0x400000U;
      constexpr ADCRegisterType CHANNEL5 = 0x500000U;
      constexpr ADCRegisterType CHANNEL6 = 0x600000U;
      constexpr ADCRegisterType CHANNEL7 = 0x700000U;
      constexpr ADCRegisterType CHANNEL8 = 0x800000U;
      constexpr ADCRegisterType CHANNEL9 = 0x900000U;
      constexpr ADCRegisterType CHANNEL10 = 0xA00000U;
      constexpr ADCRegisterType CHANNEL11 = 0xB00000U;
      constexpr ADCRegisterType CHANNEL12 = 0xC00000U;
      constexpr ADCRegisterType CHANNEL13 = 0xD00000U;
      constexpr ADCRegisterType CHANNEL14 = 0xE00000U;
      constexpr ADCRegisterType CHANNEL15 = 0xF00000U;
      constexpr ADCRegisterType CHANNEL16 = 0x1000000U;
      constexpr ADCRegisterType CHANNEL17 = 0x1100000U;
      constexpr ADCRegisterType CHANNEL18 = 0x1200000U;

   }


    namespace SQ10Bits//10th conversion in regular sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x8000U;
      constexpr ADCRegisterType CHANNEL2 = 0x10000U;
      constexpr ADCRegisterType CHANNEL3 = 0x18000U;
      constexpr ADCRegisterType CHANNEL4 = 0x20000U;
      constexpr ADCRegisterType CHANNEL5 = 0x28000U;
      constexpr ADCRegisterType CHANNEL6 = 0x30000U;
      constexpr ADCRegisterType CHANNEL7 = 0x38000U;
      constexpr ADCRegisterType CHANNEL8 = 0x40000U;
      constexpr ADCRegisterType CHANNEL9 = 0x48000U;
      constexpr ADCRegisterType CHANNEL10 = 0x50000U;
      constexpr ADCRegisterType CHANNEL11 = 0x58000U;
      constexpr ADCRegisterType CHANNEL12 = 0x60000U;
      constexpr ADCRegisterType CHANNEL13 = 0x68000U;
      constexpr ADCRegisterType CHANNEL14 = 0x70000U;
      constexpr ADCRegisterType CHANNEL15 = 0x78000U;
      constexpr ADCRegisterType CHANNEL16 = 0x80000U;
      constexpr ADCRegisterType CHANNEL17 = 0x88000U;
      constexpr ADCRegisterType CHANNEL18 = 0x90000U;

   }


    namespace SQ9Bits//9th conversion in regular sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x400U;
      constexpr ADCRegisterType CHANNEL2 = 0x800U;
      constexpr ADCRegisterType CHANNEL3 = 0xC00U;
      constexpr ADCRegisterType CHANNEL4 = 0x1000U;
      constexpr ADCRegisterType CHANNEL5 = 0x1400U;
      constexpr ADCRegisterType CHANNEL6 = 0x1800U;
      constexpr ADCRegisterType CHANNEL7 = 0x1C00U;
      constexpr ADCRegisterType CHANNEL8 = 0x2000U;
      constexpr ADCRegisterType CHANNEL9 = 0x2400U;
      constexpr ADCRegisterType CHANNEL10 = 0x2800U;
      constexpr ADCRegisterType CHANNEL11 = 0x2C00U;
      constexpr ADCRegisterType CHANNEL12 = 0x3000U;
      constexpr ADCRegisterType CHANNEL13 = 0x3400U;
      constexpr ADCRegisterType CHANNEL14 = 0x3800U;
      constexpr ADCRegisterType CHANNEL15 = 0x3C00U;
      constexpr ADCRegisterType CHANNEL16 = 0x4000U;
      constexpr ADCRegisterType CHANNEL17 = 0x4400U;
      constexpr ADCRegisterType CHANNEL18 = 0x4800U;

   }


    namespace SQ8Bits//8th conversion in regular sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x20U;
      constexpr ADCRegisterType CHANNEL2 = 0x40U;
      constexpr ADCRegisterType CHANNEL3 = 0x60U;
      constexpr ADCRegisterType CHANNEL4 = 0x80U;
      constexpr ADCRegisterType CHANNEL5 = 0xA0U;
      constexpr ADCRegisterType CHANNEL6 = 0xC0U;
      constexpr ADCRegisterType CHANNEL7 = 0xE0U;
      constexpr ADCRegisterType CHANNEL8 = 0x100U;
      constexpr ADCRegisterType CHANNEL9 = 0x120U;
      constexpr ADCRegisterType CHANNEL10 = 0x140U;
      constexpr ADCRegisterType CHANNEL11 = 0x160U;
      constexpr ADCRegisterType CHANNEL12 = 0x180U;
      constexpr ADCRegisterType CHANNEL13 = 0x1A0U;
      constexpr ADCRegisterType CHANNEL14 = 0x1C0U;
      constexpr ADCRegisterType CHANNEL15 = 0x1E0U;
      constexpr ADCRegisterType CHANNEL16 = 0x200U;
      constexpr ADCRegisterType CHANNEL17 = 0x220U;
      constexpr ADCRegisterType CHANNEL18 = 0x240U;

   }


    namespace SQ7Bits//7th conversion in regular sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x1U;
      constexpr ADCRegisterType CHANNEL2 = 0x2U;
      constexpr ADCRegisterType CHANNEL3 = 0x3U;
      constexpr ADCRegisterType CHANNEL4 = 0x4U;
      constexpr ADCRegisterType CHANNEL5 = 0x5U;
      constexpr ADCRegisterType CHANNEL6 = 0x6U;
      constexpr ADCRegisterType CHANNEL7 = 0x7U;
      constexpr ADCRegisterType CHANNEL8 = 0x8U;
      constexpr ADCRegisterType CHANNEL9 = 0x9U;
      constexpr ADCRegisterType CHANNEL10 = 0xAU;
      constexpr ADCRegisterType CHANNEL11 = 0xBU;
      constexpr ADCRegisterType CHANNEL12 = 0xCU;
      constexpr ADCRegisterType CHANNEL13 = 0xDU;
      constexpr ADCRegisterType CHANNEL14 = 0xEU;
      constexpr ADCRegisterType CHANNEL15 = 0xFU;
      constexpr ADCRegisterType CHANNEL16 = 0x10U;
      constexpr ADCRegisterType CHANNEL17 = 0x11U;
      constexpr ADCRegisterType CHANNEL18 = 0x12U;

   }


  } //End SQR2


  namespace SQR3 //regular sequence register 3
  { 

    constexpr ADCRegisterType registerOffset = 0x34U; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value


    namespace SQ6Bits//6th conversion in regular sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x2000000U;
      constexpr ADCRegisterType CHANNEL2 = 0x4000000U;
      constexpr ADCRegisterType CHANNEL3 = 0x6000000U;
      constexpr ADCRegisterType CHANNEL4 = 0x8000000U;
      constexpr ADCRegisterType CHANNEL5 = 0xA000000U;
      constexpr ADCRegisterType CHANNEL6 = 0xC000000U;
      constexpr ADCRegisterType CHANNEL7 = 0xE000000U;
      constexpr ADCRegisterType CHANNEL8 = 0x10000000U;
      constexpr ADCRegisterType CHANNEL9 = 0x12000000U;
      constexpr ADCRegisterType CHANNEL10 = 0x14000000U;
      constexpr ADCRegisterType CHANNEL11 = 0x16000000U;
      constexpr ADCRegisterType CHANNEL12 = 0x18000000U;
      constexpr ADCRegisterType CHANNEL13 = 0x1A000000U;
      constexpr ADCRegisterType CHANNEL14 = 0x1C000000U;
      constexpr ADCRegisterType CHANNEL15 = 0x1E000000U;
      constexpr ADCRegisterType CHANNEL16 = 0x20000000U;
      constexpr ADCRegisterType CHANNEL17 = 0x22000000U;
      constexpr ADCRegisterType CHANNEL18 = 0x24000000U;

   }


    namespace SQ5Bits//5th conversion in regular sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x100000U;
      constexpr ADCRegisterType CHANNEL2 = 0x200000U;
      constexpr ADCRegisterType CHANNEL3 = 0x300000U;
      constexpr ADCRegisterType CHANNEL4 = 0x400000U;
      constexpr ADCRegisterType CHANNEL5 = 0x500000U;
      constexpr ADCRegisterType CHANNEL6 = 0x600000U;
      constexpr ADCRegisterType CHANNEL7 = 0x700000U;
      constexpr ADCRegisterType CHANNEL8 = 0x800000U;
      constexpr ADCRegisterType CHANNEL9 = 0x900000U;
      constexpr ADCRegisterType CHANNEL10 = 0xA00000U;
      constexpr ADCRegisterType CHANNEL11 = 0xB00000U;
      constexpr ADCRegisterType CHANNEL12 = 0xC00000U;
      constexpr ADCRegisterType CHANNEL13 = 0xD00000U;
      constexpr ADCRegisterType CHANNEL14 = 0xE00000U;
      constexpr ADCRegisterType CHANNEL15 = 0xF00000U;
      constexpr ADCRegisterType CHANNEL16 = 0x1000000U;
      constexpr ADCRegisterType CHANNEL17 = 0x1100000U;
      constexpr ADCRegisterType CHANNEL18 = 0x1200000U;

   }


    namespace SQ4Bits//4th conversion in regular sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x8000U;
      constexpr ADCRegisterType CHANNEL2 = 0x10000U;
      constexpr ADCRegisterType CHANNEL3 = 0x18000U;
      constexpr ADCRegisterType CHANNEL4 = 0x20000U;
      constexpr ADCRegisterType CHANNEL5 = 0x28000U;
      constexpr ADCRegisterType CHANNEL6 = 0x30000U;
      constexpr ADCRegisterType CHANNEL7 = 0x38000U;
      constexpr ADCRegisterType CHANNEL8 = 0x40000U;
      constexpr ADCRegisterType CHANNEL9 = 0x48000U;
      constexpr ADCRegisterType CHANNEL10 = 0x50000U;
      constexpr ADCRegisterType CHANNEL11 = 0x58000U;
      constexpr ADCRegisterType CHANNEL12 = 0x60000U;
      constexpr ADCRegisterType CHANNEL13 = 0x68000U;
      constexpr ADCRegisterType CHANNEL14 = 0x70000U;
      constexpr ADCRegisterType CHANNEL15 = 0x78000U;
      constexpr ADCRegisterType CHANNEL16 = 0x80000U;
      constexpr ADCRegisterType CHANNEL17 = 0x88000U;
      constexpr ADCRegisterType CHANNEL18 = 0x90000U;
  
   }


    namespace SQ3Bits//3rd conversion in regular sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x400U;
      constexpr ADCRegisterType CHANNEL2 = 0x800U;
      constexpr ADCRegisterType CHANNEL3 = 0xC00U;
      constexpr ADCRegisterType CHANNEL4 = 0x1000U;
      constexpr ADCRegisterType CHANNEL5 = 0x1400U;
      constexpr ADCRegisterType CHANNEL6 = 0x1800U;
      constexpr ADCRegisterType CHANNEL7 = 0x1C00U;
      constexpr ADCRegisterType CHANNEL8 = 0x2000U;
      constexpr ADCRegisterType CHANNEL9 = 0x2400U;
      constexpr ADCRegisterType CHANNEL10 = 0x2800U;
      constexpr ADCRegisterType CHANNEL11 = 0x2C00U;
      constexpr ADCRegisterType CHANNEL12 = 0x3000U;
      constexpr ADCRegisterType CHANNEL13 = 0x3400U;
      constexpr ADCRegisterType CHANNEL14 = 0x3800U;
      constexpr ADCRegisterType CHANNEL15 = 0x3C00U;
      constexpr ADCRegisterType CHANNEL16 = 0x4000U;
      constexpr ADCRegisterType CHANNEL17 = 0x4400U;
      constexpr ADCRegisterType CHANNEL18 = 0x4800U;

   }


    namespace SQ2Bits//2nd conversion in regular sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x20U;
      constexpr ADCRegisterType CHANNEL2 = 0x40U;
      constexpr ADCRegisterType CHANNEL3 = 0x60U;
      constexpr ADCRegisterType CHANNEL4 = 0x80U;
      constexpr ADCRegisterType CHANNEL5 = 0xA0U;
      constexpr ADCRegisterType CHANNEL6 = 0xC0U;
      constexpr ADCRegisterType CHANNEL7 = 0xE0U;
      constexpr ADCRegisterType CHANNEL8 = 0x100U;
      constexpr ADCRegisterType CHANNEL9 = 0x120U;
      constexpr ADCRegisterType CHANNEL10 = 0x140U;
      constexpr ADCRegisterType CHANNEL11 = 0x160U;
      constexpr ADCRegisterType CHANNEL12 = 0x180U;
      constexpr ADCRegisterType CHANNEL13 = 0x1A0U;
      constexpr ADCRegisterType CHANNEL14 = 0x1C0U;
      constexpr ADCRegisterType CHANNEL15 = 0x1E0U;
      constexpr ADCRegisterType CHANNEL16 = 0x200U;
      constexpr ADCRegisterType CHANNEL17 = 0x220U;
      constexpr ADCRegisterType CHANNEL18 = 0x240U;

   }


    namespace SQ1Bits//1st conversion in regular sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x1U;
      constexpr ADCRegisterType CHANNEL2 = 0x2U;
      constexpr ADCRegisterType CHANNEL3 = 0x3U;
      constexpr ADCRegisterType CHANNEL4 = 0x4U;
      constexpr ADCRegisterType CHANNEL5 = 0x5U;
      constexpr ADCRegisterType CHANNEL6 = 0x6U;
      constexpr ADCRegisterType CHANNEL7 = 0x7U;
      constexpr ADCRegisterType CHANNEL8 = 0x8U;
      constexpr ADCRegisterType CHANNEL9 = 0x9U;
      constexpr ADCRegisterType CHANNEL10 = 0xAU;
      constexpr ADCRegisterType CHANNEL11 = 0xBU;
      constexpr ADCRegisterType CHANNEL12 = 0xCU;
      constexpr ADCRegisterType CHANNEL13 = 0xDU;
      constexpr ADCRegisterType CHANNEL14 = 0xEU;
      constexpr ADCRegisterType CHANNEL15 = 0xFU;
      constexpr ADCRegisterType CHANNEL16 = 0x10U;
      constexpr ADCRegisterType CHANNEL17 = 0x11U;
      constexpr ADCRegisterType CHANNEL18 = 0x12U;

   }


  } //End SQR3


  namespace JSQR //injected sequence register
  { 

    constexpr ADCRegisterType registerOffset = 0x38U; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value


    namespace JLBits//Injected sequence length
    {

      constexpr ADCRegisterType JL0 = 0x0U;
      constexpr ADCRegisterType JL1 = 0x100000U;
      constexpr ADCRegisterType JL2 = 0x200000U;
      constexpr ADCRegisterType JL3 = 0x300000U;
   }


    namespace JSQ4Bits//4th conversion in injected sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x8000U;
      constexpr ADCRegisterType CHANNEL2 = 0x10000U;
      constexpr ADCRegisterType CHANNEL3 = 0x18000U;
      constexpr ADCRegisterType CHANNEL4 = 0x20000U;
      constexpr ADCRegisterType CHANNEL5 = 0x28000U;
      constexpr ADCRegisterType CHANNEL6 = 0x30000U;
      constexpr ADCRegisterType CHANNEL7 = 0x38000U;
      constexpr ADCRegisterType CHANNEL8 = 0x40000U;
      constexpr ADCRegisterType CHANNEL9 = 0x48000U;
      constexpr ADCRegisterType CHANNEL10 = 0x50000U;
      constexpr ADCRegisterType CHANNEL11 = 0x58000U;
      constexpr ADCRegisterType CHANNEL12 = 0x60000U;
      constexpr ADCRegisterType CHANNEL13 = 0x68000U;
      constexpr ADCRegisterType CHANNEL14 = 0x70000U;
      constexpr ADCRegisterType CHANNEL15 = 0x78000U;
      constexpr ADCRegisterType CHANNEL16 = 0x80000U;
      constexpr ADCRegisterType CHANNEL17 = 0x88000U;
      constexpr ADCRegisterType CHANNEL18 = 0x90000U;

   }


    namespace JSQ3Bits//3rd conversion in injected sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x400U;
      constexpr ADCRegisterType CHANNEL2 = 0x800U;
      constexpr ADCRegisterType CHANNEL3 = 0xC00U;
      constexpr ADCRegisterType CHANNEL4 = 0x1000U;
      constexpr ADCRegisterType CHANNEL5 = 0x1400U;
      constexpr ADCRegisterType CHANNEL6 = 0x1800U;
      constexpr ADCRegisterType CHANNEL7 = 0x1C00U;
      constexpr ADCRegisterType CHANNEL8 = 0x2000U;
      constexpr ADCRegisterType CHANNEL9 = 0x2400U;
      constexpr ADCRegisterType CHANNEL10 = 0x2800U;
      constexpr ADCRegisterType CHANNEL11 = 0x2C00U;
      constexpr ADCRegisterType CHANNEL12 = 0x3000U;
      constexpr ADCRegisterType CHANNEL13 = 0x3400U;
      constexpr ADCRegisterType CHANNEL14 = 0x3800U;
      constexpr ADCRegisterType CHANNEL15 = 0x3C00U;
      constexpr ADCRegisterType CHANNEL16 = 0x4000U;
      constexpr ADCRegisterType CHANNEL17 = 0x4400U;
      constexpr ADCRegisterType CHANNEL18 = 0x4800U;

   }


    namespace JSQ2Bits//2nd conversion in injected sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x20U;
      constexpr ADCRegisterType CHANNEL2 = 0x40U;
      constexpr ADCRegisterType CHANNEL3 = 0x60U;
      constexpr ADCRegisterType CHANNEL4 = 0x80U;
      constexpr ADCRegisterType CHANNEL5 = 0xA0U;
      constexpr ADCRegisterType CHANNEL6 = 0xC0U;
      constexpr ADCRegisterType CHANNEL7 = 0xE0U;
      constexpr ADCRegisterType CHANNEL8 = 0x100U;
      constexpr ADCRegisterType CHANNEL9 = 0x120U;
      constexpr ADCRegisterType CHANNEL10 = 0x140U;
      constexpr ADCRegisterType CHANNEL11 = 0x160U;
      constexpr ADCRegisterType CHANNEL12 = 0x180U;
      constexpr ADCRegisterType CHANNEL13 = 0x1A0U;
      constexpr ADCRegisterType CHANNEL14 = 0x1C0U;
      constexpr ADCRegisterType CHANNEL15 = 0x1E0U;
      constexpr ADCRegisterType CHANNEL16 = 0x200U;
      constexpr ADCRegisterType CHANNEL17 = 0x220U;
      constexpr ADCRegisterType CHANNEL18 = 0x240U;

   }


    namespace JSQ1Bits//1st conversion in injected sequence
    {

      constexpr ADCRegisterType CHANNEL0 = 0x0U;
      constexpr ADCRegisterType CHANNEL1 = 0x1U;
      constexpr ADCRegisterType CHANNEL2 = 0x2U;
      constexpr ADCRegisterType CHANNEL3 = 0x3U;
      constexpr ADCRegisterType CHANNEL4 = 0x4U;
      constexpr ADCRegisterType CHANNEL5 = 0x5U;
      constexpr ADCRegisterType CHANNEL6 = 0x6U;
      constexpr ADCRegisterType CHANNEL7 = 0x7U;
      constexpr ADCRegisterType CHANNEL8 = 0x8U;
      constexpr ADCRegisterType CHANNEL9 = 0x9U;
      constexpr ADCRegisterType CHANNEL10 = 0xAU;
      constexpr ADCRegisterType CHANNEL11 = 0xBU;
      constexpr ADCRegisterType CHANNEL12 = 0xCU;
      constexpr ADCRegisterType CHANNEL13 = 0xDU;
      constexpr ADCRegisterType CHANNEL14 = 0xEU;
      constexpr ADCRegisterType CHANNEL15 = 0xFU;
      constexpr ADCRegisterType CHANNEL16 = 0x10U;
      constexpr ADCRegisterType CHANNEL17 = 0x11U;
      constexpr ADCRegisterType CHANNEL18 = 0x12U;

   }


  } //End JSQR


  namespace JDR1 //injected data register x
  { 

    constexpr ADCRegisterType registerOffset = 0x3CU; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End JDR1


  namespace JDR2 //injected data register x
  { 

    constexpr ADCRegisterType registerOffset = 0x40U; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End JDR2


  namespace JDR3 //injected data register x
  { 

    constexpr ADCRegisterType registerOffset = 0x44U; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End JDR3


  namespace JDR4 //injected data register x
  { 

    constexpr ADCRegisterType registerOffset = 0x48U; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End JDR4


  namespace DR //regular data register
  { 

    constexpr ADCRegisterType registerOffset = 0x4CU; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End DR


  namespace CSR //ADC Common status register
  { 

    constexpr ADCRegisterType registerOffset = 0x0U; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr ADCRegisterType OVR3 = Util::Bits::BIT21; //Overrun flag of ADC3
    constexpr ADCRegisterType STRT3 = Util::Bits::BIT20; //Regular channel Start flag of ADC 3
    constexpr ADCRegisterType JSTRT3 = Util::Bits::BIT19; //Injected channel Start flag of ADC 3
    constexpr ADCRegisterType JEOC3 = Util::Bits::BIT18; //Injected channel end of conversion of ADC 3
    constexpr ADCRegisterType EOC3 = Util::Bits::BIT17; //End of conversion of ADC 3
    constexpr ADCRegisterType AWD3 = Util::Bits::BIT16; //Analog watchdog flag of ADC 3
    constexpr ADCRegisterType OVR2 = Util::Bits::BIT13; //Overrun flag of ADC 2
    constexpr ADCRegisterType STRT2 = Util::Bits::BIT12; //Regular channel Start flag of ADC 2
    constexpr ADCRegisterType JSTRT2 = Util::Bits::BIT11; //Injected channel Start flag of ADC 2
    constexpr ADCRegisterType JEOC2 = Util::Bits::BIT10; //Injected channel end of conversion of ADC 2
    constexpr ADCRegisterType EOC2 = Util::Bits::BIT9; //End of conversion of ADC 2
    constexpr ADCRegisterType AWD2 = Util::Bits::BIT8; //Analog watchdog flag of ADC 2
    constexpr ADCRegisterType OVR1 = Util::Bits::BIT5; //Overrun flag of ADC 1
    constexpr ADCRegisterType STRT1 = Util::Bits::BIT4; //Regular channel Start flag of ADC 1
    constexpr ADCRegisterType JSTRT1 = Util::Bits::BIT3; //Injected channel Start flag of ADC 1
    constexpr ADCRegisterType JEOC1 = Util::Bits::BIT2; //Injected channel end of conversion of ADC 1
    constexpr ADCRegisterType EOC1 = Util::Bits::BIT1; //End of conversion of ADC 1
    constexpr ADCRegisterType AWD1 = Util::Bits::BIT0; //Analog watchdog flag of ADC 1

  } //End CSR


  namespace CCR //ADC common control register
  { 

    constexpr ADCRegisterType registerOffset = 0x4U; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr ADCRegisterType TSVREFE = Util::Bits::BIT23; //Temperature sensor and VREFINT enable
    constexpr ADCRegisterType VBATE = Util::Bits::BIT22; //VBAT enable

    namespace ADCPREBits//ADC prescaler
    {

      constexpr ADCRegisterType ADCPRE0 = 0x0U;
      constexpr ADCRegisterType ADCPRE1 = 0x10000U;
      constexpr ADCRegisterType ADCPRE2 = 0x20000U;
      constexpr ADCRegisterType ADCPRE3 = 0x30000U;
   }


    namespace DMABits//Direct memory access mode for multi ADC mode
    {

      constexpr ADCRegisterType DMA0_ADCS = 0x0U;
      constexpr ADCRegisterType DMA1_ADCS = 0x4000U;
      constexpr ADCRegisterType DMA2_ADCS = 0x8000U;
      constexpr ADCRegisterType DMA3_ADCS = 0xC000U;
   }

    constexpr ADCRegisterType DDS = Util::Bits::BIT13; //DMA disable selection for multi-ADC mode

    namespace DELAYBits//Delay between 2 sampling phases
    {

      constexpr ADCRegisterType DELAY0 = 0x0U;
      constexpr ADCRegisterType DELAY1 = 0x100U;
      constexpr ADCRegisterType DELAY2 = 0x200U;
      constexpr ADCRegisterType DELAY3 = 0x300U;
      constexpr ADCRegisterType DELAY4 = 0x400U;
      constexpr ADCRegisterType DELAY5 = 0x500U;
      constexpr ADCRegisterType DELAY6 = 0x600U;
      constexpr ADCRegisterType DELAY7 = 0x700U;
      constexpr ADCRegisterType DELAY8 = 0x800U;
      constexpr ADCRegisterType DELAY9 = 0x900U;
      constexpr ADCRegisterType DELAY10 = 0xA00U;
      constexpr ADCRegisterType DELAY11 = 0xB00U;
      constexpr ADCRegisterType DELAY12 = 0xC00U;
      constexpr ADCRegisterType DELAY13 = 0xD00U;
      constexpr ADCRegisterType DELAY14 = 0xE00U;
      constexpr ADCRegisterType DELAY15 = 0xF00U;
   }


    namespace MULTBits//Multi ADC mode selection
    {

      constexpr ADCRegisterType MULT0 = 0x0U;
      constexpr ADCRegisterType MULT1 = 0x1U;
      constexpr ADCRegisterType MULT2 = 0x2U;
      constexpr ADCRegisterType MULT3 = 0x3U;
      constexpr ADCRegisterType MULT4 = 0x4U;
      constexpr ADCRegisterType MULT5 = 0x5U;
      constexpr ADCRegisterType MULT6 = 0x6U;
      constexpr ADCRegisterType MULT7 = 0x7U;
      constexpr ADCRegisterType MULT8 = 0x8U;
      constexpr ADCRegisterType MULT9 = 0x9U;
      constexpr ADCRegisterType MULT10 = 0xAU;
      constexpr ADCRegisterType MULT11 = 0xBU;
      constexpr ADCRegisterType MULT12 = 0xCU;
      constexpr ADCRegisterType MULT13 = 0xDU;
      constexpr ADCRegisterType MULT14 = 0xEU;
      constexpr ADCRegisterType MULT15 = 0xFU;
      constexpr ADCRegisterType MULT16 = 0x10U;
      constexpr ADCRegisterType MULT17 = 0x11U;
      constexpr ADCRegisterType MULT18 = 0x12U;
      constexpr ADCRegisterType MULT19 = 0x13U;
      constexpr ADCRegisterType MULT20 = 0x14U;
      constexpr ADCRegisterType MULT21 = 0x15U;
      constexpr ADCRegisterType MULT22 = 0x16U;
      constexpr ADCRegisterType MULT23 = 0x17U;
      constexpr ADCRegisterType MULT24 = 0x18U;
      constexpr ADCRegisterType MULT25 = 0x19U;
      constexpr ADCRegisterType MULT26 = 0x1AU;
      constexpr ADCRegisterType MULT27 = 0x1BU;
      constexpr ADCRegisterType MULT28 = 0x1CU;
      constexpr ADCRegisterType MULT29 = 0x1DU;
      constexpr ADCRegisterType MULT30 = 0x1EU;
      constexpr ADCRegisterType MULT31 = 0x1FU;
   }


  } //End CCR


  namespace CDR //ADC common regular data register for dual and triple modes
  { 

    constexpr ADCRegisterType registerOffset = 0x8U; //Register Offset Value
    constexpr ADCRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End CDR

}

#endif /* ADCREGISTERS_H_ */
