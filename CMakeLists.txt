cmake_minimum_required(VERSION 3.27)
project(libutils LANGUAGES C VERSION 0.0.0)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -fdiagnostics-color=always")

set(UNITY_PATH ${CMAKE_SOURCE_DIR}/Unity/src)
set(UNITY_SOURCES ${UNITY_PATH}/unity.c)
include_directories(${UNITY_PATH})
add_library(Unity ${UNITY_SOURCES})
target_compile_definitions(Unity PUBLIC UNITY_INCLUDE_DOUBLE)

include_directories(include)

set(SOURCE_DIRS
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/src
  ${CMAKE_SOURCE_DIR}/test
)
set(SOURCE_LIST)
foreach(SOURCE_DIR ${SOURCE_DIRS})
  file(GLOB_RECURSE RECURSE_SOURCES ${SOURCE_DIR}/*.c ${SOURCE_DIR}/*.h)
  list(APPEND SOURCE_LIST ${RECURSE_SOURCES})
endforeach()

include(cppcheck.cmake)
include(doxygen.cmake)
include(uncrustify.cmake)

add_library(utils)
set_target_properties(utils PROPERTIES
  VERSION ${CMAKE_PROJECT_VERSION}
  SOVERSION ${CMAKE_PROJECT_VERSION_MAJOR}
  OUTPUT_NAME utils-${CMAKE_PROJECT_VERSION}
)
target_sources(utils PUBLIC
  src/DoublyLinkedList.c
  src/Queue.c
  src/SinglyLinkedList.c
  src/Stack.c
)
add_dependencies(utils uncrustify)

include(CTest)
enable_testing()

function(add_test_with_valgrind name source)
  add_executable(${name} ${source})
  target_link_libraries(${name} utils)
  target_link_libraries(${name} Unity)
  add_test(NAME ${name} COMMAND ${name})
  add_test(NAME ${name}_valgrind
    COMMAND valgrind
      --tool=memcheck
      --leak-check=full       
      --trace-children=yes
      --show-error-list=yes
      --error-exitcode=2
      --xml=yes
      --xml-file=Testing/Temporary/${name}-valgrind-report.xml
      $<TARGET_FILE:${name}>
)
endfunction()

add_test_with_valgrind(test_DoublyLinkedList test/test_DoublyLinkedList.c)
add_test_with_valgrind(test_SinglyLinkedList test/test_SinglyLinkedList.c)
add_test_with_valgrind(test_Queue test/test_Queue.c)
add_test_with_valgrind(test_Stack test/test_Stack.c)
