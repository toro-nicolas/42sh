/*
** EPITECH PROJECT, 2024
** my_strict_getnbr
** File description:
** Returns an int number starting from a string number (str) and -1 if the
** string is not an exact positive number
*/
/**
 * @file my_strict_getnbr.c
 * @brief The file containing the my_strict_getnbr function
 * @author Nicolas TORO
 */

#include "my.h"

int my_strict_getnbr(char const *str)
{
    int nb = 0;
    int start = 0;

    if (str[0] == '\0')
        return -1;
    for (int index = 0; str[index] != '\0'; index++) {
        if (str[index] != '0')
            start = index;
        if (nb < 0 || str[index] < '0' || str[index] > '9' ||
        (index > start + 8 && str[start] != '1' && str[start] != '2'))
            return -1;
        nb = nb * 10 + (str[index] - 48);
    }
    return nb;
}
