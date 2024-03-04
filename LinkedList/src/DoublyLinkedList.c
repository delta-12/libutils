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
bool DoublyLinkedList_Init(DoublyLinkedList_t *const list, const size_t itemSize) { return false; }

/**
 * @brief Free a doubly linked list.
 *
 * @param[in,out] list Pointer to the list to free
 *
 * @note This function merely calls SinglyLinkedList_Reset.  See the
 *       documentation for SinglyLinkedList_Reset for more information.
 ******************************************************************************/
bool DoublyLinkedList_Free(DoublyLinkedList_t *const list) { return false; }

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
bool DoublyLinkedList_Append(DoublyLinkedList_t *const list, const void *const item) { return false; }

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
bool DoublyLinkedList_AppendLeft(DoublyLinkedList_t *const list, const void *const item) { return false; }

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
bool DoublyLinkedList_Pop(DoublyLinkedList_t *const list, void *const item) { return false; }

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
bool DoublyLinkedList_PopLeft(DoublyLinkedList_t *const list, void *const item) { return false; }

/**
 * @brief Reset a doubly linked list to its initial state and free all nodes.
 *
 * @param[in,out] list Pointer to the list to reset
 ******************************************************************************/
bool DoublyLinkedList_Reset(DoublyLinkedList_t *const list) { return false; }

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
DoublyLinkedList_Index_t DoublyLinkedList_GetIndex(const DoublyLinkedList_t *const list, const void *const item) { return DOUBLY_LINKED_LIST_INDEX_ERROR; }

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
DoublyLinkedList_Length_t DoublyLinkedList_GetLength(const DoublyLinkedList_t *const list) { return DOUBLY_LINKED_LIST_LENGTH_ERROR; }

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
bool DoublyLinkedList_Insert(DoublyLinkedList_t *const list, const DoublyLinkedList_Index_t index, const void *const item) { return false; }

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
bool DoublyLinkedList_Remove(DoublyLinkedList_t *const list, const DoublyLinkedList_Index_t index, void *const item) { return false; }