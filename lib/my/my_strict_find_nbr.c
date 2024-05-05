/*
** EPITECH PROJECT, 2024
** my_strict_find_nbr
** File description:
** Returns an int number starting from a string number (str) and -1 if the
** string is not an exact positive number
*/
/**
 * @file my_strict_find_nbr.c
 * @brief The file containing the my_strict_find_nbr function
 * @author Nicolas TORO
 */

#include "my.h"

int my_strict_find_nbr(char const *str)
{
    int nb = -1;
    int start = -1;

    if (str[0] == '\0')
        return -1;
    for (int index = 0; str[index] != '\0'; index++) {
        if (start == -1 && str[index] >= '1' && str[index] <= '9') {
            start = index;
            nb = 0;
        }
        if (nb < -1 || str[index] < '0' || str[index] > '9' ||
        (index > start + 8 && str[start] != '1' && str[start] != '2'))
            return nb;
        nb = nb * 10 + (str[index] - 48);
    }
    return nb;
}
