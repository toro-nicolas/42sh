/*
** EPITECH PROJECT, 2024
** template
** File description:
** Free an array of words (array)
*/

#include "my.h"

void my_free_word_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++)
        FREE(array[i]);
    FREE(array);
}
