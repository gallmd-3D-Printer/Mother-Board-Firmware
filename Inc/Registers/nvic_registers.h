#ifndef NVICREGISTERS_H_
#define NVICREGISTERS_H_

#include "util.h"

namespace NVIC_MDG
{

  typedef uint32_t NVICRegisterType;

  namespace BaseRegisters
  {

    constexpr NVICRegisterType NVIC = 0xE000E000U; //Nested Vectored Interrupt      Controller

  } //End BaseRegisters

  namespace ICTR //Interrupt Controller Type Register
  { 

    constexpr NVICRegisterType registerOffset = 0x4U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


    namespace INTLINESNUMBits//Total number of interrupt lines in groups
    {

      constexpr NVICRegisterType INTLINESNUM0 = 0x0U;
      constexpr NVICRegisterType INTLINESNUM1 = 0x1U;
      constexpr NVICRegisterType INTLINESNUM2 = 0x2U;
      constexpr NVICRegisterType INTLINESNUM3 = 0x3U;
      constexpr NVICRegisterType INTLINESNUM4 = 0x4U;
      constexpr NVICRegisterType INTLINESNUM5 = 0x5U;
      constexpr NVICRegisterType INTLINESNUM6 = 0x6U;
      constexpr NVICRegisterType INTLINESNUM7 = 0x7U;
      constexpr NVICRegisterType INTLINESNUM8 = 0x8U;
      constexpr NVICRegisterType INTLINESNUM9 = 0x9U;
      constexpr NVICRegisterType INTLINESNUM10 = 0xAU;
      constexpr NVICRegisterType INTLINESNUM11 = 0xBU;
      constexpr NVICRegisterType INTLINESNUM12 = 0xCU;
      constexpr NVICRegisterType INTLINESNUM13 = 0xDU;
      constexpr NVICRegisterType INTLINESNUM14 = 0xEU;
      constexpr NVICRegisterType INTLINESNUM15 = 0xFU;

   }


  } //End ICTR


  namespace STIR //Software Triggered Interrupt Register
  { 

    constexpr NVICRegisterType registerOffset = 0xF00U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End STIR


  namespace ISER0 //Interrupt Set-Enable Register
  { 

    constexpr NVICRegisterType registerOffset = 0x100U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End ISER0


  namespace ISER1 //Interrupt Set-Enable Register
  { 

    constexpr NVICRegisterType registerOffset = 0x104U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End ISER1


  namespace ISER2 //Interrupt Set-Enable Register
  { 

    constexpr NVICRegisterType registerOffset = 0x108U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End ISER2


  namespace ICER0 //Interrupt Clear-Enable Register
  { 

    constexpr NVICRegisterType registerOffset = 0x180U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End ICER0


  namespace ICER1 //Interrupt Clear-Enable Register
  { 

    constexpr NVICRegisterType registerOffset = 0x184U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End ICER1


  namespace ICER2 //Interrupt Clear-Enable Register
  { 

    constexpr NVICRegisterType registerOffset = 0x188U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End ICER2


  namespace ISPR0 //Interrupt Set-Pending Register
  { 

    constexpr NVICRegisterType registerOffset = 0x200U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End ISPR0


  namespace ISPR1 //Interrupt Set-Pending Register
  { 

    constexpr NVICRegisterType registerOffset = 0x204U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End ISPR1


  namespace ISPR2 //Interrupt Set-Pending Register
  { 

    constexpr NVICRegisterType registerOffset = 0x208U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End ISPR2


  namespace ICPR0 //Interrupt Clear-Pending Register
  { 

    constexpr NVICRegisterType registerOffset = 0x280U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End ICPR0


  namespace ICPR1 //Interrupt Clear-Pending Register
  { 

    constexpr NVICRegisterType registerOffset = 0x284U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End ICPR1


  namespace ICPR2 //Interrupt Clear-Pending Register
  { 

    constexpr NVICRegisterType registerOffset = 0x288U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End ICPR2


  namespace IABR0 //Interrupt Active Bit Register
  { 

    constexpr NVICRegisterType registerOffset = 0x300U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IABR0


  namespace IABR1 //Interrupt Active Bit Register
  { 

    constexpr NVICRegisterType registerOffset = 0x304U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IABR1


  namespace IABR2 //Interrupt Active Bit Register
  { 

    constexpr NVICRegisterType registerOffset = 0x308U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IABR2


  namespace IPR0 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x400U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR0


  namespace IPR1 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x404U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR1


  namespace IPR2 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x408U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR2


  namespace IPR3 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x40CU; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR3


  namespace IPR4 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x410U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR4


  namespace IPR5 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x414U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR5


  namespace IPR6 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x418U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR6


  namespace IPR7 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x41CU; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR7


  namespace IPR8 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x420U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR8


  namespace IPR9 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x424U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR9


  namespace IPR10 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x428U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR10


  namespace IPR11 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x42CU; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR11


  namespace IPR12 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x430U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR12


  namespace IPR13 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x434U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR13


  namespace IPR14 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x438U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR14


  namespace IPR15 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x43CU; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR15


  namespace IPR16 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x440U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR16


  namespace IPR17 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x444U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR17


  namespace IPR18 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x448U; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR18


  namespace IPR19 //Interrupt Priority Register
  { 

    constexpr NVICRegisterType registerOffset = 0x44CU; //Register Offset Value
    constexpr NVICRegisterType registerReset = 0x0000U; //Register Reset Value


  } //End IPR19


}



#endif