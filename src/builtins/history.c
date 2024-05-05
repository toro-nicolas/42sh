/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the history builtins
*/
/**
 * @file setenv.c
 * @brief The file containing the history builtins
 */

#include "../../include/myshell.h"

/**
 * @brief Display the history
 * @param mysh The shell structure
 * @return <b>void</b>
 */
static void display_history(mysh_t *mysh)
{
    int index = 0;

    for (node_t *tmp = mysh->history; tmp != NULL; tmp = tmp->next) {
        my_printf("%d %s\n", index + 1, (char *)tmp->data);
        index++;
        if (tmp->next == mysh->history)
            break;
    }
}

/**
 * @brief Print the n last command of the history
 * @param mysh The shell structure
 * @return <b>void</b>
 */
static void print_number_history(mysh_t *mysh)
{
    int size = my_list_size_circled(mysh->history);
    int index = 1;
    int nb = my_getnbr(mysh->args[1]);

    for (node_t *tmp = mysh->history; tmp != NULL; tmp = tmp->next) {
        if (index > size - nb)
            my_printf("%d %s\n", index, (char *)tmp->data);
        index++;
        if (tmp->next == mysh->history && nb == 0) {
            my_printf("%d %s\n", index - 1, (char *)tmp->data);
            break;
        }
        if (tmp->next == mysh->history)
            break;
    }
}

/**
 * @brief The history builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_history(mysh_t *mysh)
{
    if (my_array_len((void **)mysh->args) >= 3) {
        my_fprintf(2, "history: Too many arguments.\n");
        return 1;
    }
    if (mysh->args[1] == NULL) {
        display_history(mysh);
        return 0;
    }
    if (!my_str_isnum(mysh->args[1])) {
        my_fprintf(2, "history: Badly formed number.\n");
        return 1;
    }
    print_number_history(mysh);
    return 0;
}
