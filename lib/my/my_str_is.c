/*
** EPITECH PROJECT, 2024
** my_str_is
** File description:
** Returns 1 if the string (str) is composed of characters
** in the characters list (char_list) or 0 if not
*/
/**
 * @file my_str_is.c
 * @brief The file containing the my_str_is function
 * @author Nicolas TORO
 */

#include "my.h"

int my_str_is(char *str, const char *char_list)
{
    for (int i = 0; str[i]; i++)
        if (!my_char_is(str[i], char_list))
            return 0;
    return 1;
}
