/*
** EPITECH PROJECT, 2023
** my_showmem
** File description:
** Prints a memory dump of a string (str) with a defined size
*/
/**
 * @file my_showmem.c
 * @brief The file containing the my_showmem function
 * @author Nicolas TORO
 */

#include "my.h"

static void print_address(int line)
{
    int len = 1 + line / 16;

    for (int i = 0; i < 8 - len - 1; i++)
        my_putchar('0');
    my_putnbr_base(line, "0123456789abcedf");
    my_putstr("0: ");
}

static void check_zero_in_hexadecimal(char c)
{
    if (c < 16)
        my_putchar('0');
}

static void check_space(int space)
{
    if (space != 2)
        my_putstr("  ");
}

static void check_backslash(char c, int space)
{
    if (c == '\b' && space == 0)
        my_putstr("08");
    else if (c == '\b' && space == 2)
        my_putchar('.');
    else
        check_space(space);
}

static void print_hexadecimal_content(char const *str, int size, int line)
{
    int end_of_line = 0;

    for (int i = 16 * line; i < 16 * (line + 1); i++) {
        if (i != 16 * line && i % 2 == 0)
            my_putchar(' ');
        if (i == size || str[i] == '\b' || end_of_line == 1) {
            check_backslash(str[i], end_of_line);
            end_of_line = 1;
        } else {
            check_zero_in_hexadecimal(str[i]);
            my_putnbr_base(str[i], "0123456789abcdef");
        }
    }
    my_putchar(' ');
}

static void print_string_content(char const *str, int size,
    int line, int *error)
{
    for (int i = 16 * line; i < 16 * (line + 1); i++) {
        if (i == size || str[i] == '\b') {
            check_backslash(str[i], 2);
            *error = 1;
            break;
        }
        if (str[i] >= 32 && str[i] <= 126)
            my_putchar(str[i]);
        else
            my_putchar('.');
    }
}

void my_showmem(char const *str, int size)
{
    int number_of_lines = size / 16;
    int error = 0;

    for (int line = 0; line <= number_of_lines && error == 0; line++) {
        print_address(line);
        print_hexadecimal_content(str, size, line);
        print_string_content(str, size, line, &error);
        my_putchar('\n');
    }
}
