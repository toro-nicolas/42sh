/*
** EPITECH PROJECT, 2023
** my_delete_nodes
** File description:
** Deletes nodes from a linked list
*/
/**
 * @file my_delete_nodes.c
 * @brief The file containing the my_delete_nodes function
 * @author Nicolas TORO
 */

#include "mylist.h"

static void remove_node(node_t **begin, node_t *tmp)
{
    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;
    else
        *begin = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;
    if (tmp->type != UNKNOWN)
        FREE(tmp->data);
    FREE(tmp);
}

int my_delete_nodes(node_t **begin, void const *data_ref, int (*cmp)())
{
    node_t *tmp = *begin;
    node_t *next = NULL;
    int nodes_deleted = 0;

    while (tmp != NULL) {
        next = tmp->next;
        if ((cmp == NULL && tmp->data == data_ref)
        || (cmp != NULL && cmp(tmp->data, data_ref) == 0)) {
            remove_node(begin, tmp);
            nodes_deleted++;
        }
        tmp = next;
    }
    return nodes_deleted;
}
