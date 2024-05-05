/*
** EPITECH PROJECT, 2024
** my_malloc
** File description:
** Free allocated memory (type 0) or allocates memory (type 1)
** of a certain size (size)
*/
/**
 * @file my_malloc.c
 * @brief The file containing the my_malloc function
 * @author Nicolas TORO
 */

#include "mymemory.h"

void *my_malloc(size_t size, int type)
{
    static node_t *list = NULL;
    void *ptr;

    if (type == 1 && size > 0) {
        ptr = malloc(size);
        if (ptr == NULL)
            return NULL;
        my_push_front(&list, ptr, VOID);
        return ptr;
    }
    if (type == 0)
        my_delete_list(&list);
    return NULL;
}
