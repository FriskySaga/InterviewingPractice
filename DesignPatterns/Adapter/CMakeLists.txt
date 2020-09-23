# Root Folder (Strategy)
cmake_minimum_required(VERSION 3.16.3)
project(
  Adapter
  VERSION 1.0
  DESCRIPTION "Adapter Pattern Example"
  LANGUAGES CXX
)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(Includes)
file(GLOB SOURCES Sources/*.cxx)
file(GLOB TESTS Tests/*.cxx)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(AdapterClientTest ${TESTS} ${SOURCES})
target_link_libraries(AdapterClientTest PUBLIC ${GTEST_LIBRARIES} pthread)

