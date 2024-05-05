/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the globbing functions
*/
/**
 * @file globbing.c
 * @brief The file containing the globbing functions
*/

#include "../../include/myshell.h"

/**
 * @brief Get the file list from a globbing argument
 * @param arg The argument
 * @param args_list The list of arguments for the command
 * @return <b>int</b> <u>0</u> if success, <u>-1</u> if error
 */
int get_args_list(char *arg, node_t **args_list)
{
    glob_t glob_r;
    int result;

    result = glob(arg, GLOB_TILDE, NULL, &glob_r);
    if (result == 0) {
        for (size_t j = 0; j < glob_r.gl_pathc; j++)
            my_push_back(args_list,
                my_malloc_strdup(glob_r.gl_pathv[j]), UNKNOWN);
        globfree(&glob_r);
    } else
        return -1;
    return 0;
}

/**
 * @brief Analyse and change the arguments if there are globbing
 * @param args The command arguments
 * @return <b>char **</b> The new command arguments
 * @note Pushing each argument in a list and then converting it to an array
 */
char **globbing(char **args)
{
    node_t *args_list = NULL;
    int result = 0;
    char **new_args = NULL;

    if (args == NULL)
        return NULL;
    for (int i = 0; args[i]; i++) {
        if (my_str_contains(args[i], "*?[]"))
            result = get_args_list(args[i], &args_list);
        else
            my_push_back(&args_list, args[i], UNKNOWN);
        if (result == -1) {
            my_fprintf(2, "%s: No match.\n", args[0]);
            return NULL;
        }
    }
    new_args = (char **)my_list_to_array(args_list);
    my_delete_list(&args_list);
    return new_args;
}
