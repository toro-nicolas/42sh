/*
** EPITECH PROJECT, 2023
** my_str_nbr_size_t
** File description:
** Returns the string conversion of a big unsigned number (nb)
*/
/**
 * @file my_str_nbr_size_t.c
 * @brief The file containing the my_str_nbr_size_t function
 * @author Nicolas TORO
 */

#include "my.h"

static char *set_str_nb(size_t nb, int int_nb)
{
    char *nb_str = malloc(sizeof(char) * (int_nb + 1));
    int j = 0;
    size_t figure_temp = nb;

    for (j = 0; j < int_nb; j++) {
        nb_str[j] = 48 + (figure_temp % 10);
        figure_temp = (figure_temp - (figure_temp % 10)) / 10;
    }
    nb_str[j] = '\0';
    return my_revstr(nb_str);
}

char *my_str_nbr_size_t(size_t nb)
{
    int int_nb = 1;
    size_t temp_nb = nb;

    while ((temp_nb / 10) != 0) {
        int_nb = int_nb + 1;
        temp_nb = temp_nb / 10;
    }
    return set_str_nb(nb, int_nb);
}
