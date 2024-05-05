/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** Copy a string (src) and paste it on another string (dest)
*/
/**
 * @file my_strcpy.c
 * @brief The file containing the my_strcpy function
 * @author Nicolas TORO
 */

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return dest;
}
