/**
 * @file SinglyLinkedList.c
 *
 * @brief Singly linked list.
 *
 ******************************************************************************/

/* Includes
 ******************************************************************************/

#include "SinglyLinkedList.h"
#include <string.h>

/* Function Definitions
 ******************************************************************************/

/**
 * @brief Initialize a singly linked list.
 *
 * @param[in,out] list     Pointer to the list to initialize
 * @param[in]     itemSize Size in bytes of the items held in the list
 *
 * @return Whether the list was successfully initialized or not
 *
 * @retval true  Successfully initialized
 * @retval false Failed to initialize
 ******************************************************************************/
bool SinglyLinkedList_Init(SinglyLinkedList_t *const list, const size_t itemSize)
{
    bool init = false;

    if (list != NULL)
    {
        list->Head = NULL;
        list->Length = 0L;
        list->ItemSize = itemSize;

        init = true;
    }

    return init;
}

/**
 * @brief Free a singly linked list.
 *
 * @param[in,out] list Pointer to the list to free
 *
 * @note This function merely calls SinglyLinkedList_Reset.  See the
 *       documentation for SinglyLinkedList_Reset for more information.
 ******************************************************************************/
bool SinglyLinkedList_Free(SinglyLinkedList_t *const list)
{
    return SinglyLinkedList_Reset(list);
}

/**
 * @brief Append an item to the end of a singly linked list.  Items are stored
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
bool SinglyLinkedList_Append(SinglyLinkedList_t *const list, const void *const item)
{
    bool appended = false;

    if (list != NULL && item != NULL)
    {
        SinglyLinkedList_Node_t *newNode = (SinglyLinkedList_Node_t *)malloc(sizeof(SinglyLinkedList_Node_t) + list->ItemSize);

        newNode->Next = NULL;
        newNode->Item = (uint8_t *)newNode + sizeof(SinglyLinkedList_Node_t);
        memcpy(newNode->Item, item, list->ItemSize);

        if (list->Head == NULL)
        {
            list->Head = newNode;
        }
        else
        {
            SinglyLinkedList_Node_t *node = list->Head;

            while (node->Next != NULL)
            {
                node = node->Next;
            }

            node->Next = newNode;
        }

        list->Length++;

        appended = true;
    }

    return appended;
}

/**
 * @brief Add an item to the beginning of a singly linked list.  Items are
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
bool SinglyLinkedList_AppendLeft(SinglyLinkedList_t *const list, const void *const item)
{
    bool appended = false;

    if (list != NULL && item != NULL)
    {
        SinglyLinkedList_Node_t *newNode = (SinglyLinkedList_Node_t *)malloc(sizeof(SinglyLinkedList_Node_t) + list->ItemSize);

        newNode->Next = list->Head;
        newNode->Item = (uint8_t *)newNode + sizeof(SinglyLinkedList_Node_t);
        memcpy(newNode->Item, item, list->ItemSize);
        list->Head = newNode;
        list->Length++;

        appended = true;
    }

    return appended;
}

/**
 * @brief Pop an item from the end of a singly linked list.
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
bool SinglyLinkedList_Pop(SinglyLinkedList_t *const list, void *const item)
{
    bool popped = false;

    if (list != NULL && list->Head != NULL)
    {

        SinglyLinkedList_Node_t *node = list->Head;
        SinglyLinkedList_Node_t *previousNode = list->Head;

        while (node->Next != NULL)
        {
            previousNode = node;
            node = node->Next;
        }

        if (node == list->Head)
        {
            list->Head = NULL;
        }
        else
        {
            previousNode->Next = NULL;
        }

        if (item != NULL)
        {
            memcpy(item, node->Item, list->ItemSize);
        }

        free(node);
        list->Length--;

        popped = true;
    }

    return popped;
}

/**
 * @brief Pop an item from the beginning of a singly linked list.
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
bool SinglyLinkedList_PopLeft(SinglyLinkedList_t *const list, void *const item)
{
    bool popped = false;

    if (list != NULL && list->Head != NULL)
    {

        SinglyLinkedList_Node_t *head = list->Head;

        if (item != NULL)
        {
            memcpy(item, head->Item, list->ItemSize);
        }

        list->Head = head->Next;
        free(head);
        list->Length--;

        popped = true;
    }

    return popped;
}

/**
 * @brief Reset a singly linked list to its initial state and free all nodes.
 *
 * @param[in,out] list Pointer to the list to reset
 ******************************************************************************/
