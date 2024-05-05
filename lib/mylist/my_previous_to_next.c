/*
** EPITECH PROJECT, 2023
** my_previous_to_next
** File description:
** The file containing the my_previous_to_next function
*/
/**
 * @file my_previous_to_next.c
 * @brief The file containing the my_previous_to_next function
 * @author Gianni TUERO
 */

#include "mylist.h"

node_t *my_previous_to_next(node_t **head, node_t *to_delete)
{
    if (*head == NULL || to_delete == NULL)
        return NULL;
    if (*head == to_delete) {
        if (to_delete->next != NULL) {
            (*head) = to_delete->next;
        } else
            (*head) = NULL;
        if (*head != NULL)
            (*head)->prev = NULL;
        return to_delete;
    }
    if (to_delete->prev != NULL)
        to_delete->prev->next = to_delete->next;
    if (to_delete->next != NULL)
        to_delete->next->prev = to_delete->prev;
    return to_delete;
}
