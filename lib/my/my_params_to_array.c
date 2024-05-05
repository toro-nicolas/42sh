/*
** EPITECH PROJECT, 2023
** my_params_to_array
** File description:
** Returns a info_params struct of the argc (ac) and the argv (av)
*/
/**
 * @file my_params_to_array.c
 * @brief The file containing the my_params_to_array function
 * @author Nicolas TORO
 */

#include "my.h"

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param *result;
    int i = 0;

    result = malloc(sizeof(struct info_param) * (ac + 1));
    for (; i < ac; i++) {
        result[i].length = my_strlen(av[i]);
        result[i].str = av[i];
        result[i].copy = my_strdup(av[i]);
        result[i].word_array = my_str_to_word_array(av[i]);
    }
    result[i].length = 0;
    result[i].str = 0;
    result[i].copy = 0;
    result[i].word_array = 0;
    return result;
}
