cmake_minimum_required(VERSION 3.16.3)
project(Mediator LANGUAGES CXX VERSION 1.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)
file(GLOB SOURCE source/*.cpp)

add_executable(Mediator ${SOURCE})
