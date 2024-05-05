/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the tilde functions
*/
/**
 * @file tilde.c
 * @brief The file containing the tilde functions
 */

#include "../../include/myshell.h"

/**
 * @brief Replace the tilde by the home path
 * @param mysh The shell structure
 * @param home The home path
 * @brief index The index of the tilde
 * @return <b>int</b> <u>0</u> if the replacement is successful,
 * <u>1</u> otherwise
 */
static int replace_tilde(mysh_t *mysh, char *home, int index)
{
    char *new_str = NULL;

    if (home == NULL) {
        my_putstr_error("No $home variable set.\n");
        mysh->exit_status = 1;
        return 1;
    }
    new_str = calloc((my_strlen(mysh->line)
        + my_strlen(home) + 1), sizeof(char));
    my_strncpy(new_str, mysh->line, index);
    my_strcat(new_str, home);
    my_strcat(new_str, &mysh->line[index + 1]);
    FREE(mysh->line);
    mysh->line = new_str;
    return 0;
}

/**
 * @brief Transform the tilde in the command line by the home path
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the replacement is successful,
 * <u>1</u> otherwise
 */
int check_tilde(mysh_t *mysh)
{
    char *home = get_env_var(mysh->env, "HOME");
    int result = 0;

    for (int index = 0; mysh->line[index] != '\0' && result == 0; index++) {
        if ((index == 0 || my_char_is(mysh->line[index - 1], "( \t\n") == 1) &&
        mysh->line[index] == '~' && char_is_inhibited(mysh->line, index) == 0)
            result = replace_tilde(mysh, home, index);
    }
    return result;
}
