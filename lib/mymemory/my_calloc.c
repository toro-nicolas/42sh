/*
** EPITECH PROJECT, 2024
** my_calloc
** File description:
** Free allocated memory (type 0) or allocates memory (type 1)
** of a certain size (element_count * element_size) and initializes it to zero
*/
/**
 * @file my_calloc.c
 * @brief The file containing the my_calloc function
 * @author Nicolas TORO
 */

#include "mymemory.h"

void *my_calloc(size_t element_count, size_t element_size, int type)
{
    static node_t *list = NULL;
    void *ptr;

    if (type == 1 && element_count > 0 && element_size > 0) {
        ptr = malloc(element_count * element_size);
        if (ptr == NULL)
            return NULL;
        my_push_front(&list, ptr, VOID);
        my_memset(ptr, 0, element_count * element_size);
        return ptr;
    }
    if (type == 0)
        my_delete_list(&list);
    return NULL;
}
