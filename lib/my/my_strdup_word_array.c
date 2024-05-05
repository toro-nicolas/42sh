/*
** EPITECH PROJECT, 2024
** my_strdup_word_array
** File description:
** Returns a duplication of a word array (array)
*/
/**
 * @file my_strdup_word_array.c
 * @brief The file containing the my_strdup_word_array function
 * @author Nicolas TORO
 */

#include "my.h"

char **my_strdup_word_array(char **array)
{
    char **new_array;
    int i = 0;

    if (array == NULL)
        return NULL;
    new_array = malloc(sizeof(char *) * (my_array_len((void **)array) + 1));
    for (; array[i] != NULL; i++)
        new_array[i] = my_strdup(array[i]);
    new_array[i] = NULL;
    return new_array;
}
