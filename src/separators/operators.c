/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the operators functions
*/
/**
 * @file operators.c
 * @brief The file containing the operators functions
 */

#include "../../include/myshell.h"

/**
 * @brief Check if the command is invalid
 * @param mysh The shell structure
 * @param line The command line
 * @return <b>int</b> <u>1</u> if the command is invalid, <u>0</u> otherwise
 */
static int check_invalid_command(mysh_t *mysh, char *line)
{
    int ampersand = 0;
    int pipe = 0;

    for (int index = 0; line[index] != '\0'; index++) {
        if (ampersand > 2 || pipe > 2 || line[index] == '&' &&
        line[index + 1] == '|' && char_is_protected(line, index) == 0) {
            return 1;
        }
        if (line[index] == '&' && char_is_protected(line, index) == 0)
            ampersand++;
        if (line[index] == '|' && char_is_protected(line, index) == 0)
            pipe++;
        if (line[index] != '&' && line[index] != '|' && line[index] != ' '
        && line[index] != '\t' && line[index] != '\n') {
            ampersand = 0;
            pipe = 0;
        }
    }
    return 0;
}

/**
 * @brief Execute the operators
 * @param mysh The shell structure
 * @return <b>void</b>
 */
static void execute_operators(mysh_t *mysh)
{
    node_t *operator = NULL;
    int skip = 0;

    for (; mysh->operators_cmds != NULL;) {
        analyse_pipes(mysh, mysh->operators_cmds->data);
        FREE(mysh->operators_cmds->data);
        my_free_ptr(my_pop_front(&mysh->operators_cmds));
        operator = my_pop_front(&mysh->operators_list);
        while (operator != NULL && ((my_strcmp(operator->data, "&&") == 0 &&
        (mysh->exit_status != 0 || skip)) ||
        (my_strcmp(operator->data, "||") == 0 && mysh->exit_status == 0))) {
            FREE(operator);
            my_free_ptr(my_pop_front(&mysh->operators_cmds));
            operator = my_pop_front(&mysh->operators_list);
            skip = 1;
        }
        skip = 0;
    }
}

/**
 * @brief Push the line in the commands and operators lists
 * @param mysh The shell structure
 * @param line The line to push
 * @param backup The backup of the line
 * @return <b>int</b> <u>1</u> if the line has been pushed, <u>0</u> otherwise
 */
static int push_line(mysh_t *mysh, char **line, char *backup)
{
    if (find_valid_str(*line, "&&") != NULL &&
    (find_valid_str(*line, "&&") < find_valid_str(*line, "||")
    || find_valid_str(*line, "||") == NULL)) {
        my_push_back(&mysh->operators_cmds,
            my_strndup(*line, my_strstr(*line, "&&") - *line), STRING);
        my_push_back(&mysh->operators_list, "&&", STRING);
        *line = find_valid_str(*line, "&&") + 2;
        return 1;
    }
    if (find_valid_str(*line, "||") != NULL &&
    (find_valid_str(*line, "||") < find_valid_str(*line, "&&")
    || find_valid_str(*line, "&&") == NULL)) {
        my_push_back(&mysh->operators_cmds,
            my_strndup(*line, my_strstr(*line, "||") - *line), STRING);
        my_push_back(&mysh->operators_list, "||", STRING);
        *line = find_valid_str(*line, "||") + 2;
        return 1;
    }
    return 0;
}

/**
 * @brief Analyse the operators and execute the commands
 * @param mysh The shell structure
 * @param line The command line
 * @return <b>void</b>
 */
void analyse_operators(mysh_t *mysh, char *line)
{
    char *backup = line;

    mysh->operators_cmds = NULL;
    mysh->operators_list = NULL;
    if (check_invalid_command(mysh, line)) {
        mysh->exit_status = 1;
        my_putstr_error("Invalid null command.\n");
        return;
    }
    while (find_valid_str(line, "&&") != NULL ||
    find_valid_str(line, "||") != NULL) {
        if (push_line(mysh, &line, backup))
            continue;
    }
    my_push_back(&mysh->operators_cmds, my_strdup(line), STRING);
    execute_operators(mysh);
    my_delete_list(&mysh->operators_cmds);
    my_delete_list(&mysh->operators_list);
}
