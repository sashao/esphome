/*
 * Arduino.h
 *
 *  Created on: 14 бер. 2021 р.
 *      Author: oomel
 */

#pragma once


#include<cmath>

class HardwareSerial {

};

unsigned long millis() {
	static unsigned long c = 1;
	return ++c;
}

void delay(unsigned long ms) {
	(void)ms;
}

#define ICACHE_RAM_ATTR

