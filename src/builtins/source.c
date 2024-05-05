/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the source builtin
*/
/**
 * @file source.c
 * @brief The file containing the source builtin
 */

#include "../../include/myshell.h"

/**
 * @brief Execute a bash file
 * @param mysh The shell structure
 * @param file The file descriptor
 * @param size The size of the file
 * @return <b>int</b> The exit status of last command if the command succeed,
 * <u>1</u> otherwise
 */
int execute_bash_file(mysh_t *mysh, int file, size_t size)
{
    char **file_content = NULL;
    char *buffer = CALLOC(size + 1, sizeof(char));
    pid_t pid = 0;

    if (read(file, buffer, size) == -1)
        return 1;
    pid = fork();
    if (pid == 0) {
        file_content = my_str_to_word_array_select(buffer, "\n");
        for (int i = 0; file_content[i] != NULL; i++) {
            remove_comments(file_content[i]);
            analyse_backticks(mysh, file_content[i]);
        }
        FREE_WORD_ARRAY(file_content);
        my_exit(mysh, mysh->exit_status, "");
    }
    waitpid(pid, &mysh->exit_status, 0);
    return mysh->exit_status;
}

/**
 * @brief The source builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_source(mysh_t *mysh)
{
    struct stat file_infos;
    int file;

    if (mysh->args[1] == NULL) {
        my_fprintf(2, "source: Too few arguments.\n");
        return 1;
    }
    file = open(mysh->args[1], O_RDONLY);
    if (file == -1 || stat(mysh->args[1], &file_infos) == -1) {
        my_fprintf(2, "%s: %s.\n", mysh->args[1], strerror(errno));
        return 1;
    }
    return execute_bash_file(mysh, file, file_infos.st_size);
}
