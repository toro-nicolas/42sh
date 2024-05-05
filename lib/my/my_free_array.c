/*
** EPITECH PROJECT, 2024
** my_free_array
** File description:
** Free an array (array)
*/
/**
 * @file my_free_array.c
 * @brief The file containing the my_free_array function
 * @author Nicolas TORO
 */

#include "my.h"

void my_free_array(void **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++)
        FREE(array[i]);
    FREE(array);
}
