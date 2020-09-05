# Root Folder (AbstractFactory)
cmake_minimum_required(VERSION 3.16.3)
project(
  ComputerFactory
  VERSION 1.0
  DESCRIPTION "Abstract Factory Pattern Example"
  LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(Includes)
add_subdirectory(Sources)
file(GLOB SOURCES Sources/*.cxx)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(FactoryClientTest ${SOURCES})
target_link_libraries(FactoryClientTest PUBLIC ${GTEST_LIBRARIES} pthread)

