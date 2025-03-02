/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the environnement functions
*/
/**
 * @file environnement.c
 * @brief The file containing the environnement functions
 */

#include "../include/myshell.h"

/**
 * @brief Set a new environment variable
 * @param mysh The shell structure
 * @param name The name of the variable
 * @param value The value of the variable
 * @return <b>void</b>
 */
static char *var_to_str(char *var, int start)
{
    for (int index = start; var[index] != '\0'; index++) {
        if (var[index] == '=')
            return &var[index + 1];
    }
    return NULL;
}

/**
 * @brief Get an environment variable
 * @param env The environment
 * @param var The variable to get
 * @return <b>char *</b> The value of the variable
 */
char *get_env_var(char **env, char *var)
{
    for (int index = 0; env[index] != NULL; index++) {
        if (my_strncmp(env[index], var, my_strlen(var)) == 0)
            return var_to_str(env[index], my_strlen(var));
    }
    return NULL;
}

/**
 * @brief Replace an environment variable
 * @param env The environment
 * @param name The name of the variable
 * @param value The new value
 * @return <b>void</b>
 */
void replace_env_var(char **env, char *name, char *value)
{
    for (int index = 0; env[index] != NULL; index++) {
        if (my_strncmp(env[index], name, my_strlen(name)) == 0
            && env[index][my_strlen(name)] == '=') {
            env[index] = value;
            return;
        }
    }
}

/**
 * @brief Check if the PATH is set in the environment and set it if not
 * @param mysh The shell structure
 * @return <b>void</b>
 */
void check_path(mysh_t *mysh)
{
    char *path = my_malloc_strdup(get_env_var(mysh->env, "PATH"));

    if (path == NULL)
        add_variable(mysh, "path", "/usr/bin /bin");
    else {
        my_replace_char(path, ':', ' ');
        add_variable(mysh, "path", path);
    }
}

/**
 * @brief Update the path list
 * @param mysh The shell structure
 * @return <b>void</b>
 */
void update_path_list(mysh_t *mysh)
{
    if (get_env_var(mysh->env, "PATH") == NULL)
        return;
    FREE_WORD_ARRAY(mysh->path_list);
    mysh->path_list = my_str_to_word_array_select(
        get_env_var(mysh->env, "PATH"), ":");
}
