/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** Swap the value of two integer (a and b)
*/
/**
 * @file my_swap.c
 * @brief The file containing the my_swap function
 * @author Nicolas TORO
 */

#include "my.h"

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
