/*
** EPITECH PROJECT, 2023
** my_super_array
** File description:
** Returns an array of words delimited by a list of separator (separator)
** from a string (str)
*/
/**
 * @file my_super_array.c
 * @brief The file containing the my_super_array function
 * @author Nicolas TORO
 */

#include "my.h"

static int my_char_is_sep(char c, char *sep)
{
    for (int i = 0; sep[i] != '\0'; i++) {
        if (c == sep[i])
            return 1;
    }
    return 0;
}

int count_words(char *str, char *sep)
{
    int n = 0;
    int do_it = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_char_is_sep(str[i], sep) && do_it) {
            n++;
            do_it = 0;
        }
        if (my_char_is_sep(str[i], sep))
            do_it = 1;
    }
    return n;
}

int count_letters(char *str, char *sep, int *save)
{
    int n = 0;

    for (int i = *save; str[i] != '\0'
        && !my_char_is_sep(str[i], sep); i++) {
        (*save)++;
        n++;
    }
    return n;
}

int decale_save(int *save, char *str, char *sep)
{
    for (int i = *save; str[i] != '\0'
        && my_char_is_sep(str[i], sep); i++) {
        (*save)++;
    }
    return 0;
}

int fill_str(char *to_fill, int nb_letters, int save, char *source)
{
    int a = 0;

    for (int i = save - nb_letters;
        i < nb_letters + (save - nb_letters); i++) {
        to_fill[a] = source[i];
        a++;
    }
    return 0;
}

char **my_super_array(char *str, char *sep)
{
    int nb_words = count_words(str, sep);
    char **array = malloc(sizeof(char *) * (nb_words + 1));
    int save = 0;
    int nb_letters = 0;

    for (int i = 0; i < nb_words; i++) {
        decale_save(&save, str, sep);
        nb_letters = count_letters(str, sep, &save);
        array[i] = malloc(sizeof(char) * (nb_letters + 1));
        fill_str(array[i], nb_letters, save, str);
        array[i][nb_letters] = '\0';
    }
    array[nb_words] = NULL;
    return array;
}
