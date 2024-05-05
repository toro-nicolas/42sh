/*
** EPITECH PROJECT, 2024
** my_memset
** File description:
** Fills the first (size) bytes of the memory area pointed to by (pointer)
** with the constant byte (value)
*/
/**
 * @file my_memset.c
 * @brief The file containing the my_memset function
 * @author Nicolas TORO
 */

#include "mymemory.h"

void *my_memset(void *pointer, int value, size_t size)
{
    if (pointer == NULL)
        return NULL;
    for (size_t i = 0; i < size; i++)
        ((char *)pointer)[i] = value;
    return pointer;
}
