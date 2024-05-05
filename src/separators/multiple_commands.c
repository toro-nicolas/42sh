/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the multiple_commands functions
*/
/**
 * @file multiple_commands.c
 * @brief The file containing the multiple_commands functions
 */

#include "../../include/myshell.h"

/**
 * @brief Analyse and execute multiple commands
 * @param mysh The shell structure
 * @param line The command line
 * @return <b>void</b>
 */
void analyse_multi_commands(mysh_t *mysh, char *line)
{
    mysh->multi_cmds = array_separators(line, ";");
    for (int index = 0; mysh->multi_cmds[index] != NULL; index++) {
        analyse_operators(mysh, mysh->multi_cmds[index]);
    }
    FREE_WORD_ARRAY(mysh->multi_cmds);
    mysh->multi_cmds = NULL;
    mysh->pipe_cmds = NULL;
}
