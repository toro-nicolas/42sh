/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the pipes functions
*/
/**
 * @file pipes.c
 * @brief The file containing the pipes functions
 */

#include "../../include/myshell.h"
#include <sys/mman.h>

/**
 * @brief Check if the command contains an ambiguous command
 * @param mysh The shell structure
 * @return <b>int</b> <u>1</u> if an error occurred, <u>0</u> otherwise
 */
static int check_ambiguous_command(mysh_t *mysh)
{
    for (int index = 0; mysh->input_list[index] != NULL; index++) {
        if (index != 0 && mysh->input_list[index]->left_type != 0) {
            mysh->exit_status = 1;
            my_putstr_error("Ambiguous input redirect.\n");
            free_input_list(mysh);
            FREE_WORD_ARRAY(mysh->pipe_cmds);
            return 1;
        }
        if (mysh->pipe_cmds[index + 1] != NULL &&
        mysh->input_list[index]->right_type != 0) {
            mysh->exit_status = 1;
            my_putstr_error("Ambiguous output redirect.\n");
            free_input_list(mysh);
            FREE_WORD_ARRAY(mysh->pipe_cmds);
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Check if the command is a null command
 * @param mysh The shell structure
 * @param line The command line
 * @return <b>int</b> <u>1</u> if the command is a null command,
 * <u>0</u> otherwise
 */
static int check_null_command(mysh_t *mysh, char *line)
{
    for (int index = 0; line[index] != '\0' &&
    mysh->pipe_cmds[1] == NULL; index++) {
        if (line[index] == '|' && char_is_inhibited(line, index) == 0
        && char_is_paranthesed(line, index) == 0) {
            mysh->exit_status = 1;
            my_putstr_error("Invalid null command.\n");
            free_input_list(mysh);
            FREE_WORD_ARRAY(mysh->pipe_cmds);
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Check if the command contains a pipe or not
 * @param mysh The shell structure
 * @param line The command line
 * @return <b>int</b> <u>1</u> if the command doesn't contain a pipe
 * or only pipes, <u>0</u> if the command contains a pipe
 */
static int check_pipe(mysh_t *mysh, char *line)
{
    if (check_null_command(mysh, line))
        return 1;
    if (mysh->pipe_cmds[1] == NULL) {
        select_redirections(mysh, mysh->input_list[0]);
        free_input_list(mysh);
        FREE_WORD_ARRAY(mysh->pipe_cmds);
        return 1;
    }
    for (int index = 0; mysh->pipe_cmds[index] != NULL; index++) {
        if (my_str_is(mysh->pipe_cmds[index], " \t\n") || line[0] == '|') {
            mysh->exit_status = 1;
            my_putstr_error("Invalid null command.\n");
            free_input_list(mysh);
            FREE_WORD_ARRAY(mysh->pipe_cmds);
            return 1;
        }
    }
    return check_ambiguous_command(mysh);
}

/**
 * @brief Set the pipe list (input_list and pipe_cmds)
 * @param mysh The shell structure
 * @param line The command line
 * @return <b>void</b>
 */
int set_pipe_list(mysh_t *mysh, char *line)
{
    int index = 0;

    if (line == NULL || my_strcmp(line, "") == 0)
        return 1;
    mysh->pipe_cmds = array_separators(line, "|");
    mysh->input_list = malloc(sizeof(input_command_t *) *
    (my_array_len((void **) mysh->pipe_cmds) + 1));
    for (; mysh->pipe_cmds[index] != NULL; index++) {
        mysh->input_list[index] = get_input_command(mysh->pipe_cmds[index]);
        if (mysh->input_list[index] == NULL) {
            mysh->exit_status = 1;
            free_input_list(mysh);
            FREE_WORD_ARRAY(mysh->pipe_cmds);
            return 1;
        }
    }
    mysh->input_list[index] = NULL;
    return 0;
}

/**
 * @brief Execute the pipe
 * @param mysh The shell structure
 * @param line The command line
 * @param index The index of the command
 * @return <b>void</b>
 */
static void execute_pipe(mysh_t *mysh, char *line, int index)
{
    int fd[2];
    pid_t pid = 0;

    pipe(fd);
    pid = fork();
    if (pid == 0) {
        close(fd[0]);
        dup2(fd[1], 1);
        select_redirections(mysh, mysh->input_list[index]);
        my_exit(mysh, mysh->exit_status, NULL);
    } else {
        close(fd[1]);
        dup2(fd[0], 0);
    }
}

/**
 * @brief Analyse and execute the pipes
 * @param mysh The shell structure
 * @param line The command line
 * @return <b>void</b>
 */
void analyse_pipes(mysh_t *mysh, char *line)
{
    if (set_pipe_list(mysh, line) || check_pipe(mysh, line))
        return;
    mysh->saved_stdin = dup(0);
    mysh->saved_stdout = dup(1);
    for (int index = 0; mysh->pipe_cmds[index + 1] != NULL; index++)
        execute_pipe(mysh, line, index);
    select_redirections(mysh, mysh->input_list
    [my_array_len((void **)mysh->pipe_cmds) - 1]);
    dup2(mysh->saved_stdin, 0);
    dup2(mysh->saved_stdout, 1);
    free_input_list(mysh);
    FREE_WORD_ARRAY(mysh->pipe_cmds);
}
