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

/**
 * @brief Insert a character at the index
 * @param str The string
 * @param c The character to insert
 * @param pos The position of the cursor
 * @param str2 The second string
 * @return <b>void</b>
 */
void insert_index(char *str, char c, int *pos, char **str2)
{
    if (pos[0] != pos[1]) {
        *str2 = my_malloc_strdup(&str[pos[0]]);
    }
    str[pos[0]] = c;
    str[pos[0] + 1] = 0;
    pos[1]++;
}

/**
 * @brief Display the two strings
 * @param pos The position of the cursor
 * @param str The string
 * @param str2 The second string
 * @return <b>void</b>
 */
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

/**
 * @brief Check if there are an arrow key and execute them
 * @param pos The position of the cursor
 * @param str The string
 * @param str2 The second string
 * @return <b>void</b>
 */
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

/**
 * @brief Check if there are instructions to do
 * with the character (controls, backspace...)
 * @param c The character
 * @param pos The position of the cursor
 * @param str The string
 * @param str2 The second string
 * @return <b>int</b> <u>1</u> if the character is a control character,
 * <u>0</u> otherwise
 */
static int instruction_to_do(char c, int *pos, char *str, char **str2)
{
    if (ctrl(c, pos, str, str2) == 0)
        return 1;
    if (backspace(c, pos, str, str2) == 0)
        return 1;
    return 0;
}

/**
 * @brief Stop the getline function
 * @param line The line to store the command
 * @param str The string
 * @param type The type of the stop
 * @return <b>int</b> <u>0</u> if success, <u>-1</u> if error
 */
static int stop_getline(char **line, char *str, int type)
{
    if (type) {
        *line = NULL;
        return -1;
    }
    *line = my_strdup(str);
    return 0;
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
    int instruction = 0;

    disable_buffer();
    while (1) {
        c = getchar();
        if (c == -1 || c == CTRL_D)
            return stop_getline(line, str, 1);
        instruction = instruction_to_do(c, pos, str, &str2);
        if (instruction)
            continue;
        condition(c, pos, str, &str2);
        if (c == '\n')
            return stop_getline(line, str, 0);
    }
}
