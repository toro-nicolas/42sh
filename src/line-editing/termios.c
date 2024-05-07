/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the termios functions
*/
/**
 * @file termios.c
 * @brief The file containing the termios functions
 */

#include "../../include/myshell.h"

/**
 * @brief Save terminal attributes
 * @param saved_termios The termios structure to save the terminal attributes
 * @return <b>void</b>
 */
void save_termios(struct termios *saved_termios)
{
    tcgetattr(STDIN_FILENO, saved_termios);
}

/**
 * @brief Restore terminal attributes
 * @param saved_termios The termios structure to restore the
 * terminal attributes
 * @return <b>void</b>
 */
void restore_termios(struct termios *saved_termios)
{
    tcsetattr(STDIN_FILENO, TCSANOW, saved_termios);
}

/**
 * @brief Disable the buffer
 * @note We'll need to disable the buffer when we want to my_getline
 * @return <b>int</b> <u>0</u> if the buffer is disabled, <u>-1</u> otherwise
 */
int disable_buffer(void)
{
    struct termios term;

    if (tcgetattr(STDIN_FILENO, &term) == -1)
        return -1;
    term.c_lflag &= ~(ICANON | ECHO);
    term.c_cc[VMIN] = 1;
    term.c_cc[VTIME] = 0;
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &term) == -1)
        return -1;
    return 0;
}
