/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the redirections functions
*/
/**
 * @file redirections.c
 * @brief The file containing the redirections functions
 */

#include "../../include/myshell.h"

/**
 * @brief Browse the command line to get the redirection path
 * @param line The command line
 * @return <b>char *</b> The redirection path
 */
char *get_redirection_path(char *line)
{
    char *path = CALLOC(my_strlen(line), sizeof(char));
    int start = 0;

    for (int index = 0; line[index] != '\0'; index++) {
        if (line[index] == '<' || line[index] == '>' || line[index] == '|')
            return path;
        if (start > 0 && (line[index] == ' ' || line[index] == '\t' ||
            line[index] == '\n'))
            return path;
        if (line[index] != ' ' && line[index] != '\t' && line[index] != '\n') {
            path[start] = line[index];
            start++;
        }
    }
    return path;
}

/**
 * @brief Display the error message when the name is missing
 * @param mysh The shell structure
 * @param commands The command line
 * @return <b>int</b> Always <u>1</u>
 */
int missing_name(mysh_t *mysh, char **commands)
{
    mysh->exit_status = 1;
    my_putstr_error("Missing name for redirect.\n");
    FREE_WORD_ARRAY(commands);
    return 1;
}

/**
 * @brief Analyse and execute the good redirection
 * @param mysh The shell structure
 * @param input The input command
 * @return <b>void</b>
 */
void select_redirections(mysh_t *mysh, input_command_t *input)
{
    if (input->right_type != 0)
        return exec_right_redirection(mysh, input);
    if (input->left_type == 1)
        return exec_left_simple_redirection(mysh, input);
    if (input->left_type == 2)
        return exec_left_double_redirection(mysh, input);
    return analyse_parentheses(mysh, input);
}
