/*
** EPITECH PROJECT, 2023
** my_list_size_circled
** File description:
** Returns the size of a circular linked list
*/
/**
 * @file my_list_size_circled.c
 * @brief The file containing the my_list_siz_circled function
 * @author Gianni TUERO
 */

#include "mylist.h"

int my_list_size_circled(node_t const *begin)
{
    int nb = 0;

    for (node_t const *tmp = begin; tmp != NULL; tmp = tmp->next) {
        nb++;
        if (tmp->next == begin)
            break;
    }
    return nb;
}