bool SinglyLinkedList_Reset(SinglyLinkedList_t *const list)
{
    bool reset = false;

    if (list != NULL)
    {
        SinglyLinkedList_Node_t *node = list->Head;
        SinglyLinkedList_Node_t *nextNode;

        while (node != NULL)
        {
            nextNode = node->Next;
            free(node);
            node = nextNode;
        }

        list->Head = NULL;
        list->Length = 0L;

        reset = true;
    }

    return reset;
}

/**
 * @brief Get the index of an item in a singly linked list.
 *
 * @param[in] list Pointer to the list to get the index of the item from
 * @param[in] item Pointer to the item to get the index of
 *
 * @return Index of the item in the list
 *
 * @retval SINGLY_LINKED_LIST_INDEX_ERROR Failed to get the index of the item
 ******************************************************************************/
SinglyLinkedList_Index_t SinglyLinkedList_GetIndex(const SinglyLinkedList_t *const list, const void *const item)
{
    SinglyLinkedList_Index_t index = SINGLY_LINKED_LIST_INDEX_ERROR;

    if (list != NULL && item != NULL)
    {
        const SinglyLinkedList_Node_t *node = list->Head;
        SinglyLinkedList_Index_t nodeIndex = 0L;

        while (index == SINGLY_LINKED_LIST_INDEX_ERROR && node != NULL)
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
 * @brief Get the length of a singly linked list.
 *
 * @param[in] list Pointer to the list to get the length of
 *
 * @return Length of the list
 *
 * @retval SINGLY_LINKED_LIST_LENGTH_ERROR Failed to get the length of the
 *                                         list
 ******************************************************************************/
SinglyLinkedList_Length_t SinglyLinkedList_GetLength(const SinglyLinkedList_t *const list)
{
    SinglyLinkedList_Length_t length = SINGLY_LINKED_LIST_LENGTH_ERROR;

    if (list != NULL)
    {
        length = list->Length;
    }

    return length;
}

/**
 * @brief Insert an item into a singly linked list at an index.  Items are
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
bool SinglyLinkedList_Insert(SinglyLinkedList_t *const list, const SinglyLinkedList_Index_t index, const void *const item)
{
    bool inserted = false;

    if (list != NULL && item != NULL)
    {
        if (index == 0L)
        {
            inserted = SinglyLinkedList_AppendLeft(list, item);
        }
        else if (index > 0L && index < list->Length)
        {
            SinglyLinkedList_Node_t *newNode = (SinglyLinkedList_Node_t *)malloc(sizeof(SinglyLinkedList_Node_t) + list->ItemSize);
            SinglyLinkedList_Node_t *node = list->Head;
            SinglyLinkedList_Node_t *previousNode = list->Head;
            SinglyLinkedList_Index_t nodeIndex = 0L;

            while (nodeIndex < index)
            {
                previousNode = node;
                node = node->Next;
                nodeIndex++;
            }

            previousNode->Next = newNode;
            newNode->Next = node;
            newNode->Item = (uint8_t *)newNode + sizeof(SinglyLinkedList_Node_t);
            memcpy(newNode->Item, item, list->ItemSize);
            list->Length++;

            inserted = true;
        }
        else if (index >= list->Length)
        {
            inserted = SinglyLinkedList_Append(list, item);
        }
    }

    return inserted;
}

/**
 * @brief Remove an item from a singly linked list at an index.
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
bool SinglyLinkedList_Remove(SinglyLinkedList_t *const list, const SinglyLinkedList_Index_t index, void *const item)
{
    bool removed = false;

    if (list != NULL && list->Head != NULL)
    {
        if (index >= 0L && index < list->Length)
        {
            SinglyLinkedList_Node_t *node = list->Head;
            SinglyLinkedList_Node_t *previousNode = list->Head;
            SinglyLinkedList_Index_t nodeIndex = 0L;

            while (nodeIndex < index)
            {
                previousNode = node;
                node = node->Next;
                nodeIndex++;
            }

            if (node == list->Head)
            {
                list->Head = node->Next;
            }
            else
            {
                previousNode->Next = node->Next;
            }

            if (item != NULL)
            {
                memcpy(item, node->Item, list->ItemSize);
            }

            free(node);
            list->Length--;

            removed = true;
        }
    }

    return removed;
}