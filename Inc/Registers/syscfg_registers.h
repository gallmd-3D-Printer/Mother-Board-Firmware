/*
 * syscfg_registers.h
 *
 *  Created on: Dec 28, 2020
 *      Author: matt
 */

#ifndef REGISTERS_SYSCFG_REGISTERS_H_
#define REGISTERS_SYSCFG_REGISTERS_H_

#include "stdint.h"
#include "Utility/util.h"

namespace SYSCFG_MDG
{

  typedef uint32_t SYSCFGRegisterType;

  namespace BaseRegisters
  {

    constexpr SYSCFGRegisterType SYSCFGBase = 0x40013800U; //System configuration controller

  } //End BaseRegisters

  namespace MEMRM //memory remap register
  {

    constexpr SYSCFGRegisterType registerOffset = 0x0U; //Register Offset Value
    constexpr SYSCFGRegisterType registerReset = 0x0000U; //Register Reset Value


    namespace MEM_MODEBits//MEM_MODE
    {

      constexpr SYSCFGRegisterType MEM_MODE0 = 0x0U;
      constexpr SYSCFGRegisterType MEM_MODE1 = 0x1U;
      constexpr SYSCFGRegisterType MEM_MODE2 = 0x2U;
      constexpr SYSCFGRegisterType MEM_MODE3 = 0x3U;

   }


  } //End MEMRM


  namespace PMC //peripheral mode configuration register
  {

    constexpr SYSCFGRegisterType registerOffset = 0x4U; //Register Offset Value
    constexpr SYSCFGRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr SYSCFGRegisterType MII_RMII_SEL = Util::Bits::BIT23; //Ethernet PHY interface selection

  } //End PMC


  namespace EXTICR1 //external interrupt configuration register 1
  {

    constexpr SYSCFGRegisterType registerOffset = 0x8U; //Register Offset Value
    constexpr SYSCFGRegisterType registerReset = 0x0000U; //Register Reset Value


    namespace EXTI3Bits//EXTI x configuration (x = 0 to 3)
    {

      constexpr SYSCFGRegisterType EXTI30 = 0x0U;
      constexpr SYSCFGRegisterType EXTI31 = 0x1000U;
      constexpr SYSCFGRegisterType EXTI32 = 0x2000U;
      constexpr SYSCFGRegisterType EXTI33 = 0x3000U;
      constexpr SYSCFGRegisterType EXTI34 = 0x4000U;
      constexpr SYSCFGRegisterType EXTI35 = 0x5000U;
      constexpr SYSCFGRegisterType EXTI36 = 0x6000U;
      constexpr SYSCFGRegisterType EXTI37 = 0x7000U;
      constexpr SYSCFGRegisterType EXTI38 = 0x8000U;
      constexpr SYSCFGRegisterType EXTI39 = 0x9000U;
      constexpr SYSCFGRegisterType EXTI310 = 0xA000U;
      constexpr SYSCFGRegisterType EXTI311 = 0xB000U;
      constexpr SYSCFGRegisterType EXTI312 = 0xC000U;
      constexpr SYSCFGRegisterType EXTI313 = 0xD000U;
      constexpr SYSCFGRegisterType EXTI314 = 0xE000U;
      constexpr SYSCFGRegisterType EXTI315 = 0xF000U;

   }


    namespace EXTI2Bits//EXTI x configuration (x = 0 to 3)
    {

      constexpr SYSCFGRegisterType EXTI20 = 0x0U;
      constexpr SYSCFGRegisterType EXTI21 = 0x100U;
      constexpr SYSCFGRegisterType EXTI22 = 0x200U;
      constexpr SYSCFGRegisterType EXTI23 = 0x300U;
      constexpr SYSCFGRegisterType EXTI24 = 0x400U;
      constexpr SYSCFGRegisterType EXTI25 = 0x500U;
      constexpr SYSCFGRegisterType EXTI26 = 0x600U;
      constexpr SYSCFGRegisterType EXTI27 = 0x700U;
      constexpr SYSCFGRegisterType EXTI28 = 0x800U;
      constexpr SYSCFGRegisterType EXTI29 = 0x900U;
      constexpr SYSCFGRegisterType EXTI210 = 0xA00U;
      constexpr SYSCFGRegisterType EXTI211 = 0xB00U;
      constexpr SYSCFGRegisterType EXTI212 = 0xC00U;
      constexpr SYSCFGRegisterType EXTI213 = 0xD00U;
      constexpr SYSCFGRegisterType EXTI214 = 0xE00U;
      constexpr SYSCFGRegisterType EXTI215 = 0xF00U;

   }


