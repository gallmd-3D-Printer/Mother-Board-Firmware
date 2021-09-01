/*
 * exti_registers.h
 *
 *  Created on: Dec 28, 2020
 *      Author: matt
 */

#ifndef REGISTERS_EXTI_REGISTERS_H_
#define REGISTERS_EXTI_REGISTERS_H_

namespace EXTI_MDG
{

  typedef uint32_t EXTIRegisterType;

  namespace BaseRegisters
  {

    constexpr EXTIRegisterType EXTIBase = 0x40013C00U; //External interrupt/event      controller

  } //End BaseRegisters

  namespace IMR //Interrupt mask register (EXTI_IMR)
  {

    constexpr EXTIRegisterType registerOffset = 0x0U; //Register Offset Value
    constexpr EXTIRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr EXTIRegisterType MR0 = Util::Bits::BIT0; //Interrupt Mask on line 0
    constexpr EXTIRegisterType MR1 = Util::Bits::BIT1; //Interrupt Mask on line 1
    constexpr EXTIRegisterType MR2 = Util::Bits::BIT2; //Interrupt Mask on line 2
    constexpr EXTIRegisterType MR3 = Util::Bits::BIT3; //Interrupt Mask on line 3
    constexpr EXTIRegisterType MR4 = Util::Bits::BIT4; //Interrupt Mask on line 4
    constexpr EXTIRegisterType MR5 = Util::Bits::BIT5; //Interrupt Mask on line 5
    constexpr EXTIRegisterType MR6 = Util::Bits::BIT6; //Interrupt Mask on line 6
    constexpr EXTIRegisterType MR7 = Util::Bits::BIT7; //Interrupt Mask on line 7
    constexpr EXTIRegisterType MR8 = Util::Bits::BIT8; //Interrupt Mask on line 8
    constexpr EXTIRegisterType MR9 = Util::Bits::BIT9; //Interrupt Mask on line 9
    constexpr EXTIRegisterType MR10 = Util::Bits::BIT10; //Interrupt Mask on line 10
    constexpr EXTIRegisterType MR11 = Util::Bits::BIT11; //Interrupt Mask on line 11
    constexpr EXTIRegisterType MR12 = Util::Bits::BIT12; //Interrupt Mask on line 12
    constexpr EXTIRegisterType MR13 = Util::Bits::BIT13; //Interrupt Mask on line 13
    constexpr EXTIRegisterType MR14 = Util::Bits::BIT14; //Interrupt Mask on line 14
    constexpr EXTIRegisterType MR15 = Util::Bits::BIT15; //Interrupt Mask on line 15
    constexpr EXTIRegisterType MR16 = Util::Bits::BIT16; //Interrupt Mask on line 16
    constexpr EXTIRegisterType MR17 = Util::Bits::BIT17; //Interrupt Mask on line 17
    constexpr EXTIRegisterType MR18 = Util::Bits::BIT18; //Interrupt Mask on line 18
    constexpr EXTIRegisterType MR19 = Util::Bits::BIT19; //Interrupt Mask on line 19
    constexpr EXTIRegisterType MR20 = Util::Bits::BIT20; //Interrupt Mask on line 20
    constexpr EXTIRegisterType MR21 = Util::Bits::BIT21; //Interrupt Mask on line 21
    constexpr EXTIRegisterType MR22 = Util::Bits::BIT22; //Interrupt Mask on line 22

  } //End IMR


  namespace EMR //Event mask register (EXTI_EMR)
  {

