/*
** EPITECH PROJECT, 2023
** my_find_nbr
** File description:
** Find the first number (number) found in a string
*/
/**
 * @file my_find_nbr.c
 * @brief The file containing the my_find_nbr function
 * @author Nicolas TORO
 */

#include "my.h"

int my_find_nbr(char const *number)
{
    int nb = -1;
    int start = -1;

    if (number[0] == '\0')
        return -1;
    for (int index = 0; number[index] != '\0'; index++) {
        if (number[index] >= '0' && start == -1 && number[index] <= '9')
            nb = 0;
        if (start == -1 && number[index] >= '1' && number[index] <= '9')
            start = index;
        if (number[index] < '0' || number[index] > '9')
            return nb;
        nb = nb * 10 + (number[index] - 48);
    }
    return nb;
}
