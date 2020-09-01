# Singleton (Logger)
cmake_minimum_required(VERSION 3.16.3)
project(LoggerSingleton VERSION 0.4)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(Logger Logger.cpp Logger.h LogSeverityEnum.h)
add_executable(LoggerTest LoggerTest.cpp)
target_link_libraries(LoggerTest PRIVATE Logger)

