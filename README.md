This is fork intended to add networking capabilities and run esphome's on desktop computers.

- added boost example app which can be run on linux.


to test you have to have boost libraries installed:

cd esphome
mkdir build
cd build
cmake ..
make
./test-x86-boost
Connect to it by going to HomeAssistant/Settings/Integrations/Add/ESPHome, enter ipaddress of running test-x86-boost and default port.

This will run boost based example wthich demonstrates running esphome API server and creating Switches, Sensors.
Turn on x86switch and you will bet blinking x86sensor.

Now you can link devices wihtout MQTT from C++



# ESPHome [![Build Status](https://travis-ci.org/esphome/esphome.svg?branch=master)](https://travis-ci.org/esphome/esphome) [![Discord Chat](https://img.shields.io/discord/429907082951524364.svg)](https://discord.gg/KhAMKrd) [![GitHub release](https://img.shields.io/github/release/esphome/esphome.svg)](https://GitHub.com/esphome/esphome/releases/)

[![ESPHome Logo](https://esphome.io/_images/logo-text.png)](https://esphome.io/)

**Documentation:** https://esphome.io/

For issues, please go to [the issue tracker](https://github.com/esphome/issues/issues).

For feature requests, please see [feature requests](https://github.com/esphome/feature-requests/issues).
