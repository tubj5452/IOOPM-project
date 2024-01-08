#pragma once
#include <stdbool.h>
#include "common.h"

#define int_ll_append(list, value) linked_list_append(list, int_elem(value))
#define int_ll_prepend(list, value) linked_list_prepend(list, int_elem(value))
#define int_ll_insert(list, index, value) linked_list_insert(list, index, int_elem(value))

/**
 * @file linked_list.h
 * @author Tuva Björnberg & Gustav Fridén
 * @date 29/09-2023
 * @brief The program includes functions to create and destroy a linked list, perform various operations.
 *
 * The linked list is implemented using a singly linked structure (`link_t`) with a `list_t`
 * structure holding the first and last links, the size, and an equality function.
 *
 * The linked list assumes a suitable equality function to fit the eq_function in common.h
 *
 * It is also assumed that the user ensures proper memory management when using the
 * linked list, including freeing the memory allocated for elements.
 *
 * In certain edge-cases functions will return void pointer to NULL if either imput-value is invalid or
 * have reach a NULL element. Which functions with this behavior is mentioned below.
 */

typedef struct list list_t;
typedef struct iter list_iterator_t;

typedef bool(*int_predicate)(elem_t value, void *extra);
typedef void(*apply_int_function)(elem_t *value, void *extra);

typedef void obj;

/// @brief Creates a new empty list
/// @param fun function to store in the linked list object
/// @return an empty linked list
list_t *linked_list_create(eq_function fun);

/// @brief Tear down the linked list and return all its memory (but not the memory of the elements)
/// @param list the list to be destroyed
void linked_list_destroy(list_t *list);

/// @brief Insert at the end of a linked list in O(1) time
/// @param list the linked list that will be appended
/// @param value the value to be appended
void linked_list_append(list_t *list, elem_t value);

/// @brief Insert at the front of a linked list in O(1) time
/// @param list the linked list that will be prepended to
/// @param value the value to be prepended
void linked_list_prepend(list_t *list, elem_t value);

/// @brief Insert an element into a linked list in O(n) time.
/// The valid values of index are [0,n] for a list of n elements,
/// where 0 means before the first element and n means after
/// the last element.
/// @param list the linked list that will be extended
/// @param index the position in the list
/// @param value the value to be inserted
void linked_list_insert(list_t *list, int index, elem_t value);

/// @brief Remove an element from a linked list in O(n) time.
/// The valid values of index are [0,n-1] for a list of n elements,
/// where 0 means the first element and n-1 means the last element.
/// @param list the linked list
/// @param index the position in the list
/// @return the value removed
elem_t linked_list_remove(list_t *list, int index);

/// @brief Remove an element from a linked list when the specified
/// object has been found.
/// @param list the linked list
/// @param obj_ptr the object to be removed
void linked_list_remove_object(list_t *list, obj *obj_ptr);

/// @brief Retrieve an element from a linked list in O(n) time.
/// The valid values of index are [0,n-1] for a list of n elements,
/// where 0 means the first element and n-1 means the last element.
/// @param list the linked list that will be extended
/// @param index the position in the list
/// @return the value at the given position or a void pointer to NULL if invalid index
elem_t linked_list_get(list_t *list, int index);

/// @brief Test if an element is in the list
/// @param list the linked list
/// @param element the element sought
/// @return true if element is in the list, else false
bool linked_list_contains(list_t *list, elem_t element);

/// @brief Lookup the number of elements in the linked list in O(1) time
/// @param list the linked list
/// @return the number of elements in the list
size_t linked_list_size(list_t *list);

/// @brief Test whether a list is empty or not
/// @param list the linked list
/// @return true if the number of elements int the list is 0, else false
bool linked_list_is_empty(list_t *list);

/// @brief Remove all elements from a linked list
/// @param list the linked list
void linked_list_clear(list_t *list);

/// @brief Test if a supplied property holds for all elements in a list.
/// The function returns as soon as the return value can be determined.
/// @param list the linked list
/// @param prop the property to be tested (function pointer)
/// @param extra an additional argument (may be NULL) that will be passed to all internal calls of prop
/// @return true if prop holds for all elements in the list, else false
bool linked_list_all(list_t *list, int_predicate prop, void *extra);

/// @brief Test if a supplied property holds for any element in a list.
/// The function returns as soon as the return value can be determined.
/// @param list the linked list
/// @param prop the property to be tested
/// @param extra an additional argument (may be NULL) that will be passed to all internal calls of prop
/// @return true if prop holds for any elements in the list, else false
bool linked_list_any(list_t *list, int_predicate prop, void *extra);

/// @brief Apply a supplied function to all elements in a list.
/// @param list the linked list
/// @param fun the function to be applied
/// @param extra an additional argument (may be NULL) that will be passed to all internal calls of fun
void linked_list_apply_to_all(list_t *list, apply_int_function fun, void *extra);