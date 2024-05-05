/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** The functions for precise a double
*/
/**
 * @file precise_it_double.c
 * @brief The file containing the precise_it_double function
 * @author Nicolas TORO
 */

#include "myprintf.h"

void precise_it_double(char *str_finale,
    formating_t *formating, double partie_d)
{
    int precision = (formating->id_prc != -1) ? (formating->id_nb) : 6;

    if (precision != 0) {
        my_strcat(str_finale, ".");
        for (int i = 0; i < precision; i++) {
            partie_d *= 10;
            my_strcat(str_finale, my_str_nbr(partie_d));
            partie_d -= (int)partie_d;
        }
    }
    my_round_float_str(str_finale, 48 + (partie_d * 10),
        my_strlen(str_finale) - 1, 0);
}
