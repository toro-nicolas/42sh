/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** Prints a char (c) in the stdout
*/
/**
 * @file my_putchar.c
 * @brief The file containing the my_putchar function
 * @author Nicolas TORO
 */

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
