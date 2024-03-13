include_directories(include)

set(STACK_SOURCES
    src/Stack.c
)
set(TEST_STACK_SOURCES
    test/test_Stack.c
)

add_library(Stack ${STACK_SOURCES})

add_executable(test_Stack ${TEST_STACK_SOURCES})
target_link_libraries(test_Stack Stack)
