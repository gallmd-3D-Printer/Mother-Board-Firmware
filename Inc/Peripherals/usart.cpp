#include "usart.h"



int USART::Usart::init()
{

  //Setup Peripheral clock and pins
  if(Usart::baseRegister == USART::BaseRegisters::USART1Base)
  {
      //enable clock
      dynamic_access<rcc::RCCRegisterType, rcc::RCCRegisterType>::reg_or(rcc::BaseRegisters::RccBaseRegister + rcc::RccAPB2EnableRegister::RegisterOffset,rcc::RccAPB2EnableRegister::USART1Enable);
      USART::Usart::TXPin = PINS::PIN9;
      USART::Usart::RXPin = PINS::PIN10;
      USART::Usart::TXGPIOBank = GPIOxBaseRegisters::GPIO_A;
      USART::Usart::RXGPIOBank = GPIOxBaseRegisters::GPIO_A;

      USART::Usart::pinAF = AlternateFunction::AF7;
  }
    if(Usart::baseRegister == USART::BaseRegisters::USART2Base)
  {
      //enable clock
      dynamic_access<rcc::RCCRegisterType, rcc::RCCRegisterType>::reg_or(rcc::BaseRegisters::RccBaseRegister + rcc::RccAPB1EnableRegister::RegisterOffset,rcc::RccAPB1EnableRegister::USART3Enable);
      USART::Usart::TXPin = PINS::PIN5;
      USART::Usart::RXPin = PINS::PIN6;
      USART::Usart::TXGPIOBank = GPIOxBaseRegisters::GPIO_D;
      USART::Usart::RXGPIOBank = GPIOxBaseRegisters::GPIO_D;

      USART::Usart::pinAF = AlternateFunction::AF7;
  }
    if(Usart::baseRegister == USART::BaseRegisters::USART3Base)
  {
      //enable clock
      dynamic_access<rcc::RCCRegisterType, rcc::RCCRegisterType>::reg_or(rcc::BaseRegisters::RccBaseRegister + rcc::RccAPB1EnableRegister::RegisterOffset,rcc::RccAPB1EnableRegister::USART3Enable);

      USART::Usart::TXPin = PINS::PIN10;
      USART::Usart::RXPin = PINS::PIN11;
      USART::Usart::TXGPIOBank = GPIOxBaseRegisters::GPIO_B;
      USART::Usart::RXGPIOBank = GPIOxBaseRegisters::GPIO_B;

      USART::Usart::pinAF = AlternateFunction::AF7;
  }
    if(Usart::baseRegister == USART::BaseRegisters::USART4Base)
  {
      //enable clock
      dynamic_access<rcc::RCCRegisterType, rcc::RCCRegisterType>::reg_or(rcc::RccAPB1EnableRegister::RegisterOffset,rcc::RccAPB1EnableRegister::UART4Enable);
      USART::Usart::TXPin = PINS::PIN10;
      USART::Usart::RXPin = PINS::PIN11;
      USART::Usart::TXGPIOBank = GPIOxBaseRegisters::GPIO_C;
      USART::Usart::RXGPIOBank = GPIOxBaseRegisters::GPIO_C;

      USART::Usart::pinAF = AlternateFunction::AF8;
  }
    if(Usart::baseRegister == USART::BaseRegisters::USART5Base)
  {
      //enable clock
      dynamic_access<rcc::RCCRegisterType, rcc::RCCRegisterType>::reg_or(rcc::RccAPB1EnableRegister::RegisterOffset,rcc::RccAPB1EnableRegister::UART4Enable);
      USART::Usart::TXPin = PINS::PIN12;
      USART::Usart::RXPin = PINS::PIN2;
      USART::Usart::TXGPIOBank = GPIOxBaseRegisters::GPIO_C;
      USART::Usart::RXGPIOBank = GPIOxBaseRegisters::GPIO_D;

      USART::Usart::pinAF = AlternateFunction::AF8;
  }



  gpio_config::pinSetup(USART::Usart::TXGPIOBank, 
                        USART::Usart::TXPin, 
                        GpioModes::AlternateFunction, 
                        OutputTypes::PushPull, 
                        OutputSpeed::HighSpeed, 
                        PullUpPullDown::NoPullUpPullDown,
                        USART::Usart::pinAF);

  gpio_config::pinSetup(USART::Usart::RXGPIOBank, 
                        USART::Usart::RXPin, 
                        GpioModes::AlternateFunction, 
                        OutputTypes::PushPull, 
                        OutputSpeed::HighSpeed, 
                        PullUpPullDown::NoPullUpPullDown,
                        USART::Usart::pinAF);

  //Enable Peripheral
  dynamic_access<USART::USARTRegisterType, USART::USARTRegisterType>::reg_or(USART::Usart::controlRegister1, USART::ControlRegister1::UsartEnable);

  dynamic_access<USART::USARTRegisterType, USART::USARTRegisterType>::reg_or(USART::Usart::controlRegister1, USART::ControlRegister1::TransmitterEnable);
  dynamic_access<USART::USARTRegisterType, USART::USARTRegisterType>::reg_or(USART::Usart::controlRegister1, USART::ControlRegister1::ReceiverEnable);
  dynamic_access<USART::USARTRegisterType, USART::USARTRegisterType>::reg_or(USART::Usart::controlRegister1, USART::ControlRegister1::UsartEnable);
  dynamic_access<USART::USARTRegisterType, USART::USARTRegisterType>::reg_or(USART::Usart::controlRegister1, USART::ControlRegister1::RXNotEmptyIE);
//  dynamic_access<USART::USARTRegisterType, USART::USARTRegisterType>::reg_or(USART::Usart::controlRegister1, USART::ControlRegister1::TXCompleteIE);
//  dynamic_access<USART::USARTRegisterType, USART::USARTRegisterType>::reg_or(USART::Usart::controlRegister1, USART::ControlRegister1::TXEmptyInterruptEnable);
  


  //Value from reference manual
  //104.1875
  //example from https://sites.google.com/site/johnkneenmicrocontrollers/sci_rs232/fci_f107?tmpl=%2Fsystem%2Fapp%2Ftemplates%2Fprint%2F&showPrintDialog=1#linkbaud
  // For the STM32F107 using USART2 with a clock frequency of 36MHz (Max) to obtain a baud rate of 115.2k need:

  //BRR = fclk / (16 x Baud) = 36/(16 x 0.1152) =19.53 decimal

  //DIV_Mantissa = 19 dec = 0x13
  //DIV_Fraction = 0.53 dec = 16 x 0.53 = 8.48 ~ 8
 
  //USART_BRR = 0x138 
  //configure baud rate
  //9600 Baud at default Clock
  dynamic_access<USART::USARTRegisterType, USART::USARTRegisterType>::reg_or(USART::Usart::baudRateRegister, 0x683);

  //115.2k Baud at 37.5MHz APB1 Clock
//  dynamic_access<USART::USARTRegisterType, USART::USARTRegisterType>::reg_or(USART::Usart::baudRateRegister, 0x146);



  //enable interrupts in NVIC
//  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);               
//  NVIC_InitTypeDef NVIC_InitStructure;
//
//  NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn; //TIM4 IRQ Channel
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//Preemption Priority
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //Sub Priority
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//  NVIC_Init(&NVIC_InitStructure);

  NVIC_SetPriority(USART3_IRQn, 0);
  NVIC_EnableIRQ(USART3_IRQn);

  //reset status register
  dynamic_access<USART::USARTRegisterType, USART::USARTRegisterType>::reg_set(USART::Usart::statusRegister, USART::StatusRegister::RegisterReset);



return 0;
}

void USART::Usart::registerInterrupt()
{

    handlerPointers[USART3_IDX] = this;


}


void USART::Usart::handleInterrupts(int interruptType)
{

  USART::Usart::usartStatus = dynamic_access<USART::USARTRegisterType, USART::USARTRegisterType>::reg_get(statusRegister);
  if(usartStatus && USART::StatusRegister::RXNotEmpty){

    //Put data into rx buffer, check for line end
    uint8_t data = 0;
    data = dynamic_access<USART::USARTRegisterType, uint8_t>::reg_get(dataRegister);
    rxBuffer.put(data);
    currentMessageLength++;
    if(data == '\n'){
      Usart::hasData = true;
      messageLengths.put(currentMessageLength);
      currentMessageLength = 0;
    }

  }
//  if(usartStatus & USART::StatusRegister::TXEmpty){
//    
//    dynamic_access<USART::USARTRegisterType, uint8_t>::reg_or(dataRegister, 't');
//
//   }

}


void USART::Usart::sendBytes(uint8_t data)
{

  dynamic_access<USART::USARTRegisterType, USART::USARTRegisterType>::reg_set(USART::Usart::dataRegister, data);

}
