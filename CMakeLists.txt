cmake_minimum_required(VERSION 3.5)

project(esphome LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DNDEBUG")
add_compile_options("$<$<CONFIG:DEBUG>:-DNDEBUG>")

add_library(esphome
	esphome/components/api/util.cpp
	esphome/components/api/proto.cpp
	esphome/components/api/list_entities.cpp
	esphome/components/api/user_services.cpp
	esphome/components/api/subscribe_state.cpp
	esphome/components/api/api_server.cpp
	esphome/components/api/api_connection.cpp
	esphome/components/api/api_pb2.cpp
	esphome/components/api/api_pb2_service.cpp
	esphome/components/network/async_tcp.cpp
	esphome/components/logger/logger.cpp
	esphome/components/sensor/sensor.cpp
	esphome/components/sensor/filter.cpp
	esphome/components/binary_sensor/binary_sensor.cpp
	esphome/components/binary_sensor/filter.cpp
	esphome/components/switch/switch.cpp
	esphome/components/homeassistant/sensor/homeassistant_sensor.cpp
	esphome/components/homeassistant/binary_sensor/homeassistant_binary_sensor.cpp
	esphome/components/homeassistant/text_sensor/homeassistant_text_sensor.cpp
#	esphome/components/homeassistant/time/homeassistant_time.cpp

	esphome/core/util.cpp
	esphome/core/controller.cpp
	esphome/core/helpers.cpp
	esphome/core/component.cpp
	esphome/core/log.cpp
	esphome/core/preferences.cpp
	esphome/core/scheduler.cpp
	esphome/core/application.cpp
	
	esphome/cmake_arduino/Arduino.cpp
	esphome/cmake_arduino/HardwareSerial.cpp
	esphome/cmake_arduino/network/async_tcp_client_impl.cpp
	esphome/cmake_arduino/network/async_tcp_server_impl.cpp
)

target_include_directories(esphome PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/esphome/cmake_arduino
)

add_executable(test-esp86 esphome/cmake_arduino/example/main.cpp)
target_link_libraries(test-esp86 esphome)


add_definitions(-DCMAKE_BUILD)



