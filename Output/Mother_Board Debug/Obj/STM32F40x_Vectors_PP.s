# 1 "/home/matt/Development/code/st/embedded studio/Mother_Board/STM32F4xx/Source/STM32F40x_Vectors.s"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/home/matt/Development/code/st/embedded studio/Mother_Board/STM32F4xx/Source/STM32F40x_Vectors.s"
# 22 "/home/matt/Development/code/st/embedded studio/Mother_Board/STM32F4xx/Source/STM32F40x_Vectors.s"
  .syntax unified
  .code 16

  .section .init, "ax"
  .align 0





  .thumb_func
  .weak NMI_Handler
NMI_Handler:
  b .

  .thumb_func
  .weak HardFault_Handler
HardFault_Handler:
  b .

  .thumb_func
  .weak SVC_Handler
SVC_Handler:
  b .

  .thumb_func
  .weak PendSV_Handler
PendSV_Handler:
  b .

  .thumb_func
  .weak SysTick_Handler
SysTick_Handler:
  b .

  .thumb_func
Dummy_Handler:
  b .
# 302 "/home/matt/Development/code/st/embedded studio/Mother_Board/STM32F4xx/Source/STM32F40x_Vectors.s"
  .thumb_func
  .weak WWDG_IRQHandler
WWDG_IRQHandler:
  b .

  .thumb_func
  .weak PVD_IRQHandler
PVD_IRQHandler:
  b .

  .thumb_func
  .weak TAMP_STAMP_IRQHandler
TAMP_STAMP_IRQHandler:
  b .

  .thumb_func
  .weak RTC_WKUP_IRQHandler
RTC_WKUP_IRQHandler:
  b .

  .thumb_func
  .weak RCC_IRQHandler
RCC_IRQHandler:
  b .

  .thumb_func
  .weak EXTI0_IRQHandler
EXTI0_IRQHandler:
  b .

  .thumb_func
  .weak EXTI1_IRQHandler
EXTI1_IRQHandler:
  b .

  .thumb_func
  .weak EXTI2_IRQHandler
EXTI2_IRQHandler:
  b .

  .thumb_func
  .weak EXTI3_IRQHandler
EXTI3_IRQHandler:
  b .

  .thumb_func
  .weak EXTI4_IRQHandler
EXTI4_IRQHandler:
  b .

  .thumb_func
  .weak DMA1_Stream0_IRQHandler
DMA1_Stream0_IRQHandler:
  b .

  .thumb_func
  .weak DMA1_Stream1_IRQHandler
DMA1_Stream1_IRQHandler:
  b .

  .thumb_func
  .weak DMA1_Stream2_IRQHandler
DMA1_Stream2_IRQHandler:
  b .

  .thumb_func
  .weak DMA1_Stream3_IRQHandler
DMA1_Stream3_IRQHandler:
  b .

  .thumb_func
  .weak DMA1_Stream4_IRQHandler
DMA1_Stream4_IRQHandler:
  b .

  .thumb_func
  .weak DMA1_Stream5_IRQHandler
DMA1_Stream5_IRQHandler:
  b .

  .thumb_func
  .weak DMA1_Stream6_IRQHandler
DMA1_Stream6_IRQHandler:
  b .

  .thumb_func
  .weak ADC_IRQHandler
ADC_IRQHandler:
  b .

  .thumb_func
  .weak CAN1_TX_IRQHandler
CAN1_TX_IRQHandler:
  b .

  .thumb_func
  .weak CAN1_RX0_IRQHandler
CAN1_RX0_IRQHandler:
  b .

  .thumb_func
  .weak CAN1_RX1_IRQHandler
CAN1_RX1_IRQHandler:
  b .

  .thumb_func
  .weak CAN1_SCE_IRQHandler
CAN1_SCE_IRQHandler:
  b .

  .thumb_func
  .weak EXTI9_5_IRQHandler
EXTI9_5_IRQHandler:
  b .

  .thumb_func
  .weak TIM1_BRK_TIM9_IRQHandler
TIM1_BRK_TIM9_IRQHandler:
  b .

  .thumb_func
  .weak TIM1_UP_TIM10_IRQHandler
TIM1_UP_TIM10_IRQHandler:
  b .

  .thumb_func
  .weak TIM1_TRG_COM_TIM11_IRQHandler
TIM1_TRG_COM_TIM11_IRQHandler:
  b .

  .thumb_func
  .weak TIM1_CC_IRQHandler
TIM1_CC_IRQHandler:
  b .

  .thumb_func
  .weak TIM2_IRQHandler
TIM2_IRQHandler:
  b .

  .thumb_func
  .weak TIM3_IRQHandler
TIM3_IRQHandler:
  b .

  .thumb_func
  .weak TIM4_IRQHandler
TIM4_IRQHandler:
  b .

  .thumb_func
  .weak I2C1_EV_IRQHandler
