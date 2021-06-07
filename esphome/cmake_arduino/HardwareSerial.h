/*
 * HardwareSerial.h
 *
 *  Created on: 15 бер. 2021 р.
 *      Author: oomel
 */

#pragma once

#include<string.h>

class HardwareSerial {
public:
	void println(const char *msg);
	void begin(int rate);
};

static const char *UART_SELECTIONS[] = {"UART0", "UART1", "UART0_SWAP"};

extern HardwareSerial Serial1;
extern HardwareSerial Serial;
