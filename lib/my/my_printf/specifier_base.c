/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** The functions for apply an specifier on an number in different base
*/
/**
 * @file specifier_base.c
 * @brief The file containing the specifier_base function
 * @author Nicolas TORO
 */

#include "myprintf.h"

static char *select_long_long(size_t temp, char *base)
{
    return my_str_nbr_base_unsigned_long((long)temp, base);
}

static char *select_short(size_t temp, char *base)
{
    return my_str_nbr_base_unsigned_short((unsigned short)temp, base);
}

static char *select_short_short(size_t temp, char *base)
{
    return my_str_nbr_base_unsigned_short_short((unsigned char)temp, base);
}

static char *select_size_t(size_t temp, char *base)
{
    return my_str_nbr_base_unsigned_size_t(temp, base);
}

char *specify_it_base(formating_t *formating, size_t temp, char *base)
{
    char *(*specify[])(size_t, char *) =
        {&select_long_long, &select_long_long,
        &select_short, &select_short_short, &select_size_t,
        &select_size_t, &select_size_t, &select_size_t};

    if (formating->id_sp != -1) {
        return specify[formating->id_sp](temp, base);
    } else if (formating->flag == 'b') {
        return my_convert_base_unsigned(my_str_nbr_unsigned(temp),
        "0123456789", "01");
    } else {
        return my_str_nbr_base_unsigned((unsigned)temp, base);
    }
}
