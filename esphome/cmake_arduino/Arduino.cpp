/*
 * Arduino.cpp
 *
 *  Created on: 15 бер. 2021 р.
 *      Author: oomel
 */
#include "Arduino.h"
#include "esphome/core/preferences.h"

namespace esphome {

ESPPreferences::ESPPreferences() : current_offset_(0)
{
}

//bool ESPPreferenceObject::load_()
//{
//	return true;
//}

bool ESPPreferenceObject::load_internal_()
{
	return true;
}

//bool ESPPreferenceObject::save_()
//{
//	return true;
//}

bool ESPPreferenceObject::save_internal_()
{
	return true;
}

void force_link_symbols()
{

}

} // namespace esphome







void ESPInterface::restart()
{

}


unsigned long millis() {
	static unsigned long c = 1;
	return ++c;
}

void delay(unsigned long ms) {
	(void)ms;
}

void yield() {

}

ESPInterface ESP;

