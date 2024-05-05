/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the array_string function
*/
/**
 * @file array_string.c
 * @brief The file containing the array_string function
 */

#include "../../include/myshell.h"

/**
 * @brief Check if the string is not a separator
 * @param str The string
 * @param sep The separator
 * @return <b>int</b> <u>1</u> if the string is not a separator,
 * <u>0</u> otherwise
 */
static int my_str_is_not_a_separator(char const *str, char const *sep)
{
    if (my_strncmp(str, sep, my_strlen(sep)) == 0)
        return 0;
    return 1;
}

/**
 * @brief Count the number of words and separators
 * @param str The string
 * @param sep The separator
 * @param word The number of words
 * @param separator The list of separators
 * @return <b>void</b>
 */
static void check_words_and_num(char const *str, int *sep, int *word,
    char const *separator)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((my_str_is_not_a_separator(str + i, separator)
        || char_is_inhibited((char *)str, i) ||
        char_is_paranthesed((char *)str, i)) && *sep == 1) {
            *word = *word + 1;
            *sep = 0;
        }
        if (my_str_is_not_a_separator(str + i, separator) == 0
        && char_is_inhibited((char *)str, i) == 0 &&
        char_is_paranthesed((char *)str, i) == 0)
            *sep = 1;
    }
}

/**
 * @brief Count the number of letters in a word
 * @param str The string
 * @param which_lettre The index of the letter
 * @param nbr_lettre The number of letters
 * @param separator The list of separators
 * @return <b>void</b>
 */
static void count_letter(char const *str, int which_lettre, int *nbr_lettre,
    char const *separator)
{
    for (int i = which_lettre; str[i] != '\0'
    && (my_str_is_not_a_separator(str + i, separator)
    || char_is_inhibited((char *)str, i) ||
    char_is_paranthesed((char *)str, i)); i++)
        *nbr_lettre = *nbr_lettre + 1;
}

/**
 * @brief Reset the number of letters in a word
 * @param str The string
 * @param which_lettre The index of the letter
 * @param nbr_lettre The number of letters
 * @param separator The list of separators
 * @return <b>void</b>
 */
static void reset_nbr_letter(char const *str,
    int *which_lettre, int *nbr_lettre, char const *separator)
{
    for (; str[*which_lettre] != '\0'
    && my_str_is_not_a_separator(str + *which_lettre, separator) == 0
    && char_is_inhibited((char *)str, *which_lettre) == 0
    && char_is_paranthesed((char *)str, *which_lettre) == 0;
        *which_lettre = *which_lettre + my_strlen(separator));
    *nbr_lettre = 0;
}

/**
 * @brief Get the next word
 * @param str The string
 * @param separator The list of separators
 * @return <b>char *</b> The next word
 */
static char *nbr_sep(char *str, char const *separator)
{
    int nbr_sep = 0;

    for (int i = 0; my_str_is_not_a_separator(str + i, separator) == 0
    && (char_is_inhibited((char *)str, i) == 0 ||
    char_is_paranthesed((char *)str, i)); i++)
        nbr_sep++;
    return &str[nbr_sep];
}

/**
 * @brief Initialise the value of the array of words
 * @param string The string
 * @param str The string
 * @param info The information
 * @param separator The list of separators
 * @return <b>char **</b> The array of words
 */
static char **initialise_value(char **string, char const *str,
    int **info, char const *separator)
{
    char **array_of_word;

    *string = nbr_sep(*string, separator);
    check_words_and_num(str, info[1], info[0], separator);
    array_of_word = malloc(sizeof(char *) * ((*(info[0])) + 1));
    return array_of_word;
}

/**
 * @brief Transform a string into an array of words delimited by a string
 * with inhibitors
 * @param str The string to transform
 * @param separator The separator
 * @return <b>char **</b> The array of words
 */
char **array_string(char const *str, char const *separator)
{
    int word = 0;
    int sep = 1;
    int *info[2] = {&word, &sep};
    int nbr_lettre = 0;
    int which_lettre = 0;
    char *string = (char *)str;
    char **array_of_word = initialise_value(&string, str, info, separator);

    for (int elem = 0; elem < word; elem++) {
        count_letter(string, which_lettre, &nbr_lettre, separator);
        array_of_word[elem] = malloc(sizeof(char) * (nbr_lettre + 1));
        for (int chara = 0; chara < nbr_lettre; chara++) {
            array_of_word[elem][chara] = string[which_lettre];
            which_lettre++;
        }
        array_of_word[elem][nbr_lettre] = '\0';
        reset_nbr_letter(string, &which_lettre, &nbr_lettre, separator);
    }
    array_of_word[word] = NULL;
    return array_of_word;
}
