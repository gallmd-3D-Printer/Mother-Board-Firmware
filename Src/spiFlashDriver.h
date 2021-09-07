/*
 * spiFlashDriver.h
 *
 *  Created on: Aug 20, 2021
 *      Author: matt
 */

#ifndef SPIFLASHDRIVER_H_
#define SPIFLASHDRIVER_H_

#include "spi_flash_registers.h"
#include "../Inc/Peripherals/spi_master.h"

class spiFlashDriver {
public:
	spiFlashDriver();
	virtual ~spiFlashDriver();

	void writeData();
	void readData();
	void getID();

private:
	void writeProtectEnable();
	void writeProtectDisable();

};

#endif /* SPIFLASHDRIVER_H_ */
