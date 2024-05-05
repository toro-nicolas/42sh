/*
** EPITECH PROJECT, 2023
** my_str_nbr_unsigned_long
** File description:
** Returns the string conversion of a long unsigned number (nb)
*/
/**
 * @file my_str_nbr_unsigned_long.c
 * @brief The file containing the my_str_nbr_unsigned_long function
 * @author Nicolas TORO
 */

#include "my.h"

static char *set_str_nb_unsigned_long(unsigned long int nb,
    int int_nb)
{
    char *nb_str = malloc(sizeof(char) * (int_nb + 1));
    int j = 0;
    unsigned long int figure_temp = nb;

    for (j = 0; j < int_nb; j++) {
        nb_str[j] = 48 + (figure_temp % 10);
        figure_temp = (figure_temp - (figure_temp % 10)) / 10;
    }
    nb_str[j] = '\0';
    return my_revstr(nb_str);
}

char *my_str_nbr_unsigned_long(unsigned long int nb)
{
    int int_nb = 1;
    unsigned long int temp_nb = nb;

    while ((temp_nb / 10) != 0) {
        int_nb = int_nb + 1;
        temp_nb = temp_nb / 10;
    }
    return set_str_nb_unsigned_long(nb, int_nb);
}
