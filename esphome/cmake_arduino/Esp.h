/*
 * Esp.h
 *
 *  Created on: 14 бер. 2021 р.
 *      Author: oomel
 */

#pragma once

#include<math.h>
#include<string.h>




void delayMicroseconds(unsigned long ms) {
	(void)ms;
}

unsigned long micros() {
	static unsigned long C = 1;
	return ++C;
}



