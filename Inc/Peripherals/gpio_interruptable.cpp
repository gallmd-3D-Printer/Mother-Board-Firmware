/*
 * gpio_interruptable.cpp
 *
 *  Created on: Dec 28, 2020
 *      Author: matt
 */

#include "gpio_interruptable.h"

GpioInterruptable::GpioInterruptable(BoardPins *pins) {

	//Hardcoded for pin PA2 as an example
	//GPIO configured in BoardPins

	//Enable Clock for SYSCFG Peripheral
	reg_access<RCC_MDG::RCCRegisterType2, RCC_MDG::RCCRegisterType2,
			(RCC_MDG::BaseRegisters::RCC_MDG + RCC_MDG::APB2ENR::registerOffset),
			RCC_MDG::APB2ENR::SYSCFGEN>::reg_or();

	//Set bits in EXTICR1 which contains config for line EXTI2, setting bits = 0x00 = PA2 Pin
	reg_access<SYSCFG_MDG::SYSCFGRegisterType, SYSCFG_MDG::SYSCFGRegisterType,
			(SYSCFG_MDG::BaseRegisters::SYSCFGBase
					+ SYSCFG_MDG::EXTICR1::registerOffset),
			SYSCFG_MDG::EXTICR1::EXTI2Bits::EXTI20>::reg_or();
	registerInterrupt();

	//Set falling edge for Line EXTI2
	reg_access<EXTI_MDG::EXTIRegisterType, EXTI_MDG::EXTIRegisterType,
			EXTI_MDG::BaseRegisters::EXTIBase + EXTI_MDG::FTSR::registerOffset,
			EXTI_MDG::FTSR::TR2>::reg_or();
	//Set bit for line EXTI2 in Interrupt Mask Register
	reg_access<EXTI_MDG::EXTIRegisterType, EXTI_MDG::EXTIRegisterType,
			EXTI_MDG::BaseRegisters::EXTIBase + EXTI_MDG::IMR::registerOffset,
			EXTI_MDG::IMR::MR2>::reg_or();

	//Setup EXTI2 in NVIC peripheral
	NVIC_SetPriority(EXTI2_IRQn, 0);
	NVIC_EnableIRQ(EXTI2_IRQn);

	boardPins = pins;

}

void GpioInterruptable::registerInterrupt() {

	handlerPointers[EXTI2_IDX] = this;

}

void GpioInterruptable::handleInterrupts(int interruptType) {

	//Clear Pending Register, position 2
	reg_access<EXTI_MDG::EXTIRegisterType, EXTI_MDG::EXTIRegisterType,
			EXTI_MDG::BaseRegisters::EXTIBase + EXTI_MDG::PR::registerOffset,
			EXTI_MDG::PR::PR2>::reg_or();

	boardPins->statusLED.toggle();

}
