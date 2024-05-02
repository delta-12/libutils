/**
 * @file SinglyLinkedList.h
 *
 * @brief Singly linked list.
 *
 ******************************************************************************/

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

/* Includes
 ******************************************************************************/

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/* Defines
 ******************************************************************************/

#define SINGLY_LINKED_LIST_INDEX_ERROR  (-1L) /* Value to return if there is an indexing error */
#define SINGLY_LINKED_LIST_LENGTH_ERROR (-1L) /* Value to return if there is an error with the length of a list */

/* Typedefs
 ******************************************************************************/

typedef int64_t                      SinglyLinkedList_Index_t;  /* Index of a node in a list */
typedef SinglyLinkedList_Index_t     SinglyLinkedList_Length_t; /* Length of a list */
typedef struct SinglyLinkedList_Node SinglyLinkedList_Node_t;   /* Node in a singly linked list */

/* Definition of a node in a singly linked list */
struct SinglyLinkedList_Node
{
  SinglyLinkedList_Node_t *Next; /* Pointer to the next node in the list */
  uint8_t *Item;                 /* Pointer to the buffer storing the node's item */
};

/* Definition of a singly linked list */
typedef struct
{
  SinglyLinkedList_Node_t *Head;    /* Pointer to the node at the head of the list */
  SinglyLinkedList_Length_t Length; /* Length of the list */
  size_t ItemSize;                  /* Size of each node's item in the list */
} SinglyLinkedList_t;

/* Function Prototypes
 ******************************************************************************/

bool SinglyLinkedList_Init(SinglyLinkedList_t *const list, const size_t itemSize);
bool SinglyLinkedList_Free(SinglyLinkedList_t *const list);
bool SinglyLinkedList_Append(SinglyLinkedList_t *const list, const void *const item);
bool SinglyLinkedList_AppendLeft(SinglyLinkedList_t *const list, const void *const item);
bool SinglyLinkedList_Pop(SinglyLinkedList_t *const list, void *const item);
bool SinglyLinkedList_PopLeft(SinglyLinkedList_t *const list, void *const item);
bool SinglyLinkedList_Reset(SinglyLinkedList_t *const list);
SinglyLinkedList_Index_t SinglyLinkedList_GetIndex(const SinglyLinkedList_t *const list, const void *const item);
SinglyLinkedList_Length_t SinglyLinkedList_GetLength(const SinglyLinkedList_t *const list);
bool SinglyLinkedList_Insert(SinglyLinkedList_t *const list, const SinglyLinkedList_Index_t index, const void *const item);
bool SinglyLinkedList_Remove(SinglyLinkedList_t *const list, const SinglyLinkedList_Index_t index, void *const item);
bool SinglyLinkedList_GetHead(const SinglyLinkedList_t *const list, void *const item);
bool SinglyLinkedList_GetTail(const SinglyLinkedList_t *const list, void *const item);
bool SinglyLinkedList_IsEmpty(const SinglyLinkedList_t *const list);

#endif