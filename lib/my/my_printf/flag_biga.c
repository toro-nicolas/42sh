/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Flag to print a %A (a double in hexadecimal)
*/
/**
 * @file flag_biga.c
 * @brief The file containing the flag_biga function
 * @author Nicolas TORO
 */

#include "myprintf.h"

static char *my_get_exposant_neg(int *nbr, char *converted_nb,
    char *exposant_temp)
{
    char *signe = malloc(sizeof(char) * 2);

    if (converted_nb[0] < '4'
        && my_strcmp(converted_nb, "3FF0000000000000") <= 0) {
        signe[0] = '\0';
        *nbr = my_getnbr(my_convert_base(exposant_temp, "0123456789ABCDEF",
            "0123456789")) - 0x400;
    } else {
        signe[0] = '+';
        *nbr = my_getnbr(my_convert_base(exposant_temp, "0123456789ABCDEF",
            "0123456789")) - 0x400;
    }
    signe[1] = '\0';
    return signe;
}

static char *my_get_exposant_pos(int *nbr, char *converted_nb,
    char *exposant_temp)
{
    char *signe = malloc(sizeof(char) * 2);

    if (converted_nb[0] < 'C'
        && my_strcmp(converted_nb, "BFF0000000000000") <= 0) {
        signe[0] = '\0';
        *nbr = my_getnbr(my_convert_base(exposant_temp, "0123456789ABCDEF",
            "0123456789")) - 0xC00;
    } else {
        signe[0] = '+';
        *nbr = my_getnbr(my_convert_base(exposant_temp, "0123456789ABCDEF",
            "0123456789")) - 0xC00;
    }
    signe[1] = '\0';
    return signe;
}

static char *my_get_exposant(char *converted_nb, char *signe)
{
    char *exposant = malloc(sizeof(char) * 6);
    char exposant_temp[4];
    int nbr = 0;

    exposant[0] = 'P';
    exposant_temp[0] = converted_nb[0];
    exposant_temp[1] = converted_nb[1];
    exposant_temp[2] = converted_nb[2];
    exposant_temp[3] = '\0';
    if (my_strcmp(signe, "-") != 0) {
        my_strcat(exposant, my_get_exposant_neg(&nbr, converted_nb,
            exposant_temp));
    } else {
        my_strcat(exposant, my_get_exposant_pos(&nbr, converted_nb,
            exposant_temp));
    }
    my_strcat(exposant, my_str_nbr(nbr + 1));
    my_strcat(exposant, "\0");
    return exposant;
}

static char *my_get_decimal_part(char *converted_nb, int *detected)
{
    char *decimal_part = malloc(sizeof(char) * (my_strlen(converted_nb) - 2));
    int chara = 3;

    for (; chara < my_strlen(converted_nb); chara++) {
        if (converted_nb[chara] == '0' && *detected == -1)
            *detected = chara - 3;
        if (converted_nb[chara] != '0')
            *detected = -1;
        decimal_part[chara - 3] = converted_nb[chara];
    }
    decimal_part[*detected] = '\0';
    return decimal_part;
}

static char *my_get_sign(char *converted_nb)
{
    if (converted_nb[0] > '7')
        return "-";
    else
        return "";
}

static void precise_zero(char *float_nb, int precision)
{
    if (precision < 1) {
        my_strcat(float_nb, "0X0P+0");
    } else {
        my_strcat(float_nb, "0X0.");
        for (int i = 0; i < precision; i++)
            my_strcat(float_nb, "0");
        my_strcat(float_nb, "P+0");
    }
}

static void precise_it_biga(char *float_nb, formating_t *formating,
    char *decimal_part, int detected)
{
    char temp[2];
    int i = 0;

    if (formating->id_nb == 0
        || (formating->id_prc == 0 && formating->id_nb == -1))
        return;
    if (formating->id_nb == -1 && detected != 0) {
        my_strcat(float_nb, ".");
        my_strcat(float_nb, decimal_part);
        return;
    }
    if (formating->id_nb > 0) {
        my_strcat(float_nb, ".");
        for (; i < formating->id_nb && decimal_part[i] != '\0'; i++) {
            temp[0] = decimal_part[i];
            my_strcat(float_nb, temp);
        }
        round_biga(float_nb, formating->id_nb, decimal_part[i], i);
        return;
    }
}

static char *my_get_str_float_hexa(double nb, formating_t *formating)
{
    char *converted_nb = my_convert_base_size_t(
        my_str_nbr_size_t(*(size_t *)&nb),
        "0123456789", "0123456789ABCDEF");
    char *float_nb = malloc(sizeof(char) * (my_strlen(converted_nb) + 6));
    int detected = -1;
    char *decimal_part = malloc(sizeof(char) * (my_strlen(converted_nb) - 2));

    my_strcat(float_nb, my_get_sign(converted_nb));
    if (my_strcmp(converted_nb, "0") == 0) {
        precise_zero(float_nb, formating->id_nb);
        return float_nb;
    }
    my_strcat(float_nb, "0X1");
    decimal_part = my_get_decimal_part(converted_nb, &detected);
    precise_it_biga(float_nb, formating, decimal_part, detected);
    my_strcat(float_nb, my_get_exposant(converted_nb,
        my_get_sign(converted_nb)));
    FREE(decimal_part);
    return float_nb;
}

int flag_biga(va_list list, formating_t *formating)
{
    double temp_double = va_arg(list, double);
    char *convert_base = my_get_str_float_hexa(temp_double, formating);

    format_it_double(convert_base, formating, temp_double);
    return my_putstr_fd_free(convert_base, formating->fd);
}
