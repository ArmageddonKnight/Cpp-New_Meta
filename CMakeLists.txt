cmake_minimum_required(VERSION 3.5)
project(testFS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 \
        -Wall -Wextra -Werror")

include(CTest)
enable_testing()

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

file(GLOB CHAPTERS Chapter*)
foreach(chapter ${CHAPTERS})
        add_subdirectory(${chapter})
endforeach()
