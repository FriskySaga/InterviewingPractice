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

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(Base)
add_subdirectory(Parts)

add_executable(FactoryClientTest FactoryClient.cxx)
target_compile_features(FactoryClientTest PRIVATE cxx_std_14)
target_link_libraries(FactoryClientTest PRIVATE CPU ${GTEST_LIBRARIES} pthread)

