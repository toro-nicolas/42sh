/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** The file containing the set builtin
*/
/**
 * @file set.c
 * @brief The file containing the set builtin
 */

#include "../../include/myshell.h"

/**
 * @brief Print the list of variable if only one argument
 * @param mysh The shell structure
 * @return <b>int</b> <u>1</u> if we print the variables, <u>0</u> otherwise
 */
int display_variable(mysh_t *mysh)
{
    if (mysh->args[1] != NULL)
        return 0;
    for (node_t *tmp = mysh->variable_list; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(((variable_t *)tmp->data)->name, "?") == 0)
            continue;
        my_printf("%s\t", ((variable_t *)tmp->data)->name);
        if (((variable_t *)tmp->data)->value != NULL)
            my_putstr(((variable_t *)tmp->data)->value);
        my_putchar('\n');
    }
    return 1;
}

/**
 * @brief Separate the variable name and value when there are stuck together
 * with an '='
 * @param mysh The shell structure
 * @param index The index of the args to separate
 * @return <b>void</b>
 */
static void change_args(mysh_t *mysh, int index)
{
    char **new_args = MALLOC(sizeof(char *) *
        (my_array_len((void *)mysh->args) + 3));

    for (int i = 0; i < index; i++)
        new_args[i] = mysh->args[i];
    new_args[index] = my_malloc_strndup(mysh->args[index],
        my_get_char_index(mysh->args[index], '=', 1));
    new_args[index + 1] = my_malloc_strdup("=");
    new_args[index + 2] = my_malloc_strdup(mysh->args[index] +
        my_get_char_index(mysh->args[index], '=', 1) + 1);
    for (int i = index + 1; mysh->args[i] != NULL; i++)
        new_args[i + 2] = mysh->args[i];
    new_args[my_array_len((void *)mysh->args) + 2] = NULL;
    mysh->args = new_args;
}

/**
 * @brief Check if the variable is in the right order
 * @param list The list of variable
 * @param cmp The function to compare
 * @return <b>void</b>
 */
static void check_swap(node_t **list)
{
    void *tmp = NULL;

    if ((*list)->prev != NULL
    && my_strcmp(((variable_t *)(*list)->prev->data)->name,
    ((variable_t *)(*list)->data)->name) > 0) {
        tmp = (*list)->prev->data;
        (*list)->prev->data = (*list)->data;
        (*list)->data = tmp;
    }
}

/**
 * @brief Sort the variable list
 * @param begin The list of variable
 * @param cmp The function to compare
 * @return <b>void</b>
 */
static void my_sort_variable(node_t **begin)
{
    for (node_t *list1 = *begin; list1 != NULL; list1 = list1->next) {
        for (node_t *list2 = (*begin)->next;
        list2 != NULL; list2 = list2->next)
            check_swap(&list2);
    }
}

/**
 * @brief Add a variable to the list
 * @param mysh The shell structure
 * @param name The name of the variable
 * @param value The value of the variable
 * @return <b>void</b>
 */
void add_variable(mysh_t *mysh, char *name, char *value)
{
    variable_t *variable = NULL;

    for (node_t *tmp = mysh->variable_list; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(((variable_t *)tmp->data)->name, name) == 0)
            variable = (variable_t *)tmp->data;
    }
    if (variable == NULL) {
        variable = MALLOC(sizeof(variable_t));
        variable->name = name;
        variable->value = value;
        my_push_back(&mysh->variable_list, variable, UNKNOWN);
        my_sort_variable(&mysh->variable_list);
    } else {
        variable->value = value;
    }
}

/**
 * @brief Add all the variables to the list
 * @param mysh The shell structure
 * @return <b>void</b>
 */
static void add_all_variables(mysh_t *mysh)
{
    char *value = NULL;

    for (int index = 1; mysh->args[index] != NULL; index++) {
        if (my_strcmp(mysh->args[index + 1], "=") == 0)
            value = mysh->args[index + 2];
        add_variable(mysh, mysh->args[index], value);
        if (my_strcmp(mysh->args[index + 1], "=") == 0)
            index = index + 2;
        value = NULL;
    }
}

/**
 * @brief The set builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_set(mysh_t *mysh)
{
    if (display_variable(mysh))
        return 0;
    for (int index = 1; mysh->args[index] != NULL; index++) {
        if (my_str_contains(mysh->args[index], "=") == 1
        && my_strlen(mysh->args[index]) != 1) {
            change_args(mysh, index);
            index = index + 2;
        }
    }
    for (int index = 1; mysh->args[index] != NULL; index++) {
        if (my_strcmp(mysh->args[index], "=") == 0) {
            index++;
            continue;
        }
        if (is_valid_variable(mysh->args[index], "set") == 0)
            return 1;
    }
    add_all_variables(mysh);
    return 0;
}

/**
 * @brief Get the value of a variable
 * @param mysh The shell structure
 * @param name The name of the variable
 * @return <b>char *</b> The value of the variable
 */
char *get_variable_value(mysh_t *mysh, char *name)
{
    for (node_t *tmp = mysh->variable_list; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(((variable_t *)tmp->data)->name, name) == 0)
            return ((variable_t *)tmp->data)->value;
    }
    return NULL;
}
