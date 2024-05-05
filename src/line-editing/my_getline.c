/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the getline functions
*/
/**
 * @file my_getline.c
 * @brief The file containing the getline functions
 */

#include "../../include/myshell.h"

void insert_index(char *str, char c, int *pos, char **str2)
{
    if (pos[0] != pos[1]) {
        *str2 = my_malloc_strdup(&str[pos[0]]);
    }
    str[pos[0]] = c;
    str[pos[0] + 1] = 0;
    pos[1]++;
}

static void print_two_strings(char *str, char *str2, int *pos, char c)
{
    if (pos[0] == pos[1])
        return;
    for (int i = 0; i < my_strlen(str2); i++)
        my_fprintf(0, " ");
    for (int i = 0; i < my_strlen(str2); i++)
        my_fprintf(0, "\b");
    my_fprintf(0, "%c", c);
    my_fprintf(0, "%s", str2);
    for (int i = 0; i < my_strlen(str2); i++)
        my_fprintf(0, "\b");
    if (str2 != NULL && str2[0] != 0)
        my_strcat(str, str2);
}

static void condition(char c, int *pos, char *str, char **str2)
{
    if (c == '\033')
        move_cursor(pos, str, str2);
    else {
        insert_index(str, c, pos, str2);
        print_two_strings(str, *str2, pos, c);
        pos[0]++;
    }
}

static int instruction_to_do(char c, int *pos, char *str, char **str2)
{
    if (ctrl(c, pos, str, str2) == 0)
        return 0;
    if (backspace(c, pos, str, str2) == 0)
        return 0;
    return 1;
}

/**
 * @brief Get the line from the stream
 * @param line The line to store the command
 * @param stream The stream
 * @return <b>int</b> <u>0</u> if success, <u>-1</u> if error
 */
int my_getline(char **line, FILE *stream)
{
    char c = 0;
    char *str2 = NULL;
    char str[2049] = {0};
    int *pos = CALLOC(2, sizeof(int));
    int ret = 0;

    disable_buffer();
    while (1) {
        c = getchar();
        if (c == -1)
            return -1;
        ret = instruction_to_do(c, pos, str, &str2);
        if (ret == 0)
            continue;
        condition(c, pos, str, &str2);
        if (c == '\n') {
            *line = my_strdup(str);
            return 0;
        }
    }
}
