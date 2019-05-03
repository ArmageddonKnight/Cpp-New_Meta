add_executable(exercise_2_0 main.cpp)

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
target_link_libraries(exercise_2_0 PUBLIC 
        ${Boost_LIBRARIES})

add_test(NAME exercise_2_0 COMMAND ./exercise_2_0 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
