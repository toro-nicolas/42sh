/*
** EPITECH PROJECT, 2023
** my_str_to_word_array_select
** File description:
** Returns an array of words delimited by a list of separator (separator)
** from a string (str)
*/
/**
 * @file my_str_to_word_array_select.c
 * @brief The file containing the my_str_to_word_array_select function
 * @author Nicolas TORO
 */

#include "my.h"

static int my_char_is_not_a_separator(char const c, char const *sep)
{
    for (int i = 0; sep[i] != '\0'; i++) {
        if (sep[i] == c)
            return 0;
    }
    return 1;
}

static void check_words_and_num(char const *str, int *sep, int *word,
    char const *separator)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_is_not_a_separator(str[i], separator) && *sep == 1) {
            *word = *word + 1;
            *sep = 0;
        }
        if (my_char_is_not_a_separator(str[i], separator) == 0)
            *sep = 1;
    }
    return;
}

static void count_letter(char const *str, int which_lettre, int *nbr_lettre,
    char const *separator)
{
    for (int i = which_lettre; str[i] != '\0'
    && my_char_is_not_a_separator(str[i], separator); i++)
        *nbr_lettre = *nbr_lettre + 1;
}

static void reset_nbr_letter(char const *str,
    int *which_lettre, int *nbr_lettre, char const *separator)
{
    for (; str[*which_lettre] != '\0'
    && my_char_is_not_a_separator(str[*which_lettre], separator) == 0;
        *which_lettre = *which_lettre + 1);
    *nbr_lettre = 0;
}

static char *nbr_sep(char *str, char const *separator)
{
    int nbr_sep = 0;

    for (int i = 0; my_char_is_not_a_separator(str[i], separator) == 0; i++)
        nbr_sep++;
    return &str[nbr_sep];
}

static char **initialise_value(char **string, char const *str,
    int **info, char const *separator)
{
    char **array_of_word;

    *string = nbr_sep(*string, separator);
    check_words_and_num(str, info[1], info[0], separator);
    array_of_word = malloc(sizeof(char *) * ((*(info[0])) + 1));
    return array_of_word;
}

char **my_str_to_word_array_select(char const *str, char const *separator)
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
