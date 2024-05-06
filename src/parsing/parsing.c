/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the parsing functions
*/
/**
 * @file parsing.c
 * @brief The file containing the parsing functions
 */

#include "../../include/myshell.h"

/**
 * @brief Check if a character is inhibited
 * @param str The string to check
 * @param index The index of the character
 * @return <b>char</b> The inhibitor if the character is inhibited,
 * <u>0</u> otherwise
 */
char char_is_inhibited(char *str, int index)
{
    char inhibitor = 0;

    for (int i = 0; i < index + 1; i++) {
        if (str[i] == '\0')
            break;
        if (inhibitor == str[i] && inhibitor != '\\' && i == index)
            return 0;
        if (inhibitor == str[i] && inhibitor != '\\') {
            inhibitor = 0;
            continue;
        }
        if (i == index)
            return inhibitor;
        if (inhibitor == '\\')
            inhibitor = 0;
        if (my_char_is(str[i], "\'\"\\") && inhibitor == 0)
            inhibitor = str[i];
    }
    return inhibitor;
}

/**
 * @brief Check if a char is paranthesed
 * @param str The string
 * @param index The index
 * @return <b>int</b> <u>1</u> if the char is paranthesed, <u>0</u> otherwise
 */
int char_is_paranthesed(char *str, int index)
{
    int count = 0;

    for (int i = 0; str[i] != '\0' && i <= index; i++) {
        if (i == 0)
            continue;
        if (str[i - 1] == '(')
            count++;
        if (str[i] == ')')
            count--;
    }
    if (count > 0)
        return 1;
    return 0;
}

/**
 * @brief Check if a char is protected
 * @param str The string
 * @param index The index
 * @return <b>int</b> <u>1</u> if the char is protected, <u>0</u> otherwise
 */
int char_is_protected(char *str, int index)
{
    if (char_is_inhibited(str, index) || char_is_paranthesed(str, index))
        return 1;
    return 0;
}

/**
 * @brief Find a valid string in a string
 * depending on inhibitors and parentheses
 * @note It's an improved version of my_strstr
 * @param str The string to check
 * @param to_find The string to find
 * @return <b>char *</b> The address of the string if it's valid,
 * <u>NULL</u> otherwise
 */
char *find_valid_str(char *str, char const *to_find)
{
    char *new_str = str;

    while (my_strstr(new_str, to_find) != NULL) {
        if (char_is_protected(str, my_strstr(new_str, to_find) - str) == 0)
            return my_strstr(new_str, to_find);
        new_str = my_strstr(new_str, to_find) + 1;
    }
    return NULL;
}

/**
 * @brief Check if the variable is valid
 * @param variable The variable
 * @param builtin The builtin who called the function
 * @return <b>int</b> <u>1</u> if the variable is valid, <u>0</u> otherwise
 */
int is_valid_variable(char *variable, char *builtin)
{
    if (variable == NULL || variable[0] == '\0' ||
    (my_char_is_alpha(variable[0]) == 0 && variable[0] != '_')) {
        my_fprintf(2, "%s: Variable name must begin with a letter.\n",
            builtin);
        return 0;
    }
    for (int index = 0; variable[index] != '\0'; index++) {
        if (my_char_is_alpha(variable[index]) == 0 &&
        my_char_is_num(variable[index]) == 0 && variable[index] != '_') {
            my_fprintf(2, "%s: "
                "Variable name must contain alphanumeric characters.\n",
                builtin);
            return 0;
        }
    }
    return 1;
}