I2C1_EV_IRQHandler:
  b .

  .thumb_func
  .weak I2C1_ER_IRQHandler
I2C1_ER_IRQHandler:
  b .

  .thumb_func
  .weak I2C2_EV_IRQHandler
I2C2_EV_IRQHandler:
  b .

  .thumb_func
  .weak I2C2_ER_IRQHandler
I2C2_ER_IRQHandler:
  b .

  .thumb_func
  .weak SPI1_IRQHandler
SPI1_IRQHandler:
  b .

  .thumb_func
  .weak SPI2_IRQHandler
SPI2_IRQHandler:
  b .

  .thumb_func
  .weak USART1_IRQHandler
USART1_IRQHandler:
  b .

  .thumb_func
  .weak USART2_IRQHandler
USART2_IRQHandler:
  b .

  .thumb_func
  .weak USART3_IRQHandler
USART3_IRQHandler:
  b .

  .thumb_func
  .weak EXTI15_10_IRQHandler
EXTI15_10_IRQHandler:
  b .

  .thumb_func
  .weak RTC_Alarm_IRQHandler
RTC_Alarm_IRQHandler:
  b .

  .thumb_func
  .weak OTG_FS_WKUP_IRQHandler
OTG_FS_WKUP_IRQHandler:
  b .

  .thumb_func
  .weak TIM8_BRK_TIM12_IRQHandler
TIM8_BRK_TIM12_IRQHandler:
  b .

  .thumb_func
  .weak TIM8_UP_TIM13_IRQHandler
TIM8_UP_TIM13_IRQHandler:
  b .

  .thumb_func
  .weak TIM8_TRG_COM_TIM14_IRQHandler
TIM8_TRG_COM_TIM14_IRQHandler:
  b .

  .thumb_func
  .weak TIM8_CC_IRQHandler
TIM8_CC_IRQHandler:
  b .

  .thumb_func
  .weak DMA1_Stream7_IRQHandler
DMA1_Stream7_IRQHandler:
  b .

  .thumb_func
  .weak FSMC_IRQHandler
FSMC_IRQHandler:
  b .

  .thumb_func
  .weak SDIO_IRQHandler
SDIO_IRQHandler:
  b .

  .thumb_func
  .weak TIM5_IRQHandler
TIM5_IRQHandler:
  b .

  .thumb_func
  .weak SPI3_IRQHandler
SPI3_IRQHandler:
  b .

  .thumb_func
  .weak UART4_IRQHandler
UART4_IRQHandler:
  b .

  .thumb_func
  .weak UART5_IRQHandler
UART5_IRQHandler:
  b .

  .thumb_func
  .weak TIM6_DAC_IRQHandler
TIM6_DAC_IRQHandler:
  b .

  .thumb_func
  .weak TIM7_IRQHandler
TIM7_IRQHandler:
  b .

  .thumb_func
  .weak DMA2_Stream0_IRQHandler
DMA2_Stream0_IRQHandler:
  b .

  .thumb_func
  .weak DMA2_Stream1_IRQHandler
DMA2_Stream1_IRQHandler:
  b .

  .thumb_func
  .weak DMA2_Stream2_IRQHandler
DMA2_Stream2_IRQHandler:
  b .

  .thumb_func
  .weak DMA2_Stream3_IRQHandler
DMA2_Stream3_IRQHandler:
  b .

  .thumb_func
  .weak DMA2_Stream4_IRQHandler
DMA2_Stream4_IRQHandler:
  b .

  .thumb_func
  .weak ETH_IRQHandler
ETH_IRQHandler:
  b .

  .thumb_func
  .weak ETH_WKUP_IRQHandler
ETH_WKUP_IRQHandler:
  b .

  .thumb_func
  .weak CAN2_TX_IRQHandler
CAN2_TX_IRQHandler:
  b .

  .thumb_func
  .weak CAN2_RX0_IRQHandler
CAN2_RX0_IRQHandler:
  b .

  .thumb_func
  .weak CAN2_RX1_IRQHandler
CAN2_RX1_IRQHandler:
  b .

  .thumb_func
  .weak CAN2_SCE_IRQHandler
CAN2_SCE_IRQHandler:
  b .

  .thumb_func
  .weak OTG_FS_IRQHandler
OTG_FS_IRQHandler:
  b .

  .thumb_func
  .weak DMA2_Stream5_IRQHandler
DMA2_Stream5_IRQHandler:
  b .

  .thumb_func
  .weak DMA2_Stream6_IRQHandler
DMA2_Stream6_IRQHandler:
  b .

  .thumb_func
  .weak DMA2_Stream7_IRQHandler
DMA2_Stream7_IRQHandler:
  b .

  .thumb_func
  .weak USART6_IRQHandler
USART6_IRQHandler:
  b .

  .thumb_func
  .weak I2C3_EV_IRQHandler
I2C3_EV_IRQHandler:
  b .

  .thumb_func
  .weak I2C3_ER_IRQHandler
