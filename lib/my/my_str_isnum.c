/*
** EPITECH PROJECT, 2023
** my_str_isnum
** File description:
** Returns 1 if the string (str) contains only numerical characters
*/
/**
 * @file my_str_isnum.c
 * @brief The file containing the my_str_isnum function
 * @author Nicolas TORO
 */

#include "my.h"

int my_str_isnum(char const *str)
{
    if (my_strlen(str) == 0)
        return 1;
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}
