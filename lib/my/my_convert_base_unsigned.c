/*
** EPITECH PROJECT, 2023
** my_convert_base_unsigned
** File description:
** Returns the result of the conversion of a unsigned number (nbr)
** in a specific base (base_from) to another base (base_to)
*/
/**
 * @file my_convert_base_unsigned.c
 * @brief The file containing the my_convert_base_unsigned function
 * @author Nicolas TORO
 */

#include "my.h"

static int is_valid(char c, char const *base)
{
    for (int i = 0; i < my_strlen(base); i++) {
        if (c == base[i])
            return 1;
    }
    return 0;
}

static int calculate_base(char const *str, char const *base,
    int *index, int *error)
{
    if (is_valid(str[index[0]], base) == 1) {
        if (str[index[0]] == base[index[1]]) {
            return index[1] * my_compute_power_rec(my_strlen(base),
            my_strlen(str) - index[0] - 1);
        }
    } else {
        *error = 1;
    }
    return 0;
}

static unsigned int my_getnbr_base_unsigned(char const *str, char const *base)
{
    unsigned int result = 0;
    int error = 0;
    int index[2];

    for (int i = my_strlen(str) - 1; i >= 0; i--) {
        for (int j = 0; j < my_strlen(base) && error == 0; j++) {
            index[0] = i;
            index[1] = j;
            result = result + calculate_base(str, base, index, &error);
        }
    }
    return result;
}

static char *put_str_nb(unsigned int nb, char const *base, int base_len)
{
    int len_nb = 1;
    unsigned int temp_nb = nb;
    char *nb_str;
    unsigned int figure_temp = nb;

    while ((temp_nb / base_len) != 0) {
        len_nb = len_nb + 1;
        temp_nb = temp_nb / base_len;
    }
    nb_str = malloc(sizeof(char) * len_nb);
    for (int i = 0; i < len_nb; i++) {
        nb_str[len_nb - i - 1] = base[figure_temp % base_len];
        figure_temp = (figure_temp - (figure_temp % base_len)) / base_len;
    }
    nb_str[len_nb] = '\0';
    return my_strdup(nb_str);
}

static char *my_setnbr_base(unsigned int nbr, char const *base)
{
    int base_len = 0;

    while (base[base_len] != '\0')
        base_len = base_len + 1;
    return put_str_nb(nbr, base, base_len);
}

char *my_convert_base_unsigned(char const *nbr,
    char const *base_from, char const *base_to)
{
    unsigned int number = my_getnbr_base_unsigned(nbr, base_from);
    char *result = my_setnbr_base(number, base_to);

    return result;
}
