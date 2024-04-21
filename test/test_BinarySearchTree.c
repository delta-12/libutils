#include "unity.h"
#include "BinarySearchTree.h"

#define TEST_BINARYSEARCHTREE_ITEM      uint64_t
#define TEST_BINARYSEARCHTREE_ITEM_SIZE sizeof(TEST_BINARYSEARCHTREE_ITEM)

typedef TEST_BINARYSEARCHTREE_ITEM test_BinarySearchTree_Item_t;

static BinarySearchTree_t test_BinarySearchTree_Tree;
static test_BinarySearchTree_Item_t test_BinarySearchTree_Item;

void setUp(void)
{
  BinarySearchTree_Init(&test_BinarySearchTree_Tree, TEST_BINARYSEARCHTREE_ITEM_SIZE);
  test_BinarySearchTree_Item = 0UL;
}

void tearDown(void)
{
  BinarySearchTree_Free(&test_BinarySearchTree_Tree);
}

void test_BinarySearchTree_InitFree(void)
{
  BinarySearchTree_t tree;

  TEST_ASSERT_FALSE(BinarySearchTree_Init(NULL, TEST_BINARYSEARCHTREE_ITEM_SIZE));

  BinarySearchTree_Init(&tree, TEST_BINARYSEARCHTREE_ITEM_SIZE);
  TEST_ASSERT_NULL(tree.Root);
  TEST_ASSERT_EQUAL(TEST_BINARYSEARCHTREE_ITEM_SIZE, tree.ItemSize);
  BinarySearchTree_Free(&tree);
}

void test_BinarySearchTree_InsertRemoveSearch(void)
{
  BinarySearchTree_Reset(&test_BinarySearchTree_Tree);

  /* TODO */

  TEST_ASSERT_TRUE(false);
}

void test_BinarySearchTree_ResetFree(void)
{
  BinarySearchTree_Reset(&test_BinarySearchTree_Tree);

  TEST_ASSERT_FALSE(BinarySearchTree_Free(NULL));
  TEST_ASSERT_FALSE(BinarySearchTree_Reset(NULL));

  for (test_BinarySearchTree_Item_t i = 0UL; i < 3UL; i++)
  {
    BinarySearchTree_Insert(&test_BinarySearchTree_Tree, i, &i);
  }
  TEST_ASSERT_TRUE(BinarySearchTree_Free(&test_BinarySearchTree_Tree));
  TEST_ASSERT_NULL(test_BinarySearchTree_Tree.Root);
  TEST_ASSERT_TRUE(BinarySearchTree_Free(&test_BinarySearchTree_Tree));

  for (test_BinarySearchTree_Item_t i = 0UL; i < 3UL; i++)
  {
    BinarySearchTree_Insert(&test_BinarySearchTree_Tree, i, &i);
  }
  TEST_ASSERT_TRUE(BinarySearchTree_Reset(&test_BinarySearchTree_Tree));
  TEST_ASSERT_NULL(test_BinarySearchTree_Tree.Root);
  TEST_ASSERT_TRUE(BinarySearchTree_Reset(&test_BinarySearchTree_Tree));
}

int main(void)
{
  UNITY_BEGIN();

  RUN_TEST(test_BinarySearchTree_InitFree);
  RUN_TEST(test_BinarySearchTree_InsertRemoveSearch);
  RUN_TEST(test_BinarySearchTree_ResetFree);

  return UNITY_END();
}