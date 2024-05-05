/*
** EPITECH PROJECT, 2023
** my_rev_params
** File description:
** Prints all the arguments (argc and argv) in reverse order
*/
/**
 * @file my_rev_params.c
 * @brief The file containing the my_rev_params function
 * @author Nicolas TORO
 */

#include "my.h"

void my_rev_params(int argc, char **argv)
{
    for (int i = argc; i > 0; i--) {
        my_putstr(argv[i - 1]);
        my_putstr("\n");
    }
}
