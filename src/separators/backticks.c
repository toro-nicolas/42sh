/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the backticks functions
*/
/**
 * @file backticks.c
 * @brief The file containing the backticks functions
 */

#include "../../include/myshell.h"

/**
 * @brief Check if the backticks are matched
 * @param mysh The shell structure
 * @param line The command line
 * @return <b>int</b> <u>-1</u> if the backticks are not matched,
 * the number of commands in backticks otherwise
 */
int check_unmatched(mysh_t *mysh, char *line)
{
    int count = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '`' && (i == 0 || line[i - 1] != '\\' ||
            (line[i - 1] == '\\' && char_is_inhibited(line, i - 1) == 0)))
            count++;
    }
    if (count % 2 != 0) {
        my_putstr_error("Unmatched '`'.\n");
        mysh->exit_status = 1;
        return -1;
    }
    return count / 2;
}

/**
 * @brief Execute the child process for backticks
 * @param mysh The shell structure
 * @param line The command line to execute
 * @param fd The file descriptor for the pipe
 * @return <b>void</b>
 */
static void child_process(mysh_t *mysh, char *line, int fd[2])
{
    dup2(fd[1], 1);
    close(fd[0]);
    close(fd[1]);
    analyse_multi_commands(mysh, line);
    my_exit(mysh, mysh->exit_status, NULL);
}

/**
 * @brief Execute the parent process for backticks
 * @param mysh The shell structure
 * @param command The result of the command
 * @param fd The file descriptor for the pipe
 * @param pid The process id
 * @return <b>void</b>
 */
static void parent_process(mysh_t *mysh, char **command, int fd[2], pid_t pid)
{
    int nb_bytes = 0;

    close(fd[1]);
    waitpid(pid, &mysh->exit_status, 0);
    nb_bytes = read(fd[0], *command, 1024);
    while (nb_bytes == 1024) {
        *command = realloc(*command,
            sizeof(char) * (1024 + my_strlen(*command)));
        nb_bytes = read(fd[0], *command + my_strlen(*command), 1024);
    }
    close(fd[0]);
}

/**
 * @brief Execute the command in backticks
 * @param mysh The shell structure
 * @param line The command line to execute
 * @return <b>char *</b> The result of the command
 */
char *exec_command_in_backticks(mysh_t *mysh, char *line)
{
    int fd[2];
    pid_t pid;
    char *command = calloc(1024, sizeof(char));

    line[my_get_char_index(line, '`', 1)] = '\0';
    mysh->saved_stdout = dup(1);
    pipe(fd);
    pid = fork();
    if (pid == 0)
        child_process(mysh, line, fd);
    else
        parent_process(mysh, &command, fd, pid);
    FREE(line);
    return command;
}

/**
 * @brief Set the new command line without backticks
 * @param mysh The shell structure
 * @param line The command line
 * @param new_line The new command line
 * @return <b>void</b>
 */
static void set_new_command_line(mysh_t *mysh, char *line, char **new_line)
{
    char *command = exec_command_in_backticks(mysh,
        my_strdup(line + my_get_char_index(line, '`', 1) + 1));

    my_replace_char(command, '\n', ' ');
    for (int index = my_strlen(command) - 1; index >= 0; index--) {
        if (my_char_is(command[index], " \t\n"))
            command[index] = '\0';
        else
            break;
    }
    *new_line = calloc(my_get_char_index(line, '`', 1) + strlen(command) +
        my_strlen(line + my_get_char_index(line, '`', 2)) + 2, sizeof(char));
    my_strncpy(*new_line, line, my_get_char_index(line, '`', 1));
    my_strcat(*new_line, command);
    my_strcat(*new_line, line + my_get_char_index(line, '`', 2) + 1);
    FREE(command);
}

/**
 * @brief Analyse and execute backticks commands
 * @param mysh The shell structure
 * @param line The command line
 * @return <b>void</b>
 */
void analyse_backticks(mysh_t *mysh, char *line)
{
    char *new_line = NULL;
    int nb_cmds = check_unmatched(mysh, line);
    char *backup = my_strdup(line);

    if (nb_cmds == -1)
        return;
    FREE(mysh->line);
    mysh->line = backup;
    for (int i = 0; i < nb_cmds; i++) {
        set_new_command_line(mysh, mysh->line, &new_line);
        FREE(mysh->line);
        mysh->line = new_line;
    }
    if (replace_variables(mysh) || check_tilde(mysh))
        return;
    analyse_multi_commands(mysh, mysh->line);
}
