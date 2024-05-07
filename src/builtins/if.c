/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the if builtin
*/
/**
 * @file if.c
 * @brief The file containing the if builtin
 */

#include "../../include/myshell.h"

/**
 * @brief Execute the commands specified when the condition is true
 * @param mysh The shell structure
 * @param args The command arguments
 * @param start The index of the start of the command arguments
 */
static int exec_true_condition(mysh_t *mysh, char **args, int start)
{
    pid_t pid = 0;
    int size = 0;
    char *command = NULL;

    for (int index = start; args[index] != NULL; index++)
        size += my_strlen(args[index]) + 1;
    command = calloc(size, sizeof(char));
    for (int index = start; args[index] != NULL; index++) {
        my_strcat(command, args[index]);
        if (args[index + 1] != NULL)
            my_strcat(command, " ");
    }
    pid = fork();
    if (pid == 0) {
        analyse_backticks(mysh, command);
        my_exit(mysh, mysh->exit_status, NULL);
    }
    waitpid(pid, &mysh->exit_status, 0);
    FREE(command);
    return mysh->exit_status;
}

/**
 * @brief Read the input of the user when the condition is false
 * @param mysh The shell structure
 * @return <b>char **</b> The command arguments
 */
static char **read_input(mysh_t *mysh)
{
    int size = 0;
    char *line = NULL;
    char **content = NULL;

    while (size != EOF && (content == NULL ||
    (my_strcmp(content[0], "endif") && my_strcmp(content[0], "else")))) {
        IS_ATTY_PRINT("if? ");
        free_str_and_tab(line, NULL);
        size = my_getline(&line, stdin);
        set_command_in_history(mysh, line);
        free_str_and_tab(NULL, content);
        content = str_to_array_inhibitors(line);
    }
    if (size == EOF || (content != NULL && my_strcmp(content[0], "endif")
    && my_strcmp(content[0], "else"))) {
        my_putstr_error("then: then/endif not found.\n");
        return free_str_and_tab(line, content);
    }
    free_str_and_tab(line, NULL);
    return content;
}

/**
 * @brief Execute the false condition who wait for an else or an endif
 * @param mysh The shell structure
 * @return <b>int</b> The exit status of the command executed
 */
static int exec_false_condition(mysh_t *mysh)
{
    char **line_content = read_input(mysh);
    char **new_line_content = NULL;

    if (line_content == NULL || line_content[0] == NULL) {
        FREE_WORD_ARRAY(line_content);
        return 1;
    }
    if (my_strcmp(line_content[0], "endif") == 0) {
        FREE_WORD_ARRAY(line_content);
        return 0;
    }
    if (my_strncmp(line_content[1], "if", 2) != 0) {
        new_line_content = my_malloc_strdup_word_array(line_content);
        FREE_WORD_ARRAY(line_content);
        return exec_true_condition(mysh, new_line_content, 1);
    }
    mysh->exit_status = exec_else_if(mysh, line_content);
    FREE_WORD_ARRAY(line_content);
    return mysh->exit_status;
}

/**
 * @brief The else if builtin
 * @param mysh The shell structure
 * @param line_content The command arguments
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_else_if(mysh_t *mysh, char **line_content)
{
    int condition = 0;

    if (line_content[2] == NULL) {
        my_putstr_error("if: Too few arguments.\n");
        return 1;
    }
    condition = get_condition(line_content[2]);
    if (condition == -1)
        return 1;
    if (line_content[3] == NULL) {
        my_putstr_error("if: Empty if.\n");
        return 1;
    }
    if (condition && my_strcmp(line_content[3], "then") == 0)
        return 0;
    if (condition)
        return exec_true_condition(mysh, line_content, 3);
    return exec_false_condition(mysh);
}

/**
 * @brief The if builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_if(mysh_t *mysh)
{
    int condition = 0;

    if (mysh->args[1] == NULL) {
        my_putstr_error("if: Too few arguments.\n");
        return 1;
    }
    condition = get_condition(mysh->args[1]);
    if (condition == -1)
        return 1;
    if (mysh->args[2] == NULL) {
        my_putstr_error("if: Empty if.\n");
        return 1;
    }
    if (condition && my_strcmp(mysh->args[2], "then") == 0 ||
    condition == 0 && my_strcmp(mysh->args[2], "then") != 0)
        return 0;
    if (condition)
        return exec_true_condition(mysh, mysh->args, 2);
    return exec_false_condition(mysh);
}