I2C3_ER_IRQHandler:
  b .

  .thumb_func
  .weak OTG_HS_EP1_OUT_IRQHandler
OTG_HS_EP1_OUT_IRQHandler:
  b .

  .thumb_func
  .weak OTG_HS_EP1_IN_IRQHandler
OTG_HS_EP1_IN_IRQHandler:
  b .

  .thumb_func
  .weak OTG_HS_WKUP_IRQHandler
OTG_HS_WKUP_IRQHandler:
  b .

  .thumb_func
  .weak OTG_HS_IRQHandler
OTG_HS_IRQHandler:
  b .

  .thumb_func
  .weak DCMI_IRQHandler
DCMI_IRQHandler:
  b .

  .thumb_func
  .weak FPU_IRQHandler
FPU_IRQHandler:
  b .







  .section .vectors, "ax"
  .align 0
  .global _vectors
  .extern __stack_end__
  .extern Reset_Handler

_vectors:
  .word __stack_end__
  .word Reset_Handler
  .word NMI_Handler
  .word HardFault_Handler
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word SVC_Handler
  .word 0
  .word 0
  .word PendSV_Handler
  .word SysTick_Handler
  .word WWDG_IRQHandler
  .word PVD_IRQHandler
  .word TAMP_STAMP_IRQHandler
  .word RTC_WKUP_IRQHandler
  .word Dummy_Handler
  .word RCC_IRQHandler
  .word EXTI0_IRQHandler
  .word EXTI1_IRQHandler
  .word EXTI2_IRQHandler
  .word EXTI3_IRQHandler
  .word EXTI4_IRQHandler
  .word DMA1_Stream0_IRQHandler
  .word DMA1_Stream1_IRQHandler
  .word DMA1_Stream2_IRQHandler
  .word DMA1_Stream3_IRQHandler
  .word DMA1_Stream4_IRQHandler
  .word DMA1_Stream5_IRQHandler
  .word DMA1_Stream6_IRQHandler
  .word ADC_IRQHandler
  .word CAN1_TX_IRQHandler
  .word CAN1_RX0_IRQHandler
  .word CAN1_RX1_IRQHandler
  .word CAN1_SCE_IRQHandler
  .word EXTI9_5_IRQHandler
  .word TIM1_BRK_TIM9_IRQHandler
  .word TIM1_UP_TIM10_IRQHandler
  .word TIM1_TRG_COM_TIM11_IRQHandler
  .word TIM1_CC_IRQHandler
  .word TIM2_IRQHandler
  .word TIM3_IRQHandler
  .word TIM4_IRQHandler
  .word I2C1_EV_IRQHandler
  .word I2C1_ER_IRQHandler
  .word I2C2_EV_IRQHandler
  .word I2C2_ER_IRQHandler
  .word SPI1_IRQHandler
  .word SPI2_IRQHandler
  .word USART1_IRQHandler
  .word USART2_IRQHandler
  .word USART3_IRQHandler
  .word EXTI15_10_IRQHandler
  .word RTC_Alarm_IRQHandler
  .word OTG_FS_WKUP_IRQHandler
  .word TIM8_BRK_TIM12_IRQHandler
  .word TIM8_UP_TIM13_IRQHandler
  .word TIM8_TRG_COM_TIM14_IRQHandler
  .word TIM8_CC_IRQHandler
  .word DMA1_Stream7_IRQHandler
  .word FSMC_IRQHandler
  .word SDIO_IRQHandler
  .word TIM5_IRQHandler
  .word SPI3_IRQHandler
  .word UART4_IRQHandler
  .word UART5_IRQHandler
  .word TIM6_DAC_IRQHandler
  .word TIM7_IRQHandler
  .word DMA2_Stream0_IRQHandler
  .word DMA2_Stream1_IRQHandler
  .word DMA2_Stream2_IRQHandler
  .word DMA2_Stream3_IRQHandler
  .word DMA2_Stream4_IRQHandler
  .word ETH_IRQHandler
  .word ETH_WKUP_IRQHandler
  .word CAN2_TX_IRQHandler
  .word CAN2_RX0_IRQHandler
  .word CAN2_RX1_IRQHandler
  .word CAN2_SCE_IRQHandler
  .word OTG_FS_IRQHandler
  .word DMA2_Stream5_IRQHandler
  .word DMA2_Stream6_IRQHandler
  .word DMA2_Stream7_IRQHandler
  .word USART6_IRQHandler
  .word I2C3_EV_IRQHandler
  .word I2C3_ER_IRQHandler
  .word OTG_HS_EP1_OUT_IRQHandler
  .word OTG_HS_EP1_IN_IRQHandler
  .word OTG_HS_WKUP_IRQHandler
  .word OTG_HS_IRQHandler
  .word DCMI_IRQHandler
  .word Dummy_Handler
  .word Dummy_Handler
  .word FPU_IRQHandler
_vectors_end:
