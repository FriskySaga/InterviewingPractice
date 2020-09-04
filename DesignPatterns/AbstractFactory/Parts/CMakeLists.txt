# ComputerPlatforms
add_library(CPU CPU.hpp CPU.cxx AndroidCPU.hpp AndroidCPU.cxx)
target_include_directories(CPU
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(CPU PUBLIC cxx_std_14)
target_link_libraries(CPU PUBLIC Component)

