/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** The functions for format a double
*/
/**
 * @file sub_format_double.c
 * @brief The file containing the sub_format_double functions
 * @author Nicolas TORO
 */

#include "myprintf.h"

static void do_next(char *str_finale, formating_t *formating, double nb)
{
    void (*format[])(char *, formating_t *, double) =
        {&format_moins_double, &format_plus_double, &format_esp_double,
        &format_hash_double, &format_zero_double};

    for (int j = 0; j < 5; j++) {
        if (formating->next_chara == FORMATAGE[j]) {
            format[j](str_finale, formating, nb);
            return;
        }
    }
}

static void en_plus(char *str_finale, formating_t *formating)
{
    for (int i = my_strlen(str_finale); i < formating->id_wd; i++)
        my_strcat(str_finale, " ");
}

void format_plus_double(char *str_finale, formating_t *formating, double nb)
{
    if (nb >= 0) {
        my_revstr(str_finale);
        my_strcat(str_finale, "+");
        if (formating->id_wd != -1)
            en_plus(str_finale, formating);
        my_revstr(str_finale);
    }
}

void format_moins_double(char *str_finale, formating_t *formating, double nb)
{
    if ((my_strlen(str_finale) < formating->id_wd
        && formating->next_chara == '+')
        || my_strlen(str_finale) < formating->id_wd) {
        for (int i = my_strlen(str_finale); i < formating->id_wd; i++) {
            my_strcat(str_finale, " ");
        }
    }
    do_next(str_finale, formating, nb);
}

void format_esp_double(char *str_finale, formating_t *formating, double nb)
{
    do_next(str_finale, formating, nb);
    my_revstr(str_finale);
    for (int i = my_strlen(str_finale); i < formating->id_wd; i++)
        my_strcat(str_finale, " ");
    if (formating->id_wd == -1 && formating->next_chara != '+'
        && formating->id_prc == -1)
        my_strcat(str_finale, " ");
    if (formating->id_wd != -1
        && my_strlen(str_finale) > formating->id_wd
        && (formating->flag == 'a' || formating->flag == 'A'))
        my_strcat(str_finale, " ");
    my_revstr(str_finale);
}

void format_zero_double(char *str_finale, formating_t *formating, double nb)
{
    long long int i = my_strlen(str_finale);

    my_revstr(str_finale);
    for (i;(i < formating->id_wd && formating->next_chara != '+')
        || (i < formating->id_wd - 1 && formating->next_chara == '+')
        ; i++)
        my_strcat(str_finale, "0");
    my_revstr(str_finale);
    do_next(str_finale, formating, nb);
}

void format_hash_double(char *str_finale, formating_t *formating, double nb)
{
    format_esp_double(str_finale, formating, nb);
    return;
}
