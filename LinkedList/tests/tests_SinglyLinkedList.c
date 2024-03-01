#include "unity.h"
#include "SinglyLinkedList.h"

#define TESTS_SINGLYLINKEDLIST_ITEM uint64_t
#define TESTS_SINGLYLINKEDLIST_ITEM_SIZE sizeof(TESTS_SINGLYLINKEDLIST_ITEM)

typedef TESTS_SINGLYLINKEDLIST_ITEM tests_SinglyLinkedList_Item_t;

static SinglyLinkedList_t tests_SinglyLinkedList_List;
static tests_SinglyLinkedList_Item_t tests_SinglyLinkedList_Item;

void setUp(void)
{
    SinglyLinkedList_Init(&tests_SinglyLinkedList_List, TESTS_SINGLYLINKEDLIST_ITEM_SIZE);
    tests_SinglyLinkedList_Item = 0UL;
}

void tearDown(void)
{
    SinglyLinkedList_Free(&tests_SinglyLinkedList_List);
}

void test_SinglyLinkedList_Init(void)
{
    SinglyLinkedList_t list;

    TEST_ASSERT_FALSE(SinglyLinkedList_Init(NULL, TESTS_SINGLYLINKEDLIST_ITEM_SIZE));

    SinglyLinkedList_Init(&list, TESTS_SINGLYLINKEDLIST_ITEM_SIZE);
    TEST_ASSERT_NULL(list.Head);
    TEST_ASSERT_EQUAL(0UL, SinglyLinkedList_GetLength(&list));
    TEST_ASSERT_EQUAL(TESTS_SINGLYLINKEDLIST_ITEM_SIZE, list.ItemSize);
}

void test_SinglyLinkedList_AppendPop(void)
{
    SinglyLinkedList_Reset(&tests_SinglyLinkedList_List);
    TEST_ASSERT_FALSE(SinglyLinkedList_Append(&tests_SinglyLinkedList_List, NULL));
    TEST_ASSERT_FALSE(SinglyLinkedList_Append(NULL, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_FALSE(SinglyLinkedList_Append(NULL, NULL));
    TEST_ASSERT_FALSE(SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_FALSE(SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, NULL));
    TEST_ASSERT_FALSE(SinglyLinkedList_Pop(NULL, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_FALSE(SinglyLinkedList_Pop(NULL, NULL));

    for (tests_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &i));
    }
    for (tests_SinglyLinkedList_Item_t i = 3UL; i > 0UL; i--)
    {
        TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
        TEST_ASSERT_EQUAL(i - 1UL, tests_SinglyLinkedList_Item);
    }
    TEST_ASSERT_FALSE(SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));

    for (tests_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &i));
    }
    for (tests_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, NULL));
    }
    TEST_ASSERT_FALSE(SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, NULL));

    tests_SinglyLinkedList_Item = 0UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    tests_SinglyLinkedList_Item = 1UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(1UL, tests_SinglyLinkedList_Item);
    tests_SinglyLinkedList_Item = 2UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    tests_SinglyLinkedList_Item = 3UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(3UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(2UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(0UL, tests_SinglyLinkedList_Item);
}

void test_SinglyLinkedList_AppendLeftPopLeft(void)
{
    SinglyLinkedList_Reset(&tests_SinglyLinkedList_List);
    TEST_ASSERT_FALSE(SinglyLinkedList_AppendLeft(&tests_SinglyLinkedList_List, NULL));
    TEST_ASSERT_FALSE(SinglyLinkedList_AppendLeft(NULL, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_FALSE(SinglyLinkedList_AppendLeft(NULL, NULL));
    TEST_ASSERT_FALSE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_FALSE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, NULL));
    TEST_ASSERT_FALSE(SinglyLinkedList_PopLeft(NULL, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_FALSE(SinglyLinkedList_PopLeft(NULL, NULL));

    for (tests_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&tests_SinglyLinkedList_List, &i));
    }
    for (tests_SinglyLinkedList_Item_t i = 3UL; i > 0UL; i--)
    {
        TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
        TEST_ASSERT_EQUAL(i - 1UL, tests_SinglyLinkedList_Item);
    }
    TEST_ASSERT_FALSE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));

    for (tests_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&tests_SinglyLinkedList_List, &i));
    }
    for (tests_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, NULL));
    }
    TEST_ASSERT_FALSE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, NULL));

    tests_SinglyLinkedList_Item = 0UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    tests_SinglyLinkedList_Item = 1UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(1UL, tests_SinglyLinkedList_Item);
    tests_SinglyLinkedList_Item = 2UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    tests_SinglyLinkedList_Item = 3UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(3UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(2UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(0UL, tests_SinglyLinkedList_Item);
}

void test_SinglyLinkedList_AppendLeftPop(void)
{
    SinglyLinkedList_Reset(&tests_SinglyLinkedList_List);

    for (tests_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&tests_SinglyLinkedList_List, &i));
    }
    for (tests_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
        TEST_ASSERT_EQUAL(i, tests_SinglyLinkedList_Item);
    }
    TEST_ASSERT_FALSE(SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));

    tests_SinglyLinkedList_Item = 0UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    tests_SinglyLinkedList_Item = 1UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(0UL, tests_SinglyLinkedList_Item);
    tests_SinglyLinkedList_Item = 2UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    tests_SinglyLinkedList_Item = 3UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(1UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(2UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(3UL, tests_SinglyLinkedList_Item);
}

void test_SinglyLinkedList_AppendPopLeft(void)
{
    SinglyLinkedList_Reset(&tests_SinglyLinkedList_List);

    for (tests_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &i));
    }
    for (tests_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
        TEST_ASSERT_EQUAL(i, tests_SinglyLinkedList_Item);
    }
    TEST_ASSERT_FALSE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));

    tests_SinglyLinkedList_Item = 0UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    tests_SinglyLinkedList_Item = 1UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(0UL, tests_SinglyLinkedList_Item);
    tests_SinglyLinkedList_Item = 2UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    tests_SinglyLinkedList_Item = 3UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(1UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(2UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(3UL, tests_SinglyLinkedList_Item);
}

void test_SinglyLinkedList_FreeReset(void)
{
    SinglyLinkedList_Reset(&tests_SinglyLinkedList_List);

    TEST_ASSERT_FALSE(SinglyLinkedList_Free(NULL));
    TEST_ASSERT_FALSE(SinglyLinkedList_Reset(NULL));

    for (tests_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &i);
    }
    TEST_ASSERT_EQUAL(3UL, SinglyLinkedList_GetLength(&tests_SinglyLinkedList_List));
    TEST_ASSERT_TRUE(SinglyLinkedList_Free(&tests_SinglyLinkedList_List));
    TEST_ASSERT_NULL(tests_SinglyLinkedList_List.Head);
    TEST_ASSERT_EQUAL(0UL, SinglyLinkedList_GetLength(&tests_SinglyLinkedList_List));
    TEST_ASSERT_TRUE(SinglyLinkedList_Free(&tests_SinglyLinkedList_List));

    for (tests_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
    {
        SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &i);
    }
    TEST_ASSERT_EQUAL(3UL, SinglyLinkedList_GetLength(&tests_SinglyLinkedList_List));
    TEST_ASSERT_TRUE(SinglyLinkedList_Reset(&tests_SinglyLinkedList_List));
    TEST_ASSERT_NULL(tests_SinglyLinkedList_List.Head);
    TEST_ASSERT_EQUAL(0UL, SinglyLinkedList_GetLength(&tests_SinglyLinkedList_List));
    TEST_ASSERT_TRUE(SinglyLinkedList_Reset(&tests_SinglyLinkedList_List));
}

