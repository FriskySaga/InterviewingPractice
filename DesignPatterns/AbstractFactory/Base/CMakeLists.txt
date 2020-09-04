# Base
add_library(Component Component.hpp Component.cxx)
target_include_directories(Component
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