    namespace EXTI1Bits//EXTI x configuration (x = 0 to 3)
    {

      constexpr SYSCFGRegisterType EXTI10 = 0x0U;
      constexpr SYSCFGRegisterType EXTI11 = 0x10U;
      constexpr SYSCFGRegisterType EXTI12 = 0x20U;
      constexpr SYSCFGRegisterType EXTI13 = 0x30U;
      constexpr SYSCFGRegisterType EXTI14 = 0x40U;
      constexpr SYSCFGRegisterType EXTI15 = 0x50U;
      constexpr SYSCFGRegisterType EXTI16 = 0x60U;
      constexpr SYSCFGRegisterType EXTI17 = 0x70U;
      constexpr SYSCFGRegisterType EXTI18 = 0x80U;
      constexpr SYSCFGRegisterType EXTI19 = 0x90U;
      constexpr SYSCFGRegisterType EXTI110 = 0xA0U;
      constexpr SYSCFGRegisterType EXTI111 = 0xB0U;
      constexpr SYSCFGRegisterType EXTI112 = 0xC0U;
      constexpr SYSCFGRegisterType EXTI113 = 0xD0U;
      constexpr SYSCFGRegisterType EXTI114 = 0xE0U;
      constexpr SYSCFGRegisterType EXTI115 = 0xF0U;

   }


    namespace EXTI0Bits//EXTI x configuration (x = 0 to 3)
    {

      constexpr SYSCFGRegisterType EXTI00 = 0x0U;
      constexpr SYSCFGRegisterType EXTI01 = 0x1U;
      constexpr SYSCFGRegisterType EXTI02 = 0x2U;
      constexpr SYSCFGRegisterType EXTI03 = 0x3U;
      constexpr SYSCFGRegisterType EXTI04 = 0x4U;
      constexpr SYSCFGRegisterType EXTI05 = 0x5U;
      constexpr SYSCFGRegisterType EXTI06 = 0x6U;
      constexpr SYSCFGRegisterType EXTI07 = 0x7U;
      constexpr SYSCFGRegisterType EXTI08 = 0x8U;
      constexpr SYSCFGRegisterType EXTI09 = 0x9U;
      constexpr SYSCFGRegisterType EXTI010 = 0xAU;
      constexpr SYSCFGRegisterType EXTI011 = 0xBU;
      constexpr SYSCFGRegisterType EXTI012 = 0xCU;
      constexpr SYSCFGRegisterType EXTI013 = 0xDU;
      constexpr SYSCFGRegisterType EXTI014 = 0xEU;
      constexpr SYSCFGRegisterType EXTI015 = 0xFU;

   }


  } //End EXTICR1


  namespace EXTICR2 //external interrupt configuration register 2
  {

    constexpr SYSCFGRegisterType registerOffset = 0xCU; //Register Offset Value
    constexpr SYSCFGRegisterType registerReset = 0x0000U; //Register Reset Value


    namespace EXTI7Bits//EXTI x configuration (x = 4 to 7)
    {

