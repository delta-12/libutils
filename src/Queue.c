/**
 * @file Queue.c
 *
 * @brief Dynamically and statically allocated fixed-sized queues.
 *
 ******************************************************************************/

/* Includes
 ******************************************************************************/

#include "Queue.h"
#include <string.h>

/* Function Prototypes
 ******************************************************************************/

static inline void Queue_AdvanceItemOffset(const Queue_t *const queue, size_t *const itemOffset);

/* Function Definitions
 ******************************************************************************/

/**
 * @brief Initialize a dynamically allocated queue.
 *
 * @param[in] length   Maximum number of items the queue can hold
 * @param[in] itemSize Size in bytes of the items held in the queue
 *
 * @return Pointer to the initialized queue
 *
 * @retval NULL Failed to initialize a queue
 ******************************************************************************/
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

/**
 * @brief Initialize a statically allocated queue.
 *
 * @param[in,out] queue    Pointer to the queue to initialize
 * @param[in]     buffer   Pointer to a statically allocated buffer large
 *                         enough to store the maximum number of items the
 *                         queue can hold
 * @param[in]     length   Maximum number of items the queue can hold
 * @param[in]     itemSize Size in bytes of the items held in the queue
 *
 * @return Whether the queue was successfully initialized or not
 *
 * @retval true  Successfully initialized
 * @retval false Failed to initialize
 ******************************************************************************/
bool Queue_InitStatic(Queue_t *const queue, uint8_t *const buffer, const uint64_t length, const size_t itemSize)
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

/**
 * @brief Free a dynamically allocated queue.
 *
 * @param[in,out] queue Pointer to the queue to free
 ******************************************************************************/
void Queue_Free(Queue_t *const queue)
{
  if (queue != NULL)
  {
    free((void *)queue);
  }
}

/**
 * @brief Push an item to a queue.  Items are stored by copy, not reference.
 *
 * @param[in,out] queue Pointer to the queue to push the item to
 * @param[in]     item  Pointer to the item to push to the queue
 *
 * @return Whether the item was successfully pushed to the queue or not
 *
 * @retval true  Successfully pushed the item to the queue
 * @retval false Failed to push the item to the queue
 ******************************************************************************/
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

/**
 * @brief Pop an item from a queue.
 *
 * @param[in,out] queue Pointer to the queue to pop the item from
 * @param[in,out] item  Pointer to a buffer large enough to copy the item
 *                      into
 *
 * @return Whether the item was successfully popped from the queue or not
 *
 * @retval true  Successfully popped the item from the queue
 * @retval false Failed to pop the item from the queue
 ******************************************************************************/
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

/**
 * @brief Get an item from a queue without removing it from the queue.
 *        Similar to popping an item, but without removal.
 *
 * @param[in]     queue Pointer to the queue to get the item from
 * @param[in,out] item  Pointer to a buffer large enough to copy the item
 *                      into
 *
 * @return Whether the item in the queue was successfully peeked at or not
 *
 * @retval true  Successfully peeked at the item in the queue
 * @retval false Failed to peek at the item in the queue
 ******************************************************************************/
bool Queue_Peek(const Queue_t *const queue, void *const item)
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

/**
 * @brief Reset a queue to its initial state.
 *
 * @param[in,out] queue Pointer to the queue to reset
 ******************************************************************************/
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

/**
 * @brief Check if a queue is empty.
 *
 * @param[in] queue Pointer to the queue to check
 *
 * @return Whether the queue is empty or not
 *
 * @retval true  Queue is empty
 * @retval false Queue is not empty
 ******************************************************************************/
bool Queue_IsEmpty(const Queue_t *const queue)
{
  bool empty = true;

  if (queue != NULL)
  {
    empty = (queue->Items == 0UL);
  }

  return empty;
}

/**
 * @brief Check if a queue is full.
 *
 * @param[in] queue Pointer to the queue to check
 *
 * @return Whether the queue is full or not
 *
 * @retval true  Queue is full
 * @retval false Queue is not full
 ******************************************************************************/
bool Queue_IsFull(const Queue_t *const queue)
{
  bool full = false;

  if (queue != NULL)
  {
    full = (queue->Items * queue->ItemSize == queue->BufferSize);
  }

  return full;
}

/**
 * @brief Increment a head or tail offset in a queue by the size of an item
 *        stored in the queue.
 *
 * @param[in,out] queue      Pointer to the queue with the item offset to
 *                           advance
 * @param[in,out] itemOffset Pointer to the head or tail offset to advance
 ******************************************************************************/
static inline void Queue_AdvanceItemOffset(const Queue_t *const queue, size_t *const itemOffset)
{
  if (queue != NULL && itemOffset != NULL)
  {
    *itemOffset = (*itemOffset + queue->ItemSize) % queue->BufferSize;
  }
}