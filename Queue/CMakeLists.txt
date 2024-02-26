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
