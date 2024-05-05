/*
** EPITECH PROJECT, 2023
** my_push_back_circled
** File description:
** Adds a node at the end of a linked list
*/
/**
 * @file my_push_back_circled.c
 * @brief The file containing the my_push_back_circled function
 * @author Gianni TUERO
 */

#include "mylist.h"

void my_push_back_circled(node_t **begin, void *data, type_t type)
{
    node_t *new = malloc(sizeof(node_t));
    node_t *tmp = *begin;

    new->data = data;
    new->type = type;
    if (*begin == NULL) {
        new->prev = NULL;
        new->next = NULL;
        *begin = new;
        return;
    }
    for (; tmp->next != NULL && tmp->next != *begin; tmp = tmp->next);
    tmp->next = new;
    new->prev = tmp;
    new->next = *begin;
    (*begin)->prev = new;
}
