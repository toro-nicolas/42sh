/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the unsetenv builtin
*/
/**
 * @file unsetenv.c
 * @brief The file containing the unsetenv builtin
 */

#include "../../include/myshell.h"

/**
 * @brief Skip the variables to delete
 * @param args The command arguments
 * @param env The actual env
 * @param index The index of the env
 * @return <b>void</b>
 */
static void skip_variables(char **args, char **env, int *index)
{
    for (int var_index = 1; args[var_index] != NULL && env[*index] != NULL;
    var_index++) {
        if (my_strncmp(env[*index], args[var_index],
        my_strlen(args[var_index])) == 0
        && env[*index][my_strlen(args[var_index])] == '=')
            (*index)++;
    }
}

/**
 * @brief Search and delete the variable in the env
 * @param args The command arguments
 * @param env The actual env
 * @param new_env The new env
 * @return <b>void</b>
 */
static void search_and_delete(char **args, char **env, char **new_env)
{
    int index_new = 0;

    for (int index = 0; env[index] != NULL; index++) {
        skip_variables(args, env, &index);
        new_env[index_new] = env[index];
        index_new++;
        if (env[index] == NULL)
            break;
    }
    new_env[index_new] = NULL;
}

/**
 * @brief The unsetenv builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_unsetenv(mysh_t *mysh)
{
    char **new_env;

    if (mysh->args[1] == NULL) {
        my_fprintf(2, "unsetenv: Too few arguments.\n");
        return 1;
    }
    new_env = CALLOC(my_array_len((void **)mysh->env) + 1, sizeof(char *));
    search_and_delete(mysh->args, mysh->env, new_env);
    mysh->env = new_env;
    return 0;
}
