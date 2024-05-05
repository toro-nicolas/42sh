/*
** EPITECH PROJECT, 2024
** my_nbrlen
** File description:
** Return the length of a number (nb)
*/
/**
 * @file my_nbrlen.c
 * @brief The file containing the my_nbrlen function
 * @author Nicolas TORO
 */

#include "my.h"

int my_nbrlen(int nb)
{
    int len = 0;

    if (nb == 0)
        return 1;
    if (nb < 0) {
        len++;
        nb = -nb;
    }
    while (nb > 0) {
        nb = nb / 10;
        len++;
    }
    return len;
}
