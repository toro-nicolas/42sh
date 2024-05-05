/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** Returns the root of the number (nb)
*/
/**
 * @file my_compute_square_root.c
 * @brief The file containing the my_compute_square_root function
 * @author Nicolas TORO
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int i = 1;

    if (nb == 0)
        return 0;
    while (i * i <= nb) {
        if (nb / i == i
            && nb % i == 0) {
            return i;
        }
        i++;
    }
    return 0;
}
