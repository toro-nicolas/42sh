/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the endif builtin
*/
/**
 * @file endif.c
 * @brief The file containing the endif builtin
 */

#include "../../include/myshell.h"

/**
 * @brief The endif builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_endif(mysh_t *mysh)
{
    if (mysh->args[1] != NULL) {
        my_putstr_error("endif: Too many arguments.\n");
        return 1;
    }
    return 0;
}
