/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** Returns 1 if the number (nb) is prime and 0 otherwise
*/
/**
 * @file my_is_prime.c
 * @brief The file containing the my_is_prime function
 * @author Nicolas TORO
 */

#include "my.h"

int my_is_prime(int nb)
{
    int i = 0;

    if (nb <= 1 || nb == 4) {
        return 0;
    }
    for (i = 2; i < nb / 2; i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}
