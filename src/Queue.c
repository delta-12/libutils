/**
 * @file Queue.c
 *
 * @brief Dynamically and statically allocated queues.
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
 * @param[in,out] queue    Pointer to the queue to initialize
 * @param[in]     itemSize Size in bytes of the items held in the queue
 *
 * @return Whether the queue was successfully initialized or not
 *
 * @retval true  Successfully initialized
 * @retval false Failed to initialize
 ******************************************************************************/
bool Queue_Init(Queue_t *const queue, const size_t itemSize)
{
  bool init = false;

  if (queue != NULL)
  {
    queue->Static = false;
    init = DoublyLinkedList_Init(&queue->LinkedList, itemSize);
  }

  return init;
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
    queue->Static = true;
    Queue_Reset(queue);

    init = true;
  }

  return init;
}

/**
 * @brief Free a dynamically allocated queue.
 *
 * @param[in,out] queue Pointer to the queue to free
 *
 * @return Whether the queue was successfully freed or not
 *
 * @retval true  Successfully freed
 * @retval false Failed to free
 ******************************************************************************/
bool Queue_Free(Queue_t *const queue)
{
  bool freed = false;

  if (queue != NULL && !queue->Static)
  {
    freed = DoublyLinkedList_Free(&queue->LinkedList);
  }

  return freed;
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
    if (queue->Static && queue->Items < queue->Length)
    {
      memcpy(queue->Buffer + queue->Tail, item, queue->ItemSize);
      Queue_AdvanceItemOffset(queue, &queue->Tail);
      queue->Items++;

      pushed = true;
    }
    else
    {
      pushed = DoublyLinkedList_AppendLeft(&queue->LinkedList, item);
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
    if (queue->Static)
    {
      Queue_AdvanceItemOffset(queue, &queue->Head);
      queue->Items--;

      popped = true;
    }
    else
    {
      popped = DoublyLinkedList_Pop(&queue->LinkedList, NULL);
    }
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

  if (!Queue_IsEmpty(queue) && item != NULL)
  {
    if (queue->Static)
    {
      memcpy(item, queue->Buffer + queue->Head, queue->ItemSize);

      peeked = true;
    }
    else
    {
      peeked = DoublyLinkedList_GetTail(&queue->LinkedList, item);
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
    if (queue->Static)
    {
      queue->Items = 0UL;
      queue->Head = 0UL;
      queue->Tail = 0UL;

      reset = true;
    }
    else
    {
      reset = DoublyLinkedList_Reset(&queue->LinkedList);
    }
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
    if (queue->Static)
    {
      empty = (queue->Items == 0UL);
    }
    else
    {
      empty = DoublyLinkedList_IsEmpty(&queue->LinkedList);
    }
  }

  return empty;
}

/**
 * @brief Check if a statically allocated queue is full.
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

  if (queue != NULL && queue->Static)
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
  if (queue != NULL && queue->Static && itemOffset != NULL)
  {
    *itemOffset = (*itemOffset + queue->ItemSize) % queue->BufferSize;
  }
}