      constexpr SYSCFGRegisterType EXTI70 = 0x0U;
      constexpr SYSCFGRegisterType EXTI71 = 0x1000U;
      constexpr SYSCFGRegisterType EXTI72 = 0x2000U;
      constexpr SYSCFGRegisterType EXTI73 = 0x3000U;
      constexpr SYSCFGRegisterType EXTI74 = 0x4000U;
      constexpr SYSCFGRegisterType EXTI75 = 0x5000U;
      constexpr SYSCFGRegisterType EXTI76 = 0x6000U;
      constexpr SYSCFGRegisterType EXTI77 = 0x7000U;
      constexpr SYSCFGRegisterType EXTI78 = 0x8000U;
      constexpr SYSCFGRegisterType EXTI79 = 0x9000U;
      constexpr SYSCFGRegisterType EXTI710 = 0xA000U;
      constexpr SYSCFGRegisterType EXTI711 = 0xB000U;
      constexpr SYSCFGRegisterType EXTI712 = 0xC000U;
      constexpr SYSCFGRegisterType EXTI713 = 0xD000U;
      constexpr SYSCFGRegisterType EXTI714 = 0xE000U;
      constexpr SYSCFGRegisterType EXTI715 = 0xF000U;

   }


    namespace EXTI6Bits//EXTI x configuration (x = 4 to 7)
    {

      constexpr SYSCFGRegisterType EXTI60 = 0x0U;
      constexpr SYSCFGRegisterType EXTI61 = 0x100U;
      constexpr SYSCFGRegisterType EXTI62 = 0x200U;
      constexpr SYSCFGRegisterType EXTI63 = 0x300U;
      constexpr SYSCFGRegisterType EXTI64 = 0x400U;
      constexpr SYSCFGRegisterType EXTI65 = 0x500U;
      constexpr SYSCFGRegisterType EXTI66 = 0x600U;
      constexpr SYSCFGRegisterType EXTI67 = 0x700U;
      constexpr SYSCFGRegisterType EXTI68 = 0x800U;
      constexpr SYSCFGRegisterType EXTI69 = 0x900U;
      constexpr SYSCFGRegisterType EXTI610 = 0xA00U;
      constexpr SYSCFGRegisterType EXTI611 = 0xB00U;
      constexpr SYSCFGRegisterType EXTI612 = 0xC00U;
      constexpr SYSCFGRegisterType EXTI613 = 0xD00U;
      constexpr SYSCFGRegisterType EXTI614 = 0xE00U;
      constexpr SYSCFGRegisterType EXTI615 = 0xF00U;

   }


    namespace EXTI5Bits//EXTI x configuration (x = 4 to 7)
    {

      constexpr SYSCFGRegisterType EXTI50 = 0x0U;
      constexpr SYSCFGRegisterType EXTI51 = 0x10U;
      constexpr SYSCFGRegisterType EXTI52 = 0x20U;
      constexpr SYSCFGRegisterType EXTI53 = 0x30U;
      constexpr SYSCFGRegisterType EXTI54 = 0x40U;
      constexpr SYSCFGRegisterType EXTI55 = 0x50U;
      constexpr SYSCFGRegisterType EXTI56 = 0x60U;
      constexpr SYSCFGRegisterType EXTI57 = 0x70U;
      constexpr SYSCFGRegisterType EXTI58 = 0x80U;
      constexpr SYSCFGRegisterType EXTI59 = 0x90U;
      constexpr SYSCFGRegisterType EXTI510 = 0xA0U;
      constexpr SYSCFGRegisterType EXTI511 = 0xB0U;
      constexpr SYSCFGRegisterType EXTI512 = 0xC0U;
      constexpr SYSCFGRegisterType EXTI513 = 0xD0U;
      constexpr SYSCFGRegisterType EXTI514 = 0xE0U;
      constexpr SYSCFGRegisterType EXTI515 = 0xF0U;

   }


    namespace EXTI4Bits//EXTI x configuration (x = 4 to 7)
    {

      constexpr SYSCFGRegisterType EXTI40 = 0x0U;
      constexpr SYSCFGRegisterType EXTI41 = 0x1U;
      constexpr SYSCFGRegisterType EXTI42 = 0x2U;
      constexpr SYSCFGRegisterType EXTI43 = 0x3U;
      constexpr SYSCFGRegisterType EXTI44 = 0x4U;
      constexpr SYSCFGRegisterType EXTI45 = 0x5U;
      constexpr SYSCFGRegisterType EXTI46 = 0x6U;
      constexpr SYSCFGRegisterType EXTI47 = 0x7U;
      constexpr SYSCFGRegisterType EXTI48 = 0x8U;
      constexpr SYSCFGRegisterType EXTI49 = 0x9U;
      constexpr SYSCFGRegisterType EXTI410 = 0xAU;
      constexpr SYSCFGRegisterType EXTI411 = 0xBU;
      constexpr SYSCFGRegisterType EXTI412 = 0xCU;
      constexpr SYSCFGRegisterType EXTI413 = 0xDU;
      constexpr SYSCFGRegisterType EXTI414 = 0xEU;
      constexpr SYSCFGRegisterType EXTI415 = 0xFU;

   }


  } //End EXTICR2


