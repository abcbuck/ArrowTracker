cmake_minimum_required(VERSION 4.0.0)
project(ArrowTracker CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL Windows)
  add_compile_options(/utf-8)
endif()

add_executable(ArrowTracker main.cpp)

