#include "unity.h"
#include "Stack.h"

#define TEST_STACK_ITEM      uint8_t
#define TEST_STACK_LENGTH    10UL
#define TEST_STACK_ITEM_SIZE sizeof(TEST_STACK_ITEM)

typedef TEST_STACK_ITEM test_Stack_Item_t;

static Stack_t *test_Stack;
static uint8_t test_StackStaticBuffer[TEST_STACK_LENGTH * TEST_STACK_ITEM_SIZE];

void setUp(void)
{
  test_Stack = Stack_Init(TEST_STACK_LENGTH, TEST_STACK_ITEM_SIZE);
}

void tearDown(void)
{
  Stack_Free(test_Stack);
}

void test_Stack_InitFree(void)
{
  Stack_t *stack;
  test_Stack_Item_t item;

  stack = Stack_Init(TEST_STACK_LENGTH, TEST_STACK_ITEM_SIZE);
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_TRUE(Stack_IsEmpty(stack));
  TEST_ASSERT_FALSE(Stack_Pop(stack, &item));
  TEST_ASSERT_FALSE(Stack_Peek(stack, &item));
  Stack_Free(stack);
}

void test_Stack_InitStatic(void)
{
  Stack_t stack;
  test_Stack_Item_t item;

  TEST_ASSERT_FALSE(Stack_InitStatic(NULL, test_StackStaticBuffer, TEST_STACK_LENGTH, TEST_STACK_ITEM_SIZE));
  TEST_ASSERT_FALSE(Stack_InitStatic(&stack, NULL, TEST_STACK_LENGTH, TEST_STACK_ITEM_SIZE));
  TEST_ASSERT_FALSE(Stack_InitStatic(NULL, NULL, TEST_STACK_LENGTH, TEST_STACK_ITEM_SIZE));

  TEST_ASSERT_TRUE(Stack_InitStatic(&stack, test_StackStaticBuffer, TEST_STACK_LENGTH, TEST_STACK_ITEM_SIZE));
  TEST_ASSERT_TRUE(Stack_IsEmpty(&stack));
  TEST_ASSERT_FALSE(Stack_Pop(&stack, &item));
  TEST_ASSERT_FALSE(Stack_Peek(&stack, &item));
}

