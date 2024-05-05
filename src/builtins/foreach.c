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

static void read_input(mysh_t *mysh, node_t **command_list)
{
    size_t size = 0;
    char *line = NULL;

    while ((int)size != EOF && my_strcmp(line, "end\n") != 0) {
        if (isatty(0) == 1)
            my_putstr("foreach? ");
        size = my_getline(&line, stdin);
        set_command_in_history(mysh, line);
        if (line != NULL)
            my_push_back(command_list, my_strdup(line), STRING);
    }
    FREE(line);
}

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
    read_input(mysh, &command_list);
    if (my_pop_node(&command_list, "end\n", my_strcmp) == NULL) {
        my_putstr_error("foreach: end not found.\n");
        return 1;
    }
    for (int index = 0; variable_content[index] != NULL; index++) {
        add_variable(mysh, mysh->args[1], variable_content[index]);
        for (node_t *tmp = command_list; tmp != NULL; tmp = tmp->next)
            execute_command(mysh, (char *)tmp->data);
    }
    FREE_WORD_ARRAY(variable_content);
    my_delete_list(&command_list);
    return 0;
}
