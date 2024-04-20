/**
 * @file BinarySearchTime.c
 *
 * @brief Binary search tree.
 *
 ******************************************************************************/

/* Includes
 ******************************************************************************/

#include "BinarySearchTree.h"
#include <string.h>

/* Function Definitions
 ******************************************************************************/

bool BinarySearchTree_Init(BinarySearchTree_t *const tree, const size_t keySize, const size_t itemSize)
{
  bool init = false;

  if (tree != NULL)
  {
    tree->Root = NULL;
    tree->KeySize = keySize;
    tree->ItemSize = itemSize;

    init = true;
  }

  return init;
}

bool BinarySearchTree_Free(BinarySearchTree_t *const tree)
{
  return BinarySearchTree_Reset(tree);
}

bool BinarySearchTree_Insert(BinarySearchTree_t *const tree, const void *const key, const void *const item)
{
  bool inserted = false;

  if (tree != NULL && key != NULL && item != NULL)
  {
    /* TODO */
  }

  return inserted;
}

bool BinarySearchTree_Remove(BinarySearchTree_t *const tree, const void *const key)
{
  bool removed = false;

  if (tree != NULL && key != NULL)
  {
    /* TODO */
  }

  return removed;
}

bool BinarySearchTree_Search(BinarySearchTree_t *const tree, const void *const key, void *const item)
{
  bool found = false;

  if (tree != NULL && key != NULL && item != NULL)
  {
    /* TODO */
  }

  return found;
}

bool BinarySearchTree_Reset(BinarySearchTree_t *const tree)
{
  bool reset = false;

  if (tree != NULL)
  {
    /* TODO */
  }

  return reset;
}