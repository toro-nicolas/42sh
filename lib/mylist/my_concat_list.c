/*
** EPITECH PROJECT, 2023
** my_concat_list
** File description:
** Concatenates two linked lists
*/
/**
 * @file my_concat_list.c
 * @brief The file containing the my_concat_list function
 * @author Nicolas TORO
 */

#include "mylist.h"

void my_concat_list(node_t **begin1, node_t *begin2)
{
    node_t *tmp = *begin1;

    if (*begin1 == NULL) {
        *begin1 = begin2;
        return;
    }
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = begin2;
    begin2->prev = tmp;
}
