cmake_minimum_required(VERSION 3.27)
project(LinkedList C)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

set(UNITY_PATH "../Unity/src")
set(UNITY_SOURCES ${UNITY_PATH}/unity.c)
include_directories(${UNITY_PATH})
add_library(Unity ${UNITY_SOURCES})
target_compile_definitions(Unity PUBLIC UNITY_INCLUDE_DOUBLE)

include_directories(include)
set(TESTS_QUEUE_SOURCES
    src/Queue.c
    tests/tests_Queue.c
)

add_executable(tests_Queue ${TESTS_QUEUE_SOURCES})

target_link_libraries(tests_Queue Unity)

enable_testing()
add_test(tests_Queue tests_Queue)

set(CPPCHECK_NAME cppcheck)
set(CPPCHECK_SEARCH_PATH
    ${CMAKE_SOURCE_DIR}/../tools/cppcheck/build/bin/
    /opt/cppcheck/build/bin/
)
find_program(${CPPCHECK_NAME}_BIN
    NAMES ${CPPCHECK_NAME}
    HINTS ${CPPCHECK_SEARCH_PATH}
)
if(${CPPCHECK_NAME}_BIN)
    message(STATUS "Found ${CPPCHECK_NAME} at: ${${CPPCHECK_NAME}_BIN}")
else()
    message(FATAL_ERROR "${CPPCHECK_NAME} not found.")
endif()

message(STATUS "Adding files to cppcheck")
set(CPPCHECK_SOURCES
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/tests
)

add_custom_target(
        cppcheck
        ${${CPPCHECK_NAME}_BIN}
        --enable=all
        --suppress-xml=../suppressions.xml
        --error-exitcode=2
        --xml
        --output-file=cppcheck_report.xml
        ${CPPCHECK_SOURCES}
)
