/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** Returns the length of a string (str)
*/
/**
 * @file my_strlen.c
 * @brief The file containing the my_strlen function
 * @author Nicolas TORO
 */

#include "my.h"

int my_strlen(char const *str)
{
    int len = 0;

    if (str == NULL)
        return 0;
    while (str[len] != '\0')
        len = len + 1;
    return len;
}
