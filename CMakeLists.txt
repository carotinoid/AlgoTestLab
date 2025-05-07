cmake_minimum_required(VERSION 3.11)
project(
    AlgoTestLab
    VERSION 0.1
    DESCRIPTION "An educational platform to implement algorithms"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB LIB_SOURCES "${CMAKE_SOURCE_DIR}/src/*/*.cc" "${CMAKE_SOURCE_DIR}/src/*.cc")

add_library(
    algo STATIC
    ${LIB_SOURCES}
)

### clang-format
find_program(CLANG_FORMAT_EXE NAMES clang-format)
if(CLANG_FORMAT_EXE)
    message(STATUS "Found clang-format: ${CLANG_FORMAT_EXE}")
    file(GLOB_RECURSE ALL_SOURCE_FILES
        "${CMAKE_SOURCE_DIR}/include/*.hh"
        "${CMAKE_SOURCE_DIR}/src/*.cc"
        "${CMAKE_SOURCE_DIR}/tests/*.cc"
    )
    add_custom_target(format
        COMMAND ${CLANG_FORMAT_EXE}
                -i
                --style=file
                ${ALL_SOURCE_FILES}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Running clang-format on all source files"
    )
else()
    message(WARNING "clang-format not found!")
endif()

enable_testing()

# each test target
set(TEST_BINARY_DIR ${CMAKE_BINARY_DIR}/tests)
file(MAKE_DIRECTORY ${TEST_BINARY_DIR})

file(GLOB TEST_FILES tests/*.cc)
set(GROUP_TARGETS)

foreach(test_file ${TEST_FILES})
    get_filename_component(test_name ${test_file} NAME_WE)  # e.g., t_dq_binarysearch

    string(REGEX REPLACE "^t_(.*)_([^_]+)$" "\\2" name ${test_name})  
    string(REGEX REPLACE "^t_(.*)_([^_]+)$" "\\1" group ${test_name})

    add_executable(${test_name} ${test_file})
    set_target_properties(${test_name} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${TEST_BINARY_DIR}
    )

    target_link_libraries(${test_name} algo)

    add_test(NAME ${test_name} COMMAND ${TEST_BINARY_DIR}/${test_name})
    set_tests_properties(${test_name} PROPERTIES TIMEOUT 2)

    add_custom_target(check_${name}
        COMMAND ${CMAKE_CTEST_COMMAND} -R "^t_.*_${name}" --output-on-failure
        COMMENT "Running test named '${name}'"
    )
    list(APPEND CHECK_TARGETS check_${name})

    if(NOT TARGET check_${group})
        add_custom_target(check_${group}
            COMMAND ${CMAKE_CTEST_COMMAND} -R "^t_${group}_.*" --output-on-failure
            COMMENT "Running all tests in group '${group}'"
        )
    endif()

endforeach()

add_custom_target(check
    COMMAND ${CMAKE_CTEST_COMMAND} -R "^t_.*_.*" --output-on-failure
    COMMENT "Running all tests"
)
