/*
** EPITECH PROJECT, 2024
** my_str_contains
** File description:
** Returns 1 if the string (str) contains at least one character from the
** char list (char_list), 0 otherwise
*/
/**
 * @file my_str_contains.c
 * @brief The file containing the my_str_contains function
 * @author Nicolas TORO
 */

#include "my.h"

static int check_char_list(char *str, char *char_list, int i)
{
    for (int j = 0; char_list[j] != '\0'; j++) {
        if (str[i] == char_list[j])
            return 1;
    }
    return 0;
}

int my_str_contains(char *str, char *char_list)
{
    if (str == NULL || char_list == NULL)
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (check_char_list(str, char_list, i))
            return 1;
    }
    return 0;
}
