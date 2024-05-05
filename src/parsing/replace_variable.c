/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the replace_variable functions
*/
/**
 * @file replace_variable.c
 * @brief The file containing the replace_variable functions
 */

#include "../../include/myshell.h"

/**
 * @brief Find the first valid variable in a string
 * @param line The string
 * @return <b>char *</b> The variable
 */
static char *find_valid_variable(char *line)
{
    while (my_strstr(line, "$") != NULL) {
        if (*(my_strstr(line, "$") + 1) == '\0' ||
        my_char_is(*(my_strstr(line, "$") + 1), " \t\n")) {
            line = my_strstr(line, "$") + 1;
            continue;
        }
        return my_strstr(line, "$");
    }
    return NULL;
}

/**
 * @brief Display an error message
 * @param variable The variable
 * @param type The type of error
 * @return <b>int</b> The exit status
 */
static int display_error(char *variable, int type)
{
    if (type == 1) {
        my_fprintf(2, "Illegal variable name.\n");
        return -1;
    }
    if (type == 2) {
        my_fprintf(2, "Missing '}'.\n");
        return -1;
    }
    my_fprintf(2, "%s: Undefined variable.\n", variable);
    FREE(variable);
    return 1;
}

/**
 * @brief Get the value of a variable
 * @param mysh The shell structure
 * @param variable The variable
 * @param value The value
 * @return <b>int</b> The exit status
 */
static int get_variables_value(mysh_t *mysh, char *variable, char **value)
{
    char *tmp = NULL;

    for (node_t *node = mysh->variable_list; node; node = node->next) {
        if (my_strcmp(((variable_t *)node->data)->name, variable) == 0) {
            *value = ((variable_t *)node->data)->value;
            return 1;
        }
    }
    tmp = get_env_var(mysh->env, variable);
    if (tmp != NULL) {
        *value = tmp;
        return 1;
    }
    return 0;
}

/**
 * @brief Get the new line
 * @param line The line
 * @param value The value
 * @param nb_letters The number of letters
 * @return <b>char *</b> The new line
 */
static char *get_new_line(char **line, char *value, int *nb_letters)
{
    char *new_line = NULL;

    new_line = calloc(find_valid_variable(*line) - *line +
        my_strlen(value) + my_strlen(&((*line)[find_valid_variable(*line)
        - *line + 1 + *nb_letters])) + 2, sizeof(char));
    my_strncpy(new_line, *line,
        find_valid_variable(*line) - *line);
    my_strcat(new_line, value);
    my_strcat(new_line, &((*line)[find_valid_variable(*line)
        - *line + *nb_letters + 1]));
    FREE(*line);
    *nb_letters = 0;
    return new_line;
}

/**
 * @brief Clear the variable
 * @param variable The variable
 * @return <b>char *</b> The cleared variable
 */
char *clear_var(char *variable)
{
    char *tmp = variable;

    if (variable[0] && variable[0] == '{') {
        tmp = my_strdup(&variable[1]);
        FREE(variable);
    }
    if (tmp[my_strlen(tmp) - 1] == '}')
        tmp[my_strlen(tmp) - 1] = '\0';
    return tmp;
}

/**
 * @brief Count the number of letters in a variable
 * @param line The line
 * @return <b>int</b> The number of letters
 */
static int count_letter(char *line)
{
    int nb_letters = 0;
    int bracket = 0;
    int index = find_valid_variable(line) - line + 1;

    for (; my_char_is_alpha(line[index]) || my_char_is_num(line[index]) ||
    my_char_is(line[index], "_{}?"); index++) {
        nb_letters++;
        if (line[index] == '}')
            break;
        if (line[index] == '{')
            bracket = 1;
    }
    if ((bracket && nb_letters < 2) || my_count_letter(line, '{') > 1
    || (line[index] == '}' && bracket && nb_letters == 2) ||
    (nb_letters == 1 && line[index] == '}'))
        return display_error(NULL, 1);
    if (bracket && line[index] != '}')
        return display_error(NULL, 2);
    return nb_letters;
}

/**
 * @brief Change the line
 * @param mysh The shell structure
 * @param line The line
 * @return <b>int</b> The exit status
 */
static int change_line(mysh_t *mysh, char **line)
{
    char *variable = NULL;
    int nb_letters = 0;
    char *value = NULL;

    if (find_valid_variable(*line) == NULL)
        return 0;
    while (find_valid_variable(*line) != NULL) {
        nb_letters = count_letter(*line);
        if (nb_letters == -1)
            return 1;
        variable = clear_var(my_strndup(find_valid_variable(*line) + 1,
        nb_letters));
        if (get_variables_value(mysh, variable, &value) == 0)
            return display_error(variable, 3);
        FREE(variable);
        *line = get_new_line(line, value, &nb_letters);
    }
    return 0;
}

/**
 * @brief Replace the variables in the command arguments
 * @param mysh The shell structure
 * @return <b>int/b> The new command arguments
 */
int replace_variables(mysh_t *mysh)
{
    char *exit_status = NULL;

    if (my_str_contains(mysh->line, "$") == 0)
        return 0;
    exit_status = my_str_nbr(mysh->exit_status);
    add_variable(mysh, "?", my_malloc_strdup(exit_status));
    FREE(exit_status);
    if (change_line(mysh, &mysh->line)) {
        mysh->exit_status = 1;
        return 1;
    }
    return 0;
}
