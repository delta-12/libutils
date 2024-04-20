#include "unity.h"
#include "BinarySearchTree.h"

#define TEST_BINARYSEARCHTREE_ITEM      uint64_t
#define TEST_BINARYSEARCHTREE_ITEM_SIZE sizeof(TEST_BINARYSEARCHTREE_ITEM)

typedef TEST_BINARYSEARCHTREE_ITEM test_BinarySearchTree_Item_t;

static BinarySearchTree_t test_BinarySearchTree_List;
static test_BinarySearchTree_Item_t test_BinarySearchTree_Item;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_BinarySearchTree_InitFree(void)
{
}

void test_BinarySearchTree_Insert(void)
{
}

void test_BinarySearchTree_Remove(void)
{
}

void test_BinarySearchTree_Search(void)
{
}

void test_BinarySearchTree_Reset(void)
{
}

int main(void)
{
  UNITY_BEGIN();

  RUN_TEST(test_BinarySearchTree_InitFree);
  RUN_TEST(test_BinarySearchTree_Insert);
  RUN_TEST(test_BinarySearchTree_Remove);
  RUN_TEST(test_BinarySearchTree_Search);
  RUN_TEST(test_BinarySearchTree_Reset);

  return UNITY_END();
}