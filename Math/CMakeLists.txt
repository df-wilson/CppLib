cmake_minimum_required(VERSION 3.2.2)

set(CMAKE_CXX_FLAGS " -Wall -Wextra -ftabstop=4 -march=native -std=c++17 -fshow-column")

set(SOURCE_FILES mathutil.cpp Fraction.cpp Complex.cpp)

add_library(math SHARED ${SOURCE_FILES}) 
