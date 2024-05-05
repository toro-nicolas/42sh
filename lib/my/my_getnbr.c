/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** Returns an int number starting from a string number (str)
*/
/**
 * @file my_getnbr.c
 * @brief The file containing the my_getnbr function
 * @author Nicolas TORO
 */

#include "my.h"

static int index_negative(char const *str, int index)
{
    if (index == 0)
        return 1;
    if (str[index - 1] == '-')
        return -1;
    return 1;
}

int my_getnbr(char const *str)
{
    int convert = 0;
    int index = 0;
    int index_neg = 1;
    int index_int = 0;

    if (my_strcmp(str, "-2147483648") == 0)
        return -2147483648;
    if ((str[0] < '0' || str[0] > '9') && str[0] != '-')
        return 0;
    while (str[index] < '0' || str[index] > '9')
        index++;
    index_neg = index_negative(str, index);
    while (str[index] >= '0' && str[index] <= '9') {
        convert = convert * 10 + (str[index] - 48);
        index++;
        index_int++;
        if (index_int > 10)
            convert = 0;
    }
    return index_neg * convert;
}
