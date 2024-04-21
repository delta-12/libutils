/**
 * @file BinarySearchTree.c
 *
 * @brief Binary search tree.
 *
 ******************************************************************************/

/* Includes
 ******************************************************************************/

#include "BinarySearchTree.h"
#include "Stack.h"
#include <string.h>

/* Function Prototypes
 ******************************************************************************/

static void BinarySearchTree_GetNode(const BinarySearchTree_t *const tree,
                                     const BinarySearchTree_Key_t key,
                                     BinarySearchTree_Node_t **const node,
                                     BinarySearchTree_Node_t **const parent);
static void BinarySearchTree_GetSuccessor(BinarySearchTree_Node_t *const node, BinarySearchTree_Node_t **const successor, BinarySearchTree_Node_t **const parent);
static bool BinarySearchTree_CompareNodes(const BinarySearchTree_t *const tree, const BinarySearchTree_Node_t *const a, const BinarySearchTree_Node_t *const b);

/* Function Definitions
 ******************************************************************************/

bool BinarySearchTree_Init(BinarySearchTree_t *const tree, const size_t itemSize)
{
  bool init = false;

  if (tree != NULL)
  {
    tree->Root = NULL;
    tree->ItemSize = itemSize;

    init = true;
  }

  return init;
}

bool BinarySearchTree_Free(BinarySearchTree_t *const tree)
{
  return BinarySearchTree_Reset(tree);
}

bool BinarySearchTree_Insert(BinarySearchTree_t *const tree, const BinarySearchTree_Key_t key, const void *const item)
{
  bool inserted = false;

  if (tree != NULL && item != NULL)
  {
    BinarySearchTree_Node_t *newNode = (BinarySearchTree_Node_t *)malloc(sizeof(BinarySearchTree_Node_t) + tree->ItemSize);
    BinarySearchTree_Node_t *node;
    BinarySearchTree_Node_t *parent;

    newNode->Left = NULL;
    newNode->Right = NULL;
    newNode->Key = key;
    newNode->Item = (uint8_t *)newNode + sizeof(BinarySearchTree_Node_t);
    memcpy(newNode->Item, item, tree->ItemSize);

    BinarySearchTree_GetNode(tree, key, &node, &parent);

    if (parent == NULL)
    {
      tree->Root = newNode;

      inserted = true;
    }
    else if (node == NULL)
    {
      if (key < parent->Key)
      {
        parent->Left = newNode;
      }
      else
      {
        parent->Right = newNode;
      }

      inserted = true;
    }
    else if (BinarySearchTree_CompareNodes(tree, newNode, node))
    {
      free(newNode);
    }
    else
    {
      newNode->Right = node->Right;
      node->Right = newNode;

      inserted = true;
    }
  }

  return inserted;
}

bool BinarySearchTree_Remove(BinarySearchTree_t *const tree, const BinarySearchTree_Key_t key)
{
  bool removed = false;

  if (tree != NULL)
  {
    BinarySearchTree_Node_t *node;
    BinarySearchTree_Node_t *parent;

    BinarySearchTree_GetNode(tree, key, &node, &parent);

    if (node != NULL)
    {
      BinarySearchTree_Node_t *successor;
      BinarySearchTree_Node_t *successorParent;

      BinarySearchTree_GetSuccessor(node, &successor, &successorParent);

      if (parent == NULL)
      {
        tree->Root = successor;
      }
      else
      {
        if (parent->Left == node)
        {
          parent->Left = successor;
        }
        else
        {
          parent->Right = successor;
        }
      }

      if (successor != NULL)
      {
        successor->Left = node->Left;

        if (successorParent != node)
        {
          successor->Right = node->Right;
          successorParent->Left = NULL;
        }
      }

      free(node);
    }
  }

  return removed;
}

bool BinarySearchTree_Search(const BinarySearchTree_t *const tree, const BinarySearchTree_Key_t key, void *const item)
{
  bool found = false;

  if (tree != NULL && item != NULL)
  {
    BinarySearchTree_Node_t *node;
    BinarySearchTree_Node_t *parent;

    BinarySearchTree_GetNode(tree, key, &node, &parent);

    if (node != NULL)
    {
      memcpy(item, node->Item, tree->ItemSize);

      found = true;
    }
  }

  return found;
}

bool BinarySearchTree_Reset(BinarySearchTree_t *const tree)
{
  bool reset = false;

  if (tree != NULL)
  {
    Stack_t *stack = Stack_Init(20UL, sizeof(BinarySearchTree_Node_t *)); /* TODO 20 items should be enough for balanced BST with ~1 million nodes,
                                                                             will not perform well with unbalanced trees.  MUST be updated to new Stack API. */
    BinarySearchTree_Node_t *node;

    Stack_Push(stack, &tree->Root);
    tree->Root = NULL;

    while (!Stack_IsEmpty(stack))
    {
      Stack_Pop(stack, &node);

      if (node != NULL)
      {
        Stack_Push(stack, &node->Left);
        Stack_Push(stack, &node->Right);

        free(node);
      }
    }

    Stack_Free(stack);

    reset = true;
  }

  return reset;
}

static void BinarySearchTree_GetNode(const BinarySearchTree_t *const tree,
                                     const BinarySearchTree_Key_t key,
                                     BinarySearchTree_Node_t **const node,
                                     BinarySearchTree_Node_t **const parent)
{
  *node = tree->Root;
  *parent = NULL;

  while (*node != NULL && (*node)->Key != key)
  {
    *parent = *node;

    if (key < (*node)->Key)
    {
      *node = (*node)->Left;
    }
    else
    {
      *node = (*node)->Right;
    }
  }
}

static void BinarySearchTree_GetSuccessor(BinarySearchTree_Node_t *const node, BinarySearchTree_Node_t **const successor, BinarySearchTree_Node_t **const parent)
{
  *successor = NULL;
  *parent = node;

  if (node != NULL)
  {
    if (node->Right == NULL)
    {
      *successor = node->Left;
    }
    else
    {
      *successor = node->Right;

      while ((*successor)->Left != NULL)
      {
        *parent = *successor;
        *successor = (*successor)->Left;
      }
    }
  }
}

static bool BinarySearchTree_CompareNodes(const BinarySearchTree_t *const tree, const BinarySearchTree_Node_t *const a, const BinarySearchTree_Node_t *const b)
{
  bool equal = true;

  if (a->Key == b->Key)
  {
    for (size_t i = 0UL; i < tree->ItemSize; i++)
    {
      if (*(a->Item + i) != *(b->Item + i))
      {
        equal = false;
      }
    }
  }
  else
  {
    equal = false;
  }

  return equal;
}