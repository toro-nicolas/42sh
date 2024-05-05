/*
** EPITECH PROJECT, 2024
** Shell
** File description:
** title.c
*/
/**
 * @file title.c
 * @brief The file containing the title function
 */

#include "../../include/myshell.h"

/**
 * @brief Set the title of the shell
 * @return <b>void</b>
 */
void set_title(void)
{
    char **tab;
    char *current_pwd;
    char *current_directory;

    current_pwd = getcwd(NULL, 0);
    tab = my_str_to_word_array_select(current_pwd, "/");
    if (tab[0] == NULL)
        my_printf("\033]0;🧭 root 🧭\a");
    for (int i = 0; tab[i] != NULL; i++) {
        current_directory = tab[i];
        if (tab[i + 1] == NULL)
            my_printf("\033]0;🧭 %s 🧭\a", current_directory);
    }
    my_free_array((void *)tab);
    free(current_pwd);
}
