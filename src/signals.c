/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the signals functions
*/
/**
 * @file signals.c
 * @brief The file containing the signals functions
 */

#include "../include/myshell.h"

/**
 * @brief Display the signal returned by executing a command
 * @param signal The signal
 * @return <b>void</b>
 */
void status_handler(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == 8)
            my_putstr("Floating exception");
        else
            my_putstr(strsignal(WTERMSIG(status)));
        if (WCOREDUMP(status))
            my_putstr(" (core dumped)\n");
        else
            my_putstr("\n");
    }
}

/**
 * @brief Display the prompt when the SIGINT signal is received
 * @param signal The signal
 * @return <b>void</b>
 */
void print_line(int signal)
{
    my_putchar('\n');
    check_tty();
}

/**
 * @brief Display "exit" when the a CRTL+D is received
 * @note I disabled it because it didn't work
 * @param signal The signal
 * @return <b>void</b>
 */
void print_exit(int signal)
{
    my_putstr("exit\n");
}
