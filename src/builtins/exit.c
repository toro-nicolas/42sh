/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the exit builtin
*/
/**
 * @file exit.c
 * @brief The file containing the exit builtin
 */

#include "../../include/myshell.h"

/**
 * @brief Free the input list
 * @param mysh The shell structure
 * @return <b>void</b>
 */
void free_input_list(mysh_t *mysh)
{
    if (mysh->input_list == NULL)
        return;
    for (int i = 0; mysh->input_list[i] != NULL; i++)
        my_free_array((void **)mysh->input_list[i]->args);
    my_free_array((void **)mysh->input_list);
    mysh->input_list = NULL;
}

/**
 * @brief Check if the exit command has a syntax error
 * @param mysh The shell structure
 * @return <b>int</b> <u>1</u> if the command has a syntax error,
 * <u>0</u> otherwise
 */
static int error_handling(mysh_t *mysh)
{
    if (my_char_is(mysh->args[1][0], "-0123456789") == 0 ||
    my_str_contains(mysh->args[1], "0123456789") == 0) {
        my_putstr_error("exit: Expression Syntax.\n");
        mysh->exit_status = 1;
        return 1;
    }
    if (my_errno != 0) {
        my_putstr_error("exit: Badly formed number.\n");
        mysh->exit_status = 1;
        return 1;
    }
    if (mysh->args[2] != NULL) {
        my_putstr_error("exit: Expression Syntax.\n");
        mysh->exit_status = 1;
        return 1;
    }
    return 0;
}

/**
 * @brief Free the shell structure and exit the shell
 * @param mysh The shell structure
 * @param status The exit status
 * @param message The message to display
 * @return <b>void</b>
 */
void my_exit(mysh_t *mysh, unsigned char status, char const *message)
{
    if (message != NULL && isatty(0) == 1)
        my_putstr_error(message);
    if (mysh != NULL) {
        close(mysh->config_file);
        FREE_WORD_ARRAY(mysh->path_list);
        FREE(mysh->old_pwd);
        FREE(mysh->line);
        FREE_WORD_ARRAY(mysh->multi_cmds);
        my_delete_list(&mysh->operators_cmds);
        my_delete_list(&mysh->operators_list);
        FREE_WORD_ARRAY(mysh->pipe_cmds);
        free_input_list(mysh);
        if (mysh->fd_history != NULL)
            fclose(mysh->fd_history);
        my_delete_circle_list(&mysh->history);
        my_delete_list(&mysh->alias_list);
        my_delete_list(&mysh->variable_list);
    }
    my_free();
    exit(status);
}

/**
 * @brief The exit builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> or the exit value if the command succeed,
 * <u>1</u> otherwise
 */
int exec_exit(mysh_t *mysh)
{
    int value = 0;

    if (mysh->args[1] != NULL) {
        value = my_super_number(mysh->args[1],
            (number_settings_t){0, 0, 0, 1});
        if (error_handling(mysh))
            return 1;
        free_input_list(mysh);
        my_exit(mysh, value, "exit\n");
        return value;
    }
    free_input_list(mysh);
    my_exit(mysh, value, "exit\n");
    return 0;
}
