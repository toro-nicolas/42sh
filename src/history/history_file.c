/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the history_file functions
*/
/**
 * @file history_file.c
 * @brief The file containing the history_file functions
 */

#include "../../include/myshell.h"

/**
 * @brief Set the command in the history
 * @param mysh The shell structure
 * @param line The line to set in the history
 * @return <b>void</b>
 */
void set_command_in_history(mysh_t *mysh, char *line)
{
    char *buffer = NULL;
    size_t len = 0;

    while (getline(&buffer, &len, mysh->fd_history) != EOF) {
        if (buffer[my_strlen(buffer) - 1] == '\n')
            buffer[my_strlen(buffer) - 1] = '\0';
        if (buffer[0] != '\0')
            my_push_back_circled(&mysh->history, my_strdup(buffer), STRING);
    }
    FREE(buffer);
    fwrite(line, my_strlen(line), 1, mysh->fd_history);
    if (line != NULL && line[0] != '\0')
        my_push_back_circled(&mysh->history, my_strdup(line), STRING);
}

/**
 * @brief Create the history file
 * @param mysh The shell structure
 * @return <b>void</b>
 */
void create_history(mysh_t *mysh)
{
    char *home = get_env_var(mysh->env, "HOME");
    size_t len = 0;
    char *buffer = NULL;

    if (home == NULL)
        mysh->history_path = my_malloc_strdup("./.42sh_history");
    else {
        mysh->history_path = CALLOC(my_strlen(home) + 16, sizeof(char));
        my_strcat(mysh->history_path, home);
        my_strcat(mysh->history_path, "/.42sh_history\0");
    }
    mysh->fd_history = fopen(mysh->history_path, "a+");
    while (mysh->fd_history != NULL &&
    getline(&buffer, &len, mysh->fd_history) != EOF) {
        if (buffer[my_strlen(buffer) - 1] == '\n')
            buffer[my_strlen(buffer) - 1] = '\0';
        if (buffer[0] != '\0')
            my_push_back_circled(&mysh->history, my_strdup(buffer), STRING);
    }
    FREE(buffer);
}
