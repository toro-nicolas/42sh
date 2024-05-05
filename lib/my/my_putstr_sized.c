/*
** EPITECH PROJECT, 2023
** my_putstr_limited
** File description:
** Write a string (str) in stdout with a defined size (size)
** and returns the length of the printed string
*/
/**
 * @file my_putstr_sized.c
 * @brief The file containing the my_putstr_sized function
 * @author Nicolas TORO
 */

#include "my.h"

int my_putstr_sized(char const *str, int size)
{
    if (str == NULL || size < 1)
        return 0;
    write(1, str, size);
    return size;
}
