/*
 * Arduino.cpp
 *
 *  Created on: 15 бер. 2021 р.
 *      Author: oomel
 */
#include "Arduino.h"
#include "esphome/core/preferences.h"
#include "esphome/components/network/async_tcp.h"

namespace esphome {

namespace network {

AsyncServer *createAsyncServer(uint16_t port) {
	// Here it would be possible to return any transport implementation.
	return nullptr;
}

}

ESPPreferenceObject ESPPreferences::make_preference(size_t length, uint32_t type, bool in_flash) {
  auto pref = ESPPreferenceObject(this->current_offset_, length, type);
  this->current_offset_++;
  return pref;
}


ESPPreferences::ESPPreferences() : current_offset_(0)
{
}

void ESPPreferences::begin() {
}

bool ESPPreferenceObject::load_internal_()
{
	return true;
}

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

float pow10f(float v)
{
	return exp10f(v);
}

double pow10(double v) {
	return exp10(v);
}


ESPInterface ESP;




