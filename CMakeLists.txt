cmake_minimum_required(VERSION 3.6)
project(ITAK)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Configuration.h Configuration.cpp
        AnalyzerStrategy.h AnalyzerStrategy.cpp
        ResultSet.h ResultSet.cpp
        DenialOfService.h DenialOfService.cpp
        PortScanner.h PortScanner.cpp
        Utils.h Utils.cpp
        UserInterface.cpp UserInterface.h
        Analyzer.cpp Analyzer.h)
add_executable(ITAK main.cpp ${SOURCE_FILES})

set(TEST_FILES
        Testing/Test.h
        Testing/ConfigurationTester.h Testing/ConfigurationTester.cpp
        Testing/ResultSetTester.h Testing/ResultSetTester.cpp
        Testing/DenialOfServiceTester.h Testing/DenialOfServiceTester.cpp
        Testing/PortScannerTester.cpp Testing/PortScannerTester.h)
add_executable(Test Testing/testingMain.cpp ${SOURCE_FILES} ${TEST_FILES})