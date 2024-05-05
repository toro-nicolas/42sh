/*
** EPITECH PROJECT, 2024
** my_strict_getnbr_float
** File description:
** Returns a float number starting from a string number (str) and -1.0 if the
** string is not an exact positive number
*/
/**
 * @file my_strict_getnbr_float.c
 * @brief The file containing the my_strict_getnbr_float function
 * @author Nicolas TORO
 */

#include "my.h"

float my_strict_getnbr_float(char const *str)
{
    float convert = 0;
    int index = 0;
    float index_float = 0.1;

    if (str[0] < '0' || str[0] > '9')
        return -1;
    for (; str[index] >= '0' && str[index] <= '9'; index++)
        convert = convert * 10 + (str[index] - 48);
    if (str[index] == '.') {
        index++;
        for (; str[index] >= '0' && str[index] <= '9'; index++) {
            convert = convert + index_float * (str[index] - 48);
            index_float = index_float * 0.1;
        }
    }
    return convert;
}
