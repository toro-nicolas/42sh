/*
** EPITECH PROJECT, 2024
** my_realloc.c
** File description:
** Free allocated memory (type 0) or reallocates memory (type 1)
** of a certain size (element_count * element_size) and initializes it to zero
*/
/**
 * @file my_realloc.c
 * @brief The file containing the my_realloc function
 * @author Nicolas TORO
 */

#include "mymemory.h"

void *my_realloc(void *pointer, size_t size, int type)
{
    static node_t *list = NULL;
    void *ptr;

    if (type == 1 && size > 0) {
        ptr = malloc(size);
        if (ptr == NULL)
            return NULL;
        my_memcpy(ptr, pointer, size);
        my_push_front(&list, ptr, VOID);
        return ptr;
    }
    if (type == 0)
        my_delete_list(&list);
    return NULL;
}
