cmake_minimum_required(VERSION 3.5)
project(testFS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 \
        -Wall -Wextra -Werror")

include(CTest)

add_subdirectory(Chapter2-Traits_and_Type_Manipulation)
