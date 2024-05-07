/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the command functions
*/
/**
 * @file command.c
 * @brief The file containing the command functions
 */

#include "../include/myshell.h"

/**
 * @brief Get the builtin command
 * @param index The index of the command
 * @return <b>builtin_t *</b> The builtin command selected
 */
builtin_t *get_builtin_command(int index)
{
    static builtin_t commands[] = {
        {"about", &exec_about}, {"alias", &exec_alias},
        {"cd", &exec_cd}, {"echo", &exec_echo},
        {"else", &exec_else}, {"end", &exec_end}, {"endif", &exec_endif},
        {"env", &exec_env}, {"exit", &exec_exit}, {"foreach", &exec_foreach},
        {"help", &exec_help}, {"history", &exec_history}, {"if", &exec_if},
        {"repeat", &exec_repeat}, {"set", &exec_set}, {"setenv", &exec_setenv},
        {"source", &exec_source}, {"unalias", &exec_unalias},
        {"unset", &exec_unset}, {"unsetenv", &exec_unsetenv},
        {"where", &exec_where}, {"which", &exec_which}, {NULL, &exec_command}
    };

    return &commands[index];
}

/**
 * @brief Get the path of the command
 * @param command The command
 * @param env The env
 * @return <b>char *</b> The path of the command
 */
static char *get_command_path(char *command, char **env)
{
    char *path = NULL;
    char **path_tab = my_str_to_word_array_select(
        get_env_var(env, "PATH"), ":");

    for (int index = 0; path_tab[index] != NULL; index++) {
        path = my_malloc(sizeof(char) * (my_strlen(path_tab[index]) +
            my_strlen(command) + 4), 1);
        path[0] = '\0';
        my_strcat(path, path_tab[index]);
        my_strcat(path, "/");
        my_strcat(path, command);
        if (access(path, X_OK) == 0) {
            FREE_WORD_ARRAY(path_tab);
            return path;
        }
    }
    FREE_WORD_ARRAY(path_tab);
    return NULL;
}

/**
 * @brief Display the error message
 * @param mysh The shell structure
 * @param command The command
 * @return <b>int</b> <u>1</u> if the command is invalid,
 * <u>0</u> otherwise
 */
static int display_error(mysh_t *mysh, char *command)
{
    struct stat file_info;

    if (access(mysh->args[0], F_OK) != 0) {
        my_fprintf(2, "%s: Command not found.\n", mysh->args[0]);
        return 1;
    }
    if (stat(mysh->args[0], &file_info) == -1) {
        my_fprintf(2, "%s: %s.\n", mysh->args[0], strerror(errno));
        return 1;
    }
    if (S_ISREG(file_info.st_mode) == 0 || access(mysh->args[0], X_OK) != 0) {
        my_fprintf(2, "%s: Permission denied.\n", mysh->args[0]);
        return 1;
    }
    return 0;
}

/**
 * @brief Check if the command exists
 * @param mysh The shell structure
 * @param command The command
 * @return <b>char *</b> The path of the command if it exists,
 * <u>NULL</u> otherwise
 */
char *check_command_exist(mysh_t *mysh, char *command)
{
    char *path = NULL;

    if (my_str_contains(mysh->args[0], "/") == 0)
        path = get_command_path(mysh->args[0], mysh->env);
    if (path == NULL) {
        if (my_str_contains(mysh->args[0], "/") == 0) {
            my_fprintf(2, "%s: Command not found.\n", mysh->args[0]);
            return NULL;
        }
        if (my_str_contains(mysh->args[0], "/") &&
            display_error(mysh, mysh->args[0]))
            return NULL;
        path = mysh->args[0];
    }
    return path;
}

/**
 * @brief Select the command to execute
 * @param mysh The shell structure
 * @return <b>void</b>
 */
void analyse_command(mysh_t *mysh)
{
    char **tmp = NULL;

    tmp = replace_alias_in_line(
        replace_history(mysh->args), &mysh->alias_list);
    if (tmp == NULL || tmp[0] == NULL)
        return;
    mysh->args = my_malloc_strdup_word_array(tmp);
    FREE(tmp);
    if (mysh->args == NULL || mysh->args[0] == NULL)
        return;
    for (int index = 0; get_builtin_command(index)->name != NULL; index++) {
        if (my_strcmp(mysh->args[0], get_builtin_command(index)->name) == 0) {
            mysh->exit_status =
                get_builtin_command(index)->builtin_function(mysh);
            return;
        }
    }
    mysh->exit_status = exec_command(mysh);
}

/**
 * @brief Execute the command
 * @param mysh The shell structure
 * @param input The input command
 * @return <b>void</b>
 */
void command(mysh_t *mysh, input_command_t *input)
{
    mysh->args = input->args;
    if (mysh->args == NULL || mysh->args[0] == NULL) {
        if (input->left_type != 0 || input->right_type != 0) {
            mysh->exit_status = 1;
            my_putstr_error("Invalid null command.\n");
        }
        if (my_strstr(input->command, "\"\"") != NULL ||
        my_strstr(input->command, "''") != NULL) {
            mysh->exit_status = 1;
            my_putstr_error(": Command not found.\n");
        }
        return;
    }
    analyse_command(mysh);
}
