/**
 * @file DoublyLinkedList.c
 *
 * @brief Doubly linked list.
 *
 ******************************************************************************/

/* Includes
 ******************************************************************************/

#include "DoublyLinkedList.h"
#include <string.h>

/* Function Definitions
 ******************************************************************************/

/**
 * @brief Initialize a doubly linked list.
 *
 * @param[in,out] list     Pointer to the list to initialize
 * @param[in]     itemSize Size in bytes of the items held in the list
 *
 * @return Whether the list was successfully initialized or not
 *
 * @retval true  Successfully initialized
 * @retval false Failed to initialize
 ******************************************************************************/
bool DoublyLinkedList_Init(DoublyLinkedList_t *const list, const size_t itemSize)
{
  bool init = false;

  if (list != NULL)
  {
    list->Head = NULL;
    list->Tail = NULL;
    list->Length = 0L;
    list->ItemSize = itemSize;

    init = true;
  }

  return init;
}

/**
 * @brief Free a doubly linked list.
 *
 * @param[in,out] list Pointer to the list to free
 *
 * @note This function merely calls DoublyLinkedList_Reset.  See the
 *       documentation for DoublyLinkedList_Reset for more information.
 ******************************************************************************/
bool DoublyLinkedList_Free(DoublyLinkedList_t *const list)
{
  return DoublyLinkedList_Reset(list);
}

/**
 * @brief Append an item to the end of a doubly linked list.  Items are stored
 *        by copy, not reference.
 *
 * @param[in,out] list Pointer to the list to append the item to
 * @param[in]     item Pointer to the item to append to the list
 *
 * @return Whether the item was successfully appended to the list or not
 *
 * @retval true  Successfully appended the item to the list
 * @retval false Failed to append the item to the list
 ******************************************************************************/
bool DoublyLinkedList_Append(DoublyLinkedList_t *const list, const void *const item)
{
  bool appended = false;

  if (list != NULL && item != NULL)
  {
    DoublyLinkedList_Node_t *newNode = (DoublyLinkedList_Node_t *)malloc(sizeof(DoublyLinkedList_Node_t) + list->ItemSize);

    newNode->Next = NULL;
    newNode->Previous = NULL;
    newNode->Item = (uint8_t *)newNode + sizeof(DoublyLinkedList_Node_t);
    memcpy(newNode->Item, item, list->ItemSize);

    if (list->Tail == NULL)
    {
      list->Head = newNode;
      list->Tail = newNode;
    }
    else
    {
      list->Tail->Next = newNode;
      newNode->Previous = list->Tail;
      list->Tail = newNode;
    }

    list->Length++;

    appended = true;
  }

  return appended;
}

/**
 * @brief Add an item to the beginning of a doubly linked list.  Items are
 *        stored by copy, not reference.
 *
 * @param[in,out] list Pointer to the list to append the item to the left of
 * @param[in]     item Pointer to the item to append to the left of the list
 *
 * @return Whether the item was successfully appended to the left of the list
 *         or not
 *
 * @retval true  Successfully appended the item to the left of the list
 * @retval false Failed to append the item to the left of the list
 ******************************************************************************/
bool DoublyLinkedList_AppendLeft(DoublyLinkedList_t *const list, const void *const item)
{
  bool appended = false;

  if (list != NULL && item != NULL)
  {
    DoublyLinkedList_Node_t *newNode = (DoublyLinkedList_Node_t *)malloc(sizeof(DoublyLinkedList_Node_t) + list->ItemSize);

    newNode->Next = NULL;
    newNode->Previous = NULL;
    newNode->Item = (uint8_t *)newNode + sizeof(DoublyLinkedList_Node_t);
    memcpy(newNode->Item, item, list->ItemSize);

    if (list->Head == NULL)
    {
      list->Head = newNode;
      list->Tail = newNode;
    }
    else
    {
      list->Head->Previous = newNode;
      newNode->Next = list->Head;
      list->Head = newNode;
    }

    list->Length++;

    appended = true;
  }

  return appended;
}

/**
 * @brief Pop an item from the end of a doubly linked list.
 *
 * @param[in,out] list Pointer to the list to pop the item from
 * @param[in,out] item Pointer to a buffer large enough to copy the item
 *                     into, NULL if the item does not need to be copied
 *
 * @return Whether the item was successfully popped from the list or not
 *
 * @retval true  Successfully popped the item from the list
 * @retval false Failed to pop the item from the list
 ******************************************************************************/
