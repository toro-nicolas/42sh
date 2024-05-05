/*
** EPITECH PROJECT, 2023
** my_convert_base
** File description:
** Returns the result of the conversion of a number (nbr)
** in a specific base (base_from) to another base (base_to)
*/
/**
 * @file my_convert_base.c
 * @brief The file containing the my_convert_base function
 * @author Nicolas TORO
 */

#include "my.h"

static char *put_str_nb(int nb, char const *base, int base_len, int negative)
{
    int len_nb = 1;
    int temp_nb = nb;
    char *nb_str;
    int figure_temp = nb;

    while ((temp_nb / base_len) != 0) {
        len_nb = len_nb + 1;
        temp_nb = temp_nb / base_len;
    }
    nb_str = malloc(sizeof(char) * (len_nb + negative));
    if (negative == 1)
        nb_str[0] = '-';
    for (int i = 0; i < len_nb; i++) {
        nb_str[len_nb - i - 1 + negative] = base[figure_temp % base_len];
        figure_temp = (figure_temp - (figure_temp % base_len)) / base_len;
    }
    nb_str[len_nb] = '\0';
    return my_strdup(nb_str);
}

static char *my_setnbr_base(int nbr, char const *base)
{
    int negative = 0;
    int base_len = 0;

    if (nbr < 0) {
        negative = 1;
        nbr = -nbr;
    }
    while (base[base_len] != '\0')
        base_len = base_len + 1;
    return put_str_nb(nbr, base, base_len, negative);
}

char *my_convert_base(char const *nbr,
    char const *base_from, char const *base_to)
{
    int number = my_getnbr_base(nbr, base_from);
    char *result = my_setnbr_base(number, base_to);

    return result;
}
