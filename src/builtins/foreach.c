/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the foreach builtin
*/
/**
 * @file foreach.c
 * @brief The file containing the foreach builtin
 */

#include "../../include/myshell.h"

/**
 * @brief Get the content of the variable
 * @param mysh The shell structure
 * @return <b>char **</b> The content of the variable
 */
char **get_variable_content(mysh_t *mysh)
{
    char *variables = NULL;
    char **variable_content = NULL;
    int size = 0;

    for (int index = 2; mysh->args[index] != NULL; index++)
        size += my_strlen(mysh->args[index]);
    variables = calloc(size, sizeof(char));
    my_strcpy(variables, mysh->args[2] + 1);
    for (int index = 3; mysh->args[index] != NULL; index++) {
        my_strcat(variables, mysh->args[index]);
        if (mysh->args[index + 1] != NULL)
            my_strcat(variables, " ");
    }
    variables[my_strlen(variables) - 1] = '\0';
    variable_content = STR2ARRAY_SEP(variables, " \t\n");
    free(variables);
    return variable_content;
}

/**
 * @brief Check if the foreach command is valid
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the variable is valid, <u>1</u> otherwise
 */
static int error_handling(mysh_t *mysh)
{
    if (mysh->args[1] == NULL || mysh->args[2] == NULL) {
        my_putstr_error("foreach: Too few arguments.\n");
        return 1;
    }
    if (is_valid_variable(mysh->args[1], "foreach") == 0)
        return 1;
    for (int index = 2; mysh->args[index] != NULL; index++) {
        if (my_str_contains(mysh->args[index], "(") == 0
        || my_str_contains(mysh->args[index], ")") == 0) {
            my_putstr_error("foreach: Words not parenthesized.\n");
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Read the content of the foreach
 * @param mysh The shell structure
 * @param command_list The list of commands
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
static int read_input(mysh_t *mysh, node_t **command_list)
{
    int size = 0;
    char *line = NULL;
    char **content = NULL;

    while (size != EOF && (content == NULL || my_strcmp(content[0], "end"))) {
        IS_ATTY_PRINT("foreach? ");
        free_str_and_tab(line, NULL);
        size = my_getline(&line, stdin);
        set_command_in_history(mysh, line);
        free_str_and_tab(NULL, content);
        content = str_to_array_inhibitors(line);
        if (line != NULL)
            my_push_back(command_list, my_strdup(line), STRING);
    }
    if (size == EOF || (content != NULL && my_strcmp(content[0], "end"))) {
        free_str_and_tab(line, content);
        return 1;
    }
    free_str_and_tab(line, content);
    return 0;
}

/**
 * @brief Execute the command
 * @param mysh The shell structure
 * @param command The command to execute
 * @return <b>void</b>
 */
void execute_command(mysh_t *mysh, char *command)
{
    pid_t pid = fork();

    if (pid == 0) {
        analyse_backticks(mysh, command);
        my_exit(mysh, mysh->exit_status, NULL);
    } else
        waitpid(pid, &mysh->exit_status, 0);
}

/**
 * @brief The foreach builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_foreach(mysh_t *mysh)
{
    char **variable_content = NULL;
    node_t *command_list = NULL;

    if (error_handling(mysh))
        return 1;
    variable_content = get_variable_content(mysh);
    if (read_input(mysh, &command_list)) {
        my_putstr_error("foreach: end not found.\n");
        FREE_WORD_ARRAY(variable_content);
        my_delete_list(&command_list);
        return 1;
    }
    for (int index = 0; variable_content[index] != NULL; index++) {
        add_variable(mysh, mysh->args[1], variable_content[index]);
        for (node_t *tmp = command_list; tmp && tmp->next; tmp = tmp->next)
            execute_command(mysh, (char *)tmp->data);
    }
    FREE_WORD_ARRAY(variable_content);
    my_delete_list(&command_list);
    return 0;
}
