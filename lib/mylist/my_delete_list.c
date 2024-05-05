/*
** EPITECH PROJECT, 2023
** delete_list
** File description:
** Deletes a linked list
*/
/**
 * @file my_delete_list.c
 * @brief The file containing the my_delete_list function
 * @author Nicolas TORO
 */

#include "mylist.h"

void my_delete_list(node_t **begin)
{
    node_t *tmp = *begin;
    node_t *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        if (tmp->data && tmp->data != NULL && tmp->type != UNKNOWN)
            FREE(tmp->data);
        if (tmp)
            FREE(tmp);
        tmp = next;
    }
    *begin = NULL;
}
