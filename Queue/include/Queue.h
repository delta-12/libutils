/**
 * @file Queue.h
 *
 * @brief Queue.
 *
 ******************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

/* Includes
 ******************************************************************************/

#include "stdbool.h"
#include "stdint.h"
#include "stdlib.h"

/* Typedefs
 ******************************************************************************/

typedef struct
{
    uint8_t *Buffer; /* Pointer to buffer large enough to hold the maximum number of items the queue can hold */
    uint64_t Length; /* Maximum number of items the queue can hold */
    size_t ItemSize; /* Size of each item in the queue */
    uint8_t *Head;   /* Pointer to the first item in the queue */
    uint8_t *Tail;   /* Pointer to the last item in the queue */
} Queue_t;           /* Definition of the queue */

/* Function Prototypes
 ******************************************************************************/

Queue_t *Queue_Init(const size_t length, const size_t itemSize);
bool Queue_InitStatic(Queue_t *const queue, const uint8_t *const buffer, const uint64_t length, const size_t itemSize);
void Queue_Free(Queue_t *const queue);
bool Queue_Push(Queue_t *const queue, const void *const item);
bool Queue_Pop(Queue_t *const queue, void *const item);
bool Queue_Peek(Queue_t *const queue, void *const item);
bool Queue_Reset(Queue_t *const queue);
bool Queue_IsEmpty(Queue_t *const queue);

#endif