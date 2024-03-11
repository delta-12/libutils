#include "unity.h"
#include "SinglyLinkedList.h"

#define TEST_SINGLYLINKEDLIST_ITEM uint64_t
#define TEST_SINGLYLINKEDLIST_ITEM_SIZE sizeof(TEST_SINGLYLINKEDLIST_ITEM)

typedef TEST_SINGLYLINKEDLIST_ITEM test_SinglyLinkedList_Item_t;

static SinglyLinkedList_t test_SinglyLinkedList_List;
static test_SinglyLinkedList_Item_t test_SinglyLinkedList_Item;

void setUp(void)
{
  SinglyLinkedList_Init(&test_SinglyLinkedList_List, TEST_SINGLYLINKEDLIST_ITEM_SIZE);
  test_SinglyLinkedList_Item = 0UL;
}

void tearDown(void)
{
  SinglyLinkedList_Free(&test_SinglyLinkedList_List);
}

void test_SinglyLinkedList_Init(void)
{
  SinglyLinkedList_t list;

  TEST_ASSERT_FALSE(SinglyLinkedList_Init(NULL, TEST_SINGLYLINKEDLIST_ITEM_SIZE));

  SinglyLinkedList_Init(&list, TEST_SINGLYLINKEDLIST_ITEM_SIZE);
  TEST_ASSERT_NULL(list.Head);
  TEST_ASSERT_EQUAL(0UL, SinglyLinkedList_GetLength(&list));
  TEST_ASSERT_EQUAL(TEST_SINGLYLINKEDLIST_ITEM_SIZE, list.ItemSize);
}

