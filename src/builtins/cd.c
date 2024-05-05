/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the cd builtin
*/
/**
 * @file cd.c
 * @brief The file containing the cd builtin
 */

#include "../../include/myshell.h"

/**
 * @brief Check if the cd command is a cd ~ and execute it
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed,
 * <u>1</u> if the command failed and <u>-1</u> if the command is not a cd ~
 */
int cd_home(mysh_t *mysh)
{
    char *path;

    if (mysh->args[1] == NULL ||
    (my_strcmp(mysh->args[1], "~") == 0 && mysh->args[2] != NULL)) {
        path = get_env_var(mysh->env, "HOME");
        if (path == NULL) {
            my_fprintf(2, "cd: No home directory.\n");
            return 1;
        }
        if (mysh->old_pwd != NULL)
            FREE(mysh->old_pwd);
        mysh->old_pwd = getcwd(NULL, 0);
        if (chdir(path) == -1) {
            my_fprintf(2, "%s: %s.\n", path, strerror(errno));
            return 1;
        }
        return 0;
    }
    return -1;
}

/**
 * @brief Check if the cd command is a cd - and execute it
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed,
 * <u>1</u> if the command failed and <u>-1</u> if the command is not a cd -
 */
int cd_back(mysh_t *mysh)
{
    if (mysh->args[1] != NULL &&
    mysh->args[1][0] == '-' && mysh->args[1][1] == '\0') {
        if (mysh->old_pwd == NULL) {
            my_fprintf(2, ": No such file or directory.\n");
            return 1;
        }
        if (chdir(mysh->old_pwd) == -1) {
            my_fprintf(2, "%s: %s.\n", mysh->old_pwd, strerror(errno));
            return 1;
        }
        if (mysh->old_pwd != NULL)
            FREE(mysh->old_pwd);
        mysh->old_pwd = getcwd(NULL, 0);
        replace_env_var(mysh->env, "OLDPWD", mysh->old_pwd);
        return 0;
    }
    return -1;
}

/**
 * @brief The cd builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_cd(mysh_t *mysh)
{
    int home = cd_home(mysh);
    int back = cd_back(mysh);

    if (home != -1)
        return home;
    if (mysh->args[2] != NULL) {
        my_fprintf(2, "cd: Too many arguments.\n");
        return 1;
    }
    if (back != -1)
        return back;
    if (mysh->old_pwd != NULL)
        FREE(mysh->old_pwd);
    mysh->old_pwd = getcwd(NULL, 0);
    if (chdir(mysh->args[1]) == -1) {
        my_fprintf(2, "%s: %s.\n", mysh->args[1], strerror(errno));
        return 1;
    }
    return 0;
}
