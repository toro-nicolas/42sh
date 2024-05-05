/*
** EPITECH PROJECT, 2024
** my_super_number
** File description:
** Returns an int number starting from a string number (number)
** and change my_errno if an error occurs depending on the settings (settings)
*/
/**
 * @file my_super_number.c
 * @brief The file containing the my_super_number function
 * @author Nicolas TORO
 */

#include "my.h"

int my_errno;

static char not_a_number(char c)
{
    if ((c < '0' || c > '9') && c != '-' && c != '+')
            return 1;
    return 0;
}

static char check_end(char *number, number_settings_t *settings,
    int i, int start)
{
    my_errno = 0;
    if ((!settings->letter_before && not_a_number(number[i]) && start == -1)
    || (!settings->letter_after && not_a_number(number[i]) && start != -1)
    || (!settings->letter_after && (number[i] == '-' || number[i] == '+')
    && start != -1)
    || (!settings->multiple_signe && i != 0 && (number[i] == '-' ||
    number[i] == '+') && (number[i - 1] == '-' || number[i - 1] == '+'))
    || (!settings->overflow && (i > start + 9 ||
    (i > start + 8 && number[start] != '1' && number[start] != '2')))) {
        my_errno = 1;
        return 1;
    }
    if (settings->letter_after && not_a_number(number[i]) && start != -1)
        return 1;
    return 0;
}

int my_super_number(char *number, number_settings_t settings)
{
    int nb = 0;
    int start = -1;
    char neg = 1;

    if (number[0] == '\0')
        return nb;
    for (int i = 0; number[i] != '\0'; i++) {
        if (check_end(number, &settings, i, start))
            return nb * neg;
        if ((settings.letter_before && not_a_number(number[i]) && start == -1)
        || (settings.letter_after && not_a_number(number[i]) && start != -1))
            neg = 1;
        if (number[i] == '-' && start == -1)
            neg = neg * -1;
        if (start == -1 && number[i] >= '1' && number[i] <= '9')
            start = i;
        if (number[i] >= '0' && number[i] <= '9')
            nb = nb * 10 + (number[i] - 48);
    }
    return nb * neg;
}