void test_SinglyLinkedList_GetIndex(void) { TEST_ASSERT_TRUE(false); }

void test_SinglyLinkedList_GetLength(void)
{
    SinglyLinkedList_Reset(&tests_SinglyLinkedList_List);
    tests_SinglyLinkedList_Item = 0UL;
    TEST_ASSERT_EQUAL(0UL, SinglyLinkedList_GetLength(&tests_SinglyLinkedList_List));
    SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item);
    TEST_ASSERT_EQUAL(1UL, SinglyLinkedList_GetLength(&tests_SinglyLinkedList_List));
    SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item);
    TEST_ASSERT_EQUAL(2UL, SinglyLinkedList_GetLength(&tests_SinglyLinkedList_List));
    SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, NULL);
    TEST_ASSERT_EQUAL(1UL, SinglyLinkedList_GetLength(&tests_SinglyLinkedList_List));
    SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item);
    SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item);
    SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item);
    TEST_ASSERT_EQUAL(4UL, SinglyLinkedList_GetLength(&tests_SinglyLinkedList_List));
    SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, NULL);
    SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, NULL);
    TEST_ASSERT_EQUAL(2UL, SinglyLinkedList_GetLength(&tests_SinglyLinkedList_List));
    SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, NULL);
    SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, NULL);
    TEST_ASSERT_EQUAL(0UL, SinglyLinkedList_GetLength(&tests_SinglyLinkedList_List));
    SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item);
    TEST_ASSERT_EQUAL(1UL, SinglyLinkedList_GetLength(&tests_SinglyLinkedList_List));
    SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, NULL);
    TEST_ASSERT_EQUAL(0UL, SinglyLinkedList_GetLength(&tests_SinglyLinkedList_List));
    SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item);
    SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item);
    TEST_ASSERT_EQUAL(2UL, SinglyLinkedList_GetLength(&tests_SinglyLinkedList_List));
    SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, NULL);
    SinglyLinkedList_Pop(&tests_SinglyLinkedList_List, NULL);
    TEST_ASSERT_EQUAL(0UL, SinglyLinkedList_GetLength(&tests_SinglyLinkedList_List));
}

