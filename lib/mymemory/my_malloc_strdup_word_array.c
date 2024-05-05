/*
** EPITECH PROJECT, 2024
** my_malloc_strdup_word_array
** File description:
** Returns a duplication of a word array (array) with my_malloc
*/
/**
 * @file my_malloc_strdup_word_array.c
 * @brief The file containing the my_malloc_strdup_word_array function
 * @author Nicolas TORO
 */

#include "mymemory.h"

char **my_malloc_strdup_word_array(char **array)
{
    char **new_array;
    int i = 0;

    if (array == NULL)
        return (NULL);
    new_array = my_malloc(sizeof(char *) *
        (my_array_len((void **)array) + 1), 1);
    for (; array[i] != NULL; i++)
        new_array[i] = my_malloc_strdup(array[i]);
    new_array[i] = NULL;
    return new_array;
}
