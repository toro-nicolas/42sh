/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the prompt functions
*/
/**
 * @file prompt.c
 * @brief The file containing the prompt functions
 */

#include "../../include/myshell.h"

/**
 * @brief Check if we are in a specific directory and print the right logo
 * @param mysh The shell structure
 * @param tab The current working directory
 * @param i The index of the current directory
 * @return <b>void</b>
 */
static void check_directory(mysh_t *mysh, char **tab, int i)
{
    char *user = get_env_var(mysh->env, "LOGNAME");

    if (my_strcmp(tab[i], "home") == 0 && tab[i + 1] == NULL)
        my_printf("\033[36m🔒/\033[34mhome");
    if (my_strcmp(tab[i], user) == 0 && tab[i + 1] == NULL)
        my_printf("\033[36m🏠\033[34m~");
    if (my_strcmp(tab[i], user) == 0 && tab[i + 1] != NULL)
        my_printf("\033[36m📂~");
}

/**
 * @brief Display the current path in the right color
 * @param tab The current working directory
 * @param i The index of the current directory
 * @param current_directory The current directory
 * @return <b>void</b>
 */
static void is_current_directory(char **tab, int i, char *current_directory)
{
    if (tab[i + 1] == NULL)
        my_printf("\033[34m%s", current_directory);
    else
        my_printf("\033[36m%s", current_directory);
}

/**
 * @biref Print the second line of the prompt and the arrow of the exit status
 * @param status The exit status
 * @return <b>void</b>
 */
static void print_second_line(int status)
{
    my_printf("\033[0m\n");
    my_printf("\033[34m╰─\033[0m%s>\033[0m ",
        !status ? "\033[32m" : "\033[31m");
}

/**
 * @brief Check if the user is in the root directory
 * @param tab The current working directory
 * @return <b>void</b>
 */
static void is_root(char **tab)
{
    if (tab[0] == NULL)
        my_printf("\033[36m🔒/");
    if (my_strcmp(tab[0], "home") != 0 && tab[0] != NULL)
        my_printf("\033[36m📂/\033[0m");
}

/**
 * @brief Create the custom prompt to display
 * @param mysh The shell structure
 * @param current_pwd The current working directory
 * @return <b>void</b>
 */
static void custom_prompt(mysh_t *mysh, char *current_pwd)
{
    char **tab;
    char *current_directory;

    tab = my_str_to_word_array_select(current_pwd, "/");
    my_printf("\033[34m╭─\033[0m 🧭");
    is_root(tab);
    for (int i = 0; tab[i] != NULL; i++) {
        current_directory = tab[i];
        check_directory(mysh, tab, i);
        if (my_strcmp(tab[i], "home") != 0 && my_strcmp(tab[i],
            get_env_var(mysh->env, "LOGNAME")) != 0)
            is_current_directory(tab, i, current_directory);
        if (tab[i + 1] != NULL && my_strcmp(tab[i], "home") != 0)
            my_printf("\033[36m/\033[0m");
    }
    is_git_repository();
    print_second_line(mysh->exit_status);
    my_free_array((void *)tab);
}

/**
 * @brief Display the prompt
* @return <b>void</b>
 */
void display_prompt(void)
{
    char *current_pwd = getcwd(NULL, 0);
    mysh_t *mysh = get_mysh();

    if (current_pwd == NULL)
        my_putstr("$> ");
    else
        custom_prompt(mysh, current_pwd);
    free(current_pwd);
}
