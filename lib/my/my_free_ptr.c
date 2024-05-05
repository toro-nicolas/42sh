/*
** EPITECH PROJECT, 2024
** my_free_ptr
** File description:
** Free a pointer (ptr) and set it to NULL
*/
/**
 * @file my_free_ptr.c
 * @brief The file containing the my_free_ptr function
 * @author Nicolas TORO
 */

#include "my.h"

void *my_free_ptr(void *ptr)
{
    if (ptr == NULL || !ptr)
        return NULL;
    free(ptr);
    ptr = NULL;
    return NULL;
}