    constexpr EXTIRegisterType registerOffset = 0x4U; //Register Offset Value
    constexpr EXTIRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr EXTIRegisterType MR0 = Util::Bits::BIT0; //Event Mask on line 0
    constexpr EXTIRegisterType MR1 = Util::Bits::BIT1; //Event Mask on line 1
    constexpr EXTIRegisterType MR2 = Util::Bits::BIT2; //Event Mask on line 2
    constexpr EXTIRegisterType MR3 = Util::Bits::BIT3; //Event Mask on line 3
    constexpr EXTIRegisterType MR4 = Util::Bits::BIT4; //Event Mask on line 4
    constexpr EXTIRegisterType MR5 = Util::Bits::BIT5; //Event Mask on line 5
    constexpr EXTIRegisterType MR6 = Util::Bits::BIT6; //Event Mask on line 6
    constexpr EXTIRegisterType MR7 = Util::Bits::BIT7; //Event Mask on line 7
    constexpr EXTIRegisterType MR8 = Util::Bits::BIT8; //Event Mask on line 8
    constexpr EXTIRegisterType MR9 = Util::Bits::BIT9; //Event Mask on line 9
    constexpr EXTIRegisterType MR10 = Util::Bits::BIT10; //Event Mask on line 10
    constexpr EXTIRegisterType MR11 = Util::Bits::BIT11; //Event Mask on line 11
    constexpr EXTIRegisterType MR12 = Util::Bits::BIT12; //Event Mask on line 12
    constexpr EXTIRegisterType MR13 = Util::Bits::BIT13; //Event Mask on line 13
    constexpr EXTIRegisterType MR14 = Util::Bits::BIT14; //Event Mask on line 14
    constexpr EXTIRegisterType MR15 = Util::Bits::BIT15; //Event Mask on line 15
    constexpr EXTIRegisterType MR16 = Util::Bits::BIT16; //Event Mask on line 16
    constexpr EXTIRegisterType MR17 = Util::Bits::BIT17; //Event Mask on line 17
    constexpr EXTIRegisterType MR18 = Util::Bits::BIT18; //Event Mask on line 18
    constexpr EXTIRegisterType MR19 = Util::Bits::BIT19; //Event Mask on line 19
    constexpr EXTIRegisterType MR20 = Util::Bits::BIT20; //Event Mask on line 20
    constexpr EXTIRegisterType MR21 = Util::Bits::BIT21; //Event Mask on line 21
    constexpr EXTIRegisterType MR22 = Util::Bits::BIT22; //Event Mask on line 22

  } //End EMR


  namespace RTSR //Rising Trigger selection register (EXTI_RTSR)
  {

    constexpr EXTIRegisterType registerOffset = 0x8U; //Register Offset Value
    constexpr EXTIRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr EXTIRegisterType TR0 = Util::Bits::BIT0; //Rising trigger event configuration of line 0
    constexpr EXTIRegisterType TR1 = Util::Bits::BIT1; //Rising trigger event configuration of line 1
    constexpr EXTIRegisterType TR2 = Util::Bits::BIT2; //Rising trigger event configuration of line 2
    constexpr EXTIRegisterType TR3 = Util::Bits::BIT3; //Rising trigger event configuration of line 3
    constexpr EXTIRegisterType TR4 = Util::Bits::BIT4; //Rising trigger event configuration of line 4
    constexpr EXTIRegisterType TR5 = Util::Bits::BIT5; //Rising trigger event configuration of line 5
    constexpr EXTIRegisterType TR6 = Util::Bits::BIT6; //Rising trigger event configuration of line 6
    constexpr EXTIRegisterType TR7 = Util::Bits::BIT7; //Rising trigger event configuration of line 7
    constexpr EXTIRegisterType TR8 = Util::Bits::BIT8; //Rising trigger event configuration of line 8
    constexpr EXTIRegisterType TR9 = Util::Bits::BIT9; //Rising trigger event configuration of line 9
    constexpr EXTIRegisterType TR10 = Util::Bits::BIT10; //Rising trigger event configuration of line 10
    constexpr EXTIRegisterType TR11 = Util::Bits::BIT11; //Rising trigger event configuration of line 11
    constexpr EXTIRegisterType TR12 = Util::Bits::BIT12; //Rising trigger event configuration of line 12
    constexpr EXTIRegisterType TR13 = Util::Bits::BIT13; //Rising trigger event configuration of line 13
    constexpr EXTIRegisterType TR14 = Util::Bits::BIT14; //Rising trigger event configuration of line 14
    constexpr EXTIRegisterType TR15 = Util::Bits::BIT15; //Rising trigger event configuration of line 15
    constexpr EXTIRegisterType TR16 = Util::Bits::BIT16; //Rising trigger event configuration of line 16
    constexpr EXTIRegisterType TR17 = Util::Bits::BIT17; //Rising trigger event configuration of line 17
    constexpr EXTIRegisterType TR18 = Util::Bits::BIT18; //Rising trigger event configuration of line 18
    constexpr EXTIRegisterType TR19 = Util::Bits::BIT19; //Rising trigger event configuration of line 19
    constexpr EXTIRegisterType TR20 = Util::Bits::BIT20; //Rising trigger event configuration of line 20
    constexpr EXTIRegisterType TR21 = Util::Bits::BIT21; //Rising trigger event configuration of line 21
    constexpr EXTIRegisterType TR22 = Util::Bits::BIT22; //Rising trigger event configuration of line 22

  } //End RTSR


