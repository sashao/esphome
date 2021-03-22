/*
 * Arduino.h
 *
 *  Created on: 14 бер. 2021 р.
 *      Author: oomel
 */

#pragma once

#define ARDUINO_BOARD "esp-x86"

#include<cmath>
#include"HardwareSerial.h"

float pow10f(float v);
double pow10(double v);

unsigned long millis();

void delay(unsigned long ms);

void yield();

class ESPInterface {
public:
	void restart();
};

extern ESPInterface ESP;

#define ICACHE_RAM_ATTR

