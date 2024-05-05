/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the event functions
*/
/**
 * @file event.c
 * @brief The file containing the event functions
 */

#include "../../include/myshell.h"

static int get_history_str(node_t **list, char *arg)
{
    char **arr = NULL;

    for (node_t *tmp = get_mysh()->history->prev; tmp; tmp = tmp->prev) {
        if (tmp->prev == get_mysh()->history->prev)
            break;
        if (my_strncmp(tmp->data, arg, my_strlen(arg) != 0))
            continue;
        arr = my_super_array(tmp->data, " \t");
        for (int x = 0; arr[x] != NULL; x++)
            my_push_back(list, my_malloc_strdup(arr[x]), UNKNOWN);
        return 0;
    }
    return 1;
}

static int get_history_nb(node_t **list, char *arg, int nb)
{
    char **arr = NULL;

    for (node_t *tmp = get_mysh()->history; tmp != NULL; tmp = tmp->next) {
        if (tmp->next == get_mysh()->history)
            break;
        if (nb != 1) {
            nb--;
            continue;
        }
        arr = my_super_array(tmp->data, " \t");
        for (int i = 0; arr[i] != NULL; i++)
            my_push_back(list, my_malloc_strdup(arr[i]), UNKNOWN);
        FREE_WORD_ARRAY(arr);
        return 0;
    }
    return 1;
}

int get_history(node_t **list, char *arg)
{
    int nb = my_getnbr(&arg[1]);
    int i = my_list_size_circled(get_mysh()->history) - 1;

    if (my_str_isnum(&arg[1])) {
        if (nb > i) {
            my_fprintf(2, "%s: No such event.\n", arg);
            return 1;
        }
        if (!get_history_nb(list, arg, nb))
            return 0;
    } else {
        if (!get_history_str(list, arg + 1))
            return 0;
    }
    my_fprintf(2, "%s: Event not found.\n", &arg[1]);
    return 1;
}

/**
 * @brief Replace '!' by history event
 * @param args The command arguments
 * @return <b>char **</b> The new command arguments
 */
char **replace_history(char **args)
{
    node_t *list = NULL;
    int r = 0;
    char **new_args = NULL;

    for (int i = 0; args[i] != NULL; i++) {
        if (args[i][0] == '!' && args[i][1] == '\0') {
            my_push_back(&list, my_malloc_strdup(args[i]), UNKNOWN);
            continue;
        }
        if (args[i][0] == '!')
            r = get_history(&list, args[i]);
        if (r)
            return NULL;
        if (args[i][0] != '!')
            my_push_back(&list, my_malloc_strdup(args[i]), UNKNOWN);
    }
    new_args = (char **)my_list_to_array_circled(&list);
    my_delete_circle_list(&list);
    return new_args;
}
