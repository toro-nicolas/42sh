/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** Reverses the characters in a string (str) and returns the string (str)
*/
/**
 * @file my_revstr.c
 * @brief The file containing the my_revstr function
 * @author Nicolas TORO
 */

#include "my.h"

char *my_revstr(char *str)
{
    int len = 0;
    char temp;

    while (str[len] != '\0')
        len = len + 1;
    for (int i = len / 2; i > 0; i--) {
        temp = str[i - 1];
        str[i - 1] = str[len - i];
        str[len - i] = temp;
    }
    return str;
}
