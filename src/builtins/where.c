/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the where builtin
*/
/**
 * @file where.c
 * @brief The file containing the where builtin
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
            my_printf("%s is a shell built-in\n", command);
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
            my_printf("%s is aliased to %s\n", command,
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
    int find = 0;

    for (int j = 0; mysh->path_list[j] != NULL; j++) {
        path = CALLOC(my_strlen(mysh->path_list[j]) +
            my_strlen(mysh->args[i]) + 4, sizeof(char));
        my_strcat(path, mysh->path_list[j]);
        my_strcat(path, "/");
        my_strcat(path, mysh->args[i]);
        if (access(path, F_OK | X_OK) == 0) {
            my_printf("%s\n", path);
            find = 1;
        }
    }
    return find;
}

/**
 * @brief The where builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_where(mysh_t *mysh)
{
    int find = 0;

    if (mysh->args[1] == NULL) {
        my_putstr_error("where: Too few arguments.\n");
        return 1;
    }
    mysh->exit_status = 0;
    for (int index = 1; mysh->args[index] != NULL; index++) {
        if (my_str_contains(mysh->args[index], "/")) {
            my_printf("where: / in command makes no sense\n",
                mysh->args[index]);
            mysh->exit_status = 1;
            continue;
        }
        find += is_aliased(mysh, mysh->args[index]) +
            is_builtin(mysh->args[index]) + check_command(mysh, index);
        if (find == 0)
            mysh->exit_status = 1;
    }
    return mysh->exit_status;
}
