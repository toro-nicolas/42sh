/*
** EPITECH PROJECT, 2024
** my_memchr
** File description:
** Copies (size) bytes from memory area (source) to memory area (destination)
*/
/**
 * @file my_memchr.c
 * @brief The file containing the my_memchr function
 * @author Nicolas TORO
 */

#include "mymemory.h"

void *my_memcpy(void *destination, const void *source, size_t size)
{
    char *ptr = destination;
    int end = 0;

    if (destination == NULL || source == NULL)
        return NULL;
    for (size_t index = 0; index < size; index++) {
        if (end == 1 || ((char *)source)[index] == '\0') {
            end = 1;
            ptr[index] = '\0';
        }
        ptr[index] = ((char *)source)[index];
    }
    return (void *)ptr;
}
