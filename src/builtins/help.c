/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the help builtins
*/
/**
 * @file help.c
 * @brief The file containing the help builtins
 */

#include "../../include/myshell.h"

/**
 * @brief Print the help for the shell
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
static int print_help(mysh_t *mysh)
{
    if (mysh->args[1] == NULL || my_strcmp(mysh->args[1], "help") == 0) {
        my_printf("USAGE:\n\thelp [BUILTIN]\n");
        my_printf("\tDisplay information about builtin commands.\n");
        my_printf("BUILTIN:\n");
        my_printf("\tabout\n");
        my_printf("\tcd\n");
        my_printf("\tenv\n");
        my_printf("\texit\n");
        my_printf("\thelp\n");
        my_printf("\tsetenv\n");
        my_printf("\tsource\n");
        my_printf("\tunsetenv\n");
        return 1;
    }
    return 0;
}

/**
 * @brief Show the help for the cd builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
static int cd_help(mysh_t *mysh)
{
    if (my_strcmp(mysh->args[1], "cd") == 0) {
        my_printf("cd [OPTION]\n\tChange the shell working directory.\n");
        my_printf("OPTIONS:\n\t- : "
            "Change to the previous working directory.\n");
        my_printf("\t~ : Change to the home directory.\n");
        return 1;
    }
    return 0;
}

/**
 * @brief Show the help for the env builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
static int env_help(mysh_t *mysh)
{
    if (my_strcmp(mysh->args[1], "env") == 0) {
        my_printf("env\n\tPrint the environment variables.\n");
        return 1;
    }
    return 0;
}

/**
 * @brief Show the help for the setenv builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
static int setenv_help(mysh_t *mysh)
{
    if (my_strcmp(mysh->args[1], "setenv") == 0) {
        my_printf("setenv [VARIABLE] [VALUE]\n");
        my_printf("\tSet an environment variable.\n");
        return 1;
    }
    return 0;
}

/**
 * @brief Show the help for the unsetenv builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
static int unsetenv_help(mysh_t *mysh)
{
    if (my_strcmp(mysh->args[1], "unsetenv") == 0) {
        my_printf("unsetenv [VARIABLE]\n");
        my_printf("\tUnset an environment variable.\n");
        return 1;
    }
    return 0;
}

/**
 * @brief Show the help for the next builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
static int help_next(mysh_t *mysh)
{
    if (my_strcmp(mysh->args[1], "exit") == 0) {
        my_printf("exit\n\tExit the shell.\n");
        return 0;
    }
    if (my_strcmp(mysh->args[1], "source") == 0) {
        my_printf("source [FILE]\n\tExecute commands from a file.\n");
        return 0;
    }
    if (my_strcmp(mysh->args[1], "about") == 0) {
        my_printf("about\n\tDisplay information about the shell.\n");
        return 0;
    }
    my_fprintf(2, "help: %s: No such builtin.\n", mysh->args[1]);
    return 1;
}

/**
 * @brief The help builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_help(mysh_t *mysh)
{
    if (print_help(mysh))
        return 0;
    if (cd_help(mysh))
        return 0;
    if (env_help(mysh))
        return 0;
    if (setenv_help(mysh))
        return 0;
    if (unsetenv_help(mysh))
        return 0;
    return help_next(mysh);
}
