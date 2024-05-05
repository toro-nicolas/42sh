/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the repeat builtins
*/
/**
 * @file repeat.c
 * @brief The file containing the repeat builtins
 */

#include "../../include/myshell.h"

/**
 * @brief The repeat builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_repeat(mysh_t *mysh)
{
    int count = 0;
    pid_t child_pid = 0;
    input_command_t *input_command = NULL;

    if (mysh->args[1] == NULL || mysh->args[2] == NULL) {
        my_putstr_error("repeat: Too few arguments.\n");
        return 1;
    }
    count = my_super_number(mysh->args[1], (NB){0, 0, 0, 1});
    if (my_errno == 1) {
        my_putstr_error("repeat: Badly formed number.\n");
        return 1;
    }
    input_command = malloc(sizeof(input_command_t));
    input_command->args = &mysh->args[2];
    for (int index = 0; index < count; index++)
        command(mysh, input_command);
    return mysh->exit_status;
}
