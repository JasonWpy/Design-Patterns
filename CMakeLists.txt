cmake_minimum_required(VERSION 3.12)
project(Design_Patterns)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

set(src_file
        lazy_singleton.h)


add_executable(Design_Patterns ${src_file} main.cpp)
target_link_libraries(Design_Patterns gtest)
