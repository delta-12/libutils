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

/* Function Definitions
 ******************************************************************************/

/**
 * @brief Initialize a binary search tree.
 *
 * @param[in,out] tree     Pointer to the tree to initialize
 * @param[in]     itemSize Size in bytes of the items held in the tree
 *
 * @return Whether the tree was successfully initialized or not
 *
 * @retval true  Successfully initialized
 * @retval false Failed to initialize
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

/**
 * @brief Free a binary search tree.
 *
 * @param[in,out] tree Pointer to the tree to free
 *
 * @note This function merely calls BinarySearchTree_Reset.  See the
 *       documentation for BinarySearchTree_Reset for more information.
 ******************************************************************************/
bool BinarySearchTree_Free(BinarySearchTree_t *const tree)
{
  return BinarySearchTree_Reset(tree);
}

/**
 * @brief Insert an item into a binary search tree.  Items are stored by copy,
 *        not reference.
 *
 * @param[in,out] tree Pointer to the tree to insert the item into
 * @param[in]     key  Key for the item to be inserted into the tree, used to
 *                     maintain the order of the tree
 * @param[in]     item Pointer to the item to insert into the tree
 *
 * @return Whether the item was successfully inserted into the tree or not
 *
 * @retval true  Successfully inserted the item into the tree
 * @retval false Failed to insert the item into the tree
 ******************************************************************************/
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

    if (parent == NULL && tree->Root == NULL)
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
    else
    {
      free(newNode);
    }
  }

  return inserted;
}

/**
 * @brief Remove an item from a binary search tree.
 *
 * @param[in,out] tree Pointer to the tree to remove the item from
 * @param[in]     key  Key of the item to remove from the tree
 *
 * @return Whether the item was successfully removed from the tree or not
 *
 * @retval true  Successfully removed the item from the tree
 * @retval false Failed to remove the item from the tree
 ******************************************************************************/
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
        if (successor != node->Left)
        {
          successor->Left = node->Left;
        }

        if (successorParent != node)
        {
          successorParent->Left = successor->Right;
          successor->Right = node->Right;
        }
      }

      free(node);

      removed = true;
    }
  }

  return removed;
}

/**
 * @brief Search for an item in a binary search tree.
 *
 * @param[in,out] tree Pointer to the tree to search for the item in
 * @param[in]     key  Key of the item to search for in the tree
 * @param[out]    item Pointer to a buffer large enough to copy the item into
 *
 * @return Whether the item was successfully found in the tree or not
 *
 * @retval true  Successfully found the item in the tree
 * @retval false Failed to find the item in the tree
 ******************************************************************************/
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

/**
 * @brief Reset a binary search tree to its initial state.
 *
 * @param[in,out] tree Pointer to the tree to reset
 ******************************************************************************/
bool BinarySearchTree_Reset(BinarySearchTree_t *const tree)
{
  bool reset = false;

  if (tree != NULL)
  {
    Stack_t stack;
    BinarySearchTree_Node_t *node;

    Stack_Init(&stack, sizeof(BinarySearchTree_Node_t *));
    Stack_Push(&stack, &tree->Root);
    tree->Root = NULL;

    while (!Stack_IsEmpty(&stack))
    {
      Stack_Pop(&stack, &node);

      if (node != NULL)
      {
        Stack_Push(&stack, &node->Left);
        Stack_Push(&stack, &node->Right);

        free(node);
      }
    }

    Stack_Free(&stack);

    reset = true;
  }

  return reset;
}

/**
 * @brief Get a pointer to a node and its parent in a binary search tree.
 *
 * @param[in]  tree   Pointer to the tree to get the node from
 * @param[in]  key    Key of the node to get from the tree
 * @param[out] node   Pointer to the node from the tree, NULL if there is not a
 *                    node with the key in the tree
 * @param[out] parent Pointer to the parent of the node from the tree, NULL if
 *                    there is not a node with the key in the tree or the node
 *                    with the key does not have a parent, i.e. it is the root
 ******************************************************************************/
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

/**
 * @brief Get a pointer to a node's inorder successor and the successor's
 *        parent in a binary search tree.
 *
 * @param[in]  node      Pointer to the node to get the successor of
 * @param[out] successor Pointer to the successor from the tree, NULL if there
 *                       is not a successor in the tree
 * @param[out] parent    Pointer to the parent of the successor from the tree,
 *                       points to the node if there is not a successor in the
 *                       tree
 ******************************************************************************/
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