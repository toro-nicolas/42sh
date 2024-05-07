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
    int size = 0;
    char *line = NULL;
    char **content = NULL;

    while (size != -1 && (content == NULL || my_strcmp(content[0], "endif"))) {
        IS_ATTY_PRINT("else? ");
        free_str_and_tab(line, NULL);
        size = my_getline(&line, stdin);
        set_command_in_history(mysh, line);
        free_str_and_tab(NULL, content);
        content = str_to_array_inhibitors(line);
    }
    if (size == EOF || (content != NULL && my_strcmp(content[0], "endif"))) {
        my_putstr_error("else: endif not found.\n");
        free_str_and_tab(line, content);
        return 1;
    }
    free_str_and_tab(line, content);
    return 0;
}
