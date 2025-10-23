cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(options)
include(deps)

project(VulkanTutorial)
option(DEBUG_BUILD "Build with debug flags" OFF)

prepare_sdl3()

# Common utilities and functions
add_subdirectory(common)

# Build each chapter
add_subdirectory(chapter4)
add_subdirectory(chapter5)
add_subdirectory(chapter6)
add_subdirectory(chapter7)
add_subdirectory(chapter8)
add_subdirectory(chapter9)
add_subdirectory(chapter10)
# add_subdirectory(chapter11)
