/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Flag to print a %g (a double)
*/
/**
 * @file flag_bigg.c
 * @brief The file containing the flag_bigg function
 * @author Nicolas TORO
 */

#include "myprintf.h"

static int check_precision(int precision, int nb)
{
    if (precision - my_strlen(my_str_nbr(ABS(nb))) <= 0)
        return 0;
    else
        return precision - my_strlen(my_str_nbr(ABS(nb)));
}

static int get_nb_zero(double nb)
{
    int index = 0;
    int temp_nb = 0;
    double temp_nb_double = nb;

    if (ABS(nb) < 1) {
        while (temp_nb % 10 == 0) {
            index = index + 1;
            temp_nb_double = temp_nb_double * 10;
            temp_nb = temp_nb_double;
        }
        return index - 1;
    }
    return 0;
}

static void my_get_decimal_part(char *float_nb, double nb,
    formating_t *formating)
{
    size_t precision_size = my_compute_power_rec_size_t(10, check_precision
    (formating->id_nb, nb) + get_nb_zero(nb));
    size_t nb_convert = ABS(nb * precision_size);
    int i = 0;
    char temp[2] = "";

    if (nb_convert % precision_size != 0)
        my_strcat(float_nb, ".");
    for (i = 0; i < get_nb_zero(nb - (int)nb); i++)
        my_strcat(float_nb, "0");
    for (int j = 0; j < my_strlen(my_str_nbr_long_long(nb_convert)); j++) {
        temp[0] = my_str_nbr_long_long(nb_convert % precision_size)[j];
        my_strcat(float_nb, temp);
    }
    nb_convert = ABS(nb * my_compute_power_rec_size_t(10, check_precision
    (formating->id_nb, nb) + get_nb_zero(nb) + 1));
    my_round_float_str(float_nb, 48 + (nb_convert % 10),
    my_strlen(float_nb) - 1, 0);
}

static char *my_get_str_float(double nb, formating_t *formating)
{
    char *float_nb = malloc(sizeof(char) *
        my_strlen(my_str_nbr(nb)) + 9 + formating->id_nb);
    int i = 0;

    formating->id_nb = (formating->id_prc != -1) ? (formating->id_nb) : 6;
    if (nb < 0)
        my_strcat(float_nb, "-");
    my_strcat(float_nb, my_str_nbr_long_long(ABS(nb)));
    if (formating->id_nb > 0 && check_precision(formating->id_nb, nb) != 0) {
        my_get_decimal_part(float_nb, nb, formating);
        i = my_strlen(float_nb) - 1;
        for (i; (float_nb[i] == '0' || float_nb[i] == '.') && i != 0; i--)
            float_nb[i] = '\0';
    }
    my_strcat(float_nb, "\0");
    return float_nb;
}

static char *my_get_power(int index_nb)
{
    char *power;

    if (ABS(index_nb) >= 100) {
        power = malloc(sizeof(char) * 5);
    } else {
        power = malloc(sizeof(char) * 4);
    }
    if (index_nb >= 0) {
        my_strcat(power, "+");
    } else {
        my_strcat(power, "-");
    }
    if (ABS(index_nb) < 10)
        my_strcat(power, "0");
    my_strcat(power, my_str_nbr(ABS(index_nb)));
    my_strcat(power, "\0");
    return power;
}

static void condition(double nb, int *index_nb,
    double *temp_nb_double, int *temp_nb)
{
    if (ABS(nb) > 1) {
        for (int i = 0; i < my_strlen(my_str_nbr(ABS(nb))) - 1; i++) {
            *index_nb = *index_nb + 1;
            *temp_nb_double = *temp_nb_double / 10;
        }
    } else {
        while (*temp_nb % 10 == 0) {
            *index_nb = *index_nb - 1;
            *temp_nb_double = *temp_nb_double * 10;
            *temp_nb = *temp_nb_double;
        }
    }
}

static char *my_get_str_float_scientific(double nb, formating_t *formating)
{
    char *float_nb;
    int signe = 0;
    int index_nb = 0;
    int temp_nb = nb;
    double temp_nb_double = nb;

    if (nb < 0)
        signe = 1;
    float_nb = malloc(sizeof(char) * (13 + signe));
    condition(nb, &index_nb, &temp_nb_double, &temp_nb);
    my_strcat(float_nb, my_get_str_float(temp_nb_double, formating));
    my_strcat(float_nb, "E");
    my_strcat(float_nb, my_get_power(index_nb));
    return float_nb;
}

static int my_get_index(double nb)
{
    int index_nb = 0;
    int temp_nb = nb;
    double temp_nb_double = nb;

    if (nb == 0.0)
        return 0;
    if (ABS(nb) > 1) {
        return my_strlen(my_str_nbr(ABS(nb)));
    } else {
        while (temp_nb % 10 == 0) {
            index_nb = index_nb - 1;
            temp_nb_double = temp_nb_double * 10;
            temp_nb = temp_nb_double;
        }
    }
    return index_nb;
}

int flag_bigg(va_list list, formating_t *formating)
{
    double temp_double = va_arg(list, double);
    int index = ABS(my_get_index(temp_double));
    char *temp;
    int free = 1;

    if (temp_double == 0.0) {
        temp = "0";
        free = 0;
    } else if (index - 3 < 4 && (index <= formating->id_nb ||
        formating->id_nb == -1)) {
        temp = my_get_str_float(temp_double, formating);
    } else {
        temp = my_get_str_float_scientific(temp_double, formating);
    }
    format_it_double(temp, formating, temp_double);
    if (free)
        return my_putstr_fd_free(temp, formating->fd);
    return my_putstr_fd(temp, formating->fd);
}
