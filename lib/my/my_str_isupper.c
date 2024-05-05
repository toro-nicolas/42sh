/*
** EPITECH PROJECT, 2023
** my_str_isupper
** File description:
** Returns 1 if the string (str)
** contains only uppercase alphabetical characters
*/
/**
 * @file my_str_isupper.c
 * @brief The file containing the my_str_isupper function
 * @author Nicolas TORO
 */

#include "my.h"

int my_str_isupper(char const *str)
{
    int isalpha = 0;

    if (my_strlen(str) == 0)
        return 1;
    isalpha = my_str_isalpha(str);
    for (int i = 0; i < my_strlen(str); i++) {
        if (isalpha == 0)
            return 0;
        if (str[i] < 'A' || str[i] > 'Z')
            return 0;
    }
    return 1;
}
