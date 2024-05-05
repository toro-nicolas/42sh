/*
** EPITECH PROJECT, 2024
** my_delete_circle_list
** File description:
** Deletes a circular linked list
*/
/**
 * @file my_delete_circle_list.c
 * @brief The file containing the my_delete_circle_list function
 * @author Nicolas TORO
 */

#include "mylist.h"

/**
 * @brief Deletes a circular linked list
 * @param begin The beginning of the list
 * @return void
 */
void my_delete_circle_list(node_t **begin)
{
    node_t *backup = *begin;
    node_t *tmp = NULL;
    node_t *next = NULL;

    if (backup != NULL)
        tmp = backup->next;
    while (tmp != backup && tmp != NULL) {
        next = tmp->next;
        if (tmp->data != NULL && tmp->type != UNKNOWN)
            FREE(tmp->data);
        FREE(tmp);
        tmp = next;
    }
    if (backup != NULL) {
        if (backup->data != NULL && backup->type != UNKNOWN)
            FREE(backup->data);
        FREE(backup);
    }
    *begin = NULL;
}