void test_SinglyLinkedList_Insert(void)
{
    SinglyLinkedList_Reset(&tests_SinglyLinkedList_List);

    TEST_ASSERT_FALSE(SinglyLinkedList_Insert(&tests_SinglyLinkedList_List, 0L, NULL));
    TEST_ASSERT_FALSE(SinglyLinkedList_Insert(NULL, 0L, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_FALSE(SinglyLinkedList_Insert(NULL, 0L, NULL));
    TEST_ASSERT_FALSE(SinglyLinkedList_Insert(&tests_SinglyLinkedList_List, -1L, &tests_SinglyLinkedList_Item));

    tests_SinglyLinkedList_Item = 5UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&tests_SinglyLinkedList_List, 0L, &tests_SinglyLinkedList_Item));
    tests_SinglyLinkedList_Item = 2UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&tests_SinglyLinkedList_List, 0L, &tests_SinglyLinkedList_Item));
    tests_SinglyLinkedList_Item = 0UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&tests_SinglyLinkedList_List, 0L, &tests_SinglyLinkedList_Item));
    tests_SinglyLinkedList_Item = 1UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&tests_SinglyLinkedList_List, 1L, &tests_SinglyLinkedList_Item));
    tests_SinglyLinkedList_Item = 3UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&tests_SinglyLinkedList_List, 3L, &tests_SinglyLinkedList_Item));
    tests_SinglyLinkedList_Item = 4UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&tests_SinglyLinkedList_List, 4L, &tests_SinglyLinkedList_Item));
    tests_SinglyLinkedList_Item = 6UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&tests_SinglyLinkedList_List, 6L, &tests_SinglyLinkedList_Item));
    tests_SinglyLinkedList_Item = 10UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&tests_SinglyLinkedList_List, 10L, &tests_SinglyLinkedList_Item));

    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(0UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(1UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(2UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(3UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(4UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(5UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(6UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(10UL, tests_SinglyLinkedList_Item);

    tests_SinglyLinkedList_Item = 0UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&tests_SinglyLinkedList_List, 10L, &tests_SinglyLinkedList_Item));
    tests_SinglyLinkedList_Item = 1UL;
    TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&tests_SinglyLinkedList_List, 1L, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_FALSE(SinglyLinkedList_Insert(&tests_SinglyLinkedList_List, -1L, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(0UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&tests_SinglyLinkedList_List, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(1UL, tests_SinglyLinkedList_Item);
}

void test_SinglyLinkedList_Remove(void)
{
    SinglyLinkedList_Reset(&tests_SinglyLinkedList_List);

    TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 0L, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 0L, NULL));
    TEST_ASSERT_FALSE(SinglyLinkedList_Remove(NULL, 0L, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_FALSE(SinglyLinkedList_Remove(NULL, 0L, NULL));

    for (tests_SinglyLinkedList_Item_t i = 0UL; i < 10UL; i++)
    {
        SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &i);
    }
    TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, -1L, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 10L, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 9L, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(9UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 7L, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(7UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 8L, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 5L, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(5UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 1L, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(1UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 4L, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(6UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 2L, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(3UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 2L, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(4UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 3L, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 2L, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(8UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 0L, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(0UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 0L, &tests_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(2UL, tests_SinglyLinkedList_Item);
    TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 0L, &tests_SinglyLinkedList_Item));

    for (tests_SinglyLinkedList_Item_t i = 0UL; i < 5UL; i++)
    {
        SinglyLinkedList_Append(&tests_SinglyLinkedList_List, &i);
    }
    TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, -1L, NULL));
    TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 0L, NULL));
    TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 3L, NULL));
    TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 4L, NULL));
    TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 1L, NULL));
    TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 1L, NULL));
    TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 1L, NULL));
    TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 0L, NULL));
    TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&tests_SinglyLinkedList_List, 0L, NULL));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_SinglyLinkedList_Init);
    RUN_TEST(test_SinglyLinkedList_AppendPop);
    RUN_TEST(test_SinglyLinkedList_AppendLeftPopLeft);
    RUN_TEST(test_SinglyLinkedList_AppendLeftPop);
    RUN_TEST(test_SinglyLinkedList_AppendPopLeft);
    RUN_TEST(test_SinglyLinkedList_FreeReset);
    RUN_TEST(test_SinglyLinkedList_GetIndex);
    RUN_TEST(test_SinglyLinkedList_GetLength);
    RUN_TEST(test_SinglyLinkedList_Insert);
    RUN_TEST(test_SinglyLinkedList_Remove);

    return UNITY_END();
}