/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the input_command functions
*/
/**
 * @file input_command.c
 * @brief The file containing the input_command functions
 */

#include "../../include/myshell.h"

/**
 * @brief Initialize the input command
 * @param command The command
 * @return <b>input_command_t *</b> The input command
 */
input_command_t *init_input_command(char *command)
{
    input_command_t *input_command = malloc(sizeof(input_command_t));

    input_command->command = CALLOC(my_strlen(command) + 1, sizeof(char));
    input_command->args = NULL;
    input_command->left = NULL;
    input_command->right = NULL;
    input_command->left_type = 0;
    input_command->right_type = 0;
    input_command->current = input_command->command;
    return input_command;
}

/**
 * @brief Check if there is an error in the input command
 * @param input_command The input command
 * @param command The command
 * @param index The index
 * @param inhibitors The inhibitors
 * @return <b>int</b> <u>1</u> if there is an error, <u>0</u> otherwise
 */
static int check_error(input_command_t *input_command,
    const char *command, int index, int inhibitors)
{
    if (input_command->right_type != 0 &&
    inhibitors == 0 && command[index] == '>') {
        if (input_command->right[0] == '\0')
            my_putstr_error("Missing name for redirect.\n");
        else
            my_putstr_error("Ambiguous output redirect.\n");
        return 1;
    }
    if (input_command->left_type != 0 &&
    inhibitors == 0 && command[index] == '<') {
        if (input_command->left[0] == '\0')
            my_putstr_error("Missing name for redirect.\n");
        else
            my_putstr_error("Ambiguous input redirect.\n");
        return 1;
    }
    return 0;
}

/**
 * @brief Check if the character is a right redirection and
 * change the input structure
 * @param input_command The input command
 * @param command The command
 * @param index The index
 * @return <b>int</b> <u>1</u> if the character is a right redirection,
 * <u>0</u> otherwise
 */
static int right_redirection(input_command_t *input_command,
    char *command, int *index)
{
    if (command[*index] == '>' && command[*index + 1] == '>') {
        input_command->right_type = 2;
        input_command->right = CALLOC(my_strlen(command), sizeof(char));
        input_command->current = input_command->right;
        (*index)++;
        return 1;
    }
    if (command[*index] == '>') {
        input_command->right_type = 1;
        input_command->right = CALLOC(my_strlen(command), sizeof(char));
        input_command->current = input_command->right;
        return 1;
    }
    return 0;
}

/**
 * @brief Check if the character is a left redirection and
 * change the input structure
 * @param input_command The input command
 * @param command The command
 * @param index The index
 * @return <b>int</b> <u>1</u> if the character is a left redirection,
 * <u>0</u> otherwise
 */
static int left_redirection(input_command_t *input_command,
    char *command, int *index)
{
    if (command[*index] == '<' && command[*index + 1] == '<') {
        input_command->left_type = 2;
        input_command->left = CALLOC(my_strlen(command), sizeof(char));
        input_command->current = input_command->left;
        (*index)++;
        return 1;
    }
    if (command[*index] == '<') {
        input_command->left_type = 1;
        input_command->left = CALLOC(my_strlen(command), sizeof(char));
        input_command->current = input_command->left;
        return 1;
    }
    return 0;
}

/**
 * @brief Add a character to the input command
 * @param input_command The input command
 * @param command The command
 * @param index The index
 * @param inhibitors The inhibitors
 * @return <b>int</b> The start value
 */
static int add_char_to_input(input_command_t *input_command,
    char *command, int *index, char *inhibitors)
{
    static int start = 1;

    if (*inhibitors == 0 &&
    (right_redirection(input_command, command, index) ||
    left_redirection(input_command, command, index))) {
        start = 1;
        return -1;
    }
    if (input_command->current == input_command->command ||
    (*inhibitors != 0 && *inhibitors != command[*index]) ||
    my_char_is(command[*index], " \t\n\"\'\\()") == 0 || *inhibitors == 1) {
        my_add_chr(input_command->current, command[*index]);
        start = 0;
        return -1;
    }
    if (*inhibitors != 0)
        return -1;
    return start;
}

/**
 * @brief Update the inhibitors
 * @param command The command
 * @param index The index
 * @param inhibitors The inhibitors
 * @param end_inhibitors The end inhibitors
 * @return <b>void</b>
 */
static int update_inhibitors(char *command, int index,
    char *inhibitors)
{
    if ((*inhibitors != 0 && *inhibitors == command[index]
    && *inhibitors != '\\') || (*inhibitors == '(' && command[index] == ')')) {
        *inhibitors = 0;
        return 1;
    }
    if (*inhibitors == '\\') {
        *inhibitors = 1;
        return 0;
    }
    if (*inhibitors == 0 && my_char_is(command[index], "\'\"\\(")) {
        *inhibitors = command[index];
        return 1;
    }
    return 0;
}

/**
 * @brief Validate the input command
 * @param input_command The input command
 * @param inhibitors The inhibitors
 * @return <b>input_command_t *</b> The input command if it is valid,
 * <u>NULL</u> otherwise
 */
input_command_t *validate_input_command(input_command_t *input_command,
    char inhibitors)
{
    if (inhibitors != 0 && inhibitors != 1) {
        my_fprintf(2, "Unmatched '%c'.\n", inhibitors);
        return NULL;
    }
    return input_command;
}

/**
 * @brief Get the input command
 * @param command The command
 * @return <b>input_command_t *</b> The input command
 */
input_command_t *get_input_command(char *command)
{
    input_command_t *input_command = init_input_command(command);
    char inhibitors = 0;

    while (command[0] == ' ' || command[0] == '\t' || command[0] == '\n')
        command++;
    for (int index = 0; command[index] != '\0'; index++) {
        if (update_inhibitors(command, index, &inhibitors)
        && input_command->current != input_command->command)
            continue;
        if (check_error(input_command, command, index, inhibitors) == 1)
            return NULL;
        if (!add_char_to_input(input_command, command, &index, &inhibitors))
            input_command->current = input_command->command;
        if (inhibitors == 1)
            inhibitors = 0;
    }
    return validate_input_command(input_command, inhibitors);
}

/**
 * @brief Display the input command
 * @note The function is used for debugging
 * @param input_command The input command
 * @return <b>void</b>
 */
void display_input_command(input_command_t *input_command)
{
    if (input_command == NULL)
        return;
    my_printf("Command: %s\n", input_command->command);
    my_printf("Left: %s\n", input_command->left);
    my_printf("Right: %s\n", input_command->right);
    my_printf("Left type: %d\n", input_command->left_type);
    my_printf("Right type: %d\n", input_command->right_type);
    my_printf("Args: %S", input_command->args);
}
