/*
** EPITECH PROJECT, 2023
** my_strcapitalize
** File description:
** Capitalizes the first letter of each word in a string (str)
*/
/**
 * @file my_strcapitalize.c
 * @brief The file containing the my_strcapitalize function
 * @author Nicolas TORO
 */

#include "my.h"

char *my_strcapitalize(char *str)
{
    str = my_strlowcase(str);
    for (int i = 1; str[i] != '\0'; i++) {
        if (((str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == ' '))
        && (str[i] >= 'a' && str[i] <= 'z'))
            str[i] = str[i] - 32;
    }
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] = str[0] - 32;
    return str;
}
