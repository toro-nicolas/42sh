/*
** EPITECH PROJECT, 2023
** my_push_back
** File description:
** Adds a node at the end of a linked list
*/
/**
 * @file my_push_back.c
 * @brief The file containing the my_push_back function
 * @author Nicolas TORO
 */

#include "mylist.h"

void my_push_back(node_t **begin, void *data, type_t type)
{
    node_t *new = malloc(sizeof(node_t));
    node_t *tmp = *begin;

    new->data = data;
    new->type = type;
    new->next = NULL;
    if (*begin == NULL) {
        new->prev = NULL;
        *begin = new;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    new->prev = tmp;
}
