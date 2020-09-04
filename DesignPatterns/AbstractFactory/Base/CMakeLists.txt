# Base
add_library(Component Component.h Component.cpp)
target_include_directories(Component
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

