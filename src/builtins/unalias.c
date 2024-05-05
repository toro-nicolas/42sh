/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** The file containing the unalias builtin
*/
/**
 * @file unalias.c
 * @brief The file containing the unalias builtin
 */

#include "../../include/myshell.h"

/**
 * @brief Remove an alias from the alias list
 * @param mysh The shell structure
 * @param index The index of the alias to remove
 * @return <b>void</b>
 */
static void unlink_alias(mysh_t *mysh, int index)
{
    for (node_t *tmp = mysh->alias_list; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(((alias_t *)tmp->data)->name, mysh->args[index]) == 0) {
            my_free_ptr(my_previous_to_next(&mysh->alias_list, tmp));
            return;
        }
    }
}

/**
 * @brief The unalias builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_unalias(mysh_t *mysh)
{
    if (mysh->args[1] == NULL) {
        my_putstr_error("unalias: Too few arguments.\n");
        return 1;
    }
    for (int index = 1; mysh->args[index] != NULL; index++)
        unlink_alias(mysh, index);
    return 0;
}
