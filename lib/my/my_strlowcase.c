/*
** EPITECH PROJECT, 2023
** my_strlowcase
** File description:
** Replaces upcase by lowcase of a string (str) and returns them
*/
/**
 * @file my_strlowcase.c
 * @brief The file containing the my_strlowcase function
 * @author Nicolas TORO
 */

#include "my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] = str[i] + 32;
        }
    }
    return str;
}
