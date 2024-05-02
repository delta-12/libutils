/**
 * @file Stack.h
 *
 * @brief Dynamically and statically allocated stacks.
 *
 ******************************************************************************/

#ifndef STACK_H
#define STACK_H

/* Includes
 ******************************************************************************/

#include "SinglyLinkedList.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/* Typedefs
 ******************************************************************************/

/* Definition of a stack */
typedef struct
{
  union
  {
    struct
    {
      uint8_t *Buffer;   /* Pointer to a buffer large enough to store the maximum number of items the stack can hold */
      uint64_t Length;   /* Maximum number of items the stack can hold */
      size_t ItemSize;   /* Size of each item in the stack */
      size_t BufferSize; /* Size of the buffer holding items in the stack */
      size_t Top;        /* Offset from the start of the buffer to the top item in the stack */
      uint64_t Items;    /* Number of items currently in the stack */
    };                   /* Struct for static stack */
    SinglyLinkedList_t LinkedList;
  };
  bool Static; /* Flag set for static stacks */
} Stack_t;

/* Function Prototypes
 ******************************************************************************/

bool Stack_Init(Stack_t *const stack, const size_t itemSize);
bool Stack_InitStatic(Stack_t *const stack, uint8_t *const buffer, const uint64_t length, const size_t itemSize);
bool Stack_Free(Stack_t *const stack);
bool Stack_Push(Stack_t *const stack, const void *const item);
bool Stack_Pop(Stack_t *const stack, void *const item);
bool Stack_Peek(const Stack_t *const stack, void *const item);
bool Stack_Reset(Stack_t *const stack);
bool Stack_IsEmpty(const Stack_t *const stack);
bool Stack_IsFull(const Stack_t *const stack);

#endif