  namespace EXTICR3 //external interrupt configuration register 3
  {

    constexpr SYSCFGRegisterType registerOffset = 0x10U; //Register Offset Value
    constexpr SYSCFGRegisterType registerReset = 0x0000U; //Register Reset Value


    namespace EXTI11Bits//EXTI x configuration (x = 8 to 11)
    {

      constexpr SYSCFGRegisterType EXTI110 = 0x0U;
      constexpr SYSCFGRegisterType EXTI111 = 0x1000U;
      constexpr SYSCFGRegisterType EXTI112 = 0x2000U;
      constexpr SYSCFGRegisterType EXTI113 = 0x3000U;
      constexpr SYSCFGRegisterType EXTI114 = 0x4000U;
      constexpr SYSCFGRegisterType EXTI115 = 0x5000U;
      constexpr SYSCFGRegisterType EXTI116 = 0x6000U;
      constexpr SYSCFGRegisterType EXTI117 = 0x7000U;
      constexpr SYSCFGRegisterType EXTI118 = 0x8000U;
      constexpr SYSCFGRegisterType EXTI119 = 0x9000U;
      constexpr SYSCFGRegisterType EXTI1110 = 0xA000U;
      constexpr SYSCFGRegisterType EXTI1111 = 0xB000U;
      constexpr SYSCFGRegisterType EXTI1112 = 0xC000U;
      constexpr SYSCFGRegisterType EXTI1113 = 0xD000U;
      constexpr SYSCFGRegisterType EXTI1114 = 0xE000U;
      constexpr SYSCFGRegisterType EXTI1115 = 0xF000U;

   }


    namespace EXTI10Bits//EXTI10
    {

      constexpr SYSCFGRegisterType EXTI100 = 0x0U;
      constexpr SYSCFGRegisterType EXTI101 = 0x100U;
      constexpr SYSCFGRegisterType EXTI102 = 0x200U;
      constexpr SYSCFGRegisterType EXTI103 = 0x300U;
      constexpr SYSCFGRegisterType EXTI104 = 0x400U;
      constexpr SYSCFGRegisterType EXTI105 = 0x500U;
      constexpr SYSCFGRegisterType EXTI106 = 0x600U;
      constexpr SYSCFGRegisterType EXTI107 = 0x700U;
      constexpr SYSCFGRegisterType EXTI108 = 0x800U;
      constexpr SYSCFGRegisterType EXTI109 = 0x900U;
      constexpr SYSCFGRegisterType EXTI1010 = 0xA00U;
      constexpr SYSCFGRegisterType EXTI1011 = 0xB00U;
      constexpr SYSCFGRegisterType EXTI1012 = 0xC00U;
      constexpr SYSCFGRegisterType EXTI1013 = 0xD00U;
      constexpr SYSCFGRegisterType EXTI1014 = 0xE00U;
      constexpr SYSCFGRegisterType EXTI1015 = 0xF00U;

   }


    namespace EXTI9Bits//EXTI x configuration (x = 8 to 11)
    {

