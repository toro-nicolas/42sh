/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Flag to print a %S (an array of string)
*/
/**
 * @file flag_bigs.c
 * @brief The file containing the flag_bigs function
 * @author Nicolas TORO
 */

#include "myprintf.h"

int flag_bigs(va_list list, formating_t *formating)
{
    char **temp = va_arg(list, char **);
    int len = 0;

    for (int index = 0; temp[index] != NULL; index++) {
        len = len + my_putstr_fd(temp[index], 1);
        my_putchar('\n');
        len = len + 1;
    }
    return len;
}
