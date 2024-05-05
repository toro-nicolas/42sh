/*
** EPITECH PROJECT, 2023
** my_char_isprintable
** File description:
** Returns 1 if the characters (c) is printable or 0 if not
*/
/**
 * @file my_char_is_printable.c
 * @brief The file containing the my_char_is_printable function
 * @author Nicolas TORO
 */

#include "my.h"

int my_char_is_printable(char const c)
{
    if (c < 32 || c > 126)
            return 0;
    return 1;
}
