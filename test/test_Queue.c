#include "unity.h"
#include "Queue.h"

#define TEST_QUEUE_ITEM      uint8_t
#define TEST_QUEUE_LENGTH    10UL
#define TEST_QUEUE_ITEM_SIZE sizeof(TEST_QUEUE_ITEM)

typedef TEST_QUEUE_ITEM test_Queue_Item_t;

static Queue_t *test_Queue;
static uint8_t test_QueueStaticBuffer[TEST_QUEUE_LENGTH * TEST_QUEUE_ITEM_SIZE];

void setUp(void)
{
  test_Queue = Queue_Init(TEST_QUEUE_LENGTH, TEST_QUEUE_ITEM_SIZE);
}

void tearDown(void)
{
  Queue_Free(test_Queue);
}

void test_Queue_InitFree(void)
{
  Queue_t *queue;
  test_Queue_Item_t item;

  queue = Queue_Init(TEST_QUEUE_LENGTH, TEST_QUEUE_ITEM_SIZE);
  TEST_ASSERT_NOT_NULL(queue);
  TEST_ASSERT_TRUE(Queue_IsEmpty(queue));
  TEST_ASSERT_FALSE(Queue_Pop(queue, &item));
  TEST_ASSERT_FALSE(Queue_Peek(queue, &item));
  Queue_Free(queue);
}

void test_Queue_InitStatic(void)
{
  Queue_t queue;
  test_Queue_Item_t item;

  TEST_ASSERT_TRUE(Queue_InitStatic(&queue, test_QueueStaticBuffer, TEST_QUEUE_LENGTH, TEST_QUEUE_ITEM_SIZE));
  TEST_ASSERT_TRUE(Queue_IsEmpty(&queue));
  TEST_ASSERT_FALSE(Queue_Pop(&queue, &item));
  TEST_ASSERT_FALSE(Queue_Peek(&queue, &item));
}

void test_Queue_PushPopPeekIsEmpty(void)
{
  test_Queue_Item_t item;

  Queue_Reset(test_Queue);

  item = 0U;
  TEST_ASSERT_TRUE(Queue_Push(test_Queue, &item));
  TEST_ASSERT_FALSE(Queue_IsEmpty(test_Queue));
  TEST_ASSERT_TRUE(Queue_Peek(test_Queue, &item));
  TEST_ASSERT_EQUAL(0U, item);
  item = 1U;
  TEST_ASSERT_TRUE(Queue_Push(test_Queue, &item));
  TEST_ASSERT_FALSE(Queue_IsEmpty(test_Queue));
  TEST_ASSERT_TRUE(Queue_Peek(test_Queue, &item));
  TEST_ASSERT_EQUAL(0U, item);
  item = 2U;
  TEST_ASSERT_TRUE(Queue_Push(test_Queue, &item));
  TEST_ASSERT_FALSE(Queue_IsEmpty(test_Queue));
  TEST_ASSERT_TRUE(Queue_Peek(test_Queue, &item));
  TEST_ASSERT_EQUAL(0U, item);

  TEST_ASSERT_TRUE(Queue_Pop(test_Queue, &item));
  TEST_ASSERT_EQUAL(0U, item);
  TEST_ASSERT_FALSE(Queue_IsEmpty(test_Queue));
  TEST_ASSERT_TRUE(Queue_Peek(test_Queue, &item));
  TEST_ASSERT_EQUAL(1U, item);
  TEST_ASSERT_TRUE(Queue_Pop(test_Queue, &item));
  TEST_ASSERT_EQUAL(1U, item);
  TEST_ASSERT_FALSE(Queue_IsEmpty(test_Queue));
  TEST_ASSERT_TRUE(Queue_Peek(test_Queue, &item));
  TEST_ASSERT_EQUAL(2U, item);

  item = 0U;
  TEST_ASSERT_TRUE(Queue_Push(test_Queue, &item));
  TEST_ASSERT_FALSE(Queue_IsEmpty(test_Queue));
  TEST_ASSERT_TRUE(Queue_Peek(test_Queue, &item));
  TEST_ASSERT_EQUAL(2U, item);

  TEST_ASSERT_TRUE(Queue_Pop(test_Queue, &item));
  TEST_ASSERT_EQUAL(2U, item);
  TEST_ASSERT_FALSE(Queue_IsEmpty(test_Queue));
  TEST_ASSERT_TRUE(Queue_Peek(test_Queue, &item));
  TEST_ASSERT_EQUAL(0U, item);
  TEST_ASSERT_TRUE(Queue_Pop(test_Queue, &item));
  TEST_ASSERT_EQUAL(0U, item);
  TEST_ASSERT_TRUE(Queue_IsEmpty(test_Queue));
  TEST_ASSERT_FALSE(Queue_Peek(test_Queue, &item));

  for (test_Queue_Item_t i = 0U; i < TEST_QUEUE_LENGTH; i++)
  {
    TEST_ASSERT_TRUE(Queue_Push(test_Queue, &i));
    TEST_ASSERT_FALSE(Queue_IsEmpty(test_Queue));
    TEST_ASSERT_TRUE(Queue_Peek(test_Queue, &item));
    TEST_ASSERT_EQUAL(0U, item);
  }
  for (test_Queue_Item_t i = 0U; i < TEST_QUEUE_LENGTH; i++)
  {
    TEST_ASSERT_TRUE(Queue_Pop(test_Queue, &item));
    TEST_ASSERT_EQUAL(i, item);
  }
  TEST_ASSERT_TRUE(Queue_IsEmpty(test_Queue));
}

void test_Queue_Reset(void)
{
  test_Queue_Item_t item;

  TEST_ASSERT_TRUE(Queue_Reset(test_Queue));
  TEST_ASSERT_TRUE(Queue_IsEmpty(test_Queue));
  TEST_ASSERT_FALSE(Queue_Pop(test_Queue, &item));
  TEST_ASSERT_FALSE(Queue_Peek(test_Queue, &item));
}

void test_Queue_IsFull(void)
{
  test_Queue_Item_t item = 0U;

  Queue_Reset(test_Queue);

  for (test_Queue_Item_t i = 0U; i < TEST_QUEUE_LENGTH; i++)
  {
    TEST_ASSERT_FALSE(Queue_IsFull(test_Queue));
    Queue_Push(test_Queue, &i);
  }
  TEST_ASSERT_TRUE(Queue_IsFull(test_Queue));

  Queue_Pop(test_Queue, &item);
  TEST_ASSERT_FALSE(Queue_IsFull(test_Queue));
  Queue_Push(test_Queue, &item);
  TEST_ASSERT_TRUE(Queue_IsFull(test_Queue));

  Queue_Reset(test_Queue);
  for (test_Queue_Item_t i = 0U; i < TEST_QUEUE_LENGTH; i++)
  {
    TEST_ASSERT_FALSE(Queue_IsFull(test_Queue));
    Queue_Push(test_Queue, &i);
  }
  TEST_ASSERT_TRUE(Queue_IsFull(test_Queue));

  Queue_Reset(test_Queue);
  TEST_ASSERT_FALSE(Queue_IsFull(test_Queue));
}

int main(void)
{
  UNITY_BEGIN();

  RUN_TEST(test_Queue_InitFree);
  RUN_TEST(test_Queue_InitStatic);
  RUN_TEST(test_Queue_PushPopPeekIsEmpty);
  RUN_TEST(test_Queue_Reset);
  RUN_TEST(test_Queue_IsFull);

  return UNITY_END();
}