      constexpr SYSCFGRegisterType EXTI90 = 0x0U;
      constexpr SYSCFGRegisterType EXTI91 = 0x10U;
      constexpr SYSCFGRegisterType EXTI92 = 0x20U;
      constexpr SYSCFGRegisterType EXTI93 = 0x30U;
      constexpr SYSCFGRegisterType EXTI94 = 0x40U;
      constexpr SYSCFGRegisterType EXTI95 = 0x50U;
      constexpr SYSCFGRegisterType EXTI96 = 0x60U;
      constexpr SYSCFGRegisterType EXTI97 = 0x70U;
      constexpr SYSCFGRegisterType EXTI98 = 0x80U;
      constexpr SYSCFGRegisterType EXTI99 = 0x90U;
      constexpr SYSCFGRegisterType EXTI910 = 0xA0U;
      constexpr SYSCFGRegisterType EXTI911 = 0xB0U;
      constexpr SYSCFGRegisterType EXTI912 = 0xC0U;
      constexpr SYSCFGRegisterType EXTI913 = 0xD0U;
      constexpr SYSCFGRegisterType EXTI914 = 0xE0U;
      constexpr SYSCFGRegisterType EXTI915 = 0xF0U;

   }


    namespace EXTI8Bits//EXTI x configuration (x = 8 to 11)
    {

      constexpr SYSCFGRegisterType EXTI80 = 0x0U;
      constexpr SYSCFGRegisterType EXTI81 = 0x1U;
      constexpr SYSCFGRegisterType EXTI82 = 0x2U;
      constexpr SYSCFGRegisterType EXTI83 = 0x3U;
      constexpr SYSCFGRegisterType EXTI84 = 0x4U;
      constexpr SYSCFGRegisterType EXTI85 = 0x5U;
      constexpr SYSCFGRegisterType EXTI86 = 0x6U;
      constexpr SYSCFGRegisterType EXTI87 = 0x7U;
      constexpr SYSCFGRegisterType EXTI88 = 0x8U;
      constexpr SYSCFGRegisterType EXTI89 = 0x9U;
      constexpr SYSCFGRegisterType EXTI810 = 0xAU;
      constexpr SYSCFGRegisterType EXTI811 = 0xBU;
      constexpr SYSCFGRegisterType EXTI812 = 0xCU;
      constexpr SYSCFGRegisterType EXTI813 = 0xDU;
      constexpr SYSCFGRegisterType EXTI814 = 0xEU;
      constexpr SYSCFGRegisterType EXTI815 = 0xFU;

   }


  } //End EXTICR3


  namespace EXTICR4 //external interrupt configuration register 4
  {

    constexpr SYSCFGRegisterType registerOffset = 0x14U; //Register Offset Value
    constexpr SYSCFGRegisterType registerReset = 0x0000U; //Register Reset Value


    namespace EXTI15Bits//EXTI x configuration (x = 12 to 15)
    {

      constexpr SYSCFGRegisterType EXTI150 = 0x0U;
      constexpr SYSCFGRegisterType EXTI151 = 0x1000U;
      constexpr SYSCFGRegisterType EXTI152 = 0x2000U;
      constexpr SYSCFGRegisterType EXTI153 = 0x3000U;
      constexpr SYSCFGRegisterType EXTI154 = 0x4000U;
      constexpr SYSCFGRegisterType EXTI155 = 0x5000U;
      constexpr SYSCFGRegisterType EXTI156 = 0x6000U;
      constexpr SYSCFGRegisterType EXTI157 = 0x7000U;
      constexpr SYSCFGRegisterType EXTI158 = 0x8000U;
      constexpr SYSCFGRegisterType EXTI159 = 0x9000U;
      constexpr SYSCFGRegisterType EXTI1510 = 0xA000U;
      constexpr SYSCFGRegisterType EXTI1511 = 0xB000U;
      constexpr SYSCFGRegisterType EXTI1512 = 0xC000U;
      constexpr SYSCFGRegisterType EXTI1513 = 0xD000U;
      constexpr SYSCFGRegisterType EXTI1514 = 0xE000U;
      constexpr SYSCFGRegisterType EXTI1515 = 0xF000U;

   }


    namespace EXTI14Bits//EXTI x configuration (x = 12 to 15)
    {

