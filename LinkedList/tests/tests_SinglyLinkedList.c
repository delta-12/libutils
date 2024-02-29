#include "unity.h"
#include "SinglyLinkedList.h"

#define TESTS_SINGLYLINKEDLIST_ITEM_SIZE sizeof(uint64_t)

void setUp(void)
{
}

void tearDown(void)
{
}

void test_SinglyLinkedList_Init(void)
{
    SinglyLinkedList_t list;

    SinglyLinkedList_Init(&list, TESTS_SINGLYLINKEDLIST_ITEM_SIZE);
    TEST_ASSERT_NULL(list.Head);
    TEST_ASSERT_EQUAL(0, list.Length);
    TEST_ASSERT_EQUAL(TESTS_SINGLYLINKEDLIST_ITEM_SIZE, list.ItemSize);
}

void test_SinglyLinkedList_AppendPop(void) { TEST_ASSERT_TRUE(false); }
void test_SinglyLinkedList_AppendLeftPopLeft(void) { TEST_ASSERT_TRUE(false); }
void test_SinglyLinkedList_AppendLeftPop(void) { TEST_ASSERT_TRUE(false); }
void test_SinglyLinkedList_AppendPopLeft(void) { TEST_ASSERT_TRUE(false); }
void test_SinglyLinkedList_FreeReset(void) { TEST_ASSERT_TRUE(false); }
void test_SinglyLinkedList_GetIndex(void) { TEST_ASSERT_TRUE(false); }
void test_SinglyLinkedList_GetLength(void) { TEST_ASSERT_TRUE(false); }
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