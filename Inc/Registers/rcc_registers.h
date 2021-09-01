#ifndef RCC_REGISTERS_H_
#define RCC_REGISTERS_H_

#include<stdint.h>
#include "../Utility/util.h"

namespace RCC_MDG
{

  typedef uint32_t RCCRegisterType2;

  namespace BaseRegisters
  {

    constexpr RCCRegisterType2 RCC_MDG = 0x40023800U; //Reset and clock control

  } //End BaseRegisters

  namespace CR //clock control register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x0U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 PLLI2SRDY = Util::Bits::BIT27; //PLLI2S clock ready flag
    constexpr RCCRegisterType2 PLLI2SON = Util::Bits::BIT26; //PLLI2S enable
    constexpr RCCRegisterType2 PLLRDY = Util::Bits::BIT25; //Main PLL (PLL) clock ready flag
    constexpr RCCRegisterType2 PLLON = Util::Bits::BIT24; //Main PLL (PLL) enable
    constexpr RCCRegisterType2 CSSON = Util::Bits::BIT19; //Clock security system enable
    constexpr RCCRegisterType2 HSEBYP = Util::Bits::BIT18; //HSE clock bypass
    constexpr RCCRegisterType2 HSERDY = Util::Bits::BIT17; //HSE clock ready flag
    constexpr RCCRegisterType2 HSEON = Util::Bits::BIT16; //HSE clock enable

    namespace HSITRIMBits//Internal high-speed clock trimming
    {

      constexpr RCCRegisterType2 HSITRIM0 = 0x0U;
      constexpr RCCRegisterType2 HSITRIM1 = 0x8U;
      constexpr RCCRegisterType2 HSITRIM2 = 0x10U;
      constexpr RCCRegisterType2 HSITRIM3 = 0x18U;
      constexpr RCCRegisterType2 HSITRIM4 = 0x20U;
      constexpr RCCRegisterType2 HSITRIM5 = 0x28U;
      constexpr RCCRegisterType2 HSITRIM6 = 0x30U;
      constexpr RCCRegisterType2 HSITRIM7 = 0x38U;
      constexpr RCCRegisterType2 HSITRIM8 = 0x40U;
      constexpr RCCRegisterType2 HSITRIM9 = 0x48U;
      constexpr RCCRegisterType2 HSITRIM10 = 0x50U;
      constexpr RCCRegisterType2 HSITRIM11 = 0x58U;
      constexpr RCCRegisterType2 HSITRIM12 = 0x60U;
      constexpr RCCRegisterType2 HSITRIM13 = 0x68U;
      constexpr RCCRegisterType2 HSITRIM14 = 0x70U;
      constexpr RCCRegisterType2 HSITRIM15 = 0x78U;
      constexpr RCCRegisterType2 HSITRIM16 = 0x80U;
      constexpr RCCRegisterType2 HSITRIM17 = 0x88U;
      constexpr RCCRegisterType2 HSITRIM18 = 0x90U;
      constexpr RCCRegisterType2 HSITRIM19 = 0x98U;
      constexpr RCCRegisterType2 HSITRIM20 = 0xA0U;
      constexpr RCCRegisterType2 HSITRIM21 = 0xA8U;
      constexpr RCCRegisterType2 HSITRIM22 = 0xB0U;
      constexpr RCCRegisterType2 HSITRIM23 = 0xB8U;
      constexpr RCCRegisterType2 HSITRIM24 = 0xC0U;
      constexpr RCCRegisterType2 HSITRIM25 = 0xC8U;
      constexpr RCCRegisterType2 HSITRIM26 = 0xD0U;
      constexpr RCCRegisterType2 HSITRIM27 = 0xD8U;
      constexpr RCCRegisterType2 HSITRIM28 = 0xE0U;
      constexpr RCCRegisterType2 HSITRIM29 = 0xE8U;
      constexpr RCCRegisterType2 HSITRIM30 = 0xF0U;
      constexpr RCCRegisterType2 HSITRIM31 = 0xF8U;

   }

