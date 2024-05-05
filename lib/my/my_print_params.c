/*
** EPITECH PROJECT, 2023
** my_print_params
** File description:
** Prints all the parameters of the program
*/
/**
 * @file my_print_params.c
 * @brief The file containing the my_print_params function
 * @author Nicolas TORO
 */

#include "my.h"

void my_print_params(int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        my_putstr(argv[i]);
        my_putstr("\n");
    }
}
