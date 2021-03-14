/*
 * Esp.h
 *
 *  Created on: 14 бер. 2021 р.
 *      Author: oomel
 */

#pragma once

#include<math.h>
#include<string.h>


int pow10(int v) {
	int r = 1;
	for( int i =0; i!=v; ++i)
		r*=10;
	return r;
}

void delayMicroseconds(unsigned long ms) {
	(void)ms;
}

unsigned long micros() {
	static unsigned long c = 1;
	return ++c;
}



