/*
** EPITECH PROJECT, 2023
** my_rev_list
** File description:
** Reverses a linked list
*/
/**
 * @file my_rev_list.c
 * @brief The file containing the my_rev_list function
 * @author Nicolas TORO
 */

#include "mylist.h"

void my_rev_list(node_t **begin)
{
    node_t *previous_list = NULL;
    node_t *current_list = *begin;
    node_t *next_list = NULL;

    while (current_list != NULL) {
        next_list = current_list->next;
        current_list->next = previous_list;
        current_list->prev = next_list;
        previous_list = current_list;
        current_list = next_list;
    }
    *begin = previous_list;
}