void test_SinglyLinkedList_AppendPop(void)
{
  SinglyLinkedList_Reset(&test_SinglyLinkedList_List);
  TEST_ASSERT_FALSE(SinglyLinkedList_Append(&test_SinglyLinkedList_List, NULL));
  TEST_ASSERT_FALSE(SinglyLinkedList_Append(NULL, &test_SinglyLinkedList_Item));
  TEST_ASSERT_FALSE(SinglyLinkedList_Append(NULL, NULL));
  TEST_ASSERT_FALSE(SinglyLinkedList_Pop(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_FALSE(SinglyLinkedList_Pop(&test_SinglyLinkedList_List, NULL));
  TEST_ASSERT_FALSE(SinglyLinkedList_Pop(NULL, &test_SinglyLinkedList_Item));
  TEST_ASSERT_FALSE(SinglyLinkedList_Pop(NULL, NULL));

  for (test_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(SinglyLinkedList_Append(&test_SinglyLinkedList_List, &i));
  }
  for (test_SinglyLinkedList_Item_t i = 3UL; i > 0UL; i--)
  {
    TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(i - 1UL, test_SinglyLinkedList_Item);
  }
  TEST_ASSERT_FALSE(SinglyLinkedList_Pop(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));

  for (test_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(SinglyLinkedList_Append(&test_SinglyLinkedList_List, &i));
  }
  for (test_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&test_SinglyLinkedList_List, NULL));
  }
  TEST_ASSERT_FALSE(SinglyLinkedList_Pop(&test_SinglyLinkedList_List, NULL));

  test_SinglyLinkedList_Item = 0UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_Append(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  test_SinglyLinkedList_Item = 1UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_Append(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(1UL, test_SinglyLinkedList_Item);
  test_SinglyLinkedList_Item = 2UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_Append(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  test_SinglyLinkedList_Item = 3UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_Append(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(3UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(2UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(0UL, test_SinglyLinkedList_Item);
}

void test_SinglyLinkedList_AppendLeftPopLeft(void)
{
  SinglyLinkedList_Reset(&test_SinglyLinkedList_List);
  TEST_ASSERT_FALSE(SinglyLinkedList_AppendLeft(&test_SinglyLinkedList_List, NULL));
  TEST_ASSERT_FALSE(SinglyLinkedList_AppendLeft(NULL, &test_SinglyLinkedList_Item));
  TEST_ASSERT_FALSE(SinglyLinkedList_AppendLeft(NULL, NULL));
  TEST_ASSERT_FALSE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_FALSE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, NULL));
  TEST_ASSERT_FALSE(SinglyLinkedList_PopLeft(NULL, &test_SinglyLinkedList_Item));
  TEST_ASSERT_FALSE(SinglyLinkedList_PopLeft(NULL, NULL));

  for (test_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&test_SinglyLinkedList_List, &i));
  }
  for (test_SinglyLinkedList_Item_t i = 3UL; i > 0UL; i--)
  {
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(i - 1UL, test_SinglyLinkedList_Item);
  }
  TEST_ASSERT_FALSE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));

  for (test_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&test_SinglyLinkedList_List, &i));
  }
  for (test_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, NULL));
  }
  TEST_ASSERT_FALSE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, NULL));

  test_SinglyLinkedList_Item = 0UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  test_SinglyLinkedList_Item = 1UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(1UL, test_SinglyLinkedList_Item);
  test_SinglyLinkedList_Item = 2UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  test_SinglyLinkedList_Item = 3UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(3UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(2UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(0UL, test_SinglyLinkedList_Item);
}

void test_SinglyLinkedList_AppendLeftPop(void)
{
  SinglyLinkedList_Reset(&test_SinglyLinkedList_List);

  for (test_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&test_SinglyLinkedList_List, &i));
  }
  for (test_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(i, test_SinglyLinkedList_Item);
  }
  TEST_ASSERT_FALSE(SinglyLinkedList_Pop(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));

  test_SinglyLinkedList_Item = 0UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  test_SinglyLinkedList_Item = 1UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(0UL, test_SinglyLinkedList_Item);
  test_SinglyLinkedList_Item = 2UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  test_SinglyLinkedList_Item = 3UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_AppendLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(1UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(2UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_Pop(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(3UL, test_SinglyLinkedList_Item);
}

void test_SinglyLinkedList_AppendPopLeft(void)
{
  SinglyLinkedList_Reset(&test_SinglyLinkedList_List);

  for (test_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(SinglyLinkedList_Append(&test_SinglyLinkedList_List, &i));
  }
  for (test_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
    TEST_ASSERT_EQUAL(i, test_SinglyLinkedList_Item);
  }
  TEST_ASSERT_FALSE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));

  test_SinglyLinkedList_Item = 0UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_Append(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  test_SinglyLinkedList_Item = 1UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_Append(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(0UL, test_SinglyLinkedList_Item);
  test_SinglyLinkedList_Item = 2UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_Append(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  test_SinglyLinkedList_Item = 3UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_Append(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(1UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(2UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(3UL, test_SinglyLinkedList_Item);
}

void test_SinglyLinkedList_FreeReset(void)
{
  SinglyLinkedList_Reset(&test_SinglyLinkedList_List);

  TEST_ASSERT_FALSE(SinglyLinkedList_Free(NULL));
  TEST_ASSERT_FALSE(SinglyLinkedList_Reset(NULL));

  for (test_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    SinglyLinkedList_Append(&test_SinglyLinkedList_List, &i);
  }
  TEST_ASSERT_EQUAL(3UL, SinglyLinkedList_GetLength(&test_SinglyLinkedList_List));
  TEST_ASSERT_TRUE(SinglyLinkedList_Free(&test_SinglyLinkedList_List));
  TEST_ASSERT_NULL(test_SinglyLinkedList_List.Head);
  TEST_ASSERT_EQUAL(0UL, SinglyLinkedList_GetLength(&test_SinglyLinkedList_List));
  TEST_ASSERT_TRUE(SinglyLinkedList_Free(&test_SinglyLinkedList_List));

  for (test_SinglyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    SinglyLinkedList_Append(&test_SinglyLinkedList_List, &i);
  }
  TEST_ASSERT_EQUAL(3UL, SinglyLinkedList_GetLength(&test_SinglyLinkedList_List));
  TEST_ASSERT_TRUE(SinglyLinkedList_Reset(&test_SinglyLinkedList_List));
  TEST_ASSERT_NULL(test_SinglyLinkedList_List.Head);
  TEST_ASSERT_EQUAL(0UL, SinglyLinkedList_GetLength(&test_SinglyLinkedList_List));
  TEST_ASSERT_TRUE(SinglyLinkedList_Reset(&test_SinglyLinkedList_List));
}

void test_SinglyLinkedList_GetIndex(void)
{
  SinglyLinkedList_Reset(&test_SinglyLinkedList_List);

  test_SinglyLinkedList_Item = 0UL;
  TEST_ASSERT_EQUAL(SINGLY_LINKED_LIST_INDEX_ERROR, SinglyLinkedList_GetIndex(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(SINGLY_LINKED_LIST_INDEX_ERROR, SinglyLinkedList_GetIndex(NULL, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(SINGLY_LINKED_LIST_INDEX_ERROR, SinglyLinkedList_GetIndex(&test_SinglyLinkedList_List, NULL));
  TEST_ASSERT_EQUAL(SINGLY_LINKED_LIST_INDEX_ERROR, SinglyLinkedList_GetIndex(NULL, NULL));

  for (test_SinglyLinkedList_Item_t i = 0UL; i < 8UL; i++)
  {
    SinglyLinkedList_Append(&test_SinglyLinkedList_List, &i);
  }
  for (test_SinglyLinkedList_Item_t i = 0UL; i < 8UL; i++)
  {
    TEST_ASSERT_EQUAL(i, SinglyLinkedList_GetIndex(&test_SinglyLinkedList_List, &i));
  }
  test_SinglyLinkedList_Item = 8UL;
  TEST_ASSERT_EQUAL(SINGLY_LINKED_LIST_INDEX_ERROR, SinglyLinkedList_GetIndex(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
}

void test_SinglyLinkedList_GetLength(void)
{
  SinglyLinkedList_Reset(&test_SinglyLinkedList_List);

  TEST_ASSERT_EQUAL(SINGLY_LINKED_LIST_LENGTH_ERROR, SinglyLinkedList_GetLength(NULL));

  test_SinglyLinkedList_Item = 0UL;
  TEST_ASSERT_EQUAL(0UL, SinglyLinkedList_GetLength(&test_SinglyLinkedList_List));
  SinglyLinkedList_Append(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item);
  TEST_ASSERT_EQUAL(1UL, SinglyLinkedList_GetLength(&test_SinglyLinkedList_List));
  SinglyLinkedList_Append(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item);
  TEST_ASSERT_EQUAL(2UL, SinglyLinkedList_GetLength(&test_SinglyLinkedList_List));
  SinglyLinkedList_Pop(&test_SinglyLinkedList_List, NULL);
  TEST_ASSERT_EQUAL(1UL, SinglyLinkedList_GetLength(&test_SinglyLinkedList_List));
  SinglyLinkedList_Append(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item);
  SinglyLinkedList_Append(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item);
  SinglyLinkedList_Append(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item);
  TEST_ASSERT_EQUAL(4UL, SinglyLinkedList_GetLength(&test_SinglyLinkedList_List));
  SinglyLinkedList_Pop(&test_SinglyLinkedList_List, NULL);
  SinglyLinkedList_Pop(&test_SinglyLinkedList_List, NULL);
  TEST_ASSERT_EQUAL(2UL, SinglyLinkedList_GetLength(&test_SinglyLinkedList_List));
  SinglyLinkedList_Pop(&test_SinglyLinkedList_List, NULL);
  SinglyLinkedList_Pop(&test_SinglyLinkedList_List, NULL);
  TEST_ASSERT_EQUAL(0UL, SinglyLinkedList_GetLength(&test_SinglyLinkedList_List));
  SinglyLinkedList_Append(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item);
  TEST_ASSERT_EQUAL(1UL, SinglyLinkedList_GetLength(&test_SinglyLinkedList_List));
  SinglyLinkedList_Pop(&test_SinglyLinkedList_List, NULL);
  TEST_ASSERT_EQUAL(0UL, SinglyLinkedList_GetLength(&test_SinglyLinkedList_List));
  SinglyLinkedList_Append(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item);
  SinglyLinkedList_Append(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item);
  TEST_ASSERT_EQUAL(2UL, SinglyLinkedList_GetLength(&test_SinglyLinkedList_List));
  SinglyLinkedList_Pop(&test_SinglyLinkedList_List, NULL);
  SinglyLinkedList_Pop(&test_SinglyLinkedList_List, NULL);
  TEST_ASSERT_EQUAL(0UL, SinglyLinkedList_GetLength(&test_SinglyLinkedList_List));
}

void test_SinglyLinkedList_Insert(void)
{
  SinglyLinkedList_Reset(&test_SinglyLinkedList_List);

  TEST_ASSERT_FALSE(SinglyLinkedList_Insert(&test_SinglyLinkedList_List, 0L, NULL));
  TEST_ASSERT_FALSE(SinglyLinkedList_Insert(NULL, 0L, &test_SinglyLinkedList_Item));
  TEST_ASSERT_FALSE(SinglyLinkedList_Insert(NULL, 0L, NULL));
  TEST_ASSERT_FALSE(SinglyLinkedList_Insert(&test_SinglyLinkedList_List, -1L, &test_SinglyLinkedList_Item));

  test_SinglyLinkedList_Item = 5UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&test_SinglyLinkedList_List, 0L, &test_SinglyLinkedList_Item));
  test_SinglyLinkedList_Item = 2UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&test_SinglyLinkedList_List, 0L, &test_SinglyLinkedList_Item));
  test_SinglyLinkedList_Item = 0UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&test_SinglyLinkedList_List, 0L, &test_SinglyLinkedList_Item));
  test_SinglyLinkedList_Item = 1UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&test_SinglyLinkedList_List, 1L, &test_SinglyLinkedList_Item));
  test_SinglyLinkedList_Item = 3UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&test_SinglyLinkedList_List, 3L, &test_SinglyLinkedList_Item));
  test_SinglyLinkedList_Item = 4UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&test_SinglyLinkedList_List, 4L, &test_SinglyLinkedList_Item));
  test_SinglyLinkedList_Item = 6UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&test_SinglyLinkedList_List, 6L, &test_SinglyLinkedList_Item));
  test_SinglyLinkedList_Item = 10UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&test_SinglyLinkedList_List, 10L, &test_SinglyLinkedList_Item));

  TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(0UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(1UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(2UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(3UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(4UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(5UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(6UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(10UL, test_SinglyLinkedList_Item);

  test_SinglyLinkedList_Item = 0UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&test_SinglyLinkedList_List, 10L, &test_SinglyLinkedList_Item));
  test_SinglyLinkedList_Item = 1UL;
  TEST_ASSERT_TRUE(SinglyLinkedList_Insert(&test_SinglyLinkedList_List, 1L, &test_SinglyLinkedList_Item));
  TEST_ASSERT_FALSE(SinglyLinkedList_Insert(&test_SinglyLinkedList_List, -1L, &test_SinglyLinkedList_Item));
  TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(0UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_PopLeft(&test_SinglyLinkedList_List, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(1UL, test_SinglyLinkedList_Item);
}

void test_SinglyLinkedList_Remove(void)
{
  SinglyLinkedList_Reset(&test_SinglyLinkedList_List);

  TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 0L, &test_SinglyLinkedList_Item));
  TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 0L, NULL));
  TEST_ASSERT_FALSE(SinglyLinkedList_Remove(NULL, 0L, &test_SinglyLinkedList_Item));
  TEST_ASSERT_FALSE(SinglyLinkedList_Remove(NULL, 0L, NULL));

  for (test_SinglyLinkedList_Item_t i = 0UL; i < 10UL; i++)
  {
    SinglyLinkedList_Append(&test_SinglyLinkedList_List, &i);
  }
  TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, -1L, &test_SinglyLinkedList_Item));
  TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 10L, &test_SinglyLinkedList_Item));
  TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 9L, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(9UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 7L, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(7UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 8L, &test_SinglyLinkedList_Item));
  TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 5L, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(5UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 1L, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(1UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 4L, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(6UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 2L, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(3UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 2L, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(4UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 3L, &test_SinglyLinkedList_Item));
  TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 2L, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(8UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 0L, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(0UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 0L, &test_SinglyLinkedList_Item));
  TEST_ASSERT_EQUAL(2UL, test_SinglyLinkedList_Item);
  TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 0L, &test_SinglyLinkedList_Item));

  for (test_SinglyLinkedList_Item_t i = 0UL; i < 5UL; i++)
  {
    SinglyLinkedList_Append(&test_SinglyLinkedList_List, &i);
  }
  TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, -1L, NULL));
  TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 0L, NULL));
  TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 3L, NULL));
  TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 4L, NULL));
  TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 1L, NULL));
  TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 1L, NULL));
  TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 1L, NULL));
  TEST_ASSERT_TRUE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 0L, NULL));
  TEST_ASSERT_FALSE(SinglyLinkedList_Remove(&test_SinglyLinkedList_List, 0L, NULL));
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