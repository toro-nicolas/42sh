/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Flag to print a %F (a double)
*/
/**
 * @file flag_bigf.c
 * @brief The file containing the flag_bigf function
 * @author Nicolas TORO
 */

#include "myprintf.h"

static char *my_get_str_float(double nb, formating_t *formating)
{
    long long int partie_entiere = ABS((int)nb);
    double partie_d = ABS(nb - partie_entiere);
    char *str_finale = malloc(sizeof(char) * 1000000);

    str_finale[0] = '\0';
    if (nb < 0)
        my_strcat(str_finale, "-");
    my_strcat(str_finale, my_str_nbr_long_long(partie_entiere));
    precise_it_double(str_finale, formating, partie_d);
    format_it_double(str_finale, formating, partie_d);
    return str_finale;
}

int flag_bigf(va_list list, formating_t *formating)
{
    char *temp = my_get_str_float(va_arg(list, double), formating);

    return my_putstr_fd_free(temp, formating->fd);
}
