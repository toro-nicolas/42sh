/*
** EPITECH PROJECT, 2023
** my_array_len
** File description:
** Returns the lengths of an array (array) which finish with a NULL value
*/
/**
 * @file my_array_len.c
 * @brief The file containing the my_array_len function
 * @author Nicolas TORO
 */

#include "my.h"

int my_array_len(void **array)
{
    int len = 0;

    if (array == NULL)
        return 0;
    while (array[len] != NULL)
        len = len + 1;
    return len;
}
