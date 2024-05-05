/*
** EPITECH PROJECT, 2024
** round_flag_a
** File description:
** The function to round a hexadecimal float number for the flag a
*/
/**
 * @file round_flag_a.c
 * @brief The file containing the round_flag_a function
 * @author Nicolas TORO
 */

#include "myprintf.h"

void round_biga(char *float_nb, int precision, char last_char, int i)
{
    if (last_char == '\0') {
        for (; i < precision; i++)
            my_strcat(float_nb, "0");
        return;
    }
    if (float_nb[3 + i] == '.') {
        float_nb[2] = float_nb[2] + 1;
        return;
    }
    if (last_char > '7' && float_nb[3 + i] == '9') {
        float_nb[3 + i] = 'A';
        return;
    }
    if (last_char > '7' && float_nb[3 + i] == 'F')
        float_nb[3 + i] = '0';
    if (last_char > '7' && float_nb[3 + i] != '0')
        float_nb[3 + i] = float_nb[3 + i] + 1;
    if (float_nb[3 + i] == '0')
        round_biga(float_nb, precision, last_char, i - 1);
}

void round_a(char *float_nb, int precision, char last_char, int i)
{
    if (last_char == '\0') {
        for (; i < precision; i++)
            my_strcat(float_nb, "0");
        return;
    }
    if (float_nb[3 + i] == '.') {
        float_nb[2] = float_nb[2] + 1;
        return;
    }
    if (last_char > '7' && float_nb[3 + i] == '9') {
        float_nb[3 + i] = 'a';
        return;
    }
    if (last_char > '7' && float_nb[3 + i] == 'f')
        float_nb[3 + i] = '0';
    if (last_char > '7' && float_nb[3 + i] != '0')
        float_nb[3 + i] = float_nb[3 + i] + 1;
    if (float_nb[3 + i] == '0')
        round_a(float_nb, precision, last_char, i - 1);
}
