#include "unity.h"
#include "DoublyLinkedList.h"

#define TEST_DOUBLYLINKEDLIST_ITEM      uint64_t
#define TEST_DOUBLYLINKEDLIST_ITEM_SIZE sizeof(TEST_DOUBLYLINKEDLIST_ITEM)

typedef TEST_DOUBLYLINKEDLIST_ITEM test_DoublyLinkedList_Item_t;

static DoublyLinkedList_t test_DoublyLinkedList_List;
static test_DoublyLinkedList_Item_t test_DoublyLinkedList_Item;

void setUp(void)
{
  DoublyLinkedList_Init(&test_DoublyLinkedList_List, TEST_DOUBLYLINKEDLIST_ITEM_SIZE);
  test_DoublyLinkedList_Item = 0UL;
}

void tearDown(void)
{
  DoublyLinkedList_Free(&test_DoublyLinkedList_List);
}

void test_DoublyLinkedList_Init(void)
{
  DoublyLinkedList_t list;

  TEST_ASSERT_FALSE(DoublyLinkedList_Init(NULL, TEST_DOUBLYLINKEDLIST_ITEM_SIZE));

  DoublyLinkedList_Init(&list, TEST_DOUBLYLINKEDLIST_ITEM_SIZE);
  TEST_ASSERT_NULL(list.Head);
  TEST_ASSERT_NULL(list.Tail);
  TEST_ASSERT_EQUAL(0UL, DoublyLinkedList_GetLength(&list));
  TEST_ASSERT_EQUAL(TEST_DOUBLYLINKEDLIST_ITEM_SIZE, list.ItemSize);
}

