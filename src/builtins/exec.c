/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the exec functions
*/
/**
 * @file exec.c
 * @brief The file containing the exec functions
 */

#include "../../include/myshell.h"

/**
 * @brief Check if errno is a ENOEXEC error
 * @return <b>void</b>
 */
static void check_errno(void)
{
    if (errno == ENOEXEC) {
        my_putstr_error(" Wrong Architecture.\n");
    } else {
        my_putstr_error("\n");
    }
}

/**
 * @brief Execute the command in the child process
 * @param args The arguments of the command
 * @param path The path of the command
 * @param env The environment
 */
static void do_child(char **args, char *path, char **env)
{
    if (args == NULL)
        exit(1);
    if (execve(path, args, env) == -1) {
        my_fprintf(2, "%s: %s.", path, strerror(errno));
        check_errno();
        exit(errno);
    }
    exit(0);
}

/**
 * @brief Execute the command
 * @param path The path of the command
 * @param args The arguments of the command
 * @param env The env
 * @return <b>int</b> The status of the command
 */
static int execute(char *path, char **args, char **env)
{
    int status = 0;
    pid_t pid = fork();

    if (pid == -1) {
        my_fprintf(2, "fork: %s.\n", strerror(errno));
        return 1;
    }
    if (pid == 0)
        do_child(args, path, env);
    waitpid(pid, &status, 0);
    status_handler(status);
    return WEXITSTATUS(status);
}

/**
 * @brief Execute the command
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_command(mysh_t *mysh)
{
    char *path = NULL;
    char **tmp = NULL;

    if (mysh->args[0] == NULL)
        return 1;
    tmp = globbing(mysh->args);
    if (tmp == NULL || tmp[0] == NULL)
        return 1;
    mysh->args = my_malloc_strdup_word_array(tmp);
    FREE(tmp);
    path = check_command_exist(mysh, mysh->args[0]);
    if (path == NULL)
        return 1;
    return execute(path, mysh->args, mysh->env);
}
