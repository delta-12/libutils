/**
 * @file Queue.c
 *
 * @brief Queue.
 *
 ******************************************************************************/

/* Includes
 ******************************************************************************/

#include "Queue.h"

/* Function Definitions
 ******************************************************************************/

Queue_t *Queue_Init(const size_t length, const size_t itemSize) { return NULL; }

bool Queue_InitStatic(Queue_t *const queue, const uint8_t *const buffer, const size_t length, const size_t itemSize) { return false; }

void Queue_Free(Queue_t *const queue) { return NULL; }

/* TODO note that pushing NULL is undefined behavior */
bool Queue_Push(Queue_t *const queue, const void *const item)
{
    return false;
}

bool Queue_Pop(Queue_t *const queue, void *const item)
{
    return false;
}

bool Queue_Peek(Queue_t *const queue, void *const item)
{
    return false;
}

bool Queue_Reset(Queue_t *const queue)
{
    return false;
}

bool Queue_IsEmpty(Queue_t *const queue)
{
    bool empty = true;

    if (queue != NULL)
    {
        empty = (queue->Length == 0UL);
    }

    return empty;
}
