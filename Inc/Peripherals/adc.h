#ifndef ADC_H_
#define ADC_H_

#include "../Registers/adc_registers.h"
#include "../Utility/reg_access.h"
#include "../Utility/reg_access_dynamic.h"
#include "gpio_config.h"
#include "../Registers/rcc_registers.h"
#include "../Utility/interrupts.h"
#include "../Utility/interruptable.h"
//#include "misc.h"
#include "../CMSIS/Device/ST/STM32F4xx/Include/stm32f4xx.h"
#include "../Utility/util.h"
#include <stdint.h>

#ifdef __STM32F0
  #include "stm32f0xx.h"
#endif


/**
*
*ADC Channels
*Channel  ADC1  ADC2  ADC3
*Chan0    PA0   PA0   PA0
*CHAN1    PA1   PA1   PA1
*CHAN2    PA2   PA2   PA2
*CHAN3    PA3   PA3   PA3
*CHAN4    PA4   PA4   -
*CHAN5    PA5   PA5   -
*CHAN6    PA6   PA6   -
*CHAN7    PA7   PA7   -
*CHAN8    PB0   PB0   -
*CHAN9    PB1   PB1   -
*CHAN10   PC0   PC0   PC0
*CHAN11   PC1   PC1   PC1
*CHAN12   PC2   PC2   PC2
*CHAN13   PC3   PC3   PC3
*CHAN14   PC4   PC4   -
*CHAN15   PC5   PC5   -
*CHAN16   TEMP
*CHAN17   ADC Vref
*
**/


extern interruptable * handlerPointers[sizeof(peripheralInterrupts)];
class ADC_INT{

public:
  ADC_INT(ADC_MDG::ADCRegisterType baseRegister);
  void setupChannel(ADC_MDG::ADCRegisterType channelNumber, uint8_t sequenceNumber);
  uint8_t readValue();

  

  //interrupt functions
  void handleInterrupts(int interruptType);


private:
  
  //interrupt function
  void registerInterrupt();
  void initializePin();
  void Delay(uint32_t nCount);
  uint32_t data;

  //registers
  ADC_MDG::ADCRegisterType registerStatus;
  ADC_MDG::ADCRegisterType registerControl1;
  ADC_MDG::ADCRegisterType registerControl2;
  ADC_MDG::ADCRegisterType registerSampleTime1;
  ADC_MDG::ADCRegisterType registerSampleTime2;
  ADC_MDG::ADCRegisterType registerInjectedChan1;
  ADC_MDG::ADCRegisterType registerInjectedChan2;
  ADC_MDG::ADCRegisterType registerInjectedChan3;
  ADC_MDG::ADCRegisterType registerInjectedChan4;
  ADC_MDG::ADCRegisterType registerAWDGHigh;
  ADC_MDG::ADCRegisterType registerAWDLow;
  ADC_MDG::ADCRegisterType registerRegSequence1;
  ADC_MDG::ADCRegisterType registerRegSequence2;
  ADC_MDG::ADCRegisterType registerRegSequence3;
  ADC_MDG::ADCRegisterType registerInjSequence;
  ADC_MDG::ADCRegisterType registerInjData1;
  ADC_MDG::ADCRegisterType registerInjData2;
  ADC_MDG::ADCRegisterType registerInjData3;
  ADC_MDG::ADCRegisterType registerInjData4;
  ADC_MDG::ADCRegisterType registerData;
  ADC_MDG::ADCRegisterType registerCommonStatus;
  ADC_MDG::ADCRegisterType registerCommonControl;
  ADC_MDG::ADCRegisterType registerCommonData;



};


#endif /* ADC_H_ */
