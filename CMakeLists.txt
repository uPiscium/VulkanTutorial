cmake_minimum_required(VERSION 3.30)
project(Terreate)
option(DEBUG_BUILD "Build with debug flags" OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(options)
include(sdl3)

add_subdirectory(chapter4)
add_subdirectory(chapter5)
add_subdirectory(chapter6)
add_subdirectory(chapter7)
add_subdirectory(chapter8)
add_subdirectory(chapter9)
add_subdirectory(chapter10)
add_subdirectory(chapter11)
