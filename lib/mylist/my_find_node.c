/*
** EPITECH PROJECT, 2023
** my_find_node
** File description:
** Finds a node in a linked list and return it
*/
/**
 * @file my_find_node.c
 * @brief The file containing the my_find_node function
 * @author Nicolas TORO
 */

#include "mylist.h"

node_t *my_find_node(node_t const *begin, void const *data_ref, int (*cmp) ())
{
    for (node_t *tmp = (node_t *)begin; tmp != NULL; tmp =
        tmp->next) {
        if ((cmp == NULL && tmp->data == data_ref)
        || (cmp != NULL && cmp(tmp->data, data_ref) == 0))
            return tmp;
    }
    return NULL;
}
