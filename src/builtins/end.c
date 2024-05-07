/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the end builtin
*/
/**
 * @file end.c
 * @brief The file containing the end builtin
 */

#include "../../include/myshell.h"

/**
 * @brief The end builtin
 * @param mysh The shell structure
 * @return <b>int</b> Always <u>1</u>
 */
int exec_end(mysh_t *mysh)
{
    if (mysh->args[1] != NULL) {
        my_putstr_error("end: Too many arguments.\n");
        return 1;
    }
    my_putstr_error("end: Not in while/foreach.\n");
    return 1;
}
