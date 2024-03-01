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

    SinglyLinkedList_Init(&list, TESTS_SINGLYLINKEDLIST_ITEM_SIZE);
    TEST_ASSERT_NULL(list.Head);
    TEST_ASSERT_EQUAL(0, list.Length);
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

void test_SinglyLinkedList_AppendLeftPop(void) { TEST_ASSERT_TRUE(false); }
void test_SinglyLinkedList_AppendPopLeft(void) { TEST_ASSERT_TRUE(false); }
void test_SinglyLinkedList_FreeReset(void) { TEST_ASSERT_TRUE(false); }
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

void test_SinglyLinkedList_InsertRemove(void) { TEST_ASSERT_TRUE(false); }

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
    RUN_TEST(test_SinglyLinkedList_InsertRemove);

    return UNITY_END();
}