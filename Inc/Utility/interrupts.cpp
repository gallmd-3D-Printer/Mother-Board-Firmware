#include "interrupts.h"

//array of pointers to objects that system interrupt functions will call
interruptable * handlerPointers[sizeof(peripheralInterrupts)];


//system interrupt calls
extern "C"{



   void I2C1_EV_IRQHandler(void){

    handlerPointers[I2C1_IDX]->handleInterrupts(I2C_EV);
  
  }

   void I2C1_ER_IRQHandler(void)
  {
    

    handlerPointers[I2C1_IDX]->handleInterrupts(I2C_ER);

  }

  
   void I2C2_EV_IRQHandler(void){

    handlerPointers[I2C2_IDX]->handleInterrupts(I2C_EV);
  
  }

   void I2C2_ER_IRQHandler(void)
  {
    

    handlerPointers[I2C2_IDX]->handleInterrupts(I2C_ER);

  }

  
   void I2C3_EV_IRQHandler(void){

    handlerPointers[I2C3_IDX]->handleInterrupts(I2C_EV);
  
  }

   void I2C3_ER_IRQHandler(void)
  {
    

    handlerPointers[I2C3_IDX]->handleInterrupts(I2C_ER);

  }

  void USART1_IRQHandler(void)
  {

    handlerPointers[USART1_IDX]->handleInterrupts(0);

  }

  void USART2_IRQHandler(void)
  {

    handlerPointers[USART2_IDX]->handleInterrupts(0);

  }

    void USART3_IRQHandler(void)
  {

    handlerPointers[USART3_IDX]->handleInterrupts(0);

  }

  void SPI1_IRQHandler(void)
  {

    handlerPointers[SPI1_IDX]->handleInterrupts(0);

  }

    void SPI2_IRQHandler(void)
  {

    handlerPointers[SPI2_IDX]->handleInterrupts(0);

  }

    void SPI3_IRQHandler(void)
  {

    handlerPointers[SPI3_IDX]->handleInterrupts(0);

  }

    void EXTI0_IRQHandler(void)
    {

    	handlerPointers[EXTI0_IDX]->handleInterrupts(0);

    }

    void EXTI1_IRQHandler(void){

    	handlerPointers[EXTI1_IDX]->handleInterrupts(0);
    }

    void EXTI2_IRQHandler(void){

    	handlerPointers[EXTI2_IDX]->handleInterrupts(0);

    }

    void EXTI3_IRQHandler(void){

    	handlerPointers[EXTI3_IDX]->handleInterrupts(0);

    }

    void EXTI4_IRQHandler(void){

    	handlerPointers[EXTI4_IDX]->handleInterrupts(0);

    }

    void EXTI9_5_IRQHandler(void){

    	handlerPointers[EXTI9_5_IDX]->handleInterrupts(0);

    }

    void EXTI15_10_IRQHandler(void){

    	handlerPointers[EXTI15_10_IDX]->handleInterrupts(0);

    }



}

