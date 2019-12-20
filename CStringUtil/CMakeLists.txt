cmake_minimum_required(VERSION 3.2.2)

set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_CXX_FLAGS " -Wall -Wextra -ftabstop=4 -march=native -std=c++14 -fshow-column")

set(SOURCE_FILES CStringUtils.cpp)

add_library(stringutils SHARED ${SOURCE_FILES}) 
