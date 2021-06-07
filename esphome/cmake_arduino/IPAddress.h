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
    const std::string addr_;
public:
    IPAddress(std::string str = "127.0.0.1") : addr_(str) {};
	std::string toString() const {
        return addr_;
	}
};


#endif
