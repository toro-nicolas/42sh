/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The my_replace_char.c
*/
/**
 * @file my_replace_char.c
 * @brief The file containing the my_replace_char function
 * @author Nicolas TORO
 */

#include "my.h"

void my_replace_char(char *str, char to_replace, char replace_by)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_replace)
            str[i] = replace_by;
    }
}
