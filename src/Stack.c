/**
 * @file Stack.c
 *
 * @brief Dynamically and statically allocated stacks.
 *
 ******************************************************************************/

/* Includes
 ******************************************************************************/

#include "Stack.h"
#include <string.h>

/* Function Definitions
 ******************************************************************************/

/**
 * @brief Initialize a dynamically allocated stack.
 *
 * @param[in,out] stack    Pointer to the stack to initialize
 * @param[in]     itemSize Size in bytes of the items held in the stack
 *
 * @return Whether the stack was successfully initialized or not
 *
 * @retval true  Successfully initialized
 * @retval false Failed to initialize
 ******************************************************************************/
bool Stack_Init(Stack_t *const stack, const size_t itemSize)
{
  bool init = false;

  if (stack != NULL)
  {
    stack->Static = false;
    init = SinglyLinkedList_Init(&stack->LinkedList, itemSize);
  }

  return init;
}

/**
 * @brief Initialize a statically allocated stack.
 *
 * @param[in,out] stack    Pointer to the stack to initialize
 * @param[in]     buffer   Pointer to a statically allocated buffer large
 *                         enough to store the maximum number of items the
 *                         stack can hold
 * @param[in]     length   Maximum number of items the stack can hold
 * @param[in]     itemSize Size in bytes of the items held in the stack
 *
 * @return Whether the stack was successfully initialized or not
 *
 * @retval true  Successfully initialized
 * @retval false Failed to initialize
 ******************************************************************************/
bool Stack_InitStatic(Stack_t *const stack, uint8_t *const buffer, const uint64_t length, const size_t itemSize)
{
  bool init = false;

  if (stack != NULL && buffer != NULL)
  {
    stack->Buffer = buffer;
    stack->Length = length;
    stack->ItemSize = itemSize;
    stack->BufferSize = stack->Length * stack->ItemSize;
    stack->Static = true;
    Stack_Reset(stack);

    init = true;
  }

  return init;
}

/**
 * @brief Free a dynamically allocated stack.
 *
 * @param[in,out] stack Pointer to the stack to free
 *
 * @return Whether the stack was successfully freed or not
 *
 * @retval true  Successfully freed
 * @retval false Failed to free
 ******************************************************************************/
bool Stack_Free(Stack_t *const stack)
{
  bool freed = false;

  if (stack != NULL && !stack->Static)
  {
    freed = SinglyLinkedList_Free(&stack->LinkedList);
  }

  return freed;
}

/**
 * @brief Push an item to the top of a stack.  Items are stored by copy, not
 *        reference.
 *
 * @param[in,out] stack Pointer to the stack to push the item to
 * @param[in]     item  Pointer to the item to push to the stack
 *
 * @return Whether the item was successfully pushed to the stack or not
 *
 * @retval true  Successfully pushed the item to the stack
 * @retval false Failed to push the item to the stack
 ******************************************************************************/
bool Stack_Push(Stack_t *const stack, const void *const item)
{
  bool pushed = false;

  if (stack != NULL && item != NULL)
  {
    if (stack->Static && stack->Items < stack->Length)
    {
      if (stack->Items > 0UL)
      {
        stack->Top += stack->ItemSize;
      }

      memcpy(stack->Buffer + stack->Top, item, stack->ItemSize);
      stack->Items++;

      pushed = true;
    }
    else
    {
      pushed = SinglyLinkedList_AppendLeft(&stack->LinkedList, item);
    }
  }

  return pushed;
}

/**
 * @brief Pop an item from the top of a stack.
 *
 * @param[in,out] stack Pointer to the stack to pop the item from
 * @param[in,out] item  Pointer to a buffer large enough to copy the item
 *                      into
 *
 * @return Whether the item was successfully popped from the stack or not
 *
 * @retval true  Successfully popped the item from the stack
 * @retval false Failed to pop the item from the stack
 ******************************************************************************/
bool Stack_Pop(Stack_t *const stack, void *const item)
{
  bool popped = false;

  if (Stack_Peek(stack, item))
  {
    if (stack->Static)
    {
      stack->Items--;

      if (stack->Items > 0UL)
      {
        stack->Top -= stack->ItemSize;
      }

      popped = true;
    }
    else
    {
      popped = SinglyLinkedList_PopLeft(&stack->LinkedList, NULL);
    }
  }

  return popped;
}

/**
 * @brief Get an item from the top of a stack without removing it from the
 *        stack.  Similar to popping an item, but without removal.
 *
 * @param[in]     stack Pointer to the stack to get the item from
 * @param[in,out] item  Pointer to a buffer large enough to copy the item
 *                      into
 *
 * @return Whether the item in the stack was successfully peeked at or not
 *
 * @retval true  Successfully peeked at the item in the stack
 * @retval false Failed to peek at the item in the stack
 ******************************************************************************/
bool Stack_Peek(const Stack_t *const stack, void *const item)
{
  bool peeked = false;

  if (!Stack_IsEmpty(stack) && item != NULL)
  {
    if (stack->Static)
    {
      memcpy(item, stack->Buffer + stack->Top, stack->ItemSize);

      peeked = true;
    }
    else
    {
      peeked = SinglyLinkedList_GetHead(&stack->LinkedList, item);
    }
  }

  return peeked;
}

/**
 * @brief Reset a stack to its initial state.
 *
 * @param[in,out] stack Pointer to the stack to reset
 ******************************************************************************/
bool Stack_Reset(Stack_t *const stack)
{
  bool reset = false;

  if (stack != NULL)
  {
    if (stack->Static)
    {
      stack->Items = 0UL;
      stack->Top = 0UL;

      reset = true;
    }
    else
    {
      reset = SinglyLinkedList_Reset(&stack->LinkedList);
    }
  }

  return reset;
}

/**
 * @brief Check if a stack is empty.
 *
 * @param[in] stack Pointer to the stack to check
 *
 * @return Whether the stack is empty or not
 *
 * @retval true  Stack is empty
 * @retval false Stack is not empty
 ******************************************************************************/
bool Stack_IsEmpty(const Stack_t *const stack)
{
  bool empty = true;

  if (stack != NULL)
  {
    if (stack->Static)
    {
      empty = (stack->Items == 0UL);
    }
    else
    {
      empty = SinglyLinkedList_IsEmpty(&stack->LinkedList);
    }
  }

  return empty;
}

/**
 * @brief Check if a stack is full.
 *
 * @param[in] stack Pointer to the stack to check
 *
 * @return Whether the stack is full or not
 *
 * @retval true  Stack is full
 * @retval false Stack is not full
 ******************************************************************************/
bool Stack_IsFull(const Stack_t *const stack)
{
  bool full = false;

  if (stack != NULL && stack->Static)
  {
    full = (stack->Items * stack->ItemSize == stack->BufferSize);
  }

  return full;
}