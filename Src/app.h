/*
 * app.h
 *
 *  Created on: Dec 22, 2020
 *      Author: matt
 */

#ifndef APP_H_
#define APP_H_

#include "stdint.h"
#include <array>

class app{

public:
	app();
	std::array<uint16_t, 8> DrvRegisters;

};


#endif /* APP_H_ */
