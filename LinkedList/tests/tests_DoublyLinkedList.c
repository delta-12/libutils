#include "unity.h"
#include "DoublyLinkedList.h"

#define TESTS_DOUBLYLINKEDLIST_ITEM uint64_t
#define TESTS_DOUBLYLINKEDLIST_ITEM_SIZE sizeof(TESTS_DOUBLYLINKEDLIST_ITEM)

typedef TESTS_DOUBLYLINKEDLIST_ITEM tests_DoublyLinkedList_Item_t;

static DoublyLinkedList_t tests_DoublyLinkedList_List;
static tests_DoublyLinkedList_Item_t tests_DoublyLinkedList_Item;

void setUp(void)
{
    DoublyLinkedList_Init(&tests_DoublyLinkedList_List, TESTS_DOUBLYLINKEDLIST_ITEM_SIZE);
    tests_DoublyLinkedList_Item = 0UL;
}

void tearDown(void)
{
    DoublyLinkedList_Free(&tests_DoublyLinkedList_List);
}

void test_DoublyLinkedList_Init(void)
{
    DoublyLinkedList_t list;

    TEST_ASSERT_FALSE(DoublyLinkedList_Init(NULL, TESTS_DOUBLYLINKEDLIST_ITEM_SIZE));

    DoublyLinkedList_Init(&list, TESTS_DOUBLYLINKEDLIST_ITEM_SIZE);
    TEST_ASSERT_NULL(list.Head);
    TEST_ASSERT_NULL(list.Tail);
    TEST_ASSERT_EQUAL(0UL, DoublyLinkedList_GetLength(&list));
    TEST_ASSERT_EQUAL(TESTS_DOUBLYLINKEDLIST_ITEM_SIZE, list.ItemSize);
}

