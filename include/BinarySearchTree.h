/**
 * @file BinarySearchTree.h
 *
 * @brief Binary search tree.
 *
 ******************************************************************************/

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

/* Includes
 ******************************************************************************/

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/* Typedefs
 ******************************************************************************/

typedef struct BinarySearchTree_Node BinarySearchTree_Node_t; /* Node in a binary search tree */

/* Definition of a node in a binary search tree */
struct BinarySearchTree_Node
{
  BinarySearchTree_Node_t *Left;    /* Pointer to the left child in the tree */
  BinarySearchTree_Node_t *Right;   /* Pointer to the right child in the tree */
  uint8_t *Key;                     /* Pointer to the buffer storing the node's key */
  uint8_t *Item;                    /* Pointer to the buffer storing the node's item */
};

/* Definition of a binary search tree */
typedef struct
{
  BinarySearchTree_Node_t *Root;   /* Pointer to the root of the tree */
  size_t KeySize;                  /* Size of each node's key in the tree */
  size_t ItemSize;                 /* Size of each node's item in the tree */
} BinarySearchTree_t;

/* Function Prototypes
 ******************************************************************************/

bool BinarySearchTree_Init(BinarySearchTree_t *const tree, const size_t keySize, const size_t itemSize);
bool BinarySearchTree_Free(BinarySearchTree_t *const tree);
bool BinarySearchTree_Insert(BinarySearchTree_t *const tree, const void *const key, const void *const item);
bool BinarySearchTree_Remove(BinarySearchTree_t *const tree, const void *const key);
bool BinarySearchTree_Search(BinarySearchTree_t *const tree, const void *const key, void *const item);
bool BinarySearchTree_Reset(BinarySearchTree_t *const tree);

#endif