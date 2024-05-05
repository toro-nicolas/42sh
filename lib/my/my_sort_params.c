/*
** EPITECH PROJECT, 2023
** my_sort_params
** File description:
** Sorts the arguments (argc and argv) passed to the program in ascending order
*/
/**
 * @file my_sort_params.c
 * @brief The file containing the my_sort_params function
 * @author Nicolas TORO
 */

#include "my.h"

static int check_equal(int len_s1, int len_s2, int j, int littlest_char_index)
{
    if (len_s1 < len_s2)
        return j;
    else if (len_s1 > len_s2)
        return littlest_char_index;
    else
        return littlest_char_index;
}

static int check_littlest(char **argv, int j, int littlest_char_index)
{
    int i = 0;

    while (i < my_strlen(argv[littlest_char_index])
    && i < my_strlen(argv[j])) {
        if (argv[littlest_char_index][i] < argv[j][i])
            return j;
        if (argv[littlest_char_index][i] > argv[j][i])
            return littlest_char_index;
        i++;
    }
    return check_equal(my_strlen(argv[littlest_char_index]),
    my_strlen(argv[j]), j, littlest_char_index);
}

static void check_swap(char **argv, int i, int littlest_char_index)
{
    char *temp;

    if (i != littlest_char_index) {
        temp = argv[i];
        argv[i] = argv[littlest_char_index];
        argv[littlest_char_index] = temp;
    }
}

void my_sort_params(int argc, char **argv)
{
    int littlest_char_index = 0;

    for (int i = 0; i < argc; i++) {
        littlest_char_index = i;
        for (int j = i; j < argc; j++)
            littlest_char_index = check_littlest(argv, j, littlest_char_index);
        check_swap(argv, i, littlest_char_index);
    }
    for (int i = argc; i > 0; i--) {
        my_putstr(argv[i - 1]);
        my_putstr("\n");
    }
}
