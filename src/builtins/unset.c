/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** unset
*/

#include "../../include/myshell.h"

/**
 * @brief Remove a variable from the variable list
 * @param mysh The shell structure
 * @param index The index of the variable to remove
 * @return <b>void</b>
 */
static void unset_variable(mysh_t *mysh, int index)
{
    for (node_t *tmp = mysh->variable_list; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(((variable_t *)tmp->data)->name,
        mysh->args[index]) == 0) {
            my_free_ptr(my_previous_to_next(&mysh->variable_list, tmp));
            return;
        }
    }
}

/**
 * @brief The unset builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_unset(mysh_t *mysh)
{
    if (mysh->args[1] == NULL) {
        my_putstr_error("unset: Too few arguments.\n");
        return 1;
    }
    for (int index = 0; mysh->args[index] != NULL; index++)
        unset_variable(mysh, index);
    return 0;
}
