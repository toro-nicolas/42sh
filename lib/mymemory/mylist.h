/*
** EPITECH PROJECT, 2023
** Libmylist
** File description:
** The header file of the libmylist
*/
/**
 * @file mylist.h
 * @brief The header file of the libmylist
 * @author Nicolas TORO
 */

#include "my.h"

#ifndef MYLIST_H
    #define MYLIST_H

// TYPEDEFS :

/* Enum for the type of the data */
typedef enum type {
    SHORT_SHORT,
    SHORT,
    INT,
    LONG,
    LONG_LONG,
    UNSIGNED_SHORT,
    UNSIGNED_SHORT_SHORT,
    UNSIGNED_INT,
    UNSIGNED_LONG,
    UNSIGNED_LONG_LONG,
    SIZE_T,
    FLOAT,
    DOUBLE,
    CHAR,
    STRING,
    ARRAY_OF_STRING,
    VOID,
    UNKNOWN
} type_t;

/* Node of the linked list */
typedef struct node_s {
    struct node_s *prev; /* Pointer to the previous node */
    void *data; /* Pointer to the data */
    type_t type; /* Type of the data */
    struct node_s *next; /* Pointer to the next node */
} node_t;



// FUNCTIONS PROTOTYPES :

    // Add functions :

/**
 * @brief Adds a node at the beginning of the list
 * @param begin The beginning of the list
 * @param data The data to add
 * @param type The type of the data
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_push_front(node_t **begin, void *data, type_t type);

/**
 * @brief Adds a node at the end of the list
 * @param begin The beginning of the list
 * @param data The data to add
 * @param type The type of the data
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_push_back(node_t **begin, void *data, type_t type);

    // Remove functions :

/**
 * @brief Deletes nodes from a linked list
 * @param begin The beginning of the list
 * @param data_ref The data to delete
 * @param cmp The comparison function
 * @return <b>int</b> The number of nodes deleted from the list
 * @author Nicolas TORO
 */
int my_delete_nodes(node_t **begin, void const *data_ref, int (*cmp)());

/**
 * @brief Deletes the linked list
 * @param begin The beginning of the list
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_delete_list(node_t **begin);

/**
 * @brief Removes the first node of the list
 * @param begin The beginning of the list
 * @return <b>node_t *</b> The first node of the list
 * @author Nicolas TORO
 */
node_t *my_pop_front(node_t **begin);

/**
 * @brief Removes the last node of the list
 * @param begin The beginning of the list
 * @return <b>node_t *</b> The last node of the list
 * @author Nicolas TORO
 */
node_t *my_pop_back(node_t **begin);

/**
 * @brief Removes a node from the list
 * @param begin The beginning of the list
 * @param data_ref The data to remove
 * @param cmp The comparison function
 * @return <b>node_t *</b> The node removed from the list
 * @author Nicolas TORO
 */
node_t *my_pop_node(node_t **begin, void const *data_ref, int (*cmp)());

    // Circular list functions :

/**
* @brief Adds a node at the beginning of the circular linked list
* @param begin The beginning of the list
* @param data The data to add
* @param type The type of the data
* @return <b>void</b>
*/
void my_push_back_circled(node_t **begin, void *data, type_t type);

/**
 * @brief Adds a node at the end of the circular linked list
 * @param begin The beginning of the list
 * @param data The data to add
 * @param type The type of the data
 * @return <b>void</b>
 */
int my_list_size_circled(node_t const *begin);

/**
 * @brief Converts the circular linked list to an array
 * @param list The circular linked list to convert
 * @return <b>void **</b> The array created from the circular linked list
 */
void **my_list_to_array_circled(node_t **list);

/**
 * @brief Deletes a circular linked list
 * @param begin The beginning of the list
 * @return <b>void</b>
 */
void my_delete_circle_list(node_t **begin);

    // Other functions :

/**
 * @brief Displays the linked list
 * @param list The linked list to display
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_show_list(node_t *list);

/**
 * @brief Returns the size of the linked list
 * @param begin The beginning of the list
 * @return <b>int</b> The size of the list
 * @author Nicolas TORO
 */
int my_list_size(node_t const *begin);

/**
 * @brief Reverses the linked list
 * @param begin The beginning of the list
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_rev_list(node_t **begin);

/**
 * @brief Finds a node in the linked list
 * @param begin The beginning of the list
 * @param data The data to find
 * @param cmp The comparison function
 * @return <b>node_t *</b> The node found in the list
 * @author Nicolas TORO
 */
node_t *my_find_node(node_t const *begin, void const *data, int (*cmp)());

/**
 * @brief Concatenates two linked lists
 * @param begin1 The beginning of the first list
 * @param begin2 The beginning of the second list
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_concat_list(node_t **begin1, node_t *begin2);

/**
 * @brief Sorts the linked list
 * @param begin The beginning of the list
 * @param cmp The comparison function
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_sort_list(node_t **begin, int (*cmp)());

/**
 * @brief Merges two linked lists
 * @param begin1 The beginning of the first list
 * @param begin2 The beginning of the second list
 * @param cmp The comparison function
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_merge_list(node_t **begin1, node_t *begin2, int (*cmp)());

/**
 * @brief Converts the linked list to an array
 * @param list The linked list to convert
 * @return <b>void **</b> The array created from the linked list
 * @author Nicolas TORO
 */
void **my_list_to_array(node_t *list);

/**
 * @brief Creates a linked list from the arguments (argc and argv)
 * @param ac The number of arguments
 * @param av The array of arguments
 * @return <b>node_t *</b> The linked list created from the array of strings
 * @author Nicolas TORO
 */
node_t *my_params_to_list(int ac, char *const *av);

/**
 * @brief Skip a node in a linked list and
 * change the previous node to the next node
 * @param head The beginning of the list
 * @param to_delete The node to skip
 * @return <b>node_t *</b> The to_delete node
 */
node_t *my_previous_to_next(node_t **head, node_t *to_delete);

#endif
