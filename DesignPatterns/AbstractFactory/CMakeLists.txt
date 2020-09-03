# Abstract Factory Pattern (Computer)
cmake_minimum_required(VERSION 3.16.3)
project(ComputerFactory VERSION 0.4)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add_library(Logger Logger.cpp Logger.h LogSeverityEnum.h)
# add_executable(LoggerTest LoggerTest.cpp)
# target_link_libraries(LoggerTest PRIVATE Logger)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(CharacterTest CharacterTest.cxx)
target_link_libraries(CharacterTest PUBLIC ${SOURCE_LIBS} ${GTEST_LIBRARIES} pthread) # TODO What does PUBLIC mean?