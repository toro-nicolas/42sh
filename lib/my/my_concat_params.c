/*
** EPITECH PROJECT, 2023
** my_concat_params
** File description:
** Returns a string with all the arguments (argc and argv) concatenated
*/
/**
 * @file my_concat_params.c
 * @brief The file containing the my_concat_params function
 * @author Nicolas TORO
 */

#include "my.h"

char *my_concat_params(int argc, char **argv)
{
    char *result;
    int len_result = 0;

    for (int i = 0; i < argc; i++)
        len_result = len_result + my_strlen(argv[i]);
    result = malloc(sizeof(char) * (len_result + argc));
    for (int j = 0; j < argc; j++) {
        result = my_strcat(result, argv[j]);
        result = my_strcat(result, "\n");
    }
    result[len_result + argc] = '\0';
    return result;
}
