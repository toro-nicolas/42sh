/*
** EPITECH PROJECT, 2024
** my_memcmp
** File description:
** Compares the first (size) bytes
** of the memory areas (pointer1) and (pointer2)
*/
/**
 * @file my_memcmp.c
 * @brief The file containing the my_memcmp function
 * @author Nicolas TORO
 */

#include "mymemory.h"

int my_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
    if (pointer1 == NULL || pointer2 == NULL)
        return 0;
    for (size_t index = 0; index < size; index++) {
        if (((char *)pointer1)[index] != ((char *)pointer2)[index])
            return ((char *)pointer1)[index] - ((char *)pointer2)[index];
    }
    return 0;
}
