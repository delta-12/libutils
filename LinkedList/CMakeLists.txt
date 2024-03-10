include_directories(include)

set(LINKEDLIST_SOURCES
    src/DoublyLinkedList.c
    src/SinglyLinkedList.c
)
set(TEST_DOUBLYINKEDLIST_SOURCES
    test/test_DoublyLinkedList.c
)
set(TEST_SINGLYLINKEDLIST_SOURCES
    test/test_SinglyLinkedList.c
)

add_library(LinkedList ${LINKEDLIST_SOURCES})

add_executable(test_DoublyLinkedList ${TEST_DOUBLYINKEDLIST_SOURCES})
target_link_libraries(test_DoublyLinkedList LinkedList)

add_executable(test_SinglyLinkedList ${TEST_SINGLYLINKEDLIST_SOURCES})
target_link_libraries(test_SinglyLinkedList LinkedList)
