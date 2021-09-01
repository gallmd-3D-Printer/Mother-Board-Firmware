/*
 * gpio_interruptable.h
 *
 *  Created on: Dec 28, 2020
 *      Author: matt
 */

#ifndef PERIPHERALS_GPIO_INTERRUPTABLE_H_
#define PERIPHERALS_GPIO_INTERRUPTABLE_H_


#include "Registers/syscfg_registers.h"
#include "Registers/exti_registers.h"
#include "Registers/rcc_registers.h"
#include "gpio.h"
#include "Utility/interruptable.h"
#include "Utility/reg_access.h"
#include "../CMSIS/Device/ST/STM32F4xx/Include/stm32f4xx.h"
#include "../Src/board_pins.h"


extern interruptable * handlerPointers[sizeof(peripheralInterrupts)];
class GpioInterruptable : public interruptable{

public:
	GpioInterruptable(BoardPins *pins);
	 void handleInterrupts(int interruptType);

private:
	void registerInterrupt();
	BoardPins *boardPins;


};


#endif /* PERIPHERALS_GPIO_INTERRUPTABLE_H_ */
