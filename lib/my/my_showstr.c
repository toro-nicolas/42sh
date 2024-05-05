/*
** EPITECH PROJECT, 2023
** my_showstr
** File description:
** Prints a string (str) but replaces
** non-printable characters with their hexadecimal number
*/
/**
 * @file my_showstr.c
 * @brief The file containing the my_showstr function
 * @author Nicolas TORO
 */

#include "my.h"

static void check_zero_in_hexadecimal(char c)
{
    if (c < 16)
        my_putchar('0');
}

void my_showstr(char const *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (my_char_is_printable(str[i]) == 1) {
            my_putchar(str[i]);
        } else {
            my_putchar('\\');
            check_zero_in_hexadecimal(str[i]);
            my_putnbr_base(str[i], "0123456789abcedf");
        }
    }
}
