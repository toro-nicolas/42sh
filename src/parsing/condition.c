/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the condition functions
*/
/**
 * @file condition.c
 * @brief The file containing the condition functions
 */

#include "../../include/myshell.h"

/**
 * @brief The child process who execute the command to get the result
 * @param fd The pipe file descriptor
 * @return <b>void</b>
 */
static void child_process(int *fd)
{
    static char *command[] = {"bc", "-l", NULL};

    close(fd[1]);
    dup2(fd[0], 0);
    get_mysh()->args = command;
    exec_command(get_mysh());
    my_exit(get_mysh(), get_mysh()->exit_status, NULL);
}

/**
 * @brief Read the result of the operation
 * @param new_fd The pipe file descriptor to read
 * @param pid The pid of the child process
 * @param str The string to calculate
 * @param saved_stdout The saved stdout
 * @return <b>char *</b> The result of the operation
 */
static char *read_result(int *new_fd, pid_t pid, char *str, int saved_stdout)
{
    char *result = calloc(1024, sizeof(char));
    int nb_bytes = 0;
    int status = 0;

    waitpid(pid, &status, 0);
    if (status != 0)
        return NULL;
    nb_bytes = read(new_fd[0], result, 1024);
    if (nb_bytes == -1)
        my_fprintf(2, "%s\n", strerror(errno));
    while (nb_bytes == 1024) {
        result = realloc(result, sizeof(char) * (1024 + my_strlen(result)));
        nb_bytes = read(new_fd[0], result + my_strlen(result), 1024);
    }
    result[my_strlen(result) - 1] = '\0';
    dup2(saved_stdout, 1);
    close(saved_stdout);
    return result;
}

/**
 * @brief Get the result of an operation
 * @param str The string to calculate
 * @return <b>char *</b> The result of the string
 */
static char *get_result(char *str)
{
    int fd[2] = {0};
    int new_fd[2] = {0};
    pid_t pid = 0;
    int saved_stdout = dup(1);

    pipe(new_fd);
    dup2(new_fd[1], 1);
    close(new_fd[1]);
    pipe(fd);
    pid = fork();
    if (pid == 0)
        child_process(fd);
    close(fd[0]);
    my_fprintf(fd[1], "%s\n", str);
    close(fd[1]);
    return read_result(new_fd, pid, str, saved_stdout);
}

/**
 * @brief Get the condition result from a string
 * @param str The string to calculate
 * @return <b>int</b> The result of the condition : 0 if false, 1 if true
 * and -1 if an error occurred
 */
int get_condition(char *str)
{
    char *result = get_result(str);
    int nb = 0;

    if (result == NULL) {
        my_fprintf(2, "if: Expression Syntax.\n");
        return -1;
    }
    nb = my_super_number(result, (NB){0, 0, 0, 1});
    FREE(result);
    if (my_errno) {
        my_fprintf(2, "if: Expression Syntax.\n");
        return -1;
    }
    if (nb == 0)
        return 0;
    return 1;
}
