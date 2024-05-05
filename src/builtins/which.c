/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the which builtin
*/
/**
 * @file which.c
 * @brief The file containing the which builtin
 */

#include "../../include/myshell.h"

/**
 * @brief Check if the command is a builtin and print it
 * @param command The command to check
 * @return <b>int</b> <u>1</u> if the command is a builtin,
 * <u>0</u> otherwise
 */
static int is_builtin(char *command)
{
    for (int index = 0; get_builtin_command(index)->name != NULL; index++) {
        if (my_strcmp(command, get_builtin_command(index)->name) == 0) {
            my_printf("%s: shell built-in command.\n", command);
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Check if the command is aliased and print it
 * @param mysh The shell structure
 * @param command The command to check
 * @return <b>int</b> <u>1</u> if the command is aliased, <u>0</u> otherwise
 */
static int is_aliased(mysh_t *mysh, char *command)
{
    for (node_t *tmp = mysh->alias_list; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(((alias_t *)tmp->data)->name, command) == 0) {
            my_printf("%s: \t aliased to %s\n", command,
                ((alias_t *) tmp->data)->value);
            return 1;
        }
    }
    return 0;
}

/**
 * @biref Check if the command exist and print it
 * @param mysh The shell structure
 * @param i The index of the command
 * @return <b>int</b> <u>1</u> if the command is exist,
 * <u>0</u> otherwise
 */
static int check_command(mysh_t *mysh, int i)
{
    char *path = NULL;

    for (int j = 0; mysh->path_list[j] != NULL; j++) {
        path = CALLOC(my_strlen(mysh->path_list[j]) +
            my_strlen(mysh->args[i]) + 4, sizeof(char));
        my_strcat(path, mysh->path_list[j]);
        my_strcat(path, "/");
        my_strcat(path, mysh->args[i]);
        if (access(path, X_OK) == 0) {
            my_printf("%s\n", path);
            return 1;
        }
        if (my_str_contains(mysh->args[i], "/") &&
        access(mysh->args[i], X_OK) == 0) {
            my_printf("%s\n", mysh->args[i]);
            return 1;
        }
    }
    return 0;
}

/**
 * @brief The which builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_which(mysh_t *mysh)
{
    if (mysh->args[1] == NULL) {
        my_putstr_error("which: Too few arguments.\n");
        return 1;
    }
    mysh->exit_status = 0;
    for (int index = 1; mysh->args[index] != NULL; index++) {
        if (is_aliased(mysh, mysh->args[index])
        || is_builtin(mysh->args[index]))
            continue;
        if (mysh->path_list == NULL || mysh->path_list[0] == NULL) {
            my_printf("%s: Command not found.\n", mysh->args[index]);
            mysh->exit_status = 1;
            continue;
        }
        if (check_command(mysh, index))
            continue;
        my_printf("%s: Command not found.\n", mysh->args[index]);
        mysh->exit_status = 1;
    }
    return mysh->exit_status;
}
