/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** The file containing the replace alias functions
*/
/**
 * @file replace_alias.c
 * @brief The file containing the replace alias functions
 */

#include "../../include/myshell.h"

static void check_swap(node_t **list, int (*cmp)())
{
    void *tmp;

    if ((*list)->prev != NULL
    && cmp(((alias_t *)(*list)->prev->data)->name,
    ((alias_t *)(*list)->data)->name) > 0) {
        tmp = (*list)->prev->data;
        (*list)->prev->data = (*list)->data;
        (*list)->data = tmp;
    }
}

void my_sort_alias(node_t **begin, int (*cmp)())
{
    for (node_t *list1 = *begin; list1 != NULL; list1 = list1->next) {
        for (node_t *list2 = (*begin)->next;
        list2 != NULL; list2 = list2->next)
            check_swap(&list2, cmp);
    }
}

static node_t *str_match_alias(char *str, node_t **alias_list)
{
    alias_t *alias = NULL;

    for (node_t *tmp = *alias_list; tmp != NULL; tmp = tmp->next) {
        alias = (alias_t *)tmp->data;
        if (my_strcmp(str, alias->name) == 0)
            return tmp;
    }
    return NULL;
}

static void boucle_on_alias(node_t **args_list, node_t **tmp_list,
    char **tmp_args)
{
    for (int j = 0; tmp_args[j] != NULL; j++)
        my_push_front(tmp_list, my_malloc_strdup(tmp_args[j]), UNKNOWN);
    for (node_t *tmp = *tmp_list; tmp != NULL; tmp = tmp->next)
        my_push_front(args_list, my_malloc_strdup(tmp->data), UNKNOWN);
}

static int update_alias(node_t **already_find, char **str,
    node_t **tmp_list, char **tmp_args)
{
    my_push_front(already_find, my_strdup(*str), STRING);
    my_delete_list(tmp_list);
    *tmp_list = NULL;
    if (my_strcmp(*str, tmp_args[0]) == 0) {
        my_delete_list(already_find);
        return 0;
    }
    if (my_find_node(*already_find, tmp_args[0], my_strcmp)) {
        my_putstr_error("Alias loop.\n");
        my_delete_list(already_find);
        return 1;
    }
    if (tmp_args[0] != NULL)
        *str = my_malloc_strdup(tmp_args[0]);
    return -1;
}

static int looping_on_first(node_t **args_list, char *str, node_t **alias_list)
{
    node_t *tmp_list = NULL;
    node_t *already_find = NULL;
    alias_t *matching_alias = NULL;
    char **tmp_args = NULL;
    int result = 0;

    while (str_match_alias(str, alias_list) != NULL) {
        if (args_list != NULL)
            my_free_ptr(my_pop_front(args_list));
        matching_alias = str_match_alias(str, alias_list)->data;
        tmp_args = my_super_array(matching_alias->value, " \t\n");
        boucle_on_alias(args_list, &tmp_list, tmp_args);
        result = update_alias(&already_find, &str, &tmp_list, tmp_args);
        FREE_WORD_ARRAY(tmp_args);
        if (result != -1)
            return result;
    }
    my_delete_list(&already_find);
    return 0;
}

char **replace_alias_in_line(char **args, node_t **alias_list)
{
    node_t *args_list = NULL;
    char **new_args = NULL;
    int index = 0;

    if (args == NULL || args[0] == NULL ||
    looping_on_first(&args_list, args[0], alias_list))
        return NULL;
    if (args_list != NULL)
        index++;
    for (; args[index] != NULL; index++)
        my_push_back(&args_list, args[index], UNKNOWN);
    new_args = (char **)my_list_to_array(args_list);
    my_delete_list(&args_list);
    FREE(args);
    return new_args;
}
