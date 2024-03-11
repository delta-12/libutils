cmake_minimum_required(VERSION 3.27)
project(libutils C)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

set(UNITY_PATH "Unity/src")
set(UNITY_SOURCES ${UNITY_PATH}/unity.c)
include_directories(${UNITY_PATH})
add_library(Unity ${UNITY_SOURCES})
target_compile_definitions(Unity PUBLIC UNITY_INCLUDE_DOUBLE)

add_subdirectory(LinkedList)
add_subdirectory(Queue)

target_link_libraries(test_DoublyLinkedList Unity)
target_link_libraries(test_SinglyLinkedList Unity)
target_link_libraries(test_Queue Unity)

include(cppcheck.cmake)
include(doxygen.cmake)
include(tests.cmake)

add_test_with_valgrind(test_DoublyLinkedList)
add_test_with_valgrind(test_SinglyLinkedList)
add_test_with_valgrind(test_Queue)
