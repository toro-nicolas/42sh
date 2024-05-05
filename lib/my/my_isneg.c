/*
** EPITECH PROJECT, 2023
** my_isneg
** File description:
** Prints 'P' if the number (n) is positive
** or 'N' if the number (n) is negative
*/
/**
 * @file my_isneg.c
 * @brief The file containing the my_isneg function
 * @author Nicolas TORO
 */

#include "my.h"

void my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
}
