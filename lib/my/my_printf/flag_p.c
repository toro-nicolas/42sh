/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Flag to print %p (an address in hexadecimal)
*/
/**
 * @file flag_p.c
 * @brief The file containing the flag_p function
 * @author Nicolas TORO
 */

#include "myprintf.h"

int flag_p(va_list list, formating_t *formating)
{
    unsigned long int temp = va_arg(list, unsigned long int);
    char *address_hexa = my_str_nbr_base_unsigned(temp, "0123456789abcdef");

    precise_it_int(address_hexa, formating, temp);
    my_revstr(address_hexa);
    my_strcat(address_hexa, "x0");
    my_revstr(address_hexa);
    format_it_int(address_hexa, formating, temp);
    return my_putstr_fd_free(address_hexa, formating->fd);
}
