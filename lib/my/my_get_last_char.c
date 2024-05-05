/*
** EPITECH PROJECT, 2024
** my_get_last_char
** File description:
** The file containing the my_get_last_char function
*/
/**
 * @file my_get_last_char.c
 * @brief The file containing the my_get_last_char function
 * @author Nicolas TORO
 */

#include "my.h"

char my_get_last_char(char *str)
{
    int index = 0;

    if (str == NULL || str[0] == '\0')
        return '\0';
    for (; str[index] != '\0'; index++);
    return str[index - 1];
}
