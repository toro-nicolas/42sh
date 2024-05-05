/*
** EPITECH PROJECT, 2024
** my_strndup
** File description:
** Returns a duplication of a string (src) with a defined size (n)
*/
/**
 * @file my_strndup.c
 * @brief The file containing the my_strndup function
 * @author Nicolas TORO
 */

#include "my.h"

char *my_strndup(char const *src, int n)
{
    char *dest = malloc(sizeof(char) * (n + 1));
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
