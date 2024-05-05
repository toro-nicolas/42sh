/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Flag to print a %E (a double)
*/
/**
 * @file flag_bige.c
 * @brief The file containing the flag_bige function
 * @author Nicolas TORO
 */

#include "myprintf.h"

static char *my_get_str_float(double nb, formating_t *formating)
{
    long long int partie_entiere = ABS((int)nb);
    double partie_d = ABS(nb - partie_entiere);
    char *str_finale = malloc(sizeof(char) * 1000000);

    if (nb < 0){
        my_strcat(str_finale, "-");
        nb = -nb;
    }
    my_strcat(str_finale, my_str_nbr_long_long(partie_entiere));
    precise_it_double(str_finale, formating, partie_d);
    return str_finale;
}

static char *my_get_power(int exposant)
{
    char *power;

    if (ABS(exposant) >= 100) {
        power = malloc(sizeof(char) * 5);
    } else {
        power = malloc(sizeof(char) * 4);
    }
    if (exposant >= 0) {
        my_strcat(power, "+");
    } else {
        my_strcat(power, "-");
    }
    if (ABS(exposant) < 10)
        my_strcat(power, "0");
    my_strcat(power, my_str_nbr(ABS(exposant)));
    my_strcat(power, "\0");
    return power;
}

static void condition(double nb, int *exposant,
    double *temp_nb_double, int *temp_nb)
{
    if (ABS(nb) > 1) {
        for (int i = 0; i < my_strlen(my_str_nbr(ABS(nb))) - 1; i++) {
            *exposant = *exposant + 1;
            *temp_nb_double = *temp_nb_double / 10;
        }
    } else {
        while (*temp_nb % 10 == 0) {
            *exposant = *exposant - 1;
            *temp_nb_double = *temp_nb_double * 10;
            *temp_nb = *temp_nb_double;
        }
    }
}

static char *my_get_str_float_scientific(double nb, formating_t *formating)
{
    char *float_nb;
    int signe = 0;
    int exposant = 0;
    int temp_nb = nb;
    double temp_nb_double = nb;

    if (nb < 0)
        signe = 1;
    float_nb = malloc(sizeof(char) * (16 + signe));
    if (nb == 0.0) {
        my_strcat(float_nb, my_get_str_float(temp_nb_double, formating));
        my_strcat(float_nb, "E+00\0");
        return float_nb;
    }
    condition(nb, &exposant, &temp_nb_double, &temp_nb);
    my_strcat(float_nb, my_get_str_float(temp_nb_double, formating));
    my_strcat(float_nb, "E");
    my_strcat(float_nb, my_get_power(exposant));
    return float_nb;
}

int flag_bige(va_list list, formating_t *formating)
{
    double temp_double = va_arg(list, double);
    char *temp = my_get_str_float_scientific(temp_double, formating);

    format_it_double(temp, formating, temp_double);
    return my_putstr_fd_free(temp, formating->fd);
}
