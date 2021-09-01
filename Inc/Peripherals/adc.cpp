#include "adc.h"



ADC_INT::ADC_INT(ADC_MDG::ADCRegisterType baseRegister)
{

  //Set register addresses based off of base register address
  ADC_INT::registerStatus = baseRegister + ADC_MDG::SR::registerOffset;
  ADC_INT::registerControl1 = baseRegister + ADC_MDG::CR1::registerOffset;
  ADC_INT::registerControl2 = baseRegister + ADC_MDG::CR2::registerOffset;
  ADC_INT::registerSampleTime1 = baseRegister + ADC_MDG::SMPR1::registerOffset;
  ADC_INT::registerSampleTime2 = baseRegister + ADC_MDG::SMPR2::registerOffset;
  ADC_INT::registerInjectedChan1 = baseRegister + ADC_MDG::JOFR1::registerOffset;
  ADC_INT::registerInjectedChan2 = baseRegister + ADC_MDG::JOFR2::registerOffset;
  ADC_INT::registerInjectedChan3 = baseRegister + ADC_MDG::JOFR3::registerOffset;
  ADC_INT::registerInjectedChan4 = baseRegister + ADC_MDG::JOFR4::registerOffset;
  ADC_INT::registerAWDGHigh = baseRegister + ADC_MDG::HTR::registerOffset;
  ADC_INT::registerAWDLow = baseRegister + ADC_MDG::LTR::registerOffset;
  ADC_INT::registerRegSequence1 = baseRegister + ADC_MDG::SQR1::registerOffset;
  ADC_INT::registerRegSequence2 = baseRegister + ADC_MDG::SQR2::registerOffset;
  ADC_INT::registerRegSequence3 = baseRegister + ADC_MDG::SQR3::registerOffset;
  ADC_INT::registerInjData1 = baseRegister + ADC_MDG::JDR1::registerOffset;
  ADC_INT::registerInjData2 = baseRegister + ADC_MDG::JDR2::registerOffset;
  ADC_INT::registerInjData3 = baseRegister + ADC_MDG::JDR3::registerOffset;
  ADC_INT::registerInjData4 = baseRegister + ADC_MDG::JDR4::registerOffset;
  ADC_INT::registerData = baseRegister + ADC_MDG::DR::registerOffset;
  ADC_INT::registerCommonStatus = baseRegister + ADC_MDG::CSR::registerOffset;
  ADC_INT::registerCommonControl = baseRegister + ADC_MDG::CCR::registerOffset;
  ADC_INT::registerCommonData = baseRegister + ADC_MDG::CDR::registerOffset;

  
    //Enable Clock
  RCC_MDG::RCCRegisterType2 APB2 = RCC_MDG::BaseRegisters::RCC_MDG + RCC_MDG::APB2ENR::registerOffset;
  RCC_MDG::RCCRegisterType2 enableBit;

  if(baseRegister == ADC_MDG::BaseRegisters::ADC1_MDG)
  {
    enableBit = RCC_MDG::APB2ENR::ADC1EN;
  }

    if(baseRegister == ADC_MDG::BaseRegisters::ADC2_MDG)
  {
    enableBit = RCC_MDG::APB2ENR::ADC2EN;
  }

    if(baseRegister == ADC_MDG::BaseRegisters::ADC3_MDG)
  {
    enableBit = RCC_MDG::APB2ENR::ADC3EN;
  }

  dynamic_access<RCC_MDG::RCCRegisterType2,RCC_MDG::RCCRegisterType2>::reg_or(APB2, enableBit);
  
  //hardcode to PA0 for now
  //enable pin
  gpio_config::pinSetup(GPIOxBaseRegisters::GPIO_A,
                        PINS::PIN0,
                        GpioModes::AnalogMode,
                        OutputTypes::OpenDrain,
                        OutputSpeed::VeryHighSpeeed,
                        PullUpPullDown::NoPullUpPullDown,
                        AlternateFunction::AF0);
  //set number of conversions
  dynamic_access<ADC_MDG::ADCRegisterType, ADC_MDG::ADCRegisterType>::reg_or(ADC_INT::registerRegSequence1, ADC_MDG::SQR1::LBits::L0);
  //set sequence of conversions
  dynamic_access<ADC_MDG::ADCRegisterType, ADC_MDG::ADCRegisterType>::reg_or(ADC_INT::registerRegSequence3, ADC_MDG::SQR3::SQ1Bits::CHANNEL0);
  //set sample time
  dynamic_access<ADC_MDG::ADCRegisterType, ADC_MDG::ADCRegisterType>::reg_or(ADC_INT::registerSampleTime2, ADC_MDG::SMPR2::SMP1Bits::CYCLES144);
  //set resolution to 8 bits (for ease of sending of I2C)
  dynamic_access<ADC_MDG::ADCRegisterType, ADC_MDG::ADCRegisterType>::reg_or(ADC_INT::registerControl1, ADC_MDG::CR1::RESBits::RES8BIT);

  

  //Enable ADC
  dynamic_access<ADC_MDG::ADCRegisterType, ADC_MDG::ADCRegisterType>::reg_or(ADC_INT::registerControl2, ADC_MDG::CR2::ADON);

}


uint8_t ADC_INT::readValue()
{
  dynamic_access<ADC_MDG::ADCRegisterType, ADC_MDG::ADCRegisterType>::reg_or(ADC_INT::registerControl2, ADC_MDG::CR2::SWSTART);
  Delay(0xFFF);
  ADC_INT::data = dynamic_access<ADC_MDG::ADCRegisterType, ADC_MDG::ADCRegisterType>::reg_get(ADC_INT::registerData);
  return ADC_INT::data;
}


void ADC_INT::Delay(uint32_t nCount)
{
  while(nCount--)
  {
  }
}