void test_DoublyLinkedList_AppendPop(void)
{
    DoublyLinkedList_Reset(&tests_DoublyLinkedList_List);
    TEST_ASSERT_FALSE(DoublyLinkedList_Append(&tests_DoublyLinkedList_List, NULL));
    TEST_ASSERT_FALSE(DoublyLinkedList_Append(NULL, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_FALSE(DoublyLinkedList_Append(NULL, NULL));
    TEST_ASSERT_FALSE(DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_FALSE(DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, NULL));
    TEST_ASSERT_FALSE(DoublyLinkedList_Pop(NULL, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_FALSE(DoublyLinkedList_Pop(NULL, NULL));

    for (tests_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &i));
    }
    for (tests_DoublyLinkedList_Item_t i = 3UL; i > 0UL; i--)
    {
        TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
        TEST_ASSERT_EQUAL(i - 1UL, tests_DoublyLinkedList_Item);
    }
    TEST_ASSERT_FALSE(DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));

    for (tests_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &i));
    }
    for (tests_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, NULL));
    }
    TEST_ASSERT_FALSE(DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, NULL));

    tests_DoublyLinkedList_Item = 0UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    tests_DoublyLinkedList_Item = 1UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(1UL, tests_DoublyLinkedList_Item);
    tests_DoublyLinkedList_Item = 2UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    tests_DoublyLinkedList_Item = 3UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(3UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(2UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(0UL, tests_DoublyLinkedList_Item);
}

void test_DoublyLinkedList_AppendLeftPopLeft(void)
{
    DoublyLinkedList_Reset(&tests_DoublyLinkedList_List);
    TEST_ASSERT_FALSE(DoublyLinkedList_AppendLeft(&tests_DoublyLinkedList_List, NULL));
    TEST_ASSERT_FALSE(DoublyLinkedList_AppendLeft(NULL, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_FALSE(DoublyLinkedList_AppendLeft(NULL, NULL));
    TEST_ASSERT_FALSE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_FALSE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, NULL));
    TEST_ASSERT_FALSE(DoublyLinkedList_PopLeft(NULL, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_FALSE(DoublyLinkedList_PopLeft(NULL, NULL));

    for (tests_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&tests_DoublyLinkedList_List, &i));
    }
    for (tests_DoublyLinkedList_Item_t i = 3UL; i > 0UL; i--)
    {
        TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
        TEST_ASSERT_EQUAL(i - 1UL, tests_DoublyLinkedList_Item);
    }
    TEST_ASSERT_FALSE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));

    for (tests_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&tests_DoublyLinkedList_List, &i));
    }
    for (tests_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, NULL));
    }
    TEST_ASSERT_FALSE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, NULL));

    tests_DoublyLinkedList_Item = 0UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    tests_DoublyLinkedList_Item = 1UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(1UL, tests_DoublyLinkedList_Item);
    tests_DoublyLinkedList_Item = 2UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    tests_DoublyLinkedList_Item = 3UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(3UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(2UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(0UL, tests_DoublyLinkedList_Item);
}

void test_DoublyLinkedList_AppendLeftPop(void)
{
    DoublyLinkedList_Reset(&tests_DoublyLinkedList_List);

    for (tests_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&tests_DoublyLinkedList_List, &i));
    }
    for (tests_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
        TEST_ASSERT_EQUAL(i, tests_DoublyLinkedList_Item);
    }
    TEST_ASSERT_FALSE(DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));

    tests_DoublyLinkedList_Item = 0UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    tests_DoublyLinkedList_Item = 1UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(0UL, tests_DoublyLinkedList_Item);
    tests_DoublyLinkedList_Item = 2UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    tests_DoublyLinkedList_Item = 3UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(1UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(2UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(3UL, tests_DoublyLinkedList_Item);
}

void test_DoublyLinkedList_AppendPopLeft(void)
{
    DoublyLinkedList_Reset(&tests_DoublyLinkedList_List);

    for (tests_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &i));
    }
    for (tests_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
        TEST_ASSERT_EQUAL(i, tests_DoublyLinkedList_Item);
    }
    TEST_ASSERT_FALSE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));

    tests_DoublyLinkedList_Item = 0UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    tests_DoublyLinkedList_Item = 1UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(0UL, tests_DoublyLinkedList_Item);
    tests_DoublyLinkedList_Item = 2UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    tests_DoublyLinkedList_Item = 3UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(1UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(2UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(3UL, tests_DoublyLinkedList_Item);
}

void test_DoublyLinkedList_FreeReset(void)
{
    DoublyLinkedList_Reset(&tests_DoublyLinkedList_List);

    TEST_ASSERT_FALSE(DoublyLinkedList_Free(NULL));
    TEST_ASSERT_FALSE(DoublyLinkedList_Reset(NULL));

    for (tests_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &i);
    }
    TEST_ASSERT_EQUAL(3UL, DoublyLinkedList_GetLength(&tests_DoublyLinkedList_List));
    TEST_ASSERT_TRUE(DoublyLinkedList_Free(&tests_DoublyLinkedList_List));
    TEST_ASSERT_NULL(tests_DoublyLinkedList_List.Head);
    TEST_ASSERT_NULL(tests_DoublyLinkedList_List.Tail);
    TEST_ASSERT_EQUAL(0UL, DoublyLinkedList_GetLength(&tests_DoublyLinkedList_List));
    TEST_ASSERT_TRUE(DoublyLinkedList_Free(&tests_DoublyLinkedList_List));

    for (tests_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &i);
    }
    TEST_ASSERT_EQUAL(3UL, DoublyLinkedList_GetLength(&tests_DoublyLinkedList_List));
    TEST_ASSERT_TRUE(DoublyLinkedList_Reset(&tests_DoublyLinkedList_List));
    TEST_ASSERT_NULL(tests_DoublyLinkedList_List.Head);
    TEST_ASSERT_NULL(tests_DoublyLinkedList_List.Tail);
    TEST_ASSERT_EQUAL(0UL, DoublyLinkedList_GetLength(&tests_DoublyLinkedList_List));
    TEST_ASSERT_TRUE(DoublyLinkedList_Reset(&tests_DoublyLinkedList_List));
}

