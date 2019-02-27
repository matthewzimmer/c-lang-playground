cmake_minimum_required(VERSION 3.13)
project(CLangPlayground C)

set(CMAKE_C_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(FastCTutorial)
add_subdirectory(HelloWorld)
add_subdirectory(playground)
add_subdirectory(csi403)
add_subdirectory(csi402)