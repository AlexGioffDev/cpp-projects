cmake_minimum_required(VERSION 3.10)
project(raylyb)

set(CMAKE_CXX_STANDARD 17)

# INCLUDE AND LIBRARY
set(RL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/vendor/include)
set(RL_LIBRARY_DIR ${CMAKE_SOURCE_DIR}/vendor/library)


find_library(RL_LIBRARY NAMES raylib PATHS ${RL_LIBRARY_DIR} NO_DEFAULT_PATH)
include_directories(${RL_INCLUDE_DIR})

include_directories(${CMAKE_SOURCE_DIR}/include)   # Header personali

add_executable(raylib src/main.cpp src/Player.cpp)

target_link_libraries(raylib ${RL_LIBRARY})
target_link_libraries(raylib "-framework OpenGL" "-framework Cocoa" "-framework IOKit" "-framework CoreAudio")
