/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the 42shrc functions
*/
/**
 * @file config_file.c
 * @brief The file containing the 42shrc functions
 */

#include "../include/myshell.h"

/**
 * @brief Create the 42shrc file
 * @param mysh The shell structure
 * @param path The path of the file
 * @return <b>void</b>
 */
static void create_42shrc(mysh_t *mysh, char *path)
{
    char *var = my_malloc_strdup("MYSH");
    char *str = "#42sh configuration file\n\n#42sh created by:\n#\t"
        "Arthur WARIN\n#\tChristophe VANDEVOIR\n#\tGianni TUERO\n#\t"
        "Nicolas TORO\n#\tRaphael ROSSIGNOL\n\n#ALIAS\n\n#PATH\n\n#COMMAND\n";

    mysh->config_file = open(path, O_CREAT | O_RDWR, 0664);
    write(mysh->config_file, str, my_strlen(str));
    set_new_env_var(mysh, var, path);
}

/**
 * @brief Check if the 42shrc file exists in the home directory
 * and create it if it doesn't
 * @param mysh The shell structure
 * @return <b>void</b>
 */
void check_42shrc(mysh_t *mysh)
{
    char *home = get_env_var(mysh->env, "HOME");
    char *path;
    struct stat file_infos;

    if (home == NULL)
        path = my_malloc_strdup("./.42shrc");
    else {
        path = CALLOC(my_strlen(home) + 11, sizeof(char));
        my_strcat(path, home);
        my_strcat(path, "/.42shrc");
    }
    mysh->config_file = open(path, O_RDWR);
    if (mysh->config_file == -1 || stat(path, &file_infos) == -1)
        create_42shrc(mysh, path);
    else
        execute_bash_file(mysh, mysh->config_file, file_infos.st_size);
}