void test_DoublyLinkedList_GetIndex(void)
{
    DoublyLinkedList_Reset(&tests_DoublyLinkedList_List);

    tests_DoublyLinkedList_Item = 0UL;
    TEST_ASSERT_EQUAL(DOUBLY_LINKED_LIST_INDEX_ERROR, DoublyLinkedList_GetIndex(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(DOUBLY_LINKED_LIST_INDEX_ERROR, DoublyLinkedList_GetIndex(NULL, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(DOUBLY_LINKED_LIST_INDEX_ERROR, DoublyLinkedList_GetIndex(&tests_DoublyLinkedList_List, NULL));
    TEST_ASSERT_EQUAL(DOUBLY_LINKED_LIST_INDEX_ERROR, DoublyLinkedList_GetIndex(NULL, NULL));

    for (tests_DoublyLinkedList_Item_t i = 0UL; i < 8UL; i++)
    {
        DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &i);
    }
    for (tests_DoublyLinkedList_Item_t i = 0UL; i < 8UL; i++)
    {
        TEST_ASSERT_EQUAL(i, DoublyLinkedList_GetIndex(&tests_DoublyLinkedList_List, &i));
    }
    tests_DoublyLinkedList_Item = 8UL;
    TEST_ASSERT_EQUAL(DOUBLY_LINKED_LIST_INDEX_ERROR, DoublyLinkedList_GetIndex(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
}

void test_DoublyLinkedList_GetLength(void)
{
    DoublyLinkedList_Reset(&tests_DoublyLinkedList_List);

    TEST_ASSERT_EQUAL(DOUBLY_LINKED_LIST_LENGTH_ERROR, DoublyLinkedList_GetLength(NULL));

    tests_DoublyLinkedList_Item = 0UL;
    TEST_ASSERT_EQUAL(0UL, DoublyLinkedList_GetLength(&tests_DoublyLinkedList_List));
    DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item);
    TEST_ASSERT_EQUAL(1UL, DoublyLinkedList_GetLength(&tests_DoublyLinkedList_List));
    DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item);
    TEST_ASSERT_EQUAL(2UL, DoublyLinkedList_GetLength(&tests_DoublyLinkedList_List));
    DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, NULL);
    TEST_ASSERT_EQUAL(1UL, DoublyLinkedList_GetLength(&tests_DoublyLinkedList_List));
    DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item);
    DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item);
    DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item);
    TEST_ASSERT_EQUAL(4UL, DoublyLinkedList_GetLength(&tests_DoublyLinkedList_List));
    DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, NULL);
    DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, NULL);
    TEST_ASSERT_EQUAL(2UL, DoublyLinkedList_GetLength(&tests_DoublyLinkedList_List));
    DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, NULL);
    DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, NULL);
    TEST_ASSERT_EQUAL(0UL, DoublyLinkedList_GetLength(&tests_DoublyLinkedList_List));
    DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item);
    TEST_ASSERT_EQUAL(1UL, DoublyLinkedList_GetLength(&tests_DoublyLinkedList_List));
    DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, NULL);
    TEST_ASSERT_EQUAL(0UL, DoublyLinkedList_GetLength(&tests_DoublyLinkedList_List));
    DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item);
    DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item);
    TEST_ASSERT_EQUAL(2UL, DoublyLinkedList_GetLength(&tests_DoublyLinkedList_List));
    DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, NULL);
    DoublyLinkedList_Pop(&tests_DoublyLinkedList_List, NULL);
    TEST_ASSERT_EQUAL(0UL, DoublyLinkedList_GetLength(&tests_DoublyLinkedList_List));
}

