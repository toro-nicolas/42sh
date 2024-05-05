/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the echo builtin
*/
/**
 * @file echo.c
 * @brief The file containing the echo builtin
 */

#include "../../include/myshell.h"

/**
 * @brief The echo builtin
 * @param mysh The shell structure
 * @return <b>int</b> The exit status of the echo command
 */
int exec_echo(mysh_t *mysh)
{
    char **tmp = globbing(mysh->args);
    int index = 1;

    if (tmp == NULL || tmp[0] == NULL)
        return 1;
    mysh->args = my_malloc_strdup_word_array(tmp);
    FREE(tmp);
    if (mysh->args[1] != NULL && my_strcmp(mysh->args[1], "-n") == 0)
        index = 2;
    for (; mysh->args[index] != NULL; index++) {
        my_putstr(mysh->args[index]);
        if (mysh->args[index + 1] != NULL)
            my_putchar(' ');
    }
    if (mysh->args[1] == NULL || my_strcmp(mysh->args[1], "-n") != 0)
        my_putchar('\n');
    return 0;
}