bool DoublyLinkedList_Pop(DoublyLinkedList_t *const list, void *const item)
{
  bool popped = false;

  if (list != NULL && list->Tail != NULL)
  {
    DoublyLinkedList_Node_t *newTail = list->Tail->Previous;

    if (item != NULL)
    {
      memcpy(item, list->Tail->Item, list->ItemSize);
    }

    free(list->Tail);
    list->Length--;
    list->Tail = newTail;

    if (list->Tail == NULL)
    {
      list->Head = NULL;
    }
    else
    {
      list->Tail->Next = NULL;
    }

    popped = true;
  }

  return popped;
}

/**
 * @brief Pop an item from the beginning of a doubly linked list.
 *
 * @param[in,out] list Pointer to the list to pop the item from the left of
 * @param[in,out] item Pointer to a buffer large enough to copy the item
 *                     into, NULL if the item does not need to be copied
 *
 * @return Whether the item was successfully popped from the left of the list
 *         or not
 *
 * @retval true  Successfully popped the item from the left of the list
 * @retval false Failed to pop the item from the left of the list
 ******************************************************************************/
bool DoublyLinkedList_PopLeft(DoublyLinkedList_t *const list, void *const item)
{
  bool popped = false;

  if (list != NULL && list->Head != NULL)
  {
    DoublyLinkedList_Node_t *newHead = list->Head->Next;

    if (item != NULL)
    {
      memcpy(item, list->Head->Item, list->ItemSize);
    }

    free(list->Head);
    list->Length--;
    list->Head = newHead;

    if (list->Head == NULL)
    {
      list->Tail = NULL;
    }
    else
    {
      list->Head->Previous = NULL;
    }

    popped = true;
  }

  return popped;
}

/**
 * @brief Reset a doubly linked list to its initial state and free all nodes.
 *
 * @param[in,out] list Pointer to the list to reset
 ******************************************************************************/
bool DoublyLinkedList_Reset(DoublyLinkedList_t *const list)
{
  bool reset = false;

  if (list != NULL)
  {
    DoublyLinkedList_Node_t *node = list->Head;
    DoublyLinkedList_Node_t *nextNode;

    while (node != NULL)
    {
      nextNode = node->Next;
      free(node);
      node = nextNode;
    }

    list->Head = NULL;
    list->Tail = NULL;
    list->Length = 0L;

    reset = true;
  }

  return reset;
}

/**
 * @brief Get the index of an item in a doubly linked list.
 *
 * @param[in] list Pointer to the list to get the index of the item from
 * @param[in] item Pointer to the item to get the index of
 *
 * @return Index of the item in the list
 *
 * @retval DOUBLY_LINKED_LIST_INDEX_ERROR Failed to get the index of the item
 ******************************************************************************/
DoublyLinkedList_Index_t DoublyLinkedList_GetIndex(const DoublyLinkedList_t *const list, const void *const item)
{
  DoublyLinkedList_Index_t index = DOUBLY_LINKED_LIST_INDEX_ERROR;

  if (list != NULL && item != NULL)
  {
    const DoublyLinkedList_Node_t *node = list->Head;
    DoublyLinkedList_Index_t nodeIndex = 0L;

    while (index == DOUBLY_LINKED_LIST_INDEX_ERROR && node != NULL)
    {
      if (memcmp(node->Item, item, list->ItemSize) == 0L)
      {
        index = nodeIndex;
      }

      node = node->Next;
      nodeIndex++;
    }
  }

  return index;
}

/**
 * @brief Get the length of a doubly linked list.
 *
 * @param[in] list Pointer to the list to get the length of
 *
 * @return Length of the list
 *
 * @retval DOUBLY_LINKED_LIST_LENGTH_ERROR Failed to get the length of the
 *                                         list
 ******************************************************************************/
DoublyLinkedList_Length_t DoublyLinkedList_GetLength(const DoublyLinkedList_t *const list)
{
  DoublyLinkedList_Length_t length = DOUBLY_LINKED_LIST_LENGTH_ERROR;

  if (list != NULL)
  {
    length = list->Length;
  }

  return length;
}

/**
 * @brief Insert an item into a doubly linked list at an index.  Items are
 *        stored by copy, not reference.
 *
 * @param[in,out] list  Pointer to the list to insert the item into
 * @param[in]     index Index at which to insert the item, must be greater
 *                      than or equal to zero, and the item is inserted at
 *                      the end of the list if greater than last current
 *                      index
 * @param[in]     item  Pointer to the item to insert into the list
 *
 * @return Whether the item was successfully inserted into the list or not
 *
 * @retval true  Successfully inserted the item into the list
 * @retval false Failed to insert the item into the list
 ******************************************************************************/
