/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** The functions for format an int
*/
/**
 * @file sub_format_int.c
 * @brief The functions for format an int
 * @author Nicolas TORO
 */

#include "myprintf.h"

static void do_next(char *str_finale, formating_t *formating, double nb)
{
    void (*format[])(char *, formating_t *, size_t) =
        {&format_moins_int, &format_plus_int, &format_esp_int,
        &format_hash_int, &format_zero_int};

    for (int j = 0; j < 5; j++) {
        if (formating->next_chara == FORMATAGE[j]) {
            formating->next_chara = 1;
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

void format_plus_int(char *str_finale,
    formating_t *formating, size_t nb)
{
    if ((formating->flag != 'b')
        && (formating->flag != 'x') && (formating->flag != 'X')
        && (formating->flag != 'o') && (formating->flag != 'u')){
        my_revstr(str_finale);
        my_strcat(str_finale, "+");
        if (formating->id_wd != -1 && formating->next_chara != '-')
            en_plus(str_finale, formating);
        my_revstr(str_finale);
    }
    if (formating->next_chara == '+' || formating->next_chara == '-')
        do_next(str_finale, formating, nb);
}

void format_moins_int(char *str_finale,
    formating_t *formating, size_t nb)
{
    if (formating->next_chara == '+')
        formating->id_wd -= 1;
    if ((my_strlen(str_finale) < formating->id_wd
        && formating->next_chara == '+')
        || my_strlen(str_finale) < formating->id_wd) {
        for (int i = my_strlen(str_finale); i < formating->id_wd; i++) {
            my_strcat(str_finale, " ");
        }
    }
    if (formating->next_chara == '+' || formating->next_chara == '-')
        do_next(str_finale, formating, nb);
}

void format_esp_int(char *str_finale, formating_t *formating, size_t nb)
{
    if (formating->next_chara == '+' || formating->next_chara == '-')
        do_next(str_finale, formating, nb);
    my_revstr(str_finale);
    for (int i = my_strlen(str_finale); i < formating->id_wd; i++)
        my_strcat(str_finale, " ");
    my_revstr(str_finale);
}

void format_zero_int(char *str_finale,
    formating_t *formating, size_t nb)
{
    long long int i = my_strlen(str_finale);

    if (formating->next_chara != '-') {
        my_revstr(str_finale);
        for (i; (i < formating->id_wd && formating->next_chara != '+')
        || (i < formating->id_wd - 1 && formating->next_chara == '+'); i++)
            my_strcat(str_finale, "0");
        my_revstr(str_finale);
    }
    if (formating->next_chara == '+' || formating->next_chara == '-')
        do_next(str_finale, formating, nb);
}

void format_hash_int(char *str_finale,
    formating_t *formating, size_t nb)
{
    format_esp_int(str_finale, formating, nb);
    return;
}
