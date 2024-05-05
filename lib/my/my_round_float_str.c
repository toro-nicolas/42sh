/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Modify a string (float) and round it
*/
/**
 * @file my_round_float_str.c
 * @brief The file containing the my_round_float_str function
 * @author Nicolas TORO
 */

#include "my.h"

static void add_number(char *float_nb)
{
    char *temp_float_str = malloc(sizeof(char) * my_strlen(float_nb + 1));

    temp_float_str[0] = '1';
    my_strcat(temp_float_str, float_nb);
    my_strcpy(float_nb, temp_float_str);
    if (float_nb[1] == '-') {
        float_nb[1] = float_nb[0];
        float_nb[0] = '-';
    }
    FREE(temp_float_str);
}

void my_round_float_str(char *float_nb, char last_char, int i, int enable)
{
    if (float_nb[i] == '\0' || float_nb[i] == '-')
        add_number(float_nb);
    if (float_nb[i] == '.') {
        if (float_nb[i - 1] == '9')
            float_nb[i - 1] = '0';
        else
            float_nb[i - 1] = float_nb[i - 1] + 1;
        if (float_nb[i - 1] == '0')
            my_round_float_str(float_nb, float_nb[i - 1], i - 2, 0);
        return;
    }
    if (float_nb[i] != '.' && (last_char > '4' || enable == 1)) {
        if (float_nb[i] == '9')
            float_nb[i] = '0';
        else
            float_nb[i] = float_nb[i] + 1;
        if (float_nb[i] == '0')
            my_round_float_str(float_nb, float_nb[i], i - 1, 1);
    }
}
