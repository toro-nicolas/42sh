/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the scripting functions
*/
/**
 * @file scripting.c
 * @brief The file containing the scripting functions
 */

#include "../include/myshell.h"

/**
 * @brief Remove the comments from a line
 * @param line The line
 * @return <b>void</b>
 */
void remove_comments(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '#') {
            line[i] = '\0';
            return;
        }
    }
}

/**
 * @brief Get the content of a file
 * @param file The file path
 * @param fd The file descriptor
 * @return <b>char **</b> The content of the file line by line,
 * <u>NULL</u> if an error occured
 */
static char **get_file_content(char *file, int *fd)
{
    struct stat file_info;
    char *line = NULL;
    char **file_content = NULL;

    *fd = open(file, O_RDONLY);
    if (*fd == -1 || stat(file, &file_info) == -1) {
        my_fprintf(2, "%s: %s\n", file, strerror(errno));
        return NULL;
    }
    line = calloc(file_info.st_size + 1, sizeof(char));
    if (read(*fd, line, file_info.st_size) == -1) {
        my_fprintf(2, "%s: %s\n", file, strerror(errno));
        return NULL;
    }
    file_content = STR2ARRAY_SEP(line, "\n");
    FREE(line);
    return file_content;
}

/**
 * @brief The instructions for the child process
 * (write right command line in pipe)
 * @param pipe_fd The pipe file descriptor
 * @param file_content The content of the file
 * @return <b>void</b>
 */
static void child_process(int pipe_fd[2], char **file_content)
{
    close(pipe_fd[0]);
    for (int index = 0; file_content[index] != NULL; index++) {
        remove_comments(file_content[index]);
        if (file_content[index][0] != '\0')
            my_fprintf(pipe_fd[1], "%s\n", file_content[index]);
    }
    close(pipe_fd[1]);
    exit(0);
}

/**
 * @brief Read a file and execute the commands in it
 * @param file The file path
 * @return <b>int</b> <u>0</u> if success, <u>1</u> if an error occurred
 */
int read_file_in_stdin(char *file)
{
    int fd = 0;
    char **file_content = get_file_content(file, &fd);
    int pipe_fd[2] = {0};
    pid_t pid = 0;

    if (file_content == NULL)
        return 1;
    pipe(pipe_fd);
    pid = fork();
    if (pid == 0) {
        child_process(pipe_fd, file_content);
    } else {
        close(pipe_fd[1]);
        dup2(pipe_fd[0], 0);
        waitpid(pid, NULL, 0);
    }
    FREE_WORD_ARRAY(file_content);
    close(fd);
    return 0;
}
