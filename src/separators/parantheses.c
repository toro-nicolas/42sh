/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The parantheses.c
*/
/**
 * @file parantheses.c
 * @brief The parantheses.c
 * @author Nicolas TORO
 */

#include "../../include/myshell.h"

/**
 * @brief Check if the command contains parantheses
 * @param mysh The shell structure
 * @param input The input command structure
 * @return <b>int</b> <u>0</u> if the command contains parantheses,
 * <u>1</u> otherwise
 */
static int check_no_parantheses(mysh_t *mysh, input_command_t *input)
{
    if (my_str_contains(input->command, "()") == 0) {
        input->args = str_to_array_inhibitors(input->command);
        command(mysh, input);
        return 1;
    }
    for (int index = 0; input->command[index] != '\0'; index++) {
        if (my_char_is(input->command[index], "()") &&
        char_is_inhibited(input->command, index) == 0)
            return 0;
    }
    input->args = str_to_array_inhibitors(input->command);
    command(mysh, input);
    return 1;
}

/**
 * @brief Check if the command contains if and foreach
 * @param mysh The shell structure
 * @param input The input command structure
 * @return <b>int</b> <u>1</u> if the command contains if and foreach,
 * <u>0</u> otherwise
 */
static int check_if_and_foreach(mysh_t *mysh, input_command_t *input)
{
    int index = 0;

    for (; input->command[index] != '\0' &&
    my_char_is_alpha(input->command[index]) == 0; index++);
    if (input->command[index] == '\0')
        return 0;
    if ((my_strncmp(&input->command[index], "if", 2) == 0 &&
    my_char_is(input->command[index + 2], "( \t")) ||
    (my_strncmp(&input->command[index], "foreach", 7) == 0 &&
    my_char_is(input->command[index + 7], "( \t"))) {
        input->args = str_to_array_inhibitors(input->command);
        command(mysh, input);
        return 1;
    }
    return 0;
}

/**
 * @brief Check if there are too many parantheses
 * @param mysh The shell structure
 * @param command The command to check
 * @return <b>int</b> <u>1</u> if there are too many parantheses,
 * <u>0</u> otherwise
 */
static int check_too_many(mysh_t *mysh, char *command)
{
    if (my_count_letter(command, '(') > my_count_letter(command, ')')) {
        my_fprintf(2, "Too many ('s.\n");
        mysh->exit_status = 1;
        return 1;
    }
    if (my_count_letter(command, '(') < my_count_letter(command, ')')) {
        my_fprintf(2, "Too many )'s.\n");
        mysh->exit_status = 1;
        return 1;
    }
    for (int index = my_get_char_index(command, ')', 1);
    command[index] != '\0'; index++) {
        if (command[index] == '(') {
            my_fprintf(2, "Too many )'s.\n");
            mysh->exit_status = 1;
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Check if the parantheses are badly placed
 * @param mysh The shell structure
 * @param command The command to check
 * @return <b>int</b> <u>1</u> if the parantheses are badly placed,
 * <u>0</u> otherwise
 */
static int check_badly_placed(mysh_t *mysh, char *command)
{
    int count = 0;

    for (int index = 0; command[index] != '\0'; index++) {
        if (my_char_is(command[index], " \t\n")
        && char_is_inhibited(command, index) == 0)
            continue;
        if (index != 0 && command[index - 1] == '(')
            count++;
        if (command[index] == ')')
            count--;
        if (count != 0 || my_char_is(command[index], "()"))
            continue;
        my_fprintf(2, "Badly placed ()'s.\n");
        mysh->exit_status = 1;
        return 1;
    }
    return 0;
}

/**
 * @brief Check if the command is null
 * @param mysh The shell structure
 * @param command The command to check
 * @return <b>int</b> <u>1</u> if the command is null, <u>0</u> otherwise
 */
static int check_null_command(mysh_t *mysh, char *command)
{
    for (int index = 0; command[index] != '\0'; index++) {
        if (my_char_is(command[index], " \t\n()")
        && char_is_inhibited(command, index) == 0)
            continue;
        return 0;
    }
    my_fprintf(2, "Invalid null command.\n");
    mysh->exit_status = 1;
    return 1;
}

/**
 * @brief Get the command between the parantheses
 * @param command The command to check
 * @return <b>char *</b> The command between the parantheses
 */
static char *get_command(char *command)
{
    char *new_command = NULL;
    int nb_letters = 0;
    int count = 0;

    for (int index = 0; command[index] != '\0'; index++) {
        if (index != 0 && command[index - 1] == '(')
            count++;
        if (command[index] == ')')
            count--;
        if (my_char_is(command[index], "()") && count == 0)
            continue;
        if (count != 0)
            nb_letters++;
    }
    new_command = my_strndup(my_strstr(command, "(") + 1, nb_letters);
    return new_command;
}

/**
 * @brief Analyse the parantheses
 * @param mysh The shell structure
 * @param input The input command structure
 * @return <b>void</b>
 */
void analyse_parantheses(mysh_t *mysh, input_command_t *input)
{
    pid_t pid = 0;
    char *command = NULL;

    if (check_no_parantheses(mysh, input) || check_if_and_foreach(mysh, input)
    || check_too_many(mysh, input->command) ||
    check_badly_placed(mysh, input->command) ||
    check_null_command(mysh, input->command))
        return;
    command = get_command(input->command);
    pid = fork();
    if (pid == 0) {
        analyse_multi_commands(mysh, command);
        my_exit(mysh, mysh->exit_status, NULL);
    }
    FREE(command);
    waitpid(pid, &mysh->exit_status, 0);
}
