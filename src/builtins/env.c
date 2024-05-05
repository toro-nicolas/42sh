/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the env builtin
*/
/**
 * @file env.c
 * @brief The file containing the env builtin
 */

#include "../../include/myshell.h"

/**
 * @brief The env builtin
 * @note If there is no argument, it will display the environment,
 * else it will execute the command with the environment
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, return the exit value
 * of the env command if the command failed
 */
int exec_env(mysh_t *mysh)
{
    if (mysh->args[1] != NULL) {
        return exec_command(mysh);
    }
    my_show_word_array(mysh->env);
    return 0;
}
