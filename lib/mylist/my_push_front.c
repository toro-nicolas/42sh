/*
** EPITECH PROJECT, 2023
** my_push_front
** File description:
** Adds a node at the beginning of a linked list
*/
/**
 * @file my_push_front.c
 * @brief The file containing the my_push_front function
 * @author Nicolas TORO
 */

#include "mylist.h"

void my_push_front(node_t **begin, void *data, type_t type)
{
    node_t *new = malloc(sizeof(node_t));

    new->prev = NULL;
    new->data = data;
    new->type = type;
    new->next = *begin;
    if (*begin != NULL)
        (*begin)->prev = new;
    *begin = new;
}
