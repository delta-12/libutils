cmake_minimum_required(VERSION 3.27)
project(libutils C)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

set(UNITY_PATH "Unity/src")
set(UNITY_SOURCES ${UNITY_PATH}/unity.c)
include_directories(${UNITY_PATH})
add_library(Unity ${UNITY_SOURCES})
target_compile_definitions(Unity PUBLIC UNITY_INCLUDE_DOUBLE)

set(SOURCE_DIRS
    ${CMAKE_SOURCE_DIR}/LinkedList
    ${CMAKE_SOURCE_DIR}/Queue
    ${CMAKE_SOURCE_DIR}/Stack
)
set(SOURCE_LIST)
foreach(SOURCE_DIR ${SOURCE_DIRS})
    add_subdirectory(${SOURCE_DIR})
    file(GLOB_RECURSE RECURSE_SOURCES ${SOURCE_DIR}/*.c ${SOURCE_DIR}/*.h)
    list(APPEND SOURCE_LIST ${RECURSE_SOURCES})
endforeach()

target_link_libraries(test_DoublyLinkedList Unity)
target_link_libraries(test_SinglyLinkedList Unity)
target_link_libraries(test_Queue Unity)
target_link_libraries(test_Stack Unity)

add_dependencies(test_DoublyLinkedList uncrustify)
add_dependencies(test_SinglyLinkedList uncrustify)
add_dependencies(test_Queue uncrustify)
add_dependencies(test_Stack uncrustify)

include(cppcheck.cmake)
include(doxygen.cmake)
include(tests.cmake)
include(uncrustify.cmake)

add_test_with_valgrind(test_DoublyLinkedList)
add_test_with_valgrind(test_SinglyLinkedList)
add_test_with_valgrind(test_Queue)
add_test_with_valgrind(test_Stack)
