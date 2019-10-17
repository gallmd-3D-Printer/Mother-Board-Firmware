/* Includes */
#include "stm32f4xx.h"
#include "gpio.h"
#include "usart.h"
#include "circular_buffer.h"

/* Private function prototypes */
void Delay(__IO uint32_t nCount);


int main()
{

  util::circular_buffer<uint8_t> usartTXBuf(50);
  util::circular_buffer<uint8_t> *txPtr;
  txPtr = &usartTXBuf;
  

  USART::Usart usbUsart(USART::BaseRegisters::USART3Base, txPtr);
  uint8_t data = 0;


//PC14
  const GPIO<GPIOxBaseRegisters::GPIO_C,
              PINS::PIN4,
              GpioModes::Output,
              OutputTypes::PushPull,
              OutputSpeed::MediumSpeed,
              PullUpPullDown::NoPullUpPullDown,
              AlternateFunction::AF0>statusLED;

 const GPIO<GPIOxBaseRegisters::GPIO_D,
              PINS::PIN10,
              GpioModes::Output,
              OutputTypes::PushPull,
              OutputSpeed::MediumSpeed,
              PullUpPullDown::NoPullUpPullDown,
              AlternateFunction::AF0>statusLED1;

 const GPIO<GPIOxBaseRegisters::GPIO_D,
              PINS::PIN11,
              GpioModes::Output,
              OutputTypes::PushPull,
              OutputSpeed::MediumSpeed,
              PullUpPullDown::NoPullUpPullDown,
              AlternateFunction::AF0>statusLED2;

 const GPIO<GPIOxBaseRegisters::GPIO_D,
              PINS::PIN12,
              GpioModes::Output,
              OutputTypes::PushPull,
              OutputSpeed::MediumSpeed,
              PullUpPullDown::NoPullUpPullDown,
              AlternateFunction::AF0>statusLED3;
                        
 const GPIO<GPIOxBaseRegisters::GPIO_D,
              PINS::PIN13,
              GpioModes::Output,
              OutputTypes::PushPull,
              OutputSpeed::MediumSpeed,
              PullUpPullDown::NoPullUpPullDown,
              AlternateFunction::AF0>statusLED4;

 const GPIO<GPIOxBaseRegisters::GPIO_D,
              PINS::PIN14,
              GpioModes::Output,
              OutputTypes::PushPull,
              OutputSpeed::MediumSpeed,
              PullUpPullDown::NoPullUpPullDown,
              AlternateFunction::AF0>statusLED5;

 const GPIO<GPIOxBaseRegisters::GPIO_D,
              PINS::PIN15,
              GpioModes::Output,
              OutputTypes::PushPull,
              OutputSpeed::MediumSpeed,
              PullUpPullDown::NoPullUpPullDown,
              AlternateFunction::AF0>statusLED6;

     __enable_irq();
  while(1)
  {
    statusLED.toggle();
        statusLED1.toggle();

    statusLED2.toggle();
    statusLED3.toggle();
    statusLED4.toggle();
    statusLED5.toggle();
    statusLED6.toggle();

    if(!usartTXBuf.empty()){
  
      data = usartTXBuf.get();
      usbUsart.sendBytes(data);
    }

    Delay(0xFFFF);



  }



}


void Delay(__IO uint32_t nCount)
{
  while(nCount--)
  {
  }
}