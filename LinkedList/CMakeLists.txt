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
set(TESTS_LINKED_LIST_SOURCES
    src/SinglyLinkedList.c
    tests/tests_LinkedList.c
)

add_executable(tests_LinkedList ${TESTS_LINKED_LIST_SOURCES})

target_link_libraries(tests_LinkedList Unity)

enable_testing()
add_test(tests_LinkedList tests_LinkedList)