      constexpr SYSCFGRegisterType EXTI140 = 0x0U;
      constexpr SYSCFGRegisterType EXTI141 = 0x100U;
      constexpr SYSCFGRegisterType EXTI142 = 0x200U;
      constexpr SYSCFGRegisterType EXTI143 = 0x300U;
      constexpr SYSCFGRegisterType EXTI144 = 0x400U;
      constexpr SYSCFGRegisterType EXTI145 = 0x500U;
      constexpr SYSCFGRegisterType EXTI146 = 0x600U;
      constexpr SYSCFGRegisterType EXTI147 = 0x700U;
      constexpr SYSCFGRegisterType EXTI148 = 0x800U;
      constexpr SYSCFGRegisterType EXTI149 = 0x900U;
      constexpr SYSCFGRegisterType EXTI1410 = 0xA00U;
      constexpr SYSCFGRegisterType EXTI1411 = 0xB00U;
      constexpr SYSCFGRegisterType EXTI1412 = 0xC00U;
      constexpr SYSCFGRegisterType EXTI1413 = 0xD00U;
      constexpr SYSCFGRegisterType EXTI1414 = 0xE00U;
      constexpr SYSCFGRegisterType EXTI1415 = 0xF00U;

   }


    namespace EXTI13Bits//EXTI x configuration (x = 12 to 15)
    {

      constexpr SYSCFGRegisterType EXTI130 = 0x0U;
      constexpr SYSCFGRegisterType EXTI131 = 0x10U;
      constexpr SYSCFGRegisterType EXTI132 = 0x20U;
      constexpr SYSCFGRegisterType EXTI133 = 0x30U;
      constexpr SYSCFGRegisterType EXTI134 = 0x40U;
      constexpr SYSCFGRegisterType EXTI135 = 0x50U;
      constexpr SYSCFGRegisterType EXTI136 = 0x60U;
      constexpr SYSCFGRegisterType EXTI137 = 0x70U;
      constexpr SYSCFGRegisterType EXTI138 = 0x80U;
      constexpr SYSCFGRegisterType EXTI139 = 0x90U;
      constexpr SYSCFGRegisterType EXTI1310 = 0xA0U;
      constexpr SYSCFGRegisterType EXTI1311 = 0xB0U;
      constexpr SYSCFGRegisterType EXTI1312 = 0xC0U;
      constexpr SYSCFGRegisterType EXTI1313 = 0xD0U;
      constexpr SYSCFGRegisterType EXTI1314 = 0xE0U;
      constexpr SYSCFGRegisterType EXTI1315 = 0xF0U;

   }


    namespace EXTI12Bits//EXTI x configuration (x = 12 to 15)
    {

      constexpr SYSCFGRegisterType EXTI120 = 0x0U;
      constexpr SYSCFGRegisterType EXTI121 = 0x1U;
      constexpr SYSCFGRegisterType EXTI122 = 0x2U;
      constexpr SYSCFGRegisterType EXTI123 = 0x3U;
      constexpr SYSCFGRegisterType EXTI124 = 0x4U;
      constexpr SYSCFGRegisterType EXTI125 = 0x5U;
      constexpr SYSCFGRegisterType EXTI126 = 0x6U;
      constexpr SYSCFGRegisterType EXTI127 = 0x7U;
      constexpr SYSCFGRegisterType EXTI128 = 0x8U;
      constexpr SYSCFGRegisterType EXTI129 = 0x9U;
      constexpr SYSCFGRegisterType EXTI1210 = 0xAU;
      constexpr SYSCFGRegisterType EXTI1211 = 0xBU;
      constexpr SYSCFGRegisterType EXTI1212 = 0xCU;
      constexpr SYSCFGRegisterType EXTI1213 = 0xDU;
      constexpr SYSCFGRegisterType EXTI1214 = 0xEU;
      constexpr SYSCFGRegisterType EXTI1215 = 0xFU;

   }


  } //End EXTICR4


  namespace CMPCR //Compensation cell control register
  {

    constexpr SYSCFGRegisterType registerOffset = 0x20U; //Register Offset Value
    constexpr SYSCFGRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr SYSCFGRegisterType READY = Util::Bits::BIT8; //READY
    constexpr SYSCFGRegisterType CMP_PD = Util::Bits::BIT0; //Compensation cell power-down

  } //End CMPCR


}



#endif /* REGISTERS_SYSCFG_REGISTERS_H_ */
