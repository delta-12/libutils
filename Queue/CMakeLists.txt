include_directories(include)

set(QUEUE_SOURCES
    src/Queue.c
)
set(TEST_QUEUE_SOURCES
    test/test_Queue.c
)

add_library(Queue ${QUEUE_SOURCES})

add_executable(test_Queue ${TEST_QUEUE_SOURCES})
target_link_libraries(test_Queue Queue)
