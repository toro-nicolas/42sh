/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the shell functions
*/
/**
 * @file shell.c
 * @brief The file containing the shell functions
 */

#include "../include/myshell.h"

/**
 * @brief Get the shell structure
 * @return <b>mysh_t *</b> The shell structure
 */
mysh_t *get_mysh(void)
{
    static mysh_t mysh = {0};

    return &mysh;
}

/**
 * @brief Initialize the shell structure
 * @param environ The environment variables
 * @return <b>mysh_t *</b> The shell structure
 */
mysh_t *init_shell(char **env)
{
    mysh_t *mysh = get_mysh();

    mysh->exit_status = 0;
    mysh->config_file = -1;
    mysh->env = my_malloc_strdup_word_array(env);
    update_path_list(mysh);
    return mysh;
}

/**
 * @brief Check if the shell is a tty and display the prompt if it is
* @return <b>void</b>
 */
void check_tty(void)
{
    if (isatty(0) == 1) {
        set_title();
        display_prompt();
    }
}

/**
 * @brief The shell loop
 * @param environ The environment variables
 * @return <b>void</b>
 */
void shell(char **env)
{
    mysh_t *mysh = init_shell(env);
    size_t size = 0;

    check_42shrc(mysh);
    check_path(mysh);
    create_history(mysh);
    while (1) {
        check_tty();
        if (my_getline(&mysh->line, stdin) == -1)
            my_exit(mysh, mysh->exit_status, NULL);
        if (mysh->line == NULL)
            continue;
        set_command_in_history(mysh, mysh->line);
        analyse_backticks(mysh, mysh->line);
        FREE(mysh->line);
    }
}
