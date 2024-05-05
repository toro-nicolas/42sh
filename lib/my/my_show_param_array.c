/*
** EPITECH PROJECT, 2023
** my_show_param_array
** File description:
** Prints the name, the length and word array of
** each element of an array (par) of the info_param struct
*/
/**
 * @file my_show_param_array.c
 * @brief The file containing the my_show_param_array function
 * @author Nicolas TORO
 */

#include "my.h"

void my_show_param_array(struct info_param const *par)
{
    int i = 0;

    while (par[i].length != 0) {
        my_putstr(par[i].str);
        my_putchar('\n');
        my_putnbr(par[i].length);
        my_putchar('\n');
        my_show_word_array(par[i].word_array);
        i++;
    }
}