void test_Stack_PushPopPeekIsEmpty(void)
{
  test_Stack_Item_t item;

  Stack_Reset(test_Stack);
  TEST_ASSERT_FALSE(Stack_Push(test_Stack, NULL));
  TEST_ASSERT_FALSE(Stack_Push(NULL, &item));
  TEST_ASSERT_FALSE(Stack_Push(NULL, NULL));
  TEST_ASSERT_FALSE(Stack_Pop(test_Stack, NULL));
  TEST_ASSERT_FALSE(Stack_Pop(NULL, &item));
  TEST_ASSERT_FALSE(Stack_Pop(NULL, NULL));
  TEST_ASSERT_FALSE(Stack_Peek(test_Stack, NULL));
  TEST_ASSERT_FALSE(Stack_Peek(NULL, &item));
  TEST_ASSERT_FALSE(Stack_Peek(NULL, NULL));
  TEST_ASSERT_TRUE(Stack_IsEmpty(NULL));

  item = 0U;
  TEST_ASSERT_TRUE(Stack_Push(test_Stack, &item));
  TEST_ASSERT_FALSE(Stack_IsEmpty(test_Stack));
  TEST_ASSERT_TRUE(Stack_Peek(test_Stack, &item));
  TEST_ASSERT_EQUAL(0U, item);
  item = 1U;
  TEST_ASSERT_TRUE(Stack_Push(test_Stack, &item));
  TEST_ASSERT_FALSE(Stack_IsEmpty(test_Stack));
  TEST_ASSERT_TRUE(Stack_Peek(test_Stack, &item));
  TEST_ASSERT_EQUAL(1U, item);
  item = 2U;
  TEST_ASSERT_TRUE(Stack_Push(test_Stack, &item));
  TEST_ASSERT_FALSE(Stack_IsEmpty(test_Stack));
  TEST_ASSERT_TRUE(Stack_Peek(test_Stack, &item));
  TEST_ASSERT_EQUAL(2U, item);

  TEST_ASSERT_TRUE(Stack_Pop(test_Stack, &item));
  TEST_ASSERT_EQUAL(2U, item);
  TEST_ASSERT_FALSE(Stack_IsEmpty(test_Stack));
  TEST_ASSERT_TRUE(Stack_Peek(test_Stack, &item));
  TEST_ASSERT_EQUAL(1U, item);
  TEST_ASSERT_TRUE(Stack_Pop(test_Stack, &item));
  TEST_ASSERT_EQUAL(1U, item);
  TEST_ASSERT_FALSE(Stack_IsEmpty(test_Stack));
  TEST_ASSERT_TRUE(Stack_Peek(test_Stack, &item));
  TEST_ASSERT_EQUAL(0U, item);

  item = 3U;
  TEST_ASSERT_TRUE(Stack_Push(test_Stack, &item));
  TEST_ASSERT_FALSE(Stack_IsEmpty(test_Stack));
  TEST_ASSERT_TRUE(Stack_Peek(test_Stack, &item));
  TEST_ASSERT_EQUAL(3U, item);

  TEST_ASSERT_TRUE(Stack_Pop(test_Stack, &item));
  TEST_ASSERT_EQUAL(3U, item);
  TEST_ASSERT_FALSE(Stack_IsEmpty(test_Stack));
  TEST_ASSERT_TRUE(Stack_Peek(test_Stack, &item));
  TEST_ASSERT_EQUAL(0U, item);
  TEST_ASSERT_TRUE(Stack_Pop(test_Stack, &item));
  TEST_ASSERT_EQUAL(0U, item);
  TEST_ASSERT_TRUE(Stack_IsEmpty(test_Stack));
  TEST_ASSERT_FALSE(Stack_Peek(test_Stack, &item));

  for (test_Stack_Item_t i = 0U; i < TEST_STACK_LENGTH; i++)
  {
    TEST_ASSERT_TRUE(Stack_Push(test_Stack, &i));
    TEST_ASSERT_FALSE(Stack_IsEmpty(test_Stack));
    TEST_ASSERT_TRUE(Stack_Peek(test_Stack, &item));
    TEST_ASSERT_EQUAL(i, item);
  }
  for (test_Stack_Item_t i = TEST_STACK_LENGTH; i > 0; i--)
  {
    TEST_ASSERT_TRUE(Stack_Pop(test_Stack, &item));
    TEST_ASSERT_EQUAL(i - 1UL, item);
  }
  TEST_ASSERT_TRUE(Stack_IsEmpty(test_Stack));
}

void test_Stack_Reset(void)
{
  test_Stack_Item_t item;

  TEST_ASSERT_FALSE(Stack_Reset(NULL));

  TEST_ASSERT_TRUE(Stack_Reset(test_Stack));
  TEST_ASSERT_TRUE(Stack_IsEmpty(test_Stack));
  TEST_ASSERT_FALSE(Stack_Pop(test_Stack, &item));
  TEST_ASSERT_FALSE(Stack_Peek(test_Stack, &item));
}

void test_Stack_IsFull(void)
{
  test_Stack_Item_t item = 0U;

  Stack_Reset(test_Stack);
  TEST_ASSERT_FALSE(Stack_IsFull(NULL));

  for (test_Stack_Item_t i = 0U; i < TEST_STACK_LENGTH; i++)
  {
    TEST_ASSERT_FALSE(Stack_IsFull(test_Stack));
    Stack_Push(test_Stack, &i);
  }
  TEST_ASSERT_TRUE(Stack_IsFull(test_Stack));

  Stack_Pop(test_Stack, &item);
  TEST_ASSERT_FALSE(Stack_IsFull(test_Stack));
  Stack_Push(test_Stack, &item);
  TEST_ASSERT_TRUE(Stack_IsFull(test_Stack));

  Stack_Reset(test_Stack);
  for (test_Stack_Item_t i = 0U; i < TEST_STACK_LENGTH; i++)
  {
    TEST_ASSERT_FALSE(Stack_IsFull(test_Stack));
    Stack_Push(test_Stack, &i);
  }
  TEST_ASSERT_TRUE(Stack_IsFull(test_Stack));

  Stack_Reset(test_Stack);
  TEST_ASSERT_FALSE(Stack_IsFull(test_Stack));
}

int main(void)
{
  UNITY_BEGIN();

  RUN_TEST(test_Stack_InitFree);
  RUN_TEST(test_Stack_InitStatic);
  RUN_TEST(test_Stack_PushPopPeekIsEmpty);
  RUN_TEST(test_Stack_Reset);
  RUN_TEST(test_Stack_IsFull);

  return UNITY_END();
}