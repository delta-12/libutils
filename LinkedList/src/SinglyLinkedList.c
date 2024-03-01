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

/* TODO comment blocks */

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

bool SinglyLinkedList_Free(SinglyLinkedList_t *const list)
{
    return SinglyLinkedList_Reset(list);
}

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

/* TODO return -1 if error or not found */
SinglyLinkedList_Index_t SinglyLinkedList_GetIndex(const SinglyLinkedList_t *const list, const void *const item) { return 0L; }

SinglyLinkedList_Length_t SinglyLinkedList_GetLength(const SinglyLinkedList_t *const list)
{
    SinglyLinkedList_Length_t length = -1L;

    if (list != NULL)
    {
        length = list->Length;
    }

    return length;
}

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
            newNode->Next = node->Next;
            newNode->Item = (uint8_t *)newNode + sizeof(SinglyLinkedList_Node_t);
            memcpy(newNode->Item, item, list->ItemSize);

            inserted = true;
        }
        else if (index > list->Length)
        {
            inserted = SinglyLinkedList_Append(list, item);
        }
    }

    return inserted;
}

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