  namespace FTSR //Falling Trigger selection register (EXTI_FTSR)
  {

    constexpr EXTIRegisterType registerOffset = 0xCU; //Register Offset Value
    constexpr EXTIRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr EXTIRegisterType TR0 = Util::Bits::BIT0; //Falling trigger event configuration of line 0
    constexpr EXTIRegisterType TR1 = Util::Bits::BIT1; //Falling trigger event configuration of line 1
    constexpr EXTIRegisterType TR2 = Util::Bits::BIT2; //Falling trigger event configuration of line 2
    constexpr EXTIRegisterType TR3 = Util::Bits::BIT3; //Falling trigger event configuration of line 3
    constexpr EXTIRegisterType TR4 = Util::Bits::BIT4; //Falling trigger event configuration of line 4
    constexpr EXTIRegisterType TR5 = Util::Bits::BIT5; //Falling trigger event configuration of line 5
    constexpr EXTIRegisterType TR6 = Util::Bits::BIT6; //Falling trigger event configuration of line 6
    constexpr EXTIRegisterType TR7 = Util::Bits::BIT7; //Falling trigger event configuration of line 7
    constexpr EXTIRegisterType TR8 = Util::Bits::BIT8; //Falling trigger event configuration of line 8
    constexpr EXTIRegisterType TR9 = Util::Bits::BIT9; //Falling trigger event configuration of line 9
    constexpr EXTIRegisterType TR10 = Util::Bits::BIT10; //Falling trigger event configuration of line 10
    constexpr EXTIRegisterType TR11 = Util::Bits::BIT11; //Falling trigger event configuration of line 11
    constexpr EXTIRegisterType TR12 = Util::Bits::BIT12; //Falling trigger event configuration of line 12
    constexpr EXTIRegisterType TR13 = Util::Bits::BIT13; //Falling trigger event configuration of line 13
    constexpr EXTIRegisterType TR14 = Util::Bits::BIT14; //Falling trigger event configuration of line 14
    constexpr EXTIRegisterType TR15 = Util::Bits::BIT15; //Falling trigger event configuration of line 15
    constexpr EXTIRegisterType TR16 = Util::Bits::BIT16; //Falling trigger event configuration of line 16
    constexpr EXTIRegisterType TR17 = Util::Bits::BIT17; //Falling trigger event configuration of line 17
    constexpr EXTIRegisterType TR18 = Util::Bits::BIT18; //Falling trigger event configuration of line 18
    constexpr EXTIRegisterType TR19 = Util::Bits::BIT19; //Falling trigger event configuration of line 19
    constexpr EXTIRegisterType TR20 = Util::Bits::BIT20; //Falling trigger event configuration of line 20
    constexpr EXTIRegisterType TR21 = Util::Bits::BIT21; //Falling trigger event configuration of line 21
    constexpr EXTIRegisterType TR22 = Util::Bits::BIT22; //Falling trigger event configuration of line 22

  } //End FTSR


  namespace SWIER //Software interrupt event register (EXTI_SWIER)
  {

