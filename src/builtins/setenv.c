/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the setenv builtin
*/
/**
 * @file setenv.c
 * @brief The file containing the setenv builtin
 */

#include "../../include/myshell.h"

/**
 * @brief Check if a string is valid to be an environment variable
 * @param str The string to check
 * @return <b>int</b> <u>1</u> if the string is valid, <u>0</u> otherwise
 */
int my_str_is_valid(char const *str)
{
    if (my_strlen(str) == 0)
        return 1;
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] != '_' &&
        (str[i] < '0' || (str[i] > '9' && str[i] < 'A') ||
        (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z'))
            return 0;
    }
    return 1;
}

/**
 * @brief Display an error message if the variable name is invalid
 * @param var The variable name
 * @return <b>int</b> <u>1</u> if the variable name is invalid,
 * <u>0</u> otherwise
 */
static int error_handling(char *var)
{
    if (my_char_is_alpha(var[0]) == 0 && var[0] != '_') {
        my_fprintf(2, "setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    if (my_str_is_valid(var) == 0) {
        my_fprintf(2, "setenv: "
            "Variable name must contain alphanumeric characters.\n");
        return 1;
    }
    return 0;
}

/**
 * @brief Set a new environment variable
 * @param mysh The shell structure
 * @param var The variable name
 * @param value The variable value
 * @return <b>int</b> 0 if the command succeed, 1 otherwise
 */
int set_new_env_var(mysh_t *mysh, char *var, char *value)
{
    char **new_env = MALLOC(sizeof(char *) *
        (my_array_len((void **)mysh->env) + 2));
    int index = 0;

    if (error_handling(var))
        return 1;
    for (; mysh->env[index] != NULL; index++)
        new_env[index] = mysh->env[index];
    new_env[index] = CALLOC((my_strlen(var) +
        my_strlen(value) + 4), sizeof(char));
    new_env[index] = my_strcat(new_env[index], var);
    new_env[index] = my_strcat(new_env[index], "=");
    if (value != NULL)
        new_env[index] = my_strcat(new_env[index], value);
    new_env[index + 1] = NULL;
    mysh->env = new_env;
    update_path_list(mysh);
    return 0;
}

/**
 * @brief The setenv builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_setenv(mysh_t *mysh)
{
    if (mysh->args[1] == NULL)
        return exec_env(mysh);
    if (mysh->args[2] != NULL && mysh->args[3] != NULL) {
        my_fprintf(2, "setenv: Too many arguments.\n");
        return 1;
    }
    for (int index = 0; mysh->env[index] != NULL; index++) {
        if (my_strncmp(mysh->env[index], mysh->args[1],
        my_strlen(mysh->args[1])) == 0) {
            mysh->env[index] = CALLOC((my_strlen(mysh->args[1]) +
                my_strlen(mysh->args[2]) + 4), sizeof(char));
            my_strcat(mysh->env[index], mysh->args[1]);
            my_strcat(mysh->env[index], "=\0");
            my_strcat(mysh->env[index], mysh->args[2]);
            update_path_list(mysh);
            return 0;
        }
    }
    return set_new_env_var(mysh, mysh->args[1], mysh->args[2]);
}