void test_DoublyLinkedList_Insert(void)
{
    DoublyLinkedList_Reset(&tests_DoublyLinkedList_List);

    TEST_ASSERT_FALSE(DoublyLinkedList_Insert(&tests_DoublyLinkedList_List, 0L, NULL));
    TEST_ASSERT_FALSE(DoublyLinkedList_Insert(NULL, 0L, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_FALSE(DoublyLinkedList_Insert(NULL, 0L, NULL));
    TEST_ASSERT_FALSE(DoublyLinkedList_Insert(&tests_DoublyLinkedList_List, -1L, &tests_DoublyLinkedList_Item));

    tests_DoublyLinkedList_Item = 5UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&tests_DoublyLinkedList_List, 0L, &tests_DoublyLinkedList_Item));
    tests_DoublyLinkedList_Item = 2UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&tests_DoublyLinkedList_List, 0L, &tests_DoublyLinkedList_Item));
    tests_DoublyLinkedList_Item = 0UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&tests_DoublyLinkedList_List, 0L, &tests_DoublyLinkedList_Item));
    tests_DoublyLinkedList_Item = 1UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&tests_DoublyLinkedList_List, 1L, &tests_DoublyLinkedList_Item));
    tests_DoublyLinkedList_Item = 3UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&tests_DoublyLinkedList_List, 3L, &tests_DoublyLinkedList_Item));
    tests_DoublyLinkedList_Item = 4UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&tests_DoublyLinkedList_List, 4L, &tests_DoublyLinkedList_Item));
    tests_DoublyLinkedList_Item = 6UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&tests_DoublyLinkedList_List, 6L, &tests_DoublyLinkedList_Item));
    tests_DoublyLinkedList_Item = 10UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&tests_DoublyLinkedList_List, 10L, &tests_DoublyLinkedList_Item));

    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(0UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(1UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(2UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(3UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(4UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(5UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(6UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(10UL, tests_DoublyLinkedList_Item);

    tests_DoublyLinkedList_Item = 0UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&tests_DoublyLinkedList_List, 10L, &tests_DoublyLinkedList_Item));
    tests_DoublyLinkedList_Item = 1UL;
    TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&tests_DoublyLinkedList_List, 1L, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_FALSE(DoublyLinkedList_Insert(&tests_DoublyLinkedList_List, -1L, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(0UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&tests_DoublyLinkedList_List, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(1UL, tests_DoublyLinkedList_Item);
}

void test_DoublyLinkedList_Remove(void)
{
    DoublyLinkedList_Reset(&tests_DoublyLinkedList_List);

    TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 0L, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 0L, NULL));
    TEST_ASSERT_FALSE(DoublyLinkedList_Remove(NULL, 0L, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_FALSE(DoublyLinkedList_Remove(NULL, 0L, NULL));

    for (tests_DoublyLinkedList_Item_t i = 0UL; i < 10UL; i++)
    {
        DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &i);
    }
    TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, -1L, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 10L, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 9L, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(9UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 7L, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(7UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 8L, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 5L, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(5UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 1L, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(1UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 4L, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(6UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 2L, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(3UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 2L, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(4UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 3L, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 2L, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(8UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 0L, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(0UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 0L, &tests_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(2UL, tests_DoublyLinkedList_Item);
    TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 0L, &tests_DoublyLinkedList_Item));

    for (tests_DoublyLinkedList_Item_t i = 0UL; i < 5UL; i++)
    {
        DoublyLinkedList_Append(&tests_DoublyLinkedList_List, &i);
    }
    TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, -1L, NULL));
    TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 0L, NULL));
    TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 3L, NULL));
    TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 4L, NULL));
    TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 1L, NULL));
    TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 1L, NULL));
    TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 1L, NULL));
    TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 0L, NULL));
    TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&tests_DoublyLinkedList_List, 0L, NULL));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_DoublyLinkedList_Init);
    RUN_TEST(test_DoublyLinkedList_AppendPop);
    RUN_TEST(test_DoublyLinkedList_AppendLeftPopLeft);
    RUN_TEST(test_DoublyLinkedList_AppendLeftPop);
    RUN_TEST(test_DoublyLinkedList_AppendPopLeft);
    RUN_TEST(test_DoublyLinkedList_FreeReset);
    RUN_TEST(test_DoublyLinkedList_GetIndex);
    RUN_TEST(test_DoublyLinkedList_GetLength);
    RUN_TEST(test_DoublyLinkedList_Insert);
    RUN_TEST(test_DoublyLinkedList_Remove);

    return UNITY_END();
}