void test_DoublyLinkedList_AppendPop(void)
{
  DoublyLinkedList_Reset(&test_DoublyLinkedList_List);
  TEST_ASSERT_FALSE(DoublyLinkedList_Append(&test_DoublyLinkedList_List, NULL));
  TEST_ASSERT_FALSE(DoublyLinkedList_Append(NULL, &test_DoublyLinkedList_Item));
  TEST_ASSERT_FALSE(DoublyLinkedList_Append(NULL, NULL));
  TEST_ASSERT_FALSE(DoublyLinkedList_Pop(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_FALSE(DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL));
  TEST_ASSERT_FALSE(DoublyLinkedList_Pop(NULL, &test_DoublyLinkedList_Item));
  TEST_ASSERT_FALSE(DoublyLinkedList_Pop(NULL, NULL));

  for (test_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(DoublyLinkedList_Append(&test_DoublyLinkedList_List, &i));
  }
  for (test_DoublyLinkedList_Item_t i = 3UL; i > 0UL; i--)
  {
    TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(i - 1UL, test_DoublyLinkedList_Item);
  }
  TEST_ASSERT_FALSE(DoublyLinkedList_Pop(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));

  for (test_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(DoublyLinkedList_Append(&test_DoublyLinkedList_List, &i));
  }
  for (test_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL));
  }
  TEST_ASSERT_FALSE(DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL));

  test_DoublyLinkedList_Item = 0UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  test_DoublyLinkedList_Item = 1UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(1UL, test_DoublyLinkedList_Item);
  test_DoublyLinkedList_Item = 2UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  test_DoublyLinkedList_Item = 3UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(3UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(2UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(0UL, test_DoublyLinkedList_Item);
}

void test_DoublyLinkedList_AppendLeftPopLeft(void)
{
  DoublyLinkedList_Reset(&test_DoublyLinkedList_List);
  TEST_ASSERT_FALSE(DoublyLinkedList_AppendLeft(&test_DoublyLinkedList_List, NULL));
  TEST_ASSERT_FALSE(DoublyLinkedList_AppendLeft(NULL, &test_DoublyLinkedList_Item));
  TEST_ASSERT_FALSE(DoublyLinkedList_AppendLeft(NULL, NULL));
  TEST_ASSERT_FALSE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_FALSE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, NULL));
  TEST_ASSERT_FALSE(DoublyLinkedList_PopLeft(NULL, &test_DoublyLinkedList_Item));
  TEST_ASSERT_FALSE(DoublyLinkedList_PopLeft(NULL, NULL));

  for (test_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&test_DoublyLinkedList_List, &i));
  }
  for (test_DoublyLinkedList_Item_t i = 3UL; i > 0UL; i--)
  {
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(i - 1UL, test_DoublyLinkedList_Item);
  }
  TEST_ASSERT_FALSE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));

  for (test_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&test_DoublyLinkedList_List, &i));
  }
  for (test_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, NULL));
  }
  TEST_ASSERT_FALSE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, NULL));

  test_DoublyLinkedList_Item = 0UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  test_DoublyLinkedList_Item = 1UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(1UL, test_DoublyLinkedList_Item);
  test_DoublyLinkedList_Item = 2UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  test_DoublyLinkedList_Item = 3UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(3UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(2UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(0UL, test_DoublyLinkedList_Item);
}

void test_DoublyLinkedList_AppendLeftPop(void)
{
  DoublyLinkedList_Reset(&test_DoublyLinkedList_List);

  for (test_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&test_DoublyLinkedList_List, &i));
  }
  for (test_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(i, test_DoublyLinkedList_Item);
  }
  TEST_ASSERT_FALSE(DoublyLinkedList_Pop(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));

  test_DoublyLinkedList_Item = 0UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  test_DoublyLinkedList_Item = 1UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(0UL, test_DoublyLinkedList_Item);
  test_DoublyLinkedList_Item = 2UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  test_DoublyLinkedList_Item = 3UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_AppendLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(1UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(2UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_Pop(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(3UL, test_DoublyLinkedList_Item);
}

void test_DoublyLinkedList_AppendPopLeft(void)
{
  DoublyLinkedList_Reset(&test_DoublyLinkedList_List);

  for (test_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(DoublyLinkedList_Append(&test_DoublyLinkedList_List, &i));
  }
  for (test_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
    TEST_ASSERT_EQUAL(i, test_DoublyLinkedList_Item);
  }
  TEST_ASSERT_FALSE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));

  test_DoublyLinkedList_Item = 0UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  test_DoublyLinkedList_Item = 1UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(0UL, test_DoublyLinkedList_Item);
  test_DoublyLinkedList_Item = 2UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  test_DoublyLinkedList_Item = 3UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(1UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(2UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(3UL, test_DoublyLinkedList_Item);
}

void test_DoublyLinkedList_FreeReset(void)
{
  DoublyLinkedList_Reset(&test_DoublyLinkedList_List);

  TEST_ASSERT_FALSE(DoublyLinkedList_Free(NULL));
  TEST_ASSERT_FALSE(DoublyLinkedList_Reset(NULL));

  for (test_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    DoublyLinkedList_Append(&test_DoublyLinkedList_List, &i);
  }
  TEST_ASSERT_EQUAL(3UL, DoublyLinkedList_GetLength(&test_DoublyLinkedList_List));
  TEST_ASSERT_TRUE(DoublyLinkedList_Free(&test_DoublyLinkedList_List));
  TEST_ASSERT_NULL(test_DoublyLinkedList_List.Head);
  TEST_ASSERT_NULL(test_DoublyLinkedList_List.Tail);
  TEST_ASSERT_EQUAL(0UL, DoublyLinkedList_GetLength(&test_DoublyLinkedList_List));
  TEST_ASSERT_TRUE(DoublyLinkedList_Free(&test_DoublyLinkedList_List));

  for (test_DoublyLinkedList_Item_t i = 0UL; i < 3UL; i++)
  {
    DoublyLinkedList_Append(&test_DoublyLinkedList_List, &i);
  }
  TEST_ASSERT_EQUAL(3UL, DoublyLinkedList_GetLength(&test_DoublyLinkedList_List));
  TEST_ASSERT_TRUE(DoublyLinkedList_Reset(&test_DoublyLinkedList_List));
  TEST_ASSERT_NULL(test_DoublyLinkedList_List.Head);
  TEST_ASSERT_NULL(test_DoublyLinkedList_List.Tail);
  TEST_ASSERT_EQUAL(0UL, DoublyLinkedList_GetLength(&test_DoublyLinkedList_List));
  TEST_ASSERT_TRUE(DoublyLinkedList_Reset(&test_DoublyLinkedList_List));
}

void test_DoublyLinkedList_GetIndex(void)
{
  DoublyLinkedList_Reset(&test_DoublyLinkedList_List);

  test_DoublyLinkedList_Item = 0UL;
  TEST_ASSERT_EQUAL(DOUBLY_LINKED_LIST_INDEX_ERROR, DoublyLinkedList_GetIndex(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(DOUBLY_LINKED_LIST_INDEX_ERROR, DoublyLinkedList_GetIndex(NULL, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(DOUBLY_LINKED_LIST_INDEX_ERROR, DoublyLinkedList_GetIndex(&test_DoublyLinkedList_List, NULL));
  TEST_ASSERT_EQUAL(DOUBLY_LINKED_LIST_INDEX_ERROR, DoublyLinkedList_GetIndex(NULL, NULL));

  for (test_DoublyLinkedList_Item_t i = 0UL; i < 8UL; i++)
  {
    DoublyLinkedList_Append(&test_DoublyLinkedList_List, &i);
  }
  for (test_DoublyLinkedList_Item_t i = 0UL; i < 8UL; i++)
  {
    TEST_ASSERT_EQUAL(i, DoublyLinkedList_GetIndex(&test_DoublyLinkedList_List, &i));
  }
  test_DoublyLinkedList_Item = 8UL;
  TEST_ASSERT_EQUAL(DOUBLY_LINKED_LIST_INDEX_ERROR, DoublyLinkedList_GetIndex(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
}

void test_DoublyLinkedList_GetLength(void)
{
  DoublyLinkedList_Reset(&test_DoublyLinkedList_List);

  TEST_ASSERT_EQUAL(DOUBLY_LINKED_LIST_LENGTH_ERROR, DoublyLinkedList_GetLength(NULL));

  test_DoublyLinkedList_Item = 0UL;
  TEST_ASSERT_EQUAL(0UL, DoublyLinkedList_GetLength(&test_DoublyLinkedList_List));
  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  TEST_ASSERT_EQUAL(1UL, DoublyLinkedList_GetLength(&test_DoublyLinkedList_List));
  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  TEST_ASSERT_EQUAL(2UL, DoublyLinkedList_GetLength(&test_DoublyLinkedList_List));
  DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL);
  TEST_ASSERT_EQUAL(1UL, DoublyLinkedList_GetLength(&test_DoublyLinkedList_List));
  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  TEST_ASSERT_EQUAL(4UL, DoublyLinkedList_GetLength(&test_DoublyLinkedList_List));
  DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL);
  DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL);
  TEST_ASSERT_EQUAL(2UL, DoublyLinkedList_GetLength(&test_DoublyLinkedList_List));
  DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL);
  DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL);
  TEST_ASSERT_EQUAL(0UL, DoublyLinkedList_GetLength(&test_DoublyLinkedList_List));
  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  TEST_ASSERT_EQUAL(1UL, DoublyLinkedList_GetLength(&test_DoublyLinkedList_List));
  DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL);
  TEST_ASSERT_EQUAL(0UL, DoublyLinkedList_GetLength(&test_DoublyLinkedList_List));
  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  TEST_ASSERT_EQUAL(2UL, DoublyLinkedList_GetLength(&test_DoublyLinkedList_List));
  DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL);
  DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL);
  TEST_ASSERT_EQUAL(0UL, DoublyLinkedList_GetLength(&test_DoublyLinkedList_List));
}

