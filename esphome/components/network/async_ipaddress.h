/*
 * IPAddress.h
 *
 *  Created on: 14 March 2021
 *      Author: Oleksandr Omelchuk
 */

#pragma once

#include<stdint.h>
#include<string>
#include<cstring>

#ifndef CMAKE_BUILD

#include<IPAddress.h>

#else

class IPAddress {
public:
	std::string toString() const {
		return std::string("127.0.0.1");
	}
};


#endif
