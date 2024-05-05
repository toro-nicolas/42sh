/*
** EPITECH PROJECT, 2023
** my_print_combn
** File description:
** Prints all the numbers composed by (n) different digits numbers
** All digits in the number are different and only the smallest
** number composed by those digits are display
*/
/**
 * @file my_print_combn.c
 * @brief The file containing the my_print_combn function
 * @author Nicolas TORO
 */

#include "my.h"

static char *str_number_to_int(int nb, int n)
{
    int len_nb = 1;
    int temp_nb = nb;
    char *nb_str;
    int figure_temp = nb;
    int nb_zero = 0;

    while ((temp_nb / 10) != 0) {
        len_nb = len_nb + 1;
        temp_nb = temp_nb / 10;
    }
    nb_str = malloc(sizeof(char) * n);
    for (; nb_zero < n - len_nb - 1; nb_zero++)
        nb_str[nb_zero] = '0';
    for (int i = 0; i < n; i++) {
        nb_str[n - i - 1 + nb_zero] = 48 + (figure_temp % 10);
        figure_temp = (figure_temp - (figure_temp % 10)) / 10;
    }
    nb_str[n] = '\0';
    return nb_str;
}

static int check_printable(char *number, int figure, int *start)
{
    if (number[figure - 1] >= number[figure])
        return 1;
    if (figure - 1 == 0) {
        if (*start == 1)
            *start = 0;
        else {
            my_putchar(',');
            my_putchar(' ');
        }
        my_putstr(number);
    }
    return 0;
}

void my_print_combn(int n)
{
    int stop = 0;
    int start = 1;

    for (int number = 0; number < my_compute_power_rec(10, n); number++) {
        for (int figure = n - 1; figure >= 0 && stop == 0; figure--) {
            stop = check_printable(str_number_to_int(number, n),
            figure, &start);
        }
        stop = 0;
    }
}
