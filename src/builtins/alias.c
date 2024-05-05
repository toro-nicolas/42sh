/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** The file containing the alias functions
*/
/**
 * @file alias.c
 * @brief The file containing the alias functions
 */

#include "../../include/myshell.h"

/**
 * @brief Print the concated syntax
 * @param is_concated The alias is concated
 * @param start The alias is at the start of the printing
 * @return <b>void</b>
 */
static void print_concated(int is_concated, int start)
{
    if (is_concated && start)
        my_putchar('(');
    if (is_concated && !start)
        my_putstr(")\n");
    if (!is_concated && !start)
        my_putchar('\n');
}

/**
 * @brief Search the alias in the list and print the value
 * @param mysh The shell structure
 * @param alias The alias name to search
 * @return <b>void</b>
 */
void print_alias(mysh_t *mysh, char *alias)
{
    for (node_t *tmp = mysh->alias_list; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(((alias_t *)tmp->data)->name, alias) == 0) {
            my_putstr(((alias_t *)tmp->data)->value);
            break;
        }
    }
}

/**
 * @brief Check if the alias has an error
 * @param mysh The shell structure
 * @param alias The alias structure
 * @return <b>int</b> <u>1</u> if the command argument are less than 3,
 * <u>0</u> otherwise
 */
int display_alias(mysh_t *mysh)
{
    if (mysh->args[1] == NULL) {
        for (node_t *tmp = mysh->alias_list; tmp != NULL; tmp = tmp->next) {
            my_printf("%s\t", ((alias_t *)tmp->data)->name);
            print_concated(((alias_t *)tmp->data)->is_concated, 1);
            my_putstr(((alias_t *)tmp->data)->value);
            print_concated(((alias_t *)tmp->data)->is_concated, 0);
        }
        return 1;
    }
    if (mysh->args[2] == NULL) {
        print_alias(mysh, mysh->args[1]);
        return 1;
    }
    return 0;
}

/**
 * @brief Concatenate the arguments
 * @param mysh The shell structure
 * @param alias The alias structure
 * @return <b>void</b>
 */
static void concat_args(mysh_t *mysh, alias_t *alias)
{
    for (int j = 3; mysh->args[j] != NULL; j++) {
        alias->value = my_strcat(alias->value, " ");
        alias->value = my_strcat(alias->value, mysh->args[j]);
    }
}

/**
 * @brief Replace the alias if it already exists
 * @param mysh The shell structure
 * @param alias The alias structure
 * @return <b>int</b> <u>1</u> if the alias is replaced, <u>0</u> otherwise
 */
int replace_alias(mysh_t *mysh)
{
    alias_t *alias;

    for (node_t *tmp = mysh->alias_list; tmp != NULL; tmp = tmp->next) {
        alias = (alias_t *)tmp->data;
        if (my_strcmp(alias->name, mysh->args[1]) == 0 &&
        mysh->args[3] == NULL) {
            alias->is_concated = 0;
            alias->value = my_strcpy(alias->value, mysh->args[2]);
            return 1;
        }
        if (my_strcmp(alias->name, mysh->args[1]) == 0 &&
        mysh->args[3] != NULL) {
            alias->is_concated = 1;
            alias->value = my_strcpy(alias->value, mysh->args[2]);
            concat_args(mysh, alias);
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Add an alias to the list
 * @param mysh The shell structure
 * @return <b>void</b>
 */
void add_alias(mysh_t *mysh)
{
    alias_t *alias = MALLOC(sizeof(alias_t));
    int len = 0;

    alias->is_concated = 0;
    alias->name = my_malloc_strdup(mysh->args[1]);
    for (int i = 2; mysh->args[i] != NULL; i++)
        len += my_strlen(mysh->args[i]) + 1;
    alias->value = CALLOC(my_strlen(mysh->args[2]) + len + 1, sizeof(char));
    alias->value = my_strcpy(alias->value, mysh->args[2]);
    if (mysh->args[3] == NULL)
        return my_push_back(&mysh->alias_list, alias, UNKNOWN);
    alias->is_concated = 1;
    concat_args(mysh, alias);
    my_push_back(&mysh->alias_list, alias, UNKNOWN);
}

/**
 * @brief The alias builtin
 * @param mysh The shell structure
 * @return <b>int</b> Always <u>0</u>
 */
int exec_alias(mysh_t *mysh)
{
    if (display_alias(mysh))
        return 0;
    if (replace_alias(mysh))
        return 0;
    add_alias(mysh);
    my_sort_alias(&mysh->alias_list, &my_strcmp);
    return 0;
}
