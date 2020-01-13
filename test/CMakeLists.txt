cmake_minimum_required(VERSION 3.2.2)

set(CMAKE_CXX_FLAGS " -Wall -Wextra -ftabstop=4 -march=native -std=c++17 -fshow-column")

set(SOURCE_FILES
    main.cpp
    01_BinarySearchTreeTest.cpp
    02_LinkedListTest.cpp
    03_QueueTest.cpp
    04_StackTest.cpp
    101_FractionTest.cpp
    103_Vector3Test.cpp
    301_CStringUtilTest.cpp
)

add_executable(tests ${SOURCE_FILES}) 

TARGET_LINK_LIBRARIES(tests stringutils math)
