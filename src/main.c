/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** The main file of the project
*/
/**
 * @file main.c
 * @brief The main file of the project
 */

#include <termios.h>
#include "../include/myshell.h"

/**
 * @brief Show the usage of the shell
 * @return <b>int</b> Return <u>84</u>
 */
int show_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./42sh\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    42sh is a custom shell\n");
    my_putstr("    You can execute the help command to see");
    my_putstr(" the list of available builtins\n");
    return 84;
}

/**
 * @brief Check if the shell can be running and run it or execute the usage
 * @note The first function called when the program is launched
 * @param argc The number of arguments
 * @param argv The arguments
 * @param env The environment variables
 * @return <b>int</b> <u>0</u> if the shell is running,
 * <u>84</u> if the usage is executed
 */
int main(int argc, char **argv, char **env)
{
    struct termios saved_termios;

    if (argc != 1 &&
    (my_strcmp(argv[1], "-h") == 0 || my_strcmp(argv[1], "--help") == 0))
        return show_usage();
    if (argc != 1 && read_file_in_stdin(argv[1]))
        return 84;
    signal(SIGINT, &print_line);
    signal(SIGKILL, SIG_IGN);
    save_termios(&saved_termios);
    shell(env);
    restore_termios(&saved_termios);
    return 0;
}
