/**
 * @file DoublyLinkedList.h
 *
 * @brief Doubly linked list.
 *
 ******************************************************************************/

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

/* Includes
 ******************************************************************************/

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/* Defines
 ******************************************************************************/

#define DOUBLY_LINKED_LIST_INDEX_ERROR (-1L)  /* Value to return if there is an indexing error */
#define DOUBLY_LINKED_LIST_LENGTH_ERROR (-1L) /* Value to return if there is an error with the length of a list */

/* Typedefs
 ******************************************************************************/

typedef int64_t DoublyLinkedList_Index_t;                   /* Index of a node in a list */
typedef DoublyLinkedList_Index_t DoublyLinkedList_Length_t; /* Length of a list */

typedef struct DoublyLinkedList_Node DoublyLinkedList_Node_t; /* Node in a singly linked list */

/* Definition of a node in a singly linked list */
struct DoublyLinkedList_Node
{
    DoublyLinkedList_Node_t *Next;     /* Pointer to the next node in the list */
    DoublyLinkedList_Node_t *Previous; /* Pointer to the previous node in the list */
    uint8_t *Item;                     /* Pointer to the buffer storing the node's item */
};

/* Definition of a singly linked list */
typedef struct
{
    DoublyLinkedList_Node_t *Head;    /* Pointer to the node at the head of the list */
    DoublyLinkedList_Node_t *Tail;    /* Pointer to the node at the tail of the list */
    DoublyLinkedList_Length_t Length; /* Length of the list */
    size_t ItemSize;                  /* Size of each node's item in the list */
} DoublyLinkedList_t;

/* Function Prototypes
 ******************************************************************************/

bool DoublyLinkedList_Init(DoublyLinkedList_t *const list, const size_t itemSize);
bool DoublyLinkedList_Free(DoublyLinkedList_t *const list);
bool DoublyLinkedList_Append(DoublyLinkedList_t *const list, const void *const item);
bool DoublyLinkedList_AppendLeft(DoublyLinkedList_t *const list, const void *const item);
bool DoublyLinkedList_Pop(DoublyLinkedList_t *const list, void *const item);
bool DoublyLinkedList_PopLeft(DoublyLinkedList_t *const list, void *const item);
bool DoublyLinkedList_Reset(DoublyLinkedList_t *const list);
DoublyLinkedList_Index_t DoublyLinkedList_GetIndex(const DoublyLinkedList_t *const list, const void *const item);
DoublyLinkedList_Length_t DoublyLinkedList_GetLength(const DoublyLinkedList_t *const list);
bool DoublyLinkedList_Insert(DoublyLinkedList_t *const list, const DoublyLinkedList_Index_t index, const void *const item);
bool DoublyLinkedList_Remove(DoublyLinkedList_t *const list, const DoublyLinkedList_Index_t index, void *const item);

#endif