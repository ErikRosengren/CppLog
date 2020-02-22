cmake_minimum_required(VERSION 2.8)
project( LogExample )
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/*.cpp")
add_executable(Example
	example.cpp
	log.cpp
	)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set( CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 \
-std=c++17 \
-g \
-fsanitize=address,undefined \
-Wall \
-Wextra \
-pedantic-errors \
-Wold-style-cast")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address,undefined")
