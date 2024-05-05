/*
** EPITECH PROJECT, 2024
** template
** File description:
** The my_pop_back.c
*/
/**
 * @file my_pop_back.c
 * @brief The file containing the my_pop_back function
 * @author Nicolas TORO
 */

#include "mylist.h"

node_t *my_pop_back(node_t **begin)
{
    node_t *tmp = *begin;

    if (*begin == NULL)
        return NULL;
    for (; tmp->next != NULL; tmp = tmp->next);
    if (tmp->prev != NULL)
        tmp->prev->next = NULL;
    else
        *begin = NULL;
    return tmp;
}
