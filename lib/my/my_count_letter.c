/*
** EPITECH PROJECT, 2024
** my_count_letter
** File description:
** Returns the number of times the letter (c) chose is in the string (str)
*/
/**
 * @file my_count_letter.c
 * @brief The file containing the my_count_letter function
 * @author Nicolas TORO
 */

#include "my.h"

int my_count_letter(char const *str, char c)
{
    int count = 0;

    for (int index = 0; str[index] != '\0'; index++) {
        if (str[index] == c)
            count++;
    }
    return count;
}
