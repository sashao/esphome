/*
 * Arduino.h
 *
 *  Created on: 14 бер. 2021 р.
 *      Author: oomel
 */

#pragma once


#include<cmath>
#include"HardwareSerial.h"

unsigned long millis();

void delay(unsigned long ms);

void yield();

class ESPInterface {
public:
	void restart();
};

extern ESPInterface ESP;

#define ICACHE_RAM_ATTR