    constexpr RCCRegisterType2 HSIRDY = Util::Bits::BIT1; //Internal high-speed clock ready flag
    constexpr RCCRegisterType2 HSION = Util::Bits::BIT0; //Internal high-speed clock enable

  } //End CR


 namespace PLLCFGR //PLL configuration register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x4U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value


    namespace PLLQxBits//Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks
    {

      constexpr RCCRegisterType2 DivBy2 = 0x2000000U;
      constexpr RCCRegisterType2 DivBy3 = 0x3000000U;
      constexpr RCCRegisterType2 DivBy4 = 0x4000000U;
      constexpr RCCRegisterType2 DivBy5 = 0x5000000U;
      constexpr RCCRegisterType2 DivBy6 = 0x6000000U;
      constexpr RCCRegisterType2 DivBy7 = 0x7000000U;
      constexpr RCCRegisterType2 DivBy8 = 0x8000000U;
      constexpr RCCRegisterType2 DivBy9 = 0x9000000U;
      constexpr RCCRegisterType2 DivBy10 = 0xA000000U;
      constexpr RCCRegisterType2 DivBy11 = 0xB000000U;
      constexpr RCCRegisterType2 DivBy12 = 0xC000000U;
      constexpr RCCRegisterType2 DivBy13 = 0xD000000U;
      constexpr RCCRegisterType2 DivBy14 = 0xE000000U;
      constexpr RCCRegisterType2 DivBy15 = 0xF000000U;

   }

    constexpr RCCRegisterType2 PLLSRC = Util::Bits::BIT22; //Main PLL(PLL) and audio PLL (PLLI2S) entry clock source

    namespace PLLPxBits//Main PLL (PLL) division factor for main system clock
    {

      constexpr RCCRegisterType2 DivBy2 = 0x0U;
      constexpr RCCRegisterType2 DivBy4 = 0x10000U;
      constexpr RCCRegisterType2 DivBy6 = 0x20000U;
      constexpr RCCRegisterType2 DivBy8 = 0x30000U;

   }

    constexpr RCCRegisterType2 PLLN8 = Util::Bits::BIT14; //Main PLL (PLL) multiplication factor for VCO
    constexpr RCCRegisterType2 PLLN7 = Util::Bits::BIT13; //Main PLL (PLL) multiplication factor for VCO
    constexpr RCCRegisterType2 PLLN6 = Util::Bits::BIT12; //Main PLL (PLL) multiplication factor for VCO
    constexpr RCCRegisterType2 PLLN5 = Util::Bits::BIT11; //Main PLL (PLL) multiplication factor for VCO
    constexpr RCCRegisterType2 PLLN4 = Util::Bits::BIT10; //Main PLL (PLL) multiplication factor for VCO
    constexpr RCCRegisterType2 PLLN3 = Util::Bits::BIT9; //Main PLL (PLL) multiplication factor for VCO
    constexpr RCCRegisterType2 PLLN2 = Util::Bits::BIT8; //Main PLL (PLL) multiplication factor for VCO
    constexpr RCCRegisterType2 PLLN1 = Util::Bits::BIT7; //Main PLL (PLL) multiplication factor for VCO
    constexpr RCCRegisterType2 PLLN0 = Util::Bits::BIT6; //Main PLL (PLL) multiplication factor for VCO

    namespace PLLM0Bits//Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
    {

      constexpr RCCRegisterType2 DivBy2 = 0x2U;
      constexpr RCCRegisterType2 DivBy3 = 0x3U;
      constexpr RCCRegisterType2 DivBy4 = 0x4U;
      constexpr RCCRegisterType2 DivBy5 = 0x5U;
      constexpr RCCRegisterType2 DivBy6 = 0x6U;
      constexpr RCCRegisterType2 DivBy7 = 0x7U;
      constexpr RCCRegisterType2 DivBy8 = 0x8U;
      constexpr RCCRegisterType2 DivBy9 = 0x9U;
      constexpr RCCRegisterType2 DivBy10 = 0xAU;
      constexpr RCCRegisterType2 DivBy11 = 0xBU;
      constexpr RCCRegisterType2 DivBy12 = 0xCU;
      constexpr RCCRegisterType2 DivBy13 = 0xDU;
      constexpr RCCRegisterType2 DivBy14 = 0xEU;
      constexpr RCCRegisterType2 DivBy15 = 0xFU;
      constexpr RCCRegisterType2 DivBy16 = 0x10U;
      constexpr RCCRegisterType2 DivBy17 = 0x11U;
      constexpr RCCRegisterType2 DivBy18 = 0x12U;
      constexpr RCCRegisterType2 DivBy19 = 0x13U;
      constexpr RCCRegisterType2 DivBy20 = 0x14U;
      constexpr RCCRegisterType2 DivBy21 = 0x15U;
      constexpr RCCRegisterType2 DivBy22 = 0x16U;
      constexpr RCCRegisterType2 DivBy23 = 0x17U;
      constexpr RCCRegisterType2 DivBy24 = 0x18U;
      constexpr RCCRegisterType2 DivBy25 = 0x19U;
      constexpr RCCRegisterType2 DivBy26 = 0x1AU;
      constexpr RCCRegisterType2 DivBy27 = 0x1BU;
      constexpr RCCRegisterType2 DivBy28 = 0x1CU;
      constexpr RCCRegisterType2 DivBy29 = 0x1DU;
      constexpr RCCRegisterType2 DivBy30 = 0x1EU;
      constexpr RCCRegisterType2 DivBy31 = 0x1FU;
      constexpr RCCRegisterType2 DivBy32 = 0x20U;
      constexpr RCCRegisterType2 DivBy33 = 0x21U;
      constexpr RCCRegisterType2 DivBy34 = 0x22U;
      constexpr RCCRegisterType2 DivBy35 = 0x23U;
      constexpr RCCRegisterType2 DivBy36 = 0x24U;
      constexpr RCCRegisterType2 DivBy37 = 0x25U;
      constexpr RCCRegisterType2 DivBy38 = 0x26U;
      constexpr RCCRegisterType2 DivBy39 = 0x27U;
      constexpr RCCRegisterType2 DivBy40 = 0x28U;
      constexpr RCCRegisterType2 DivBy41 = 0x29U;
      constexpr RCCRegisterType2 DivBy42 = 0x2AU;
      constexpr RCCRegisterType2 DivBy43 = 0x2BU;
      constexpr RCCRegisterType2 DivBy44 = 0x2CU;
      constexpr RCCRegisterType2 DivBy45 = 0x2DU;
      constexpr RCCRegisterType2 DivBy46 = 0x2EU;
      constexpr RCCRegisterType2 DivBy47 = 0x2FU;
      constexpr RCCRegisterType2 DivBy48 = 0x30U;
      constexpr RCCRegisterType2 DivBy49 = 0x31U;
      constexpr RCCRegisterType2 DivBy50 = 0x32U;
      constexpr RCCRegisterType2 DivBy51 = 0x33U;
      constexpr RCCRegisterType2 DivBy52 = 0x34U;
      constexpr RCCRegisterType2 DivBy53 = 0x35U;
      constexpr RCCRegisterType2 DivBy54 = 0x36U;
      constexpr RCCRegisterType2 DivBy55 = 0x37U;
      constexpr RCCRegisterType2 DivBy56 = 0x38U;
      constexpr RCCRegisterType2 DivBy57 = 0x39U;
      constexpr RCCRegisterType2 DivBy58 = 0x3AU;
      constexpr RCCRegisterType2 DivBy59 = 0x3BU;
      constexpr RCCRegisterType2 DivBy60 = 0x3CU;
      constexpr RCCRegisterType2 DivBy61 = 0x3DU;
      constexpr RCCRegisterType2 DivBy62 = 0x3EU;
      constexpr RCCRegisterType2 DivBy63 = 0x3FU;

   }


  } //End PLLCFGR


  namespace CFGR //clock configuration register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x8U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value


    namespace MCO2Bits//Microcontroller clock output 2
    {

      constexpr RCCRegisterType2 SystemClock = 0x0U;
      constexpr RCCRegisterType2 PLLI2SClock = 0x40000000U;
      constexpr RCCRegisterType2 HSEClock = 0x80000000U;
      constexpr RCCRegisterType2 PLLClock = 0xC0000000U;

   }


    namespace MCO2PREBits//MCO2 prescaler
    {

      constexpr RCCRegisterType2 DivBy1 = 0x0U;
      constexpr RCCRegisterType2 DivBy2 = 0x20000000U;
      constexpr RCCRegisterType2 DivBy3 = 0x28000000U;
      constexpr RCCRegisterType2 DivBy4 = 0x30000000U;
      constexpr RCCRegisterType2 DivBy5 = 0x38000000U;

   }


    namespace MCO1PREBits//MCO1 prescaler
    {

      constexpr RCCRegisterType2 DivBy1 = 0x0U;
      constexpr RCCRegisterType2 DivBy2 = 0x4000000U;
      constexpr RCCRegisterType2 DivBy3 = 0x5000000U;
      constexpr RCCRegisterType2 DivBy4 = 0x6000000U;
      constexpr RCCRegisterType2 DivBy5 = 0x7000000U;

   }

    constexpr RCCRegisterType2 I2SSRC = Util::Bits::BIT23; //I2S clock selection

    namespace MCO1Bits//Microcontroller clock output 1
    {

      constexpr RCCRegisterType2 HSIClock = 0x0U;
      constexpr RCCRegisterType2 LSECLock = 0x200000U;
      constexpr RCCRegisterType2 HSECLock = 0x400000U;
      constexpr RCCRegisterType2 PLLClock = 0x600000U;

   }


    namespace RTCPREBits//HSE division factor for RTC clock
    {

      constexpr RCCRegisterType2 NoClock = 0x0U;
      constexpr RCCRegisterType2 DivBy2 = 0x20000U;
      constexpr RCCRegisterType2 DivBy3 = 0x30000U;
      constexpr RCCRegisterType2 DivBy4 = 0x40000U;
      constexpr RCCRegisterType2 DivBy5 = 0x50000U;
      constexpr RCCRegisterType2 DivBy6 = 0x60000U;
      constexpr RCCRegisterType2 DivBy7 = 0x70000U;
      constexpr RCCRegisterType2 DivBy8 = 0x80000U;
      constexpr RCCRegisterType2 DivBy9 = 0x90000U;
      constexpr RCCRegisterType2 DivBy10 = 0xA0000U;
      constexpr RCCRegisterType2 DivBy11 = 0xB0000U;
      constexpr RCCRegisterType2 DivBy12 = 0xC0000U;
      constexpr RCCRegisterType2 DivBy13 = 0xD0000U;
      constexpr RCCRegisterType2 DivBy14 = 0xE0000U;
      constexpr RCCRegisterType2 DivBy15 = 0xF0000U;
      constexpr RCCRegisterType2 DivBy16 = 0x100000U;
      constexpr RCCRegisterType2 DivBy17 = 0x110000U;
      constexpr RCCRegisterType2 DivBy18 = 0x120000U;
      constexpr RCCRegisterType2 DivBy19 = 0x130000U;
      constexpr RCCRegisterType2 DivBy20 = 0x140000U;
      constexpr RCCRegisterType2 DivBy21 = 0x150000U;
      constexpr RCCRegisterType2 DivBy22 = 0x160000U;
      constexpr RCCRegisterType2 DivBy23 = 0x170000U;
      constexpr RCCRegisterType2 DivBy24 = 0x180000U;
      constexpr RCCRegisterType2 DivBy25 = 0x190000U;
      constexpr RCCRegisterType2 DivBy26 = 0x1A0000U;
      constexpr RCCRegisterType2 DivBy27 = 0x1B0000U;
      constexpr RCCRegisterType2 DivBy28 = 0x1C0000U;
      constexpr RCCRegisterType2 DivBy29 = 0x1D0000U;
      constexpr RCCRegisterType2 DivBy30 = 0x1E0000U;
      constexpr RCCRegisterType2 DivBy31 = 0x1F0000U;

   }


    namespace PPRE2Bits//APB high-speed prescaler (APB2)
    {

      constexpr RCCRegisterType2 DivBy1 = 0x0U;
      constexpr RCCRegisterType2 DivBy2 = 0x8000U;
      constexpr RCCRegisterType2 DivBy4 = 0xA000U;
      constexpr RCCRegisterType2 DivBy8 = 0xC000U;
      constexpr RCCRegisterType2 DivBy16 = 0xE000U;

   }


    namespace PPRE1Bits//APB Low speed prescaler (APB1)
    {

      constexpr RCCRegisterType2 DivBy1 = 0x0U;
      constexpr RCCRegisterType2 DivBy2 = 0x1000U;
      constexpr RCCRegisterType2 DivBy4 = 0x1400U;
      constexpr RCCRegisterType2 DivBy8 = 0x1800U;
      constexpr RCCRegisterType2 DivBy16 = 0x1C00U;

   }


    namespace HPREBits//AHB prescaler
    {

      constexpr RCCRegisterType2 DivBy1 = 0x0U;
      constexpr RCCRegisterType2 DivBy2 = 0x80U;
      constexpr RCCRegisterType2 DivBy4 = 0x90U;
      constexpr RCCRegisterType2 DivBy8 = 0xA0U;
      constexpr RCCRegisterType2 DivBy16 = 0xB0U;
      constexpr RCCRegisterType2 DivBy64 = 0xC0U;
      constexpr RCCRegisterType2 DivBy128 = 0xD0U;
      constexpr RCCRegisterType2 DivBy256 = 0xE0U;
      constexpr RCCRegisterType2 DivBy512 = 0xF0U;

   }

   namespace SWBits //Clock source
   {

      constexpr RCCRegisterType2 HSIOscillator = 0x0U;
      constexpr RCCRegisterType2 HSEOscillator = 0x1U;
      constexpr RCCRegisterType2 PLLSource = 0x2U;

   }


  } //End CFGR


  namespace CIR //clock interrupt register
  { 

    constexpr RCCRegisterType2 registerOffset = 0xCU; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 CSSC = Util::Bits::BIT23; //Clock security system interrupt clear
    constexpr RCCRegisterType2 PLLI2SRDYC = Util::Bits::BIT21; //PLLI2S ready interrupt clear
    constexpr RCCRegisterType2 PLLRDYC = Util::Bits::BIT20; //Main PLL(PLL) ready interrupt clear
    constexpr RCCRegisterType2 HSERDYC = Util::Bits::BIT19; //HSE ready interrupt clear
    constexpr RCCRegisterType2 HSIRDYC = Util::Bits::BIT18; //HSI ready interrupt clear
    constexpr RCCRegisterType2 LSERDYC = Util::Bits::BIT17; //LSE ready interrupt clear
    constexpr RCCRegisterType2 LSIRDYC = Util::Bits::BIT16; //LSI ready interrupt clear
    constexpr RCCRegisterType2 PLLI2SRDYIE = Util::Bits::BIT13; //PLLI2S ready interrupt enable
    constexpr RCCRegisterType2 PLLRDYIE = Util::Bits::BIT12; //Main PLL (PLL) ready interrupt enable
    constexpr RCCRegisterType2 HSERDYIE = Util::Bits::BIT11; //HSE ready interrupt enable
    constexpr RCCRegisterType2 HSIRDYIE = Util::Bits::BIT10; //HSI ready interrupt enable
    constexpr RCCRegisterType2 LSERDYIE = Util::Bits::BIT9; //LSE ready interrupt enable
    constexpr RCCRegisterType2 LSIRDYIE = Util::Bits::BIT8; //LSI ready interrupt enable
    constexpr RCCRegisterType2 CSSF = Util::Bits::BIT7; //Clock security system interrupt flag
    constexpr RCCRegisterType2 PLLI2SRDYF = Util::Bits::BIT5; //PLLI2S ready interrupt flag
    constexpr RCCRegisterType2 PLLRDYF = Util::Bits::BIT4; //Main PLL (PLL) ready interrupt flag
    constexpr RCCRegisterType2 HSERDYF = Util::Bits::BIT3; //HSE ready interrupt flag
    constexpr RCCRegisterType2 HSIRDYF = Util::Bits::BIT2; //HSI ready interrupt flag
    constexpr RCCRegisterType2 LSERDYF = Util::Bits::BIT1; //LSE ready interrupt flag
    constexpr RCCRegisterType2 LSIRDYF = Util::Bits::BIT0; //LSI ready interrupt flag

  } //End CIR


  namespace AHB1RSTR //AHB1 peripheral reset register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x10U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 OTGHSRST = Util::Bits::BIT29; //USB OTG HS module reset
    constexpr RCCRegisterType2 ETHMACRST = Util::Bits::BIT25; //Ethernet MAC reset
    constexpr RCCRegisterType2 DMA2RST = Util::Bits::BIT22; //DMA2 reset
    constexpr RCCRegisterType2 DMA1RST = Util::Bits::BIT21; //DMA2 reset
    constexpr RCCRegisterType2 CRCRST = Util::Bits::BIT12; //CRC reset
    constexpr RCCRegisterType2 GPIOIRST = Util::Bits::BIT8; //IO port I reset
    constexpr RCCRegisterType2 GPIOHRST = Util::Bits::BIT7; //IO port H reset
    constexpr RCCRegisterType2 GPIOGRST = Util::Bits::BIT6; //IO port G reset
    constexpr RCCRegisterType2 GPIOFRST = Util::Bits::BIT5; //IO port F reset
    constexpr RCCRegisterType2 GPIOERST = Util::Bits::BIT4; //IO port E reset
    constexpr RCCRegisterType2 GPIODRST = Util::Bits::BIT3; //IO port D reset
    constexpr RCCRegisterType2 GPIOCRST = Util::Bits::BIT2; //IO port C reset
    constexpr RCCRegisterType2 GPIOBRST = Util::Bits::BIT1; //IO port B reset
    constexpr RCCRegisterType2 GPIOARST = Util::Bits::BIT0; //IO port A reset

  } //End AHB1RSTR


  namespace AHB2RSTR //AHB2 peripheral reset register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x14U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 OTGFSRST = Util::Bits::BIT7; //USB OTG FS module reset
    constexpr RCCRegisterType2 RNGRST = Util::Bits::BIT6; //Random number generator module reset
    constexpr RCCRegisterType2 DCMIRST = Util::Bits::BIT0; //Camera interface reset

  } //End AHB2RSTR


  namespace AHB3RSTR //AHB3 peripheral reset register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x18U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 FSMCRST = Util::Bits::BIT0; //Flexible static memory controller module reset

  } //End AHB3RSTR


  namespace APB1RSTR //APB1 peripheral reset register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x20U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 DACRST = Util::Bits::BIT29; //DAC reset
    constexpr RCCRegisterType2 PWRRST = Util::Bits::BIT28; //Power interface reset
    constexpr RCCRegisterType2 CAN2RST = Util::Bits::BIT26; //CAN2 reset
    constexpr RCCRegisterType2 CAN1RST = Util::Bits::BIT25; //CAN1 reset
    constexpr RCCRegisterType2 I2C3RST = Util::Bits::BIT23; //I2C3 reset
    constexpr RCCRegisterType2 I2C2RST = Util::Bits::BIT22; //I2C 2 reset
    constexpr RCCRegisterType2 I2C1RST = Util::Bits::BIT21; //I2C 1 reset
    constexpr RCCRegisterType2 UART5RST = Util::Bits::BIT20; //USART 5 reset
    constexpr RCCRegisterType2 UART4RST = Util::Bits::BIT19; //USART 4 reset
    constexpr RCCRegisterType2 UART3RST = Util::Bits::BIT18; //USART 3 reset
    constexpr RCCRegisterType2 UART2RST = Util::Bits::BIT17; //USART 2 reset
    constexpr RCCRegisterType2 SPI3RST = Util::Bits::BIT15; //SPI 3 reset
    constexpr RCCRegisterType2 SPI2RST = Util::Bits::BIT14; //SPI 2 reset
    constexpr RCCRegisterType2 WWDGRST = Util::Bits::BIT11; //Window watchdog reset
    constexpr RCCRegisterType2 TIM14RST = Util::Bits::BIT8; //TIM14 reset
    constexpr RCCRegisterType2 TIM13RST = Util::Bits::BIT7; //TIM13 reset
    constexpr RCCRegisterType2 TIM12RST = Util::Bits::BIT6; //TIM12 reset
    constexpr RCCRegisterType2 TIM7RST = Util::Bits::BIT5; //TIM7 reset
    constexpr RCCRegisterType2 TIM6RST = Util::Bits::BIT4; //TIM6 reset
    constexpr RCCRegisterType2 TIM5RST = Util::Bits::BIT3; //TIM5 reset
    constexpr RCCRegisterType2 TIM4RST = Util::Bits::BIT2; //TIM4 reset
    constexpr RCCRegisterType2 TIM3RST = Util::Bits::BIT1; //TIM3 reset
    constexpr RCCRegisterType2 TIM2RST = Util::Bits::BIT0; //TIM2 reset

  } //End APB1RSTR


  namespace APB2RSTR //APB2 peripheral reset register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x24U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 TIM11RST = Util::Bits::BIT18; //TIM11 reset
    constexpr RCCRegisterType2 TIM10RST = Util::Bits::BIT17; //TIM10 reset
    constexpr RCCRegisterType2 TIM9RST = Util::Bits::BIT16; //TIM9 reset
    constexpr RCCRegisterType2 SYSCFGRST = Util::Bits::BIT14; //System configuration controller reset
    constexpr RCCRegisterType2 SPI1RST = Util::Bits::BIT12; //SPI 1 reset
    constexpr RCCRegisterType2 SDIORST = Util::Bits::BIT11; //SDIO reset
    constexpr RCCRegisterType2 ADCRST = Util::Bits::BIT8; //ADC interface reset (common to all ADCs)
    constexpr RCCRegisterType2 USART6RST = Util::Bits::BIT5; //USART6 reset
    constexpr RCCRegisterType2 USART1RST = Util::Bits::BIT4; //USART1 reset
    constexpr RCCRegisterType2 TIM8RST = Util::Bits::BIT1; //TIM8 reset
    constexpr RCCRegisterType2 TIM1RST = Util::Bits::BIT0; //TIM1 reset

  } //End APB2RSTR


  namespace AHB1ENR //AHB1 peripheral clock register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x30U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 OTGHSULPIEN = Util::Bits::BIT30; //USB OTG HSULPI clock enable
    constexpr RCCRegisterType2 OTGHSEN = Util::Bits::BIT29; //USB OTG HS clock enable
    constexpr RCCRegisterType2 ETHMACPTPEN = Util::Bits::BIT28; //Ethernet PTP clock enable
    constexpr RCCRegisterType2 ETHMACRXEN = Util::Bits::BIT27; //Ethernet Reception clock enable
    constexpr RCCRegisterType2 ETHMACTXEN = Util::Bits::BIT26; //Ethernet Transmission clock enable
    constexpr RCCRegisterType2 ETHMACEN = Util::Bits::BIT25; //Ethernet MAC clock enable
    constexpr RCCRegisterType2 DMA2EN = Util::Bits::BIT22; //DMA2 clock enable
    constexpr RCCRegisterType2 DMA1EN = Util::Bits::BIT21; //DMA1 clock enable
    constexpr RCCRegisterType2 BKPSRAMEN = Util::Bits::BIT18; //Backup SRAM interface clock enable
    constexpr RCCRegisterType2 CRCEN = Util::Bits::BIT12; //CRC clock enable
    constexpr RCCRegisterType2 GPIOIEN = Util::Bits::BIT8; //IO port I clock enable
    constexpr RCCRegisterType2 GPIOHEN = Util::Bits::BIT7; //IO port H clock enable
    constexpr RCCRegisterType2 GPIOGEN = Util::Bits::BIT6; //IO port G clock enable
    constexpr RCCRegisterType2 GPIOFEN = Util::Bits::BIT5; //IO port F clock enable
    constexpr RCCRegisterType2 GPIOEEN = Util::Bits::BIT4; //IO port E clock enable
    constexpr RCCRegisterType2 GPIODEN = Util::Bits::BIT3; //IO port D clock enable
    constexpr RCCRegisterType2 GPIOCEN = Util::Bits::BIT2; //IO port C clock enable
    constexpr RCCRegisterType2 GPIOBEN = Util::Bits::BIT1; //IO port B clock enable
    constexpr RCCRegisterType2 GPIOAEN = Util::Bits::BIT0; //IO port A clock enable

  } //End AHB1ENR


  namespace AHB2ENR //AHB2 peripheral clock enable register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x34U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 OTGFSEN = Util::Bits::BIT7; //USB OTG FS clock enable
    constexpr RCCRegisterType2 RNGEN = Util::Bits::BIT6; //Random number generator clock enable
    constexpr RCCRegisterType2 DCMIEN = Util::Bits::BIT0; //Camera interface enable

  } //End AHB2ENR


  namespace AHB3ENR //AHB3 peripheral clock enable register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x38U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 FSMCEN = Util::Bits::BIT0; //Flexible static memory controller module clock enable

  } //End AHB3ENR


  namespace APB1ENR //APB1 peripheral clock enable register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x40U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 DACEN = Util::Bits::BIT29; //DAC interface clock enable
    constexpr RCCRegisterType2 PWREN = Util::Bits::BIT28; //Power interface clock enable
    constexpr RCCRegisterType2 CAN2EN = Util::Bits::BIT26; //CAN 2 clock enable
    constexpr RCCRegisterType2 CAN1EN = Util::Bits::BIT25; //CAN 1 clock enable
    constexpr RCCRegisterType2 I2C3EN = Util::Bits::BIT23; //I2C3 clock enable
    constexpr RCCRegisterType2 I2C2EN = Util::Bits::BIT22; //I2C2 clock enable
    constexpr RCCRegisterType2 I2C1EN = Util::Bits::BIT21; //I2C1 clock enable
    constexpr RCCRegisterType2 UART5EN = Util::Bits::BIT20; //UART5 clock enable
    constexpr RCCRegisterType2 UART4EN = Util::Bits::BIT19; //UART4 clock enable
    constexpr RCCRegisterType2 USART3EN = Util::Bits::BIT18; //USART3 clock enable
    constexpr RCCRegisterType2 USART2EN = Util::Bits::BIT17; //USART 2 clock enable
    constexpr RCCRegisterType2 SPI3EN = Util::Bits::BIT15; //SPI3 clock enable
    constexpr RCCRegisterType2 SPI2EN = Util::Bits::BIT14; //SPI2 clock enable
    constexpr RCCRegisterType2 WWDGEN = Util::Bits::BIT11; //Window watchdog clock enable
    constexpr RCCRegisterType2 TIM14EN = Util::Bits::BIT8; //TIM14 clock enable
    constexpr RCCRegisterType2 TIM13EN = Util::Bits::BIT7; //TIM13 clock enable
    constexpr RCCRegisterType2 TIM12EN = Util::Bits::BIT6; //TIM12 clock enable
    constexpr RCCRegisterType2 TIM7EN = Util::Bits::BIT5; //TIM7 clock enable
    constexpr RCCRegisterType2 TIM6EN = Util::Bits::BIT4; //TIM6 clock enable
    constexpr RCCRegisterType2 TIM5EN = Util::Bits::BIT3; //TIM5 clock enable
    constexpr RCCRegisterType2 TIM4EN = Util::Bits::BIT2; //TIM4 clock enable
    constexpr RCCRegisterType2 TIM3EN = Util::Bits::BIT1; //TIM3 clock enable
    constexpr RCCRegisterType2 TIM2EN = Util::Bits::BIT0; //TIM2 clock enable

  } //End APB1ENR


  namespace APB2ENR //APB2 peripheral clock enable register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x44U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 TIM11EN = Util::Bits::BIT18; //TIM11 clock enable
    constexpr RCCRegisterType2 TIM10EN = Util::Bits::BIT17; //TIM10 clock enable
    constexpr RCCRegisterType2 TIM9EN = Util::Bits::BIT16; //TIM9 clock enable
    constexpr RCCRegisterType2 SYSCFGEN = Util::Bits::BIT14; //System configuration controller clock enable
    constexpr RCCRegisterType2 SPI1EN = Util::Bits::BIT12; //SPI1 clock enable
    constexpr RCCRegisterType2 SDIOEN = Util::Bits::BIT11; //SDIO clock enable
    constexpr RCCRegisterType2 ADC3EN = Util::Bits::BIT10; //ADC3 clock enable
    constexpr RCCRegisterType2 ADC2EN = Util::Bits::BIT9; //ADC2 clock enable
    constexpr RCCRegisterType2 ADC1EN = Util::Bits::BIT8; //ADC1 clock enable
    constexpr RCCRegisterType2 USART6EN = Util::Bits::BIT5; //USART6 clock enable
    constexpr RCCRegisterType2 USART1EN = Util::Bits::BIT4; //USART1 clock enable
    constexpr RCCRegisterType2 TIM8EN = Util::Bits::BIT1; //TIM8 clock enable
    constexpr RCCRegisterType2 TIM1EN = Util::Bits::BIT0; //TIM1 clock enable

  } //End APB2ENR


  namespace AHB1LPENR //AHB1 peripheral clock enable in low power mode register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x50U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 OTGHSULPILPEN = Util::Bits::BIT30; //USB OTG HS ULPI clock enable during Sleep mode
    constexpr RCCRegisterType2 OTGHSLPEN = Util::Bits::BIT29; //USB OTG HS clock enable during Sleep mode
    constexpr RCCRegisterType2 ETHMACPTPLPEN = Util::Bits::BIT28; //Ethernet PTP clock enable during Sleep mode
    constexpr RCCRegisterType2 ETHMACRXLPEN = Util::Bits::BIT27; //Ethernet reception clock enable during Sleep mode
    constexpr RCCRegisterType2 ETHMACTXLPEN = Util::Bits::BIT26; //Ethernet transmission clock enable during Sleep mode
    constexpr RCCRegisterType2 ETHMACLPEN = Util::Bits::BIT25; //Ethernet MAC clock enable during Sleep mode
    constexpr RCCRegisterType2 DMA2LPEN = Util::Bits::BIT22; //DMA2 clock enable during Sleep mode
    constexpr RCCRegisterType2 DMA1LPEN = Util::Bits::BIT21; //DMA1 clock enable during Sleep mode
    constexpr RCCRegisterType2 BKPSRAMLPEN = Util::Bits::BIT18; //Backup SRAM interface clock enable during Sleep mode
    constexpr RCCRegisterType2 SRAM2LPEN = Util::Bits::BIT17; //SRAM 2 interface clock enable during Sleep mode
    constexpr RCCRegisterType2 SRAM1LPEN = Util::Bits::BIT16; //SRAM 1interface clock enable during Sleep mode
    constexpr RCCRegisterType2 FLITFLPEN = Util::Bits::BIT15; //Flash interface clock enable during Sleep mode
    constexpr RCCRegisterType2 CRCLPEN = Util::Bits::BIT12; //CRC clock enable during Sleep mode
    constexpr RCCRegisterType2 GPIOILPEN = Util::Bits::BIT8; //IO port I clock enable during Sleep mode
    constexpr RCCRegisterType2 GPIOHLPEN = Util::Bits::BIT7; //IO port H clock enable during Sleep mode
    constexpr RCCRegisterType2 GPIOGLPEN = Util::Bits::BIT6; //IO port G clock enable during Sleep mode
    constexpr RCCRegisterType2 GPIOFLPEN = Util::Bits::BIT5; //IO port F clock enable during Sleep mode
    constexpr RCCRegisterType2 GPIOELPEN = Util::Bits::BIT4; //IO port E clock enable during Sleep mode
    constexpr RCCRegisterType2 GPIODLPEN = Util::Bits::BIT3; //IO port D clock enable during Sleep mode
    constexpr RCCRegisterType2 GPIOCLPEN = Util::Bits::BIT2; //IO port C clock enable during Sleep mode
    constexpr RCCRegisterType2 GPIOBLPEN = Util::Bits::BIT1; //IO port B clock enable during Sleep mode
    constexpr RCCRegisterType2 GPIOALPEN = Util::Bits::BIT0; //IO port A clock enable during sleep mode

  } //End AHB1LPENR


  namespace AHB2LPENR //AHB2 peripheral clock enable in low power mode register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x54U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 OTGFSLPEN = Util::Bits::BIT7; //USB OTG FS clock enable during Sleep mode
    constexpr RCCRegisterType2 RNGLPEN = Util::Bits::BIT6; //Random number generator clock enable during Sleep mode
    constexpr RCCRegisterType2 DCMILPEN = Util::Bits::BIT0; //Camera interface enable during Sleep mode

  } //End AHB2LPENR


  namespace AHB3LPENR //AHB3 peripheral clock enable in low power mode register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x58U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 FSMCLPEN = Util::Bits::BIT0; //Flexible static memory controller module clock enable during Sleep mode

  } //End AHB3LPENR


  namespace APB1LPENR //APB1 peripheral clock enable in low power mode register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x60U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 DACLPEN = Util::Bits::BIT29; //DAC interface clock enable during Sleep mode
    constexpr RCCRegisterType2 PWRLPEN = Util::Bits::BIT28; //Power interface clock enable during Sleep mode
    constexpr RCCRegisterType2 CAN2LPEN = Util::Bits::BIT26; //CAN 2 clock enable during Sleep mode
    constexpr RCCRegisterType2 CAN1LPEN = Util::Bits::BIT25; //CAN 1 clock enable during Sleep mode
    constexpr RCCRegisterType2 I2C3LPEN = Util::Bits::BIT23; //I2C3 clock enable during Sleep mode
    constexpr RCCRegisterType2 I2C2LPEN = Util::Bits::BIT22; //I2C2 clock enable during Sleep mode
    constexpr RCCRegisterType2 I2C1LPEN = Util::Bits::BIT21; //I2C1 clock enable during Sleep mode
    constexpr RCCRegisterType2 UART5LPEN = Util::Bits::BIT20; //UART5 clock enable during Sleep mode
    constexpr RCCRegisterType2 UART4LPEN = Util::Bits::BIT19; //UART4 clock enable during Sleep mode
    constexpr RCCRegisterType2 USART3LPEN = Util::Bits::BIT18; //USART3 clock enable during Sleep mode
    constexpr RCCRegisterType2 USART2LPEN = Util::Bits::BIT17; //USART2 clock enable during Sleep mode
    constexpr RCCRegisterType2 SPI3LPEN = Util::Bits::BIT15; //SPI3 clock enable during Sleep mode
    constexpr RCCRegisterType2 SPI2LPEN = Util::Bits::BIT14; //SPI2 clock enable during Sleep mode
    constexpr RCCRegisterType2 WWDGLPEN = Util::Bits::BIT11; //Window watchdog clock enable during Sleep mode
    constexpr RCCRegisterType2 TIM14LPEN = Util::Bits::BIT8; //TIM14 clock enable during Sleep mode
    constexpr RCCRegisterType2 TIM13LPEN = Util::Bits::BIT7; //TIM13 clock enable during Sleep mode
    constexpr RCCRegisterType2 TIM12LPEN = Util::Bits::BIT6; //TIM12 clock enable during Sleep mode
    constexpr RCCRegisterType2 TIM7LPEN = Util::Bits::BIT5; //TIM7 clock enable during Sleep mode
    constexpr RCCRegisterType2 TIM6LPEN = Util::Bits::BIT4; //TIM6 clock enable during Sleep mode
    constexpr RCCRegisterType2 TIM5LPEN = Util::Bits::BIT3; //TIM5 clock enable during Sleep mode
    constexpr RCCRegisterType2 TIM4LPEN = Util::Bits::BIT2; //TIM4 clock enable during Sleep mode
    constexpr RCCRegisterType2 TIM3LPEN = Util::Bits::BIT1; //TIM3 clock enable during Sleep mode
    constexpr RCCRegisterType2 TIM2LPEN = Util::Bits::BIT0; //TIM2 clock enable during Sleep mode

  } //End APB1LPENR


  namespace APB2LPENR //APB2 peripheral clock enabled in low power mode register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x64U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 TIM11LPEN = Util::Bits::BIT18; //TIM11 clock enable during Sleep mode
    constexpr RCCRegisterType2 TIM10LPEN = Util::Bits::BIT17; //TIM10 clock enable during Sleep mode
    constexpr RCCRegisterType2 TIM9LPEN = Util::Bits::BIT16; //TIM9 clock enable during sleep mode
    constexpr RCCRegisterType2 SYSCFGLPEN = Util::Bits::BIT14; //System configuration controller clock enable during Sleep mode
    constexpr RCCRegisterType2 SPI1LPEN = Util::Bits::BIT12; //SPI 1 clock enable during Sleep mode
    constexpr RCCRegisterType2 SDIOLPEN = Util::Bits::BIT11; //SDIO clock enable during Sleep mode
    constexpr RCCRegisterType2 ADC3LPEN = Util::Bits::BIT10; //ADC 3 clock enable during Sleep mode
    constexpr RCCRegisterType2 ADC2LPEN = Util::Bits::BIT9; //ADC2 clock enable during Sleep mode
    constexpr RCCRegisterType2 ADC1LPEN = Util::Bits::BIT8; //ADC1 clock enable during Sleep mode
    constexpr RCCRegisterType2 USART6LPEN = Util::Bits::BIT5; //USART6 clock enable during Sleep mode
    constexpr RCCRegisterType2 USART1LPEN = Util::Bits::BIT4; //USART1 clock enable during Sleep mode
    constexpr RCCRegisterType2 TIM8LPEN = Util::Bits::BIT1; //TIM8 clock enable during Sleep mode
    constexpr RCCRegisterType2 TIM1LPEN = Util::Bits::BIT0; //TIM1 clock enable during Sleep mode

  } //End APB2LPENR


  namespace BDCR //Backup domain control register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x70U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 BDRST = Util::Bits::BIT16; //Backup domain software reset
    constexpr RCCRegisterType2 RTCEN = Util::Bits::BIT15; //RTC clock enable
    constexpr RCCRegisterType2 RTCSEL1 = Util::Bits::BIT9; //RTC clock source selection
    constexpr RCCRegisterType2 RTCSEL0 = Util::Bits::BIT8; //RTC clock source selection
    constexpr RCCRegisterType2 LSEBYP = Util::Bits::BIT2; //External low-speed oscillator bypass
    constexpr RCCRegisterType2 LSERDY = Util::Bits::BIT1; //External low-speed oscillator ready
    constexpr RCCRegisterType2 LSEON = Util::Bits::BIT0; //External low-speed oscillator enable

  } //End BDCR


  namespace CSR //clock control & status register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x74U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 LPWRRSTF = Util::Bits::BIT31; //Low-power reset flag
    constexpr RCCRegisterType2 WWDGRSTF = Util::Bits::BIT30; //Window watchdog reset flag
    constexpr RCCRegisterType2 WDGRSTF = Util::Bits::BIT29; //Independent watchdog reset flag
    constexpr RCCRegisterType2 SFTRSTF = Util::Bits::BIT28; //Software reset flag
    constexpr RCCRegisterType2 PORRSTF = Util::Bits::BIT27; //POR/PDR reset flag
    constexpr RCCRegisterType2 PADRSTF = Util::Bits::BIT26; //PIN reset flag
    constexpr RCCRegisterType2 BORRSTF = Util::Bits::BIT25; //BOR reset flag
    constexpr RCCRegisterType2 RMVF = Util::Bits::BIT24; //Remove reset flag
    constexpr RCCRegisterType2 LSIRDY = Util::Bits::BIT1; //Internal low-speed oscillator ready
    constexpr RCCRegisterType2 LSION = Util::Bits::BIT0; //Internal low-speed oscillator enable

  } //End CSR


  namespace SSCGR //spread spectrum clock generation register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x80U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value

    constexpr RCCRegisterType2 SSCGEN = Util::Bits::BIT31; //Spread spectrum modulation enable
    constexpr RCCRegisterType2 SPREADSEL = Util::Bits::BIT30; //Spread Select

  } //End SSCGR


  namespace PLLI2SCFGR //PLLI2S configuration register
  { 

    constexpr RCCRegisterType2 registerOffset = 0x84U; //Register Offset Value
    constexpr RCCRegisterType2 registerReset = 0x0000U; //Register Reset Value


    namespace PLLI2SRxBits//PLLI2S division factor for I2S clocks
    {

  
      constexpr RCCRegisterType2 divBy2 = 0x20000000U;
      constexpr RCCRegisterType2 divBy3 = 0x30000000U;
      constexpr RCCRegisterType2 divBy4 = 0x40000000U;
      constexpr RCCRegisterType2 divBy5 = 0x50000000U;
      constexpr RCCRegisterType2 divBy6 = 0x60000000U;
      constexpr RCCRegisterType2 divBY7 = 0x70000000U;

   }


  } //End PLLI2SCFGR


}



#endif