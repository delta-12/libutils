/**
 * @file Stack.c
 *
 * @brief Dynamically and statically allocated fixed-sized stacks.
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
 * @param[in] length   Maximum number of items the stack can hold
 * @param[in] itemSize Size in bytes of the items held in the stack
 *
 * @return Pointer to the initialized stack
 *
 * @retval NULL Failed to initialize a stack
 ******************************************************************************/
Stack_t *Stack_Init(const uint64_t length, const size_t itemSize)
{
  uint8_t *allocated = (uint8_t *)malloc(sizeof(Stack_t) + (length * itemSize));
  Stack_t *stack = (Stack_t *)allocated;
  uint8_t *buffer = (uint8_t *)(allocated + sizeof(Stack_t));

  if (!Stack_InitStatic(stack, buffer, length, itemSize))
  {
    Stack_Free(stack);

    stack = NULL;
  }

  return stack;
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
    Stack_Reset(stack);

    init = true;
  }

  return init;
}

/**
 * @brief Free a dynamically allocated stack.
 *
 * @param[in,out] stack Pointer to the stack to free
 ******************************************************************************/
void Stack_Free(Stack_t *const stack)
{
  if (stack != NULL)
  {
    free((void *)stack);
  }
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
    if (stack->Items < stack->Length)
    {
      if (stack->Items > 0UL)
      {
        stack->Top += stack->ItemSize;
      }

      memcpy(stack->Buffer + stack->Top, item, stack->ItemSize);
      stack->Items++;

      pushed = true;
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
    stack->Top -= stack->ItemSize;
    stack->Items--;

    popped = true;
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

  if (stack != NULL && item != NULL)
  {
    if (!Stack_IsEmpty(stack))
    {
      memcpy(item, stack->Buffer + stack->Top, stack->ItemSize);

      peeked = true;
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
    stack->Items = 0UL;
    stack->Top = 0UL;

    reset = true;
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
    empty = (stack->Items == 0UL);
  }

  return empty;
}