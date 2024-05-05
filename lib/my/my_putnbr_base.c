/*
** EPITECH PROJECT, 2023
** my_putnbr_base
** File description:
** Prints a number (nb) in the requested base (base) in stdout
*/
/**
 * @file my_putnbr_base.c
 * @brief The file containing the my_putnbr_base function
 * @author Nicolas TORO
 */

#include "my.h"

static void put_str_nb(int nb, int len_nb, char const *base, int base_len)
{
    char nb_str[len_nb];
    int figure_temp = nb;

    for (int i = 0; i < len_nb; i++) {
        nb_str[len_nb - i - 1] = base[figure_temp % base_len];
        figure_temp = (figure_temp - (figure_temp % base_len)) / base_len;
    }
    nb_str[len_nb] = '\0';
    my_putstr(nb_str);
}

void my_putnbr_base(int nbr, char const *base)
{
    int len_nb = 1;
    int temp_nb = nbr;
    int base_len = 0;

    if (nbr < 0) {
        my_putchar('-');
        nbr = -nbr;
    }
    while (base[base_len] != '\0') {
        base_len = base_len + 1;
    }
    while ((temp_nb / base_len) != 0) {
        len_nb = len_nb + 1;
        temp_nb = temp_nb / base_len;
    }
    put_str_nb(nbr, len_nb, base, base_len);
}
