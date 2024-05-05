/*
** EPITECH PROJECT, 2024
** my_list_to_array
** File description:
** Returns an array from a linked list
*/
/**
 * @file my_list_to_array.c
 * @brief The file containing the my_list_to_array function
 * @author Nicolas TORO
 */

#include "mylist.h"

void **my_list_to_array(node_t *list)
{
    int size = my_list_size(list);
    void **array = malloc(sizeof(void *) * (size + 1));
    node_t *tmp = list;

    if (array == NULL)
        return NULL;
    for (int i = 0; tmp != NULL; i++) {
        array[i] = tmp->data;
        tmp = tmp->next;
    }
    array[size] = NULL;
    return array;
}
