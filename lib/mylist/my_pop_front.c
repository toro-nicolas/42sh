/*
** EPITECH PROJECT, 2024
** template
** File description:
** The my_pop_front.c
*/
/**
 * @file my_pop_front.c
 * @brief The file containing the my_pop_front function
 * @author Nicolas TORO
 */

#include "mylist.h"

node_t *my_pop_front(node_t **begin)
{
    node_t *tmp = *begin;

    if (*begin == NULL)
        return NULL;
    *begin = (*begin)->next;
    if (*begin != NULL)
        (*begin)->prev = NULL;
    return tmp;
}
