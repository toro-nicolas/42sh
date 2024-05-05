/*
** EPITECH PROJECT, 2023
** my_show_word_array
** File description:
** Prints all word in an array (tab)
*/
/**
 * @file my_show_word_array.c
 * @brief The file containing the my_show_word_array function
 * @author Nicolas TORO
 */

#include "my.h"

void my_show_word_array(char *const *tab)
{
    int index_tab = 0;

    if (tab == NULL)
        return;
    while (tab[index_tab] != NULL) {
        my_putstr(tab[index_tab]);
        my_putchar('\n');
        index_tab = index_tab + 1;
    }
}
