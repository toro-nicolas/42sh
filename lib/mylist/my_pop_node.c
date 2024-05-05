/*
** EPITECH PROJECT, 2024
** my_pop_list
** File description:
** Return the last node of a linked list and remove it from the list
*/
/**
 * @file my_pop_node.c
 * @brief The file containing the my_pop_node function
 * @author Nicolas TORO
 */

#include "mylist.h"

static void change_list(node_t **begin, node_t *tmp)
{
    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;
    else
        *begin = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;
}

node_t *my_pop_node(node_t **begin, void const *data_ref, int (*cmp)())
{
    node_t *tmp = *begin;
    node_t *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        if ((cmp == NULL && tmp->data == data_ref)
        || (cmp != NULL && cmp(tmp->data, data_ref) == 0)) {
            change_list(begin, tmp);
            return tmp;
        }
        tmp = next;
    }
    return NULL;
}
