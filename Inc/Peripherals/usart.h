/*
 * i2c.h
 *
 *  Created on: Jan 25, 2019
 *      Author: matt
 */

#ifndef USART_H_
#define USART_H_

#include "../Utility/interruptable.h"
#include "../Utility/interrupts.h"
#include "../Utility/reg_access.h"
#include "../Utility/reg_access_dynamic.h"
#include "gpio.h"
#include "gpio_config.h"
#include "rcc.h"
//#include "misc.h"
#include "../Utility/circular_buffer.h"
#include "../Utility/util.h"
#include "../CMSIS/Device/ST/STM32F4xx/Include/stm32f4xx.h"
extern interruptable *handlerPointers[sizeof(peripheralInterrupts)];

namespace USART {

typedef uint32_t USARTRegisterType;
constexpr uint8_t BUFFER_SIZE = 50;

namespace BaseRegisters {

constexpr USARTRegisterType USART1Base = 0x40011000U;
constexpr USARTRegisterType USART2Base = 0x40004400U;
constexpr USARTRegisterType USART3Base = 0x40004800U;
constexpr USARTRegisterType USART4Base = 0x40004C00U;
constexpr USARTRegisterType USART5Base = 0x40005000U;
constexpr USARTRegisterType USART6Base = 0x40011400U;
constexpr USARTRegisterType USART7Base = 0x40007800U;
constexpr USARTRegisterType USART8Base = 0x40007C00U;

}

namespace StatusRegister {

constexpr USARTRegisterType RegisterOffset = 0x00U;
constexpr USARTRegisterType RegisterReset = 0x00000000U;
//    constexpr USARTRegisterType RegisterReset = 0x000000C0U;

constexpr USARTRegisterType ClearToSendFlag = Util::Bits::BIT9;
constexpr USARTRegisterType LineBreakDetection = Util::Bits::BIT8;
constexpr USARTRegisterType TXEmpty = Util::Bits::BIT7;
constexpr USARTRegisterType TransmissionComplete = Util::Bits::BIT6;
constexpr USARTRegisterType RXNotEmpty = Util::Bits::BIT5;
constexpr USARTRegisterType IdleLineDetected = Util::Bits::BIT4;
constexpr USARTRegisterType OverrunError = Util::Bits::BIT3;
constexpr USARTRegisterType NoiseDetected = Util::Bits::BIT2;
constexpr USARTRegisterType FramingError = Util::Bits::BIT1;
constexpr USARTRegisterType ParityError = Util::Bits::BIT0;

}

namespace DataRegister {

constexpr USARTRegisterType RegisterOffset = 0x04U;
constexpr USARTRegisterType RegisterReset = 0x00U;

}

namespace BaudRateRegister {

constexpr USARTRegisterType RegisterOffset = 0x08U;
constexpr USARTRegisterType RegisterReset = 0x00U;

}

namespace ControlRegister1 {

constexpr USARTRegisterType RegisterOffset = 0x0CU;
constexpr USARTRegisterType RegisterReset = 0x00U;

constexpr USARTRegisterType OversamplingMode = Util::Bits::BIT15;
constexpr USARTRegisterType UsartEnable = Util::Bits::BIT13;
constexpr USARTRegisterType WordLength = Util::Bits::BIT12;
constexpr USARTRegisterType WakeupMethod = Util::Bits::BIT11;
constexpr USARTRegisterType ParityControlEnable = Util::Bits::BIT10;
constexpr USARTRegisterType ParitySelection = Util::Bits::BIT9;
constexpr USARTRegisterType ParityIE = Util::Bits::BIT8;
constexpr USARTRegisterType TXEmptyInterruptEnable = Util::Bits::BIT7;
constexpr USARTRegisterType TXCompleteIE = Util::Bits::BIT6;
constexpr USARTRegisterType RXNotEmptyIE = Util::Bits::BIT5;
constexpr USARTRegisterType IdleIE = Util::Bits::BIT4;
constexpr USARTRegisterType TransmitterEnable = Util::Bits::BIT3;
constexpr USARTRegisterType ReceiverEnable = Util::Bits::BIT2;
constexpr USARTRegisterType ReceiverWakeup = Util::Bits::BIT1;
constexpr USARTRegisterType SendBreak = Util::Bits::BIT0;

}

namespace ControlRegister2 {

constexpr USARTRegisterType RegisterOffset = 0x10U;
constexpr USARTRegisterType RegisterReset = 0x00U;

constexpr USARTRegisterType LINModeEnable = Util::Bits::BIT14;
constexpr USARTRegisterType ClockEnable = Util::Bits::BIT11;
constexpr USARTRegisterType ClockPolarity = Util::Bits::BIT10;
constexpr USARTRegisterType ClockPhase = Util::Bits::BIT9;
constexpr USARTRegisterType LastBitClockPulse = Util::Bits::BIT8;
constexpr USARTRegisterType LINBreakDetectionIE = Util::Bits::BIT6;
constexpr USARTRegisterType LINBreakDetectionLength = Util::Bits::BIT5;

namespace StopBits {
constexpr USARTRegisterType OneStopBit = 0x00U;
constexpr USARTRegisterType HalfStopBit = 0x1000U;
constexpr USARTRegisterType TwoStopBits = 0x2000U;
constexpr USARTRegisterType OneAndHalfStopBits = 0x3000U;

}

}

namespace ControlRegister3 {

constexpr USARTRegisterType RegisterOffset = 0x14U;
constexpr USARTRegisterType RegisterReset = 0x00U;

constexpr USARTRegisterType OneSampleBit = Util::Bits::BIT11;
constexpr USARTRegisterType ClearToSendIE = Util::Bits::BIT10;
constexpr USARTRegisterType ClearToSendEnable = Util::Bits::BIT9;
constexpr USARTRegisterType ReadyToSendEnable = Util::Bits::BIT8;
constexpr USARTRegisterType DMATXEnable = Util::Bits::BIT7;
constexpr USARTRegisterType DMARXEnable = Util::Bits::BIT6;
constexpr USARTRegisterType SmartCardEnable = Util::Bits::BIT5;
constexpr USARTRegisterType SmartCardNACKEnable = Util::Bits::BIT4;
constexpr USARTRegisterType HalfDuplexSelection = Util::Bits::BIT3;
constexpr USARTRegisterType IrDALowPower = Util::Bits::BIT2;
constexpr USARTRegisterType IrDAModeEnable = Util::Bits::BIT1;
constexpr USARTRegisterType ErrorIE = Util::Bits::BIT0;

}

//Bits [15:8] used for guard time in Smartcard Mode
//Bits [7:0]  used for prescaler in IrDA and Smartcard Mode
namespace GuardTimePrescalerRegister {

constexpr USARTRegisterType RegisterOffset = 0x18U;
constexpr USARTRegisterType RegisterReset = 0x00U;

//Used in IRdA and Smartcard Modes
namespace PrescalerValues {

}

}

class Usart : public interruptable {

public:
  Usart(USART::USARTRegisterType baseRegister) : rxBuffer{USART::BUFFER_SIZE},
                                                 messageLengths{8} {
    USART::Usart::baseRegister = baseRegister;
    USART::Usart::controlRegister1 = baseRegister + USART::ControlRegister1::RegisterOffset;
    USART::Usart::controlRegister2 = baseRegister + USART::ControlRegister2::RegisterOffset;
    USART::Usart::controlRegister3 = baseRegister + USART::ControlRegister3::RegisterOffset;
    USART::Usart::baudRateRegister = baseRegister + USART::BaudRateRegister::RegisterOffset;
    USART::Usart::statusRegister = baseRegister + USART::StatusRegister::RegisterOffset;
    USART::Usart::dataRegister = baseRegister + USART::DataRegister::RegisterOffset;
    Usart::Usart::guardTimePrescalerRegister = baseRegister + USART::GuardTimePrescalerRegister::RegisterOffset;
    hasData = false;
    currentMessageLength = 0;

    USART::Usart::init();
    USART::Usart::registerInterrupt();
  };
  void handleInterrupts(int interruptType);
  void sendBytes(uint8_t data);
  bool hasData;
  util::circular_buffer<uint8_t> rxBuffer;
  util::circular_buffer<uint8_t> messageLengths;
  uint8_t currentMessageLength;

private:
  //Register Addresses
  USART::USARTRegisterType baseRegister;
  USART::USARTRegisterType statusRegister;
  USART::USARTRegisterType dataRegister;
  USART::USARTRegisterType baudRateRegister;
  USART::USARTRegisterType controlRegister1;
  USART::USARTRegisterType controlRegister2;
  USART::USARTRegisterType controlRegister3;
  USART::USARTRegisterType guardTimePrescalerRegister;

  uint32_t usartStatus;

  PinType TXPin;
  PinType RXPin;
  GPIOxRegisterType TXGPIOBank;
  GPIOxRegisterType RXGPIOBank;
  AlternateFunctionType pinAF;


  void registerInterrupt();
  int init();
};

}

#endif
