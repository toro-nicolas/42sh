/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Flag to print %%
*/
/**
 * @file flag_percent.c
 * @brief The file containing the flag_percent function
 * @author Nicolas TORO
 */

#include "myprintf.h"

int flag_percent(va_list liste, formating_t *formating)
{
    write(formating->fd, "%", 1);
    return 1;
}
