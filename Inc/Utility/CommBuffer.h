/*
 * CommBuffer.h
 *
 *  Created on: Aug 17, 2021
 *      Author: matt
 */

#ifndef UTILITY_COMMBUFFER_H_
#define UTILITY_COMMBUFFER_H_

#include "circular_buffer.h"
#include<stdint.h>


class CommBuffer {

public:
	CommBuffer(): dataBuff{64}, messageLengths{10}
	{

	}
	virtual ~CommBuffer();
	bool hasData;

	uint8_t getData();
	void putData(uint8_t data);

private:
	util::circular_buffer<uint8_t> dataBuff;
	util::circular_buffer<uint8_t> messageLengths;

};

#endif /* UTILITY_COMMBUFFER_H_ */
