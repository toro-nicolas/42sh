/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Flag to print a %n (store a int)
*/
/**
 * @file flag_n.c
 * @brief The file containing the flag_n function
 * @author Nicolas TORO
 */

#include "myprintf.h"

static void signed_char(va_list list, int len)
{
    signed char *variable_char = va_arg(list, signed char *);

    *variable_char = len;
}

static void short_int(va_list list, int len)
{
    short *variable_short = va_arg(list, short *);

    *variable_short = len;
}

static void basic_int(va_list list, int len)
{
    int *variable_int = va_arg(list, int *);

    *variable_int = len;
}

static void long_int(va_list list, int len)
{
    long int *variable_long = va_arg(list, long *);

    *variable_long = len;
}

static void long_long_int(va_list list, int len)
{
    long long int *variable_long_long = va_arg(list, long long *);

    *variable_long_long = len;
}

static void basic_size_t(va_list list, int len)
{
    size_t *variable_size_t = va_arg(list, size_t *);

    *variable_size_t = len;
}

int flag_n(va_list list, formating_t *formating, int len)
{
    void (*specify[])(va_list, int) = {&long_int, &long_long_int,
        &short_int, &signed_char, &basic_size_t,
        &basic_size_t, &basic_size_t, &basic_size_t};

    if (formating->id_sp != -1) {
        specify[formating->id_sp](list, len);
    } else {
        basic_int(list, len);
    }
    return 0;
}
