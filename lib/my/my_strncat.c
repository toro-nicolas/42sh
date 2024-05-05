/*
** EPITECH PROJECT, 2023
** my_strncat
** File description:
** Concatenates a string (dest) with another string (src)
** with a defined size (n) and returns the destination string (dest)
*/
/**
 * @file my_strncat.c
 * @brief The file containing the my_strncat function
 * @author Nicolas TORO
 */

#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int len_dest = my_strlen(dest);
    int i = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    for (i = 0; i < n; i++)
        dest[len_dest + i] = src[i];
    dest[len_dest + i] = '\0';
    return dest;
}
