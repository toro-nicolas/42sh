/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** The functions for precise an int
*/
/**
 * @file precise_it_int.c
 * @brief The file containing the precise_it_int function
 * @author Nicolas TORO
 */

#include "myprintf.h"

void precise_it_int(char *str_finale,
    formating_t *formating, size_t nb)
{
    int precision = formating->id_nb;

    if (precision != 0 && my_strlen(str_finale) < precision) {
        my_revstr(str_finale);
        for (int i = my_strlen(str_finale); i < precision; i++) {
            my_strcat(str_finale, "0");
        }
        my_revstr(str_finale);
    } else if (precision == 0 && nb == '\0') {
        str_finale[0] = '\0';
    }
}
