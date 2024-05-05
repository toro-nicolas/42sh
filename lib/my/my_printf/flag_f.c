/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Flag to print a %f (a double)
*/
/**
 * @file flag_f.c
 * @brief The file containing the flag_f function
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
    format_it_double(str_finale, formating, nb);
    return str_finale;
}

int flag_f(va_list list, formating_t *formating)
{
    double temp_nb = va_arg(list, double);
    char *temp = my_get_str_float(temp_nb, formating);

    return my_putstr_fd_free(temp, formating->fd);
}
