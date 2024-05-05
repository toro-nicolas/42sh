/*
** EPITECH PROJECT, 2024
** my_memchr
** File description:
** Searches for the first occurrence of the character (c)
** in the first (n) bytes of the string (s)
*/
/**
 * @file my_memchr.c
 * @brief The file containing the my_memchr function
 * @author Nicolas TORO
 */

#include "mymemory.h"

void *my_memchr(const void *memory_block, int searched_char, size_t size)
{
    if (memory_block == NULL)
        return NULL;
    for (size_t index = 0; index < size; index++) {
        if (((char *)memory_block)[index] == searched_char)
            return (void *)&((char *)memory_block)[index];
    }
    return NULL;
}
