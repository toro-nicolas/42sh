/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the right redirections functions
*/
/**
 * @file right_redirections.c
 * @brief The file containing the right redirections functions
 */

#include "../../include/myshell.h"

/**
 * @brief Get the file descriptor
 * @param mysh The shell structure
 * @param input The input command
 * @return <b>int</b> The file descriptor
 */
static int get_file_descriptor(mysh_t *mysh, input_command_t *input)
{
    int fd;

    if (input->right[0] == '\0') {
        my_fprintf(2, "Missing name for redirect.\n");
        mysh->exit_status = 1;
        return -1;
    }
    fd = open(input->right, O_WRONLY | O_CREAT |
        ((input->right_type == 2) ? O_APPEND : O_TRUNC), 0644);
    if (fd == -1) {
        mysh->exit_status = 1;
        my_fprintf(2, "%s: %s.\n", input->right, strerror(errno));
    }
    return fd;
}

/**
 * @brief Execute the right redirection
 * @param mysh The shell structure
 * @param input The input command
 * @return <b>void</b>
 */
void exec_right_redirection(mysh_t *mysh, input_command_t *input)
{
    int fd = get_file_descriptor(mysh, input);

    if (fd == -1)
        return;
    mysh->saved_stdout = dup(1);
    dup2(fd, 1);
    close(fd);
    if (input->left_type == 1)
        exec_left_simple_redirection(mysh, input);
    else if (input->left_type == 2)
        exec_left_double_redirection(mysh, input);
    else
        analyse_parentheses(mysh, input);
    dup2(mysh->saved_stdout, 1);
    close(mysh->saved_stdout);
}
