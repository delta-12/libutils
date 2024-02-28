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

/* Typedefs
 ******************************************************************************/

/* TODO typedef comments */

typedef int64_t SinglyLinkedList_Index_t;
typedef SinglyLinkedList_Index_t SinglyLinkedList_Length_t;

typedef struct SinglyLinkedList_Node SinglyLinkedList_Node_t;

struct SinglyLinkedList_Node
{
    SinglyLinkedList_Node_t *Next;
    void *Item;
};

typedef struct
{
    SinglyLinkedList_Node_t *Head;
    SinglyLinkedList_Length_t Length;
} SinglyLinkedList_t;

/* Function Prototypes
 ******************************************************************************/

bool SinglyLinkedList_Init(SinglyLinkedList_t *const list);
bool SinglyLinkedList_Free(SinglyLinkedList_t *const list);
bool SinglyLinkedList_Append(SinglyLinkedList_t *const list, const void *const item);
bool SinglyLinkedList_AppendLeft(SinglyLinkedList_t *const list, const void *const item);
bool SinglyLinkedList_Pop(SinglyLinkedList_t *const list, void *const item);
bool SinglyLinkedList_PopLeft(SinglyLinkedList_t *const list, void *const item);
bool SinglyLinkedList_Reset(SinglyLinkedList_t *const list, const void *const item);
SinglyLinkedList_Index_t SinglyLinkedList_GetIndex(const SinglyLinkedList_t *const list);
SinglyLinkedList_Length_t SinglyLinkedList_GetLength(const SinglyLinkedList_t *const list);
bool SinglyLinkedList_Insert(SinglyLinkedList_t *const list, const void *const item, const SinglyLinkedList_Index_t index);
bool SinglyLinkedList_Remove(SinglyLinkedList_t *const list, const SinglyLinkedList_Index_t index);

#endif