void test_DoublyLinkedList_Insert(void)
{
  DoublyLinkedList_Reset(&test_DoublyLinkedList_List);

  TEST_ASSERT_FALSE(DoublyLinkedList_Insert(&test_DoublyLinkedList_List, 0L, NULL));
  TEST_ASSERT_FALSE(DoublyLinkedList_Insert(NULL, 0L, &test_DoublyLinkedList_Item));
  TEST_ASSERT_FALSE(DoublyLinkedList_Insert(NULL, 0L, NULL));
  TEST_ASSERT_FALSE(DoublyLinkedList_Insert(&test_DoublyLinkedList_List, -1L, &test_DoublyLinkedList_Item));

  test_DoublyLinkedList_Item = 5UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&test_DoublyLinkedList_List, 0L, &test_DoublyLinkedList_Item));
  test_DoublyLinkedList_Item = 2UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&test_DoublyLinkedList_List, 0L, &test_DoublyLinkedList_Item));
  test_DoublyLinkedList_Item = 0UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&test_DoublyLinkedList_List, 0L, &test_DoublyLinkedList_Item));
  test_DoublyLinkedList_Item = 1UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&test_DoublyLinkedList_List, 1L, &test_DoublyLinkedList_Item));
  test_DoublyLinkedList_Item = 3UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&test_DoublyLinkedList_List, 3L, &test_DoublyLinkedList_Item));
  test_DoublyLinkedList_Item = 4UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&test_DoublyLinkedList_List, 4L, &test_DoublyLinkedList_Item));
  test_DoublyLinkedList_Item = 6UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&test_DoublyLinkedList_List, 6L, &test_DoublyLinkedList_Item));
  test_DoublyLinkedList_Item = 10UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&test_DoublyLinkedList_List, 10L, &test_DoublyLinkedList_Item));

  TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(0UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(1UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(2UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(3UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(4UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(5UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(6UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(10UL, test_DoublyLinkedList_Item);

  test_DoublyLinkedList_Item = 0UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&test_DoublyLinkedList_List, 10L, &test_DoublyLinkedList_Item));
  test_DoublyLinkedList_Item = 1UL;
  TEST_ASSERT_TRUE(DoublyLinkedList_Insert(&test_DoublyLinkedList_List, 1L, &test_DoublyLinkedList_Item));
  TEST_ASSERT_FALSE(DoublyLinkedList_Insert(&test_DoublyLinkedList_List, -1L, &test_DoublyLinkedList_Item));
  TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(0UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(1UL, test_DoublyLinkedList_Item);
}

void test_DoublyLinkedList_Remove(void)
{
  DoublyLinkedList_Reset(&test_DoublyLinkedList_List);

  TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 0L, &test_DoublyLinkedList_Item));
  TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 0L, NULL));
  TEST_ASSERT_FALSE(DoublyLinkedList_Remove(NULL, 0L, &test_DoublyLinkedList_Item));
  TEST_ASSERT_FALSE(DoublyLinkedList_Remove(NULL, 0L, NULL));

  for (test_DoublyLinkedList_Item_t i = 0UL; i < 10UL; i++)
  {
    DoublyLinkedList_Append(&test_DoublyLinkedList_List, &i);
  }
  TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, -1L, &test_DoublyLinkedList_Item));
  TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 10L, &test_DoublyLinkedList_Item));
  TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 9L, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(9UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 7L, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(7UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 8L, &test_DoublyLinkedList_Item));
  TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 5L, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(5UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 1L, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(1UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 4L, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(6UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 2L, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(3UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 2L, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(4UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 3L, &test_DoublyLinkedList_Item));
  TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 2L, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(8UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 0L, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(0UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 0L, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(2UL, test_DoublyLinkedList_Item);
  TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 0L, &test_DoublyLinkedList_Item));

  for (test_DoublyLinkedList_Item_t i = 0UL; i < 5UL; i++)
  {
    DoublyLinkedList_Append(&test_DoublyLinkedList_List, &i);
  }
  TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, -1L, NULL));
  TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 0L, NULL));
  TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 3L, NULL));
  TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 4L, NULL));
  TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 1L, NULL));
  TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 1L, NULL));
  TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 1L, NULL));
  TEST_ASSERT_TRUE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 0L, NULL));
  TEST_ASSERT_FALSE(DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 0L, NULL));
}

