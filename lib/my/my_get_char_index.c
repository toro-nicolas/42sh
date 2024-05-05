/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The my_get_char_index.c
*/
/**
 * @file my_get_char_index.c
 * @brief The file containing the my_get_char_index function
 * @author Nicolas TORO
 */

#include "my.h"

int my_get_char_index(char *str, char c, int occurrence)
{
    int index = -1;
    int count = 0;

    if (str == NULL)
        return index;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            index = i;
            count++;
        }
        if (count == occurrence)
            break;
    }
    return index;
}