    constexpr EXTIRegisterType registerOffset = 0x10U; //Register Offset Value
    constexpr EXTIRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr EXTIRegisterType SWIER0 = Util::Bits::BIT0; //Software Interrupt on line 0
    constexpr EXTIRegisterType SWIER1 = Util::Bits::BIT1; //Software Interrupt on line 1
    constexpr EXTIRegisterType SWIER2 = Util::Bits::BIT2; //Software Interrupt on line 2
    constexpr EXTIRegisterType SWIER3 = Util::Bits::BIT3; //Software Interrupt on line 3
    constexpr EXTIRegisterType SWIER4 = Util::Bits::BIT4; //Software Interrupt on line 4
    constexpr EXTIRegisterType SWIER5 = Util::Bits::BIT5; //Software Interrupt on line 5
    constexpr EXTIRegisterType SWIER6 = Util::Bits::BIT6; //Software Interrupt on line 6
    constexpr EXTIRegisterType SWIER7 = Util::Bits::BIT7; //Software Interrupt on line 7
    constexpr EXTIRegisterType SWIER8 = Util::Bits::BIT8; //Software Interrupt on line 8
    constexpr EXTIRegisterType SWIER9 = Util::Bits::BIT9; //Software Interrupt on line 9
    constexpr EXTIRegisterType SWIER10 = Util::Bits::BIT10; //Software Interrupt on line 10
    constexpr EXTIRegisterType SWIER11 = Util::Bits::BIT11; //Software Interrupt on line 11
    constexpr EXTIRegisterType SWIER12 = Util::Bits::BIT12; //Software Interrupt on line 12
    constexpr EXTIRegisterType SWIER13 = Util::Bits::BIT13; //Software Interrupt on line 13
    constexpr EXTIRegisterType SWIER14 = Util::Bits::BIT14; //Software Interrupt on line 14
    constexpr EXTIRegisterType SWIER15 = Util::Bits::BIT15; //Software Interrupt on line 15
    constexpr EXTIRegisterType SWIER16 = Util::Bits::BIT16; //Software Interrupt on line 16
    constexpr EXTIRegisterType SWIER17 = Util::Bits::BIT17; //Software Interrupt on line 17
    constexpr EXTIRegisterType SWIER18 = Util::Bits::BIT18; //Software Interrupt on line 18
    constexpr EXTIRegisterType SWIER19 = Util::Bits::BIT19; //Software Interrupt on line 19
    constexpr EXTIRegisterType SWIER20 = Util::Bits::BIT20; //Software Interrupt on line 20
    constexpr EXTIRegisterType SWIER21 = Util::Bits::BIT21; //Software Interrupt on line 21
    constexpr EXTIRegisterType SWIER22 = Util::Bits::BIT22; //Software Interrupt on line 22

  } //End SWIER


  namespace PR //Pending register (EXTI_PR)
  {

    constexpr EXTIRegisterType registerOffset = 0x14U; //Register Offset Value
    constexpr EXTIRegisterType registerReset = 0x0000U; //Register Reset Value

    constexpr EXTIRegisterType PR0 = Util::Bits::BIT0; //Pending bit 0
    constexpr EXTIRegisterType PR1 = Util::Bits::BIT1; //Pending bit 1
    constexpr EXTIRegisterType PR2 = Util::Bits::BIT2; //Pending bit 2
    constexpr EXTIRegisterType PR3 = Util::Bits::BIT3; //Pending bit 3
    constexpr EXTIRegisterType PR4 = Util::Bits::BIT4; //Pending bit 4
    constexpr EXTIRegisterType PR5 = Util::Bits::BIT5; //Pending bit 5
    constexpr EXTIRegisterType PR6 = Util::Bits::BIT6; //Pending bit 6
    constexpr EXTIRegisterType PR7 = Util::Bits::BIT7; //Pending bit 7
    constexpr EXTIRegisterType PR8 = Util::Bits::BIT8; //Pending bit 8
    constexpr EXTIRegisterType PR9 = Util::Bits::BIT9; //Pending bit 9
    constexpr EXTIRegisterType PR10 = Util::Bits::BIT10; //Pending bit 10
    constexpr EXTIRegisterType PR11 = Util::Bits::BIT11; //Pending bit 11
    constexpr EXTIRegisterType PR12 = Util::Bits::BIT12; //Pending bit 12
    constexpr EXTIRegisterType PR13 = Util::Bits::BIT13; //Pending bit 13
    constexpr EXTIRegisterType PR14 = Util::Bits::BIT14; //Pending bit 14
    constexpr EXTIRegisterType PR15 = Util::Bits::BIT15; //Pending bit 15
    constexpr EXTIRegisterType PR16 = Util::Bits::BIT16; //Pending bit 16
    constexpr EXTIRegisterType PR17 = Util::Bits::BIT17; //Pending bit 17
    constexpr EXTIRegisterType PR18 = Util::Bits::BIT18; //Pending bit 18
    constexpr EXTIRegisterType PR19 = Util::Bits::BIT19; //Pending bit 19
    constexpr EXTIRegisterType PR20 = Util::Bits::BIT20; //Pending bit 20
    constexpr EXTIRegisterType PR21 = Util::Bits::BIT21; //Pending bit 21
    constexpr EXTIRegisterType PR22 = Util::Bits::BIT22; //Pending bit 22

  } //End PR


}



#endif /* REGISTERS_EXTI_REGISTERS_H_ */
