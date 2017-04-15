cmake_minimum_required(VERSION 3.6)
project(ITAK)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ITAK.h Message.h
        Configuration.h Configuration.cpp
        Analyzer.h Analyzer.cpp
        ResultSet.h
        DenialOfService.h DenialOfService.cpp
        PortScanner.h PortScanner.cpp)
add_executable(ITAK main.cpp ${SOURCE_FILES})

set(TEST_FILES Testing/ConfigurationTester.h Testing/ConfigurationTester.cpp)
add_executable(Test Testing/testingMain.cpp ${SOURCE_FILES} ${TEST_FILES})