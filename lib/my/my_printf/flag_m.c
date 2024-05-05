/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Flag to print a %m (an errno) | Disable
*/
/**
 * @file flag_m.c
 * @brief The file containing the flag_m function
 * @author Nicolas TORO
 */

#include "myprintf.h"

int flag_m(va_list list, formating_t *formating)
{
    return my_putstr_fd(my_strerror(errno), formating->fd);
}
