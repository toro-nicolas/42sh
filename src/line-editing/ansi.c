/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the ansi functions
*/
/**
 * @file ansi.c
 * @brief The file containing the ansi functions
 */

#include "../../include/myshell.h"

static void up_to(char *str, int *pos, node_t **tmp)
{
    if (*tmp == NULL)
        return;
    (*tmp) = (*tmp)->prev ? (*tmp)->prev : (*tmp);
    for (int x = 0; str[x] != 0; x++)
        my_fprintf(0, "\b \b");
    my_memset(str, 0, 2049);
    if (((char *)(*tmp)->data)[my_strlen((*tmp)->data) - 1] == '\n')
        ((char *)(*tmp)->data)[my_strlen((*tmp)->data) - 1] = '\0';
    my_fprintf(0, "%s", (*tmp)->data);
    my_strcpy(str, (*tmp)->data);
    pos[0] = my_strlen(str);
    pos[1] = pos[0];
}

static void down(char *str, int *pos, node_t **tmp)
{
    if (*tmp == NULL)
        return;
    (*tmp) = (*tmp)->next ? (*tmp)->next : (*tmp);
    for (int x = 0; str[x] != 0; x++)
        my_fprintf(0, "\b \b");
    my_memset(str, 0, 2049);
    if (((char *)(*tmp)->data)[my_strlen((*tmp)->data) - 1] == '\n')
        ((char *)(*tmp)->data)[my_strlen((*tmp)->data) - 1] = '\0';
    my_fprintf(0, "%s", (*tmp)->data);
    my_strcpy(str, (*tmp)->data);
    pos[0] = my_strlen(str);
    pos[1] = pos[0];
}

static int vertical_arrow(char c, int *pos, char *str, char **str2)
{
    static node_t *tmp = NULL;

    if (tmp == NULL)
        tmp = get_mysh()->history;
    if (c == 'A') {
        if (pos[0] != pos[1])
            return 0;
        up_to(str, pos, &tmp);
        return 0;
    }
    if (c == 'B') {
        if (pos[0] != pos[1])
            return 0;
        down(str, pos, &tmp);
        return 0;
    }
    return 1;
}

static int horizontal_arrow(char c, int *pos, char *str, char **str2)
{
    if (c == 'C') {
        pos[0] += pos[0] < pos[1]
        ? (my_fprintf(STDIN_FILENO, "\033[C"), 1) : 0;
        *str2 = my_malloc_strdup(&str[pos[0]]);
        return 0;
    }
    if (c == 'D') {
        pos[0] -= pos[0] > 0 ? (my_fprintf(STDIN_FILENO, "\b"), 1) : 0;
        return 0;
    }
    return 1;
}

/**
 * @brief Move the cursor
 * @param stream The stream
 * @param pos The position of the cursor
 * @param str The string
 * @param str2 The second string
 * @return <b>void</b>
 */
void move_cursor(int *pos, char *str, char **str2)
{
    char c1;

    getchar();
    c1 = getchar();
    if (vertical_arrow(c1, pos, str, str2) == 0)
        return;
    if (horizontal_arrow(c1, pos, str, str2) == 0)
        return;
    if (getchar() == '~') {
        my_fprintf(STDIN_FILENO, "\033[P");
        pos[1]--;
        str[pos[0]] = 0;
        *str2 = my_malloc_strdup(&str[pos[0] + 1]);
        my_strcat(str, *str2);
    }
}

/**
 * @brief Handle the control key
 * @param c The character
 * @param pos The position of the cursor
 * @param str The string
 * @param str2 The second string
 * @return <b>int</b> <u>0</u> if success, <u>1</u> otherwise
 */
int ctrl(char c, int *pos, char *str, char **str2)
{
    if (c != CTRL_KEYPRESS('A') && c != CTRL_KEYPRESS('E'))
        return 1;
    if (c == CTRL_KEYPRESS('E')) {
        for (int i = 0; i < pos[1] - pos[0]; i++)
            my_fprintf(0, "\033[C");
        pos[0] = pos[1];
        *str2 = my_malloc_strdup(&str[pos[0] + 1]);
    } else {
        for (int i = 0; i < pos[0]; i++)
            my_fprintf(0, "\b");
        pos[0] = 0;
        *str2 = my_malloc_strdup(str);
    }
    return 0;
}

/**
 * @brief Handle the backspace key
 * @param c The character
 * @param pos The position of the cursor
 * @param str The string
 * @param str2 The second string
 * @return <b>int</b> <u>0</u> if success, <u>1</u> otherwise
 */
int backspace(char c, int *pos, char *str, char **str2)
{
    if (c != 127)
        return 1;
    if (pos[0] == 0)
        return 0;
    if (pos[0] == pos[1])
        pos[1]--;
    pos[0]--;
    my_fprintf(0, "\b \b");
    *str2 = my_malloc_strdup(&str[pos[0] + 1]);
    for (int i = 0; i <= my_strlen(*str2); i++)
        my_fprintf(0, " ");
    for (int i = 0; i <= my_strlen(*str2); i++)
        my_fprintf(0, "\b");
    my_fprintf(0, "%s", *str2);
    for (int i = 0; i < my_strlen(*str2); i++)
        my_fprintf(0, "\b");
    str[pos[0]] = 0;
    my_strcat(str, *str2);
    return 0;
}
