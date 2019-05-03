function(add_exercise_test)
        file(RELATIVE_PATH EXERCISE_REL_PATH 
                ${CMAKE_SOURCE_DIR}
                ${CMAKE_CURRENT_SOURCE_DIR})

        string(REPLACE / - EXERCISE_NAME ${EXERCISE_REL_PATH})

        add_executable(${EXERCISE_NAME} main.cpp)
        target_link_libraries(${EXERCISE_NAME} PUBLIC 
                ${Boost_LIBRARIES})
        add_test(NAME ${EXERCISE_NAME} COMMAND ./${EXERCISE_NAME}
                WORKING_DIRECTORY 
                ${CMAKE_CURRENT_BINARY_DIR})
endfunction()
