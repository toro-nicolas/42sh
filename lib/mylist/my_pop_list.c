/*
** EPITECH PROJECT, 2024
** my_pop_list
** File description:
** Return the last node of a linked list and remove it from the list
*/

#include "mylist.h"

linked_list_t *my_pop_list(linked_list_t **begin)
{
    linked_list_t *tmp = *begin;

    if (*begin == NULL)
        return NULL;
    for (; tmp->next != NULL; tmp = tmp->next);
    if (tmp->prev != NULL)
        tmp->prev->next = NULL;
    else
        *begin = NULL;
    return tmp;
}
