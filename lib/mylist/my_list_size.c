/*
** EPITECH PROJECT, 2023
** my_list_size
** File description:
** Returns the size of a linked list
*/
/**
 * @file my_list_size.c
 * @brief The file containing the my_list_size function
 * @author Nicolas TORO
 */

#include "mylist.h"

int my_list_size(node_t const *begin)
{
    int nb = 0;

    for (; begin != NULL; nb++)
        begin = begin->next;
    return nb;
}
