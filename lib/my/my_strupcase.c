/*
** EPITECH PROJECT, 2023
** my_strupcase
** File description:
** Replaces lowcase by upcase of a string (str) and returns them
*/
/**
 * @file my_strupcase.c
 * @brief The file containing the my_strupcase function
 * @author Nicolas TORO
 */

#include "my.h"

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] = str[i] - 32;
        }
    }
    return str;
}
