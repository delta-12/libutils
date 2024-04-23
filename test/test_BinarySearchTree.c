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

  TEST_ASSERT_FALSE(BinarySearchTree_Insert(NULL, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, NULL));
  TEST_ASSERT_FALSE(BinarySearchTree_Insert(NULL, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, NULL));
  TEST_ASSERT_FALSE(BinarySearchTree_Remove(NULL, (BinarySearchTree_Key_t)test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(NULL, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, NULL));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(NULL, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, NULL));

  test_BinarySearchTree_Item = 0UL;
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item));

  test_BinarySearchTree_Item = 50UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 30UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 70UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 20UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 40UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 60UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 80UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));

  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 0UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 20UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(20UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 30UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(30UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 40UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(40UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 50UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(50UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 60UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(60UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 70UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(70UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 80UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(80UL, test_BinarySearchTree_Item);

  test_BinarySearchTree_Item = 80UL;
  TEST_ASSERT_FALSE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 50UL;
  TEST_ASSERT_FALSE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));

  TEST_ASSERT_FALSE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 0UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 50UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 60UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 70UL));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 50UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 60UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 70UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 50UL));
  TEST_ASSERT_FALSE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 60UL));
  TEST_ASSERT_FALSE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 70UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 40UL));
  TEST_ASSERT_FALSE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 40UL));

  test_BinarySearchTree_Item = 40UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 50UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 60UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 70UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));

  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 40UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(40UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 50UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(50UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 60UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(60UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 70UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(70UL, test_BinarySearchTree_Item);

  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 20UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 30UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 40UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 50UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 60UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 70UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 80UL));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 20UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 30UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 40UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 50UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 60UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 70UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 80UL, &test_BinarySearchTree_Item));

  test_BinarySearchTree_Item = 200UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 100UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 150UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 170UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 180UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 120UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 190UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 110UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 130UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 160UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 140UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));

  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 200UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(200UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 110UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(110UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 100UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(100UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 190UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(190UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 150UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(150UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 120UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(120UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 170UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(170UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 180UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(180UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 130UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(130UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 160UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(160UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 140UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(140UL, test_BinarySearchTree_Item);

  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 200UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 110UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 100UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 190UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 150UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 120UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 170UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 180UL));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 200UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 110UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 100UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 190UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 150UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 120UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 170UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 180UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 130UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 160UL, &test_BinarySearchTree_Item));

  test_BinarySearchTree_Item = 80UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 90UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 0UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 10UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 20UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 30UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 180UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 120UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 190UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 110UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 40UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 50UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 60UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 70UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 200UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 100UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 150UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));
  test_BinarySearchTree_Item = 170UL;
  TEST_ASSERT_TRUE(BinarySearchTree_Insert(&test_BinarySearchTree_Tree, (BinarySearchTree_Key_t)test_BinarySearchTree_Item, &test_BinarySearchTree_Item));

  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 10UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(10UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 20UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(20UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 30UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(30UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 40UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(40UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 50UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(50UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 60UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(60UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 70UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(70UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 80UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(80UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 90UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(90UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 100UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(100UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 110UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(110UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 120UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(120UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 130UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(130UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 140UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(140UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 150UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(150UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 160UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(160UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 170UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(170UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 180UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(180UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 190UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(190UL, test_BinarySearchTree_Item);
  TEST_ASSERT_TRUE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 200UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_EQUAL(200UL, test_BinarySearchTree_Item);

  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 10UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 20UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 30UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 40UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 50UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 60UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 70UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 80UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 90UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 100UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 110UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 120UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 130UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 140UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 150UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 160UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 170UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 180UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 190UL));
  TEST_ASSERT_TRUE(BinarySearchTree_Remove(&test_BinarySearchTree_Tree, 200UL));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 10UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 20UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 30UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 40UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 50UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 60UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 70UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 80UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 90UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 100UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 110UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 120UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 130UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 140UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 150UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 160UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 170UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 180UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 190UL, &test_BinarySearchTree_Item));
  TEST_ASSERT_FALSE(BinarySearchTree_Search(&test_BinarySearchTree_Tree, 200UL, &test_BinarySearchTree_Item));

  BinarySearchTree_Reset(&test_BinarySearchTree_Tree);
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

void test_BinarySearchTree_LargeReset(void)
{
  /* TODO add large amount of random numbers to BST after new Stack implementation and reset without memory leaks */
}

int main(void)
{
  UNITY_BEGIN();

  RUN_TEST(test_BinarySearchTree_InitFree);
  RUN_TEST(test_BinarySearchTree_InsertRemoveSearch);
  RUN_TEST(test_BinarySearchTree_ResetFree);
  RUN_TEST(test_BinarySearchTree_LargeReset);

  return UNITY_END();
}