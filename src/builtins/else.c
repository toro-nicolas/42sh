/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the else builtin
*/
/**
 * @file else.c
 * @brief The file containing the else builtin
 */

#include "../../include/myshell.h"

/**
 * @brief The else builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_else(mysh_t *mysh)
{
    size_t size = 0;
    char *line = NULL;

    while ((int)size != EOF && my_strcmp(line, "endif\n") != 0) {
        if (isatty(0) == 1)
            my_putstr("else? ");
        size = my_getline(&line, stdin);
        set_command_in_history(mysh, line);
    }
    if (my_strcmp(line, "endif\n") != 0) {
        my_putstr_error("else: endif not found.\n");
        return 1;
    }
    FREE(line);
    return 0;
}
