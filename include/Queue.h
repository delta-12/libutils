/**
 * @file Queue.h
 *
 * @brief Dynamically and statically allocated fixed-sized queues.
 *
 ******************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

/* Includes
 ******************************************************************************/

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/* Typedefs
 ******************************************************************************/

/* Definition of a queue */
typedef struct
{
  uint8_t *Buffer;   /* Pointer to a buffer large enough to store the maximum number of items the queue can hold */
  uint64_t Length;   /* Maximum number of items the queue can hold */
  size_t ItemSize;   /* Size of each item in the queue */
  size_t BufferSize; /* Size of the buffer holding items in the queue */
  size_t Head;       /* Offset from the start of the buffer to the first item in the queue */
  size_t Tail;       /* Offset from the start of the buffer to the last item in the queue */
  uint64_t Items;    /* Number of items currently in the queue */
} Queue_t;

/* Function Prototypes
 ******************************************************************************/

Queue_t *Queue_Init(const uint64_t length, const size_t itemSize);
bool Queue_InitStatic(Queue_t *const queue, uint8_t *const buffer, const uint64_t length, const size_t itemSize);
void Queue_Free(Queue_t *const queue);
bool Queue_Push(Queue_t *const queue, const void *const item);
bool Queue_Pop(Queue_t *const queue, void *const item);
bool Queue_Peek(const Queue_t *const queue, void *const item);
bool Queue_Reset(Queue_t *const queue);
bool Queue_IsEmpty(const Queue_t *const queue);

#endif