/**
 * @file Queue.c
 *
 * @brief Queue.
 *
 ******************************************************************************/

/* Includes
 ******************************************************************************/

#include "Queue.h"
#include <string.h>

/* Function Prototypes
 ******************************************************************************/

static inline void Queue_AdvanceItemOffset(Queue_t *const queue, size_t *const itemOffset);

/* Function Definitions
 ******************************************************************************/

/* TODO comment blocks */
Queue_t *Queue_Init(const uint64_t length, const size_t itemSize)
{
    uint8_t *allocated = (uint8_t *)malloc(sizeof(Queue_t) + (length * itemSize));
    Queue_t *queue = (Queue_t *)allocated;
    uint8_t *buffer = (uint8_t *)(allocated + sizeof(Queue_t));

    if (!Queue_InitStatic(queue, buffer, length, itemSize))
    {
        Queue_Free(queue);

        queue = NULL;
    }

    return queue;
}

bool Queue_InitStatic(Queue_t *const queue, uint8_t *const buffer, const size_t length, const size_t itemSize)
{
    bool init = false;

    if (queue != NULL && buffer != NULL)
    {
        queue->Buffer = buffer;
        queue->Length = length;
        queue->ItemSize = itemSize;
        queue->BufferSize = queue->Length * queue->ItemSize;
        Queue_Reset(queue);

        init = true;
    }

    return init;
}

void Queue_Free(Queue_t *const queue)
{
    if (queue != NULL)
    {
        free((void *)queue);
    }
}

bool Queue_Push(Queue_t *const queue, const void *const item)
{
    bool pushed = false;

    if (queue != NULL && item != NULL)
    {
        if (queue->Items < queue->Length)
        {
            memcpy(queue->Buffer + queue->Tail, item, queue->ItemSize);
            Queue_AdvanceItemOffset(queue, &queue->Tail);
            queue->Items++;

            pushed = true;
        }
    }

    return pushed;
}

bool Queue_Pop(Queue_t *const queue, void *const item)
{
    bool popped = false;

    if (Queue_Peek(queue, item))
    {
        Queue_AdvanceItemOffset(queue, &queue->Head);
        queue->Items--;

        popped = true;
    }

    return popped;
}

bool Queue_Peek(Queue_t *const queue, void *const item)
{
    bool peeked = false;

    if (queue != NULL && item != NULL)
    {
        if (!Queue_IsEmpty(queue))
        {
            memcpy(item, queue->Buffer + queue->Head, queue->ItemSize);

            peeked = true;
        }
    }

    return peeked;
}

bool Queue_Reset(Queue_t *const queue)
{
    bool reset = false;

    if (queue != NULL)
    {
        queue->Items = 0UL;
        queue->Head = 0UL;
        queue->Tail = 0UL;

        reset = true;
    }

    return reset;
}

bool Queue_IsEmpty(Queue_t *const queue)
{
    bool empty = true;

    if (queue != NULL)
    {
        empty = (queue->Items == 0UL);
    }

    return empty;
}

static inline void Queue_AdvanceItemOffset(Queue_t *const queue, size_t *const itemOffset)
{
    if (queue != NULL && itemOffset != NULL)
    {
        *itemOffset = (*itemOffset + queue->ItemSize) % queue->BufferSize;
    }
}
