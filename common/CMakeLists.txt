include(options)

set_cmake_options()
project(common)

add_library(
  ${PROJECT_NAME} STATIC
  src/common.cpp
  src/tiny_object_loader.cc
  src/util.cpp
)

setup_include(${PROJECT_NAME})
setup_link(${PROJECT_NAME})
