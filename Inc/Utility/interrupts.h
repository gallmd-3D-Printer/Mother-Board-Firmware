#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "interruptable.h"
//#include "stm32f4xx.h"



enum peripheralInterrupts
{
  I2C1_IDX,
  I2C2_IDX,
  I2C3_IDX,
  USART1_IDX,
  USART2_IDX,
  USART3_IDX,
  USART4_IDX,
  USART5_IDX,
  USART6_IDX,
  USART7_IDX,
  USART8_IDX,
  SPI1_IDX,
  SPI2_IDX,
  SPI3_IDX,
  EXTI0_IDX,
  EXTI1_IDX,
  EXTI2_IDX,
  EXTI3_IDX,
  EXTI4_IDX,
  EXTI9_5_IDX,
  EXTI15_10_IDX

 };

 enum interruptSource
 {

  I2C_EV,
  I2C_ER

 };



 #endif
