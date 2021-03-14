/*
 * Esp.h
 *
 *  Created on: 14 бер. 2021 р.
 *      Author: oomel
 */

#pragma once

#include<math.h>

int pow10(int v) {
	int r = 1;
	for( int i =0; i!=v; ++i)
		r*=10;
	return r;
}

int strcasecmp(const char *s1, const char *s2)
{
	return 0; // TODO
}

void delayMicroseconds(unsigned long ms) {
	(void)ms;
}

unsigned long micros() {
	static unsigned long c = 1;
	return ++c;
}
