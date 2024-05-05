/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** Returns the next prime number starting form a number (nb)
*/
/**
 * @file my_find_prime_sup.c
 * @brief The file containing the my_find_prime_sup function
 * @author Nicolas TORO
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int i = 0;

    if (nb <= 1)
        return 2;
    while (my_is_prime(nb + i) == 0)
        i++;
    return nb + i;
}
