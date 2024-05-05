/*
** EPITECH PROJECT, 2024
** my_free
** File description:
** Free all the memory allocated by
** the my_malloc, my_calloc and my_realloc functions
*/
/**
 * @file my_free.c
 * @brief The file containing the my_free function
 * @author Nicolas TORO
 */

#include "mymemory.h"

void my_free(void)
{
    my_malloc(0, 0);
    my_calloc(0, 0, 0);
    my_realloc(NULL, 0, 0);
}
