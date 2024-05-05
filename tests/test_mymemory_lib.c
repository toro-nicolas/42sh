/*
** EPITECH PROJECT, 2024
** test_mymemory_lib
** File description:
** Unit tests for each function of the mymemory lib
*/
/**
 * @file test_mymemory_lib.c
 * @brief Unit tests for each function of the mymemory lib
 * @author Nicolas TORO
 */

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../include/mymemory.h"

Test(my_memset, test_my_memset)
{
    char *str = malloc(sizeof(char) * 10);

    cr_assert_not_null(str);
    my_memset(str, 'a', 10);
    cr_assert_str_eq(str, "aaaaaaaaaa");
    free(str);
    my_memset(NULL, 'a', 10);
}

Test(my_memcpy, test_my_memcpy)
{
    char *str = malloc(sizeof(char) * 10);
    char *str2 = malloc(sizeof(char) * 10);
    char *str3 = malloc(sizeof(char) * 10);
    char *str4 = malloc(sizeof(char) * 10);

    cr_assert_not_null(str);
    cr_assert_not_null(str2);
    my_memset(str, 'a', 10);
    my_memcpy(str2, str, 10);
    my_memcpy(str3, str, 5);
    my_memcpy(str4, str, 15);
    cr_assert_str_eq(str2, "aaaaaaaaaa");
    cr_assert_str_eq(str3, "aaaaa");
    cr_assert_str_eq(str4, "aaaaaaaaaa");
    free(str);
    free(str2);
    free(str3);
    free(str4);
    my_memcpy(NULL, NULL, 10);
}

Test(my_memmove, test_my_memmove)
{
    char *str = malloc(sizeof(char) * 10);
    char *str2 = malloc(sizeof(char) * 10);
    char *str3 = malloc(sizeof(char) * 10);
    char *str4 = malloc(sizeof(char) * 10);

    cr_assert_not_null(str);
    cr_assert_not_null(str2);
    my_memset(str, 'a', 10);
    my_memmove(str2, str, 10);
    my_memmove(str3, str, 5);
    my_memmove(str4, str, 15);
    cr_assert_str_eq(str2, "aaaaaaaaaa");
    cr_assert_str_eq(str3, "aaaaa");
    cr_assert_str_eq(str4, "aaaaaaaaaa");
    free(str);
    free(str2);
    free(str3);
    free(str4);
    my_memmove(NULL, NULL, 10);
}

Test(my_memchr, test_my_memchr)
{
    char *str = malloc(sizeof(char) * 10);

    cr_assert_not_null(str);
    my_memset(str, 'a', 10);
    cr_assert_eq(my_memchr(str, 'a', 10), str);
    cr_assert_eq(my_memchr(str, 'b', 10), NULL);
    free(str);
    my_memchr(NULL, 'a', 10);
}

Test(my_memcmp, test_my_memcmp)
{
    char *str = malloc(sizeof(char) * 10);
    char *str2 = malloc(sizeof(char) * 10);

    cr_assert_not_null(str);
    cr_assert_not_null(str2);
    my_memset(str, 'a', 10);
    my_memset(str2, 'a', 10);
    cr_assert_eq(my_memcmp(str, str2, 10), 0);
    my_memset(str2, 'b', 10);
    cr_assert_eq(my_memcmp(str, str2, 10), -1);
    free(str);
    free(str2);
    my_memcmp(NULL, NULL, 10);
}

Test(my_calloc, test_my_calloc)
{
    char *str = my_calloc(10, sizeof(char), 1);

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "\0");
    my_calloc(0, 0, 1);
    my_calloc(100000000000000000, 100000000000000000, 1);
    my_free();
}

Test(my_malloc_strdup, test_my_malloc_strdup)
{
    char *str = my_malloc_strdup("Hello World");

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "Hello World");
    my_malloc_strdup(NULL);
}

Test(my_malloc_strdup_word_array, test_my_malloc_strdup_word_array)
{
    char **array = malloc(sizeof(char *) * 3);
    char **array2 = my_malloc_strdup_word_array(array);

    cr_assert_not_null(array2);
    cr_assert_eq(array2[0], NULL);
    cr_assert_eq(array2[1], NULL);
    cr_assert_eq(array2[2], NULL);
    my_malloc_strdup_word_array(NULL);
    array = STR2ARRAY_SEP("Hello World", " ");
    array2 = my_malloc_strdup_word_array(array);
    my_free();
}

Test(my_realloc, test_my_realloc)
{
    char *str = malloc(sizeof(char) * 10);
    char *str2 = my_realloc(str, 20, 1);

    cr_assert_not_null(str2);
    free(str2);
    my_realloc(NULL, 0, 1);
    my_realloc(NULL, 100000000000000000, 1);
}

Test(my_malloc, test_my_malloc)
{
    char *str = my_malloc(10, 1);

    cr_assert_not_null(str);
    free(str);
    my_malloc(0, 1);
    my_malloc(100000000000000000, 1);
}

