# ComputerPlatforms
add_library(CPU CPU.h CPU.cpp AndroidCPU.h AndroidCPU.cpp)
target_include_directories(CPU
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

# All users of this library will need at least C++14
target_compile_features(CPU PUBLIC cxx_std_14)