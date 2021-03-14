cmake_minimum_required(VERSION 3.5)

project(serialtransmit LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DNDEBUG")
add_compile_options("$<$<CONFIG:DEBUG>:-DNDEBUG>")

#find_package(Qt5Core)

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
)
#target_link_libraries(serialtransmit Qt5::Core)

target_include_directories(esphome PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

add_definitions(-DCMAKE_BUILD)



