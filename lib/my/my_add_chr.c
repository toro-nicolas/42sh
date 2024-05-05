/*
** EPITECH PROJECT, 2024
** my_add_chr
** File description:
** Adds a char (chr) at the end of a string (str)
*/
/**
 * @file my_add_chr.c
 * @brief The file containing the my_add_chr function
 * @author Nicolas TORO
 */

#include "my.h"

char *my_add_chr(char *str, char chr)
{
    int index = 0;

    for (; str[index] != '\0'; index++);
    str[index] = chr;
    str[index + 1] = '\0';
    return str;
}
