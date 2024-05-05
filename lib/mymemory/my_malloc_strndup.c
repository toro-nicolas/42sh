/*
** EPITECH PROJECT, 2023
** my_malloc_strndup
** File description:
** Returns a duplication of a string (src) with a defined size (n)
** with my_malloc
*/
/**
 * @file my_malloc_strndup.c
 * @brief The file containing the my_malloc_strndup function
 * @author Nicolas TORO
 */

#include "mymemory.h"

char *my_malloc_strndup(char const *src, int n)
{
    char *dest = my_malloc(sizeof(char) * (n + 1), 1);
    int i = 0;

    if (src == NULL)
        return NULL;
    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
