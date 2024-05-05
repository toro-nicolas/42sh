/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** The functions for format a char
*/
/**
 * @file sub_format_char.c
 * @brief The file containing the sub_format_char functions
 * @author Nicolas TORO
 */

#include "myprintf.h"

static void do_next_char(char *str_finale,
    formating_t *formating, char c)
{
    void (*format[])(char *, formating_t *, char) =
        {&format_moins_char, &format_plus_char, &format_esp_char,
        &format_hash_char, &format_zero_char};

    for (int j = 0; j < 5; j++) {
        if (formating->next_chara == FORMATAGE[j]) {
            format[j](str_finale, formating, c);
            return;
        }
    }
}

void format_plus_char(char *str_finale,
    formating_t *formating, char c)
{
    format_esp_char(str_finale, formating, c);
    return;
}

void format_moins_char(char *str_finale,
    formating_t *formating, char c)
{
    if ((my_strlen(str_finale) < formating->id_wd
        && formating->next_chara == '+')
        || my_strlen(str_finale) < formating->id_wd) {
        for (int i = my_strlen(str_finale); i < formating->id_wd; i++) {
            my_strcat(str_finale, " ");
        }
    }
    do_next_char(str_finale, formating, c);
}

void format_esp_char(char *str_finale,
    formating_t *formating, char c)
{
    my_revstr(str_finale);
    for (int i = my_strlen(str_finale); i < formating->id_wd; i++)
        my_strcat(str_finale, " ");
    my_revstr(str_finale);
}

void format_zero_char(char *str_finale,
    formating_t *formating, char c)
{
    long long int i = my_strlen(str_finale);

    my_revstr(str_finale);
    for (i;(i < formating->id_wd && formating->next_chara != '+')
        || (i < formating->id_wd - 1 && formating->next_chara == '+')
        ; i++)
        my_strcat(str_finale, "0");
    my_revstr(str_finale);
    do_next_char(str_finale, formating, c);
}

void format_hash_char(char *str_finale,
    formating_t *formating, char c)
{
    format_esp_char(str_finale, formating, c);
    return;
}
