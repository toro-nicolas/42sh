/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the git_repository functions for the prompt
*/
/**
 * @file git_repository.c
 * @brief The file containing the git_repository functions for the prompt
 */

#include "../../include/myshell.h"

/**
 * @brief Display the current branch
 * @return <b>void</b>
 */
static void current_branch(void)
{
    char *buff;
    char **tab;
    struct stat st;
    int fd = open(".git/HEAD", O_RDONLY);

    if (fd == -1)
        return;
    stat(".git/HEAD", &st);
    buff = malloc(sizeof(char) * (st.st_size + 1));
    read(fd, buff, st.st_size);
    buff[st.st_size] = '\0';
    tab = my_str_to_word_array_select(buff, "/: \n");
    my_printf("\033[1m\033[32m%s\033[0m", tab[3]);
    free(buff);
    my_free_array((void *)tab);
    close(fd);
}

/**
 * @brief Check if we are in a git repository and display the branch
 * @return <b>void</b>
 */
void is_git_repository(void)
{
    if (access(".git", X_OK) == 0) {
        my_printf("\033[32m 🐱\033[0m");
        current_branch();
    }
}
