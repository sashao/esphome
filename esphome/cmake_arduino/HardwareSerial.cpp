/*
 * HardwareSerial.cpp
 *
 *  Created on: 15 бер. 2021 р.
 *      Author: oomel
 */

#include "HardwareSerial.h"
#include <stdio.h>

HardwareSerial Serial1;
HardwareSerial Serial;

void HardwareSerial::println(const char *msg)
{
	printf("SERIAL: %s\n", msg);
}

void HardwareSerial::begin(int)
{

}
