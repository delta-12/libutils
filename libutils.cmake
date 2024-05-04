include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
add_library(utils)
target_sources(utils PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/src/BinarySearchTree.c
  ${CMAKE_CURRENT_LIST_DIR}/src/DoublyLinkedList.c
  ${CMAKE_CURRENT_LIST_DIR}/src/Queue.c
  ${CMAKE_CURRENT_LIST_DIR}/src/SinglyLinkedList.c
  ${CMAKE_CURRENT_LIST_DIR}/src/Stack.c
)