bool DoublyLinkedList_Insert(DoublyLinkedList_t *const list, const DoublyLinkedList_Index_t index, const void *const item)
{
  bool inserted = false;

  if (list != NULL && item != NULL)
  {
    if (index == 0L)
    {
      inserted = DoublyLinkedList_AppendLeft(list, item);
    }
    else if (index > 0L && index < list->Length)
    {
      DoublyLinkedList_Node_t *newNode = (DoublyLinkedList_Node_t *)malloc(sizeof(DoublyLinkedList_Node_t) + list->ItemSize);
      DoublyLinkedList_Node_t *node = list->Head;
      DoublyLinkedList_Index_t nodeIndex = 0L;

      while (nodeIndex < index)
      {
        node = node->Next;
        nodeIndex++;
      }

      newNode->Previous = node->Previous;
      newNode->Next = node;
      newNode->Previous->Next = newNode;
      newNode->Next->Previous = newNode;
      newNode->Item = (uint8_t *)newNode + sizeof(DoublyLinkedList_Node_t);
      memcpy(newNode->Item, item, list->ItemSize);
      list->Length++;

      inserted = true;
    }
    else if (index >= list->Length)
    {
      inserted = DoublyLinkedList_Append(list, item);
    }
  }

  return inserted;
}

/**
 * @brief Remove an item from a doubly linked list at an index.
 *
 * @param[in,out] list  Pointer to the list to remove the item from
 * @param[in]     index Index at which to remove the item, must be within
 *                      the range of current indices
 * @param[in,out] item  Pointer to a buffer large enough to copy the item
 *                      into, NULL if the item does not need to be copied
 *
 * @return Whether the item was successfully removed from the list or not
 *
 * @retval true  Successfully removed the item from the list
 * @retval false Failed to remove the item from the list
 ******************************************************************************/
bool DoublyLinkedList_Remove(DoublyLinkedList_t *const list, const DoublyLinkedList_Index_t index, void *const item)
{
  bool removed = false;

  if (list != NULL && list->Head != NULL)
  {
    DoublyLinkedList_Index_t lastIndex = list->Length - 1L;

    if (index == 0L)
    {
      removed = DoublyLinkedList_PopLeft(list, item);
    }
    else if (index > 0L && index < lastIndex)
    {
      DoublyLinkedList_Node_t *node = list->Head;
      DoublyLinkedList_Index_t nodeIndex = 0L;

      while (nodeIndex < index)
      {
        node = node->Next;
        nodeIndex++;
      }

      if (item != NULL)
      {
        memcpy(item, node->Item, list->ItemSize);
      }

      node->Previous->Next = node->Next;
      node->Next->Previous = node->Previous;
      free(node);
      list->Length--;

      removed = true;
    }
    else if (index == lastIndex)
    {
      removed = DoublyLinkedList_Pop(list, item);
    }
  }

  return removed;
}

/**
 * @brief Get the item from at the head of a doubly linked list.
 *
 * @param[in]     list Pointer to the list to get the item from
 * @param[in,out] item Pointer to a buffer large enough to copy the item
 *                     into
 *
 * @return Whether getting the the item at the head of the list was successful
 *         or not
 *
 * @retval true  Successfully got at the item at the head of the list
 * @retval false Failed to get the item at the head of the list
 ******************************************************************************/
bool DoublyLinkedList_GetHead(const DoublyLinkedList_t *const list, void *const item)
{
  bool get = false;

  if (list != NULL && item != NULL && !DoublyLinkedList_IsEmpty(list))
  {
    memcpy(item, list->Head->Item, list->ItemSize);

    get = true;
  }

  return get;
}

/**
 * @brief Get the item from at the tail of a doubly linked list.
 *
 * @param[in]     list Pointer to the list to get the item from
 * @param[in,out] item Pointer to a buffer large enough to copy the item
 *                     into
 *
 * @return Whether getting the the item at the tail of the list was successful
 *         or not
 *
 * @retval true  Successfully got at the item at the tail of the list
 * @retval false Failed to get the item at the tail of the list
 ******************************************************************************/
bool DoublyLinkedList_GetTail(const DoublyLinkedList_t *const list, void *const item)
{
  bool get = false;

  if (list != NULL && item != NULL && !DoublyLinkedList_IsEmpty(list))
  {
    memcpy(item, list->Tail->Item, list->ItemSize);

    get = true;
  }

  return get;
}

/**
 * @brief Check if a doubly linked list is empty.
 *
 * @param[in] list Pointer to the list to check
 *
 * @return Whether the list is empty or not
 *
 * @retval true  List is empty
 * @retval false List is not empty
 ******************************************************************************/
bool DoublyLinkedList_IsEmpty(const DoublyLinkedList_t *const list)
{
  bool empty = true;

  if (list != NULL)
  {
    empty = (list->Head == NULL);
  }

  return empty;
}