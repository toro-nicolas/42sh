/*
** EPITECH PROJECT, 2023
** my_str_isprintable
** File description:
** Returns 1 if the string (str) contains only printable characters
*/
/**
 * @file my_str_isprintable.c
 * @brief The file containing the my_str_isprintable function
 * @author Nicolas TORO
 */

#include "my.h"

int my_str_isprintable(char const *str)
{
    if (my_strlen(str) == 0)
        return 1;
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] < 32 || str[i] == 127)
            return 0;
    }
    return 1;
}
