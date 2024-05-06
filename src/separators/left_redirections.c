/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the left redirections functions
*/
/**
 * @file left_redirections.c
 * @brief The file containing the left redirections functions
 */

#include "../../include/myshell.h"

/**
 * @brief Error handling for the left double redirection
 * @param mysh The shell structure
 * @param input The input command
 * @return <b>int</b> <u>1</u> if an error occurred, <u>0</u> otherwise
 */
static int error_handling(mysh_t *mysh, input_command_t *input)
{
    if (input->left[0] == '\0') {
        my_fprintf(2, "Missing name for redirect.\n");
        mysh->exit_status = 1;
        return 1;
    }
    if (input->command[0] == '\0') {
        my_fprintf(2, "Invalid null command.\n");
        mysh->exit_status = 1;
        return 1;
    }
    return 0;
}

/**
 * @brief Execute the child process of the left double redirection
 * @param mysh The shell structure
 * @param input The input command
 * @param fd The file descriptor
 * @return <b>void</b>
 */
static void child_process(mysh_t *mysh, input_command_t *input, int fd[2])
{
    close(fd[1]);
    dup2(fd[0], 0);
    analyse_parentheses(mysh, input);
    my_exit(mysh, mysh->exit_status, "");
}

/**
 * @brief Read the input of the left double redirection and push it in a node
 * @param mysh The shell structure
 * @param input The input command
 * @param node The node
 * @return <b>void</b>
 */
static void read_input(mysh_t *mysh, input_command_t *input, node_t **node)
{
    size_t size = 0;
    char *line = NULL;

    while ((int)size != EOF && my_strcmp(line, input->left) != 0) {
        if (line != NULL)
            my_push_back(node, my_strdup(line), STRING);
        if (isatty(0) == 1)
            my_putstr("? ");
        size = my_getline(&line, stdin);
        set_command_in_history(mysh, line);
    }
    FREE(line);
}

/**
 * @brief Execute the left double redirection
 * @param mysh The shell structure
 * @param input The input command
 * @return <b>void</b>
 */
void exec_left_double_redirection(mysh_t *mysh, input_command_t *input)
{
    node_t *node = NULL;
    int fd[2] = {0};
    pid_t pid = 0;

    if (error_handling(mysh, input))
        return;
    my_add_chr(input->left, '\n');
    pipe(fd);
    pid = fork();
    if (pid == 0) {
        child_process(mysh, input, fd);
    } else {
        close(fd[0]);
        read_input(mysh, input, &node);
        for (node_t *tmp = node; tmp != NULL; tmp = tmp->next)
            my_fprintf(fd[1], "%s", tmp->data);
        my_delete_list(&node);
        close(fd[1]);
        waitpid(pid, &mysh->exit_status, 0);
    }
}

/**
 * @brief Execute the left simple redirection
 * @param mysh The shell structure
 * @param input The input command
 * @return <b>void</b>
 */
void exec_left_simple_redirection(mysh_t *mysh, input_command_t *input)
{
    int fd;

    if (input->left[0] == '\0') {
        my_fprintf(2, "Missing name for redirect.\n");
        mysh->exit_status = 1;
        return;
    }
    fd = open(input->left, O_RDONLY);
    if (fd == -1) {
        mysh->exit_status = 1;
        my_fprintf(2, "%s: %s.\n", input->left, strerror(errno));
        return;
    }
    mysh->saved_stdin = dup(0);
    dup2(fd, 0);
    close(fd);
    analyse_parentheses(mysh, input);
    dup2(mysh->saved_stdin, 0);
    close(mysh->saved_stdin);
}
