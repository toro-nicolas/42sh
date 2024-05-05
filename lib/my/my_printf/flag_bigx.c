/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Flag to print a %X (an int in hexadecimal)
*/
/**
 * @file flag_bigx.c
 * @brief The file containing the flag_bigx function
 * @author Nicolas TORO
 */

#include "myprintf.h"

int flag_bigx(va_list list, formating_t *formating)
{
    size_t temp = va_arg(list, size_t);
    char *convert_base = specify_it_base(formating,
        temp, "0123456789ABCDEF");

    precise_it_int(convert_base, formating, temp);
    if (formating->id_ft == 3) {
        my_revstr(convert_base);
        my_strcat(convert_base, "X0");
        my_revstr(convert_base);
    }
    format_it_int(convert_base, formating, temp);
    return my_putstr_fd_free(convert_base, formating->fd);
}
