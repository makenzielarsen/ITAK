cmake_minimum_required(VERSION 3.6)
project(ITAK)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES )
add_executable(ITAK main.cpp ${SOURCE_FILES})

set(TEST_FILES )
add_executable(Test Testing/testingMain.cpp ${SOURCE_FILES} ${TEST_FILES})