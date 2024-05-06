/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the inhibitors functions
*/
/**
 * @file inhibitors.c
 * @brief The file containing the inhibitors functions
 */

#include "../../include/myshell.h"

/**
 * @brief Update the inhibitor
 * @param command The command
 * @param index The index
 * @param inhibitor The inhibitor
 * @param end_inhibitors The end inhibitors
 * @return <b>void</b>
 */
static int update_inhibitor(char *command, int index,
    char *inhibitor, int *parentheses)
{
    if ((*inhibitor == '(' && command[index] == ')') ||
    ((*inhibitor == 0 || *inhibitor == '(') && command[index] == '(')) {
        *parentheses += (command[index] == '(') ? 1 : - 1;
        *inhibitor = (*parentheses) ? '(' : 0;
        return 0;
    }
    if (*inhibitor != 0 && *inhibitor == command[index]
    && *inhibitor != '\\') {
        *inhibitor = 0;
        return 1;
    }
    if (*inhibitor == '\\') {
        *inhibitor = 1;
        return 0;
    }
    if (*inhibitor == 0 && my_char_is(command[index], "\'\"\\")) {
        *inhibitor = command[index];
        return 1;
    }
    return 0;
}

/**
 * @brief Count the number of words in a string
 * @param str The string
 * @return <b>int</b> The number of words
 */
static int count_words(char *str)
{
    int n = 0;
    char inhibitor = 0;
    int add_it = 1;
    int parentheses = 0;

    for (int index = 0; str[index] != '\0'; index++) {
        if (update_inhibitor(str, index, &inhibitor, &parentheses))
            continue;
        if (my_char_is(str[index], " \t\n\"\'\\(") == 0 || inhibitor != 0) {
            n = (add_it) ? n + 1 : n;
            add_it = 0;
            continue;
        }
        if (inhibitor == 1)
            inhibitor = 0;
        add_it = 1;
    }
    return n;
}

/**
 * @brief Count the number of letters in a word
 * @param str The string
 * @param save The save
 * @return <b>int</b> The number of letters
 */
static int count_letters(char *str, int *save)
{
    int n = 0;
    char inhibitor = 0;
    int parentheses = 0;

    for (int i = *save; str[i] != '\0'; i++) {
        update_inhibitor(str, i, &inhibitor, &parentheses);
        if (my_char_is(str[i], " \t\n") && inhibitor == 0)
            return n;
        if (inhibitor == 1)
            inhibitor = 0;
        (*save)++;
        n++;
    }
    return n;
}

/**
 * @brief Move the save to the next word
 * @param save The save
 * @param str The string
 * @return <b>void</b>
 */
static void move_save(int *save, char *str, int index)
{
    for (int i = *save; str[i] != '\0'; i++) {
        if (my_char_is(str[i], " \t\n") == 0)
            return;
        (*save)++;
    }
}

/**
 * @brief Fill the string with the letters
 * @param to_fill The string to fill
 * @param nb_letters The number of letters to fill
 * @param save The save
 * @param source The source
 * @return <b>void</b>
 */
static void fill_str(char *to_fill, int nb_letters, int save, char *source)
{
    char inhibitor = 0;
    int parentheses = 0;

    for (int index = save - nb_letters; index < save; index++) {
        if (update_inhibitor(source, index, &inhibitor, &parentheses))
            continue;
        if (my_char_is(source[index], " \t\n") && inhibitor == 0)
            return;
        my_add_chr(to_fill, source[index]);
        if (inhibitor == 1)
            inhibitor = 0;
    }
}

/**
 * @brief Add an element to the new array
 * @param new_array The new array
 * @param array The array
 * @param index The index
 * @param array_index The array index
 * @return <b>void</b>
 */
static void add_element(char **new_array, char **array,
    int *index, int array_index)
{
    if (my_str_contains(array[array_index], "()") &&
    array[array_index][0] != '(') {
        new_array[*index] = my_strndup(array[array_index],
        my_get_char_index(array[array_index], '(', 1));
        (*index)++;
    }
    new_array[*index] = (my_strstr(array[array_index], "(") != NULL) ?
        my_strndup(my_strstr(array[array_index], "("), my_get_char_index(
        my_strstr(array[array_index], "("), ')', my_count_letter(
        array[array_index], ')')) + 1) : my_strdup(array[array_index]);
    if (my_str_contains(array[array_index], "()") &&
    my_get_last_char(array[array_index]) != ')') {
        (*index)++;
        new_array[*index] = my_strdup(my_strstr(array[array_index], ")"));
    }
}

/**
 * @brief Separate the words in the array which are stuck with parentheses
 * @param array The array
 * @param nb_words The number of words
 * @return <b>char **</b> The new array
 */
static char **separate_parentheses(char **array, int nb_words)
{
    char **new_array = NULL;
    int array_index = 0;

    for (int index = 0; index < nb_words && array[index] != NULL; index++) {
        if (my_str_contains(array[index], "()") && array[index][0] != '(')
            nb_words++;
        if (my_str_contains(array[index], "()") &&
        my_get_last_char(array[index]) != ')')
            nb_words++;
    }
    new_array = calloc(nb_words + 1, sizeof(char *));
    for (int index = 0; array[array_index] != NULL; index++) {
        add_element(new_array, array, &index, array_index);
        array_index++;
    }
    new_array[nb_words] = NULL;
    FREE_WORD_ARRAY(array);
    return new_array;
}

/**
 * @brief Transform a string into an array of words with inhibitors
 * @param str The string to transform
 * @return <b>char **</b> The array of words
 */
char **str_to_array_inhibitors(char *str)
{
    int nb_words = 0;
    int save = 0;
    int nb_letters = 0;
    char **array = NULL;

    if (str == NULL)
        return NULL;
    nb_words = count_words(str);
    array = malloc(sizeof(char *) * (nb_words + 1));
    for (int index = 0; index < nb_words; index++) {
        move_save(&save, str, index);
        nb_letters = count_letters(str, &save);
        array[index] = calloc(nb_letters + 1, sizeof(char));
        fill_str(array[index], nb_letters, save, str);
    }
    array[nb_words] = NULL;
    array = separate_parentheses(array, nb_words);
    return array;
}
