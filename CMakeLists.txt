cmake_minimum_required(VERSION 3.12)
project(Design_Patterns)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

set(src_file bridge.h)

add_executable(Design_Patterns ${src_file} main.cpp)
target_link_libraries(Design_Patterns gtest)