void test_DoublyLinkedList_GetHead(void)
{
  DoublyLinkedList_Reset(&test_DoublyLinkedList_List);

  TEST_ASSERT_FALSE(DoublyLinkedList_GetHead(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_FALSE(DoublyLinkedList_GetHead(&test_DoublyLinkedList_List, NULL));
  TEST_ASSERT_FALSE(DoublyLinkedList_GetHead(NULL, &test_DoublyLinkedList_Item));
  TEST_ASSERT_FALSE(DoublyLinkedList_GetHead(NULL, NULL));

  test_DoublyLinkedList_Item = 0UL;
  DoublyLinkedList_AppendLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  TEST_ASSERT_FALSE(DoublyLinkedList_GetHead(&test_DoublyLinkedList_List, NULL));
  TEST_ASSERT_TRUE(DoublyLinkedList_GetHead(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(0UL, test_DoublyLinkedList_Item);

  DoublyLinkedList_Reset(&test_DoublyLinkedList_List);
  TEST_ASSERT_FALSE(DoublyLinkedList_GetHead(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  test_DoublyLinkedList_Item = 1UL;
  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  test_DoublyLinkedList_Item = 2UL;
  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetHead(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(1UL, test_DoublyLinkedList_Item);
  test_DoublyLinkedList_Item = 3UL;
  DoublyLinkedList_AppendLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetHead(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(3UL, test_DoublyLinkedList_Item);
  DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetHead(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(3UL, test_DoublyLinkedList_Item);
  test_DoublyLinkedList_Item = 4UL;
  DoublyLinkedList_Insert(&test_DoublyLinkedList_List, 1UL, &test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetHead(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(3UL, test_DoublyLinkedList_Item);
  test_DoublyLinkedList_Item = 5UL;
  DoublyLinkedList_Insert(&test_DoublyLinkedList_List, 0UL, &test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetHead(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(5UL, test_DoublyLinkedList_Item);
  DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, NULL);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetHead(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(3UL, test_DoublyLinkedList_Item);
  test_DoublyLinkedList_Item = 6UL;
  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetHead(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(3UL, test_DoublyLinkedList_Item);
  DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 0UL, &test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetHead(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(4UL, test_DoublyLinkedList_Item);
  test_DoublyLinkedList_Item = 7UL;
  DoublyLinkedList_AppendLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetHead(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(7UL, test_DoublyLinkedList_Item);
  DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 2UL, NULL);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetHead(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(7UL, test_DoublyLinkedList_Item);
  DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, NULL);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetHead(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(4UL, test_DoublyLinkedList_Item);
  DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, NULL);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetHead(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(6UL, test_DoublyLinkedList_Item);
  DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL);
  TEST_ASSERT_FALSE(DoublyLinkedList_GetHead(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
}

void test_DoublyLinkedList_GetTail(void)
{
  DoublyLinkedList_Reset(&test_DoublyLinkedList_List);

  TEST_ASSERT_FALSE(DoublyLinkedList_GetTail(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_FALSE(DoublyLinkedList_GetTail(&test_DoublyLinkedList_List, NULL));
  TEST_ASSERT_FALSE(DoublyLinkedList_GetTail(NULL, &test_DoublyLinkedList_Item));
  TEST_ASSERT_FALSE(DoublyLinkedList_GetTail(NULL, NULL));

  test_DoublyLinkedList_Item = 0UL;
  DoublyLinkedList_AppendLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  TEST_ASSERT_FALSE(DoublyLinkedList_GetTail(&test_DoublyLinkedList_List, NULL));
  TEST_ASSERT_TRUE(DoublyLinkedList_GetTail(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(0UL, test_DoublyLinkedList_Item);
  DoublyLinkedList_Reset(&test_DoublyLinkedList_List);

  DoublyLinkedList_Reset(&test_DoublyLinkedList_List);
  TEST_ASSERT_FALSE(DoublyLinkedList_GetTail(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  test_DoublyLinkedList_Item = 1UL;
  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  test_DoublyLinkedList_Item = 2UL;
  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetTail(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(2UL, test_DoublyLinkedList_Item);
  test_DoublyLinkedList_Item = 3UL;
  DoublyLinkedList_AppendLeft(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetTail(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(2UL, test_DoublyLinkedList_Item);
  DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetTail(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(1UL, test_DoublyLinkedList_Item);
  test_DoublyLinkedList_Item = 4UL;
  DoublyLinkedList_Insert(&test_DoublyLinkedList_List, 2UL, &test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetTail(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(4UL, test_DoublyLinkedList_Item);
  test_DoublyLinkedList_Item = 5UL;
  DoublyLinkedList_Insert(&test_DoublyLinkedList_List, 2UL, &test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetTail(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(4UL, test_DoublyLinkedList_Item);
  DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, NULL);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetTail(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(4UL, test_DoublyLinkedList_Item);
  test_DoublyLinkedList_Item = 6UL;
  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetTail(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(6UL, test_DoublyLinkedList_Item);
  DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 3UL, &test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetTail(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(4UL, test_DoublyLinkedList_Item);
  test_DoublyLinkedList_Item = 7UL;
  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetTail(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(7UL, test_DoublyLinkedList_Item);
  DoublyLinkedList_Remove(&test_DoublyLinkedList_List, 3UL, NULL);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetTail(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(4UL, test_DoublyLinkedList_Item);
  DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetTail(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(5UL, test_DoublyLinkedList_Item);
  DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL);
  TEST_ASSERT_TRUE(DoublyLinkedList_GetTail(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
  TEST_ASSERT_EQUAL(1UL, test_DoublyLinkedList_Item);
  DoublyLinkedList_PopLeft(&test_DoublyLinkedList_List, NULL);
  TEST_ASSERT_FALSE(DoublyLinkedList_GetTail(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item));
}

void test_DoublyLinkedList_IsEmpty(void)
{
  DoublyLinkedList_Reset(&test_DoublyLinkedList_List);

  TEST_ASSERT_TRUE(DoublyLinkedList_IsEmpty(NULL));
  TEST_ASSERT_TRUE(DoublyLinkedList_IsEmpty(&test_DoublyLinkedList_List));

  test_DoublyLinkedList_Item = 0UL;
  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  TEST_ASSERT_FALSE(DoublyLinkedList_IsEmpty(&test_DoublyLinkedList_List));
  DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL);
  TEST_ASSERT_TRUE(DoublyLinkedList_IsEmpty(&test_DoublyLinkedList_List));

  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  TEST_ASSERT_FALSE(DoublyLinkedList_IsEmpty(&test_DoublyLinkedList_List));
  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  TEST_ASSERT_FALSE(DoublyLinkedList_IsEmpty(&test_DoublyLinkedList_List));

  DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL);
  TEST_ASSERT_FALSE(DoublyLinkedList_IsEmpty(&test_DoublyLinkedList_List));
  DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL);
  DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL);
  DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL);
  TEST_ASSERT_TRUE(DoublyLinkedList_IsEmpty(&test_DoublyLinkedList_List));

  DoublyLinkedList_Append(&test_DoublyLinkedList_List, &test_DoublyLinkedList_Item);
  TEST_ASSERT_FALSE(DoublyLinkedList_IsEmpty(&test_DoublyLinkedList_List));
  DoublyLinkedList_Pop(&test_DoublyLinkedList_List, NULL);
  TEST_ASSERT_TRUE(DoublyLinkedList_IsEmpty(&test_DoublyLinkedList_List));
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
  RUN_TEST(test_DoublyLinkedList_GetHead);
  RUN_TEST(test_DoublyLinkedList_GetTail);
  RUN_TEST(test_DoublyLinkedList_IsEmpty);

  return UNITY_END();
}