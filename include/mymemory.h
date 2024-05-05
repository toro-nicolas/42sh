/*
** EPITECH PROJECT, 2024
** Libmymemory
** File description:
** The header file of the libmymemory
*/
/**
 * @file mymemory.h
 * @brief The header file of the libmymemory
 * @author Nicolas TORO
 */

#include "mylist.h"

#ifndef MYMEMORY_H_
    #define MYMEMORY_H_

// MACROS :

    // Shortcuts :

    #define CALLOC(elt_count, elt_size) my_calloc(elt_count, elt_size, 1)
    #define MALLOC(size) my_malloc(size, 1)
    #define REALLOC(ptr, size) my_realloc(ptr, size, 1)



// FUNCTIONS PROTOTYPES :

/**
 * @brief Allocates memory for an array of elements (element_count)
 * of bytes (element_size) each and initializes the memory to zero
 * @note <b>type</b> = 0: Free allocated memory with my_calloc
 * @note <b>type</b> = 1: Allocate memory
 * @param element_count The number of elements
 * @param element_size The size of each element
 * @param type The type of the usage
 * @return <b>void *</b> A pointer to the allocated memory
 * @author Nicolas TORO
 */
void *my_calloc(size_t element_count, size_t element_size, int type);

/**
 * @brief Free allocated memory with my_calloc, my_malloc and my_realloc
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_free(void);

/**
 * @brief Allocates memory for an array of bytes (size)
 * @note <b>type</b> = 0: Free allocated memory with my_malloc
 * @note <b>type</b> = 1: Allocate memory
 * @param size The size of the memory to allocate
 * @param type The type of the usage
 * @return <b>void *</b> A pointer to the allocated memory
 * @author Nicolas TORO
 */
void *my_malloc(size_t size, int type);

/**
 * @brief Duplicates a string with my_malloc
 * @note The duplicated string must be free only with my_free
 * @param src The string to duplicate
 * @return <b>char *</b> A pointer to the duplicated string
 * @author Nicolas TORO
 */
char *my_malloc_strdup(char const *src);

/**
 * @brief Duplicates a word array (array) with my_malloc
 * @note The duplicated word array must be free only with my_free
 * @param array The word array to duplicate
 * @return <b>char **</b> A pointer to the duplicated word array
 * @author Nicolas TORO
 */
char **my_malloc_strdup_word_array(char **array);

/**
 * @brief Duplicates a string with a defined size with my_malloc
 * @note The duplicated string must be free only with my_free
 * @param src The string to duplicate
 * @param n The size of the string
 * @return <b>char*</b> A pointer to the duplicated string
 * @author Nicolas TORO
 */
char *my_malloc_strndup(char const *src, int n);

/**
 * @brief Copies bytes (size) from memory area (source)
 * to memory area (destination)
 * @param destination The destination memory area
 * @param source The source memory area
 * @param size The number of bytes to copy
 * @return <b>void *</b> A pointer to the destination memory area
 * @author Nicolas TORO
 */
void *my_memchr(const void *memory_block, int searched_char, size_t size);

/**
 * @brief Copies bytes (size) from memory area (source)
 * to memory area (destination)
 * @param destination The destination memory area
 * @param source The source memory area
 * @param size The number of bytes to copy
 * @return <b>void *</b> A pointer to the destination memory area
 * @author Nicolas TORO
 */
void *my_memcpy(void *destination, const void *source, size_t size);

/**
 * @brief Compares the first (size) bytes of
 * the two memory areas (pointer1 and pointer2)
 * @param pointer1 The first memory area
 * @param pointer2 The second memory area
 * @param size The number of bytes to compare
 * @return <b>int</b> <u>0</u> if the strings are identical, otherwise
 * the difference between the first different byte in the memory areas
 * @author Nicolas TORO
 */
int my_memcmp(const void *pointer1, const void *pointer2, size_t size);

/**
 * @brief Moves bytes (size) from memory area (source)
 * to memory area (destination)
 * @note Did the same as my_memcpy
 * @param destination The destination memory area
 * @param source The source memory area
 * @param size The number of bytes to copy
 * @return <b>void *</b> A pointer to the destination memory area
 * @author Nicolas TORO
 */
void *my_memmove(void *destination, const void *source, size_t size);

/**
 * @brief Fill bytes (size) of memory area (pointer) with a value (value)
 * @param pointer The memory area to fill
 * @param value The value to fill the memory area with
 * @param size The number of bytes to fill
 * @return <b>void *</b> A pointer to the memory area filled with (value)
 * @author Nicolas TORO
 */
void *my_memset(void *pointer, int value, size_t size);

/**
 * @brief Reallocates memory for an array of bytes (size)
 * @note <b>type</b> = 0: Free allocated memory with my_realloc
 * @note <b>type</b> = 1: Allocate memory
 * @param pointer The pointer to the memory to reallocate
 * @param size The size of the memory to reallocate
 * @param type The type of the usage
 * @return <b>void *</b> A pointer to the reallocated memory
 * @author Nicolas TORO
 */
void *my_realloc(void *pointer, size_t size, int type);

#endif /* MYMEMORY_H_ */
