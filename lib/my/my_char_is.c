/*
** EPITECH PROJECT, 2024
** my_char_is
** File description:
** Returns 1 if the characters (c) is in the characters list (char_list)
** or 0 if not
*/
/**
 * @file my_char_is.c
 * @brief The file containing the my_char_is function
 * @author Nicolas TORO
 */

#include "my.h"

int my_char_is(char c, const char *char_list)
{
    for (int i = 0; char_list[i]; i++)
        if (c == char_list[i])
            return 1;
    return 0;
}
