/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** The functions for format a string
*/
/**
 * @file sub_format_str.c
 * @brief The file containing the sub_format_str functions
 * @author Nicolas TORO
*/

#include "myprintf.h"

static void do_next_str(char *str_finale,
    formating_t *formating)
{
    void (*format[])(char *, formating_t *) =
        {&format_moins_str, &format_plus_str, &format_esp_str,
        &format_hash_str, &format_zero_str};

    for (int j = 0; j < 5; j++) {
        if (formating->next_chara == FORMATAGE[j]) {
            format[j](str_finale, formating);
            return;
        }
    }
}

void format_plus_str(char *str_finale,
    formating_t *formating)
{
    format_esp_str(str_finale, formating);
    return;
}

void format_moins_str(char *str_finale,
    formating_t *formating)
{
    if ((my_strlen(str_finale) < formating->id_wd
        && formating->next_chara == '+')
        || my_strlen(str_finale) < formating->id_wd) {
        for (int i = my_strlen(str_finale); i < formating->id_wd; i++) {
            my_strcat(str_finale, " ");
        }
    }
    do_next_str(str_finale, formating);
}

void format_esp_str(char *str_finale,
    formating_t *formating)
{
    my_revstr(str_finale);
    for (int i = my_strlen(str_finale); i < formating->id_wd; i++)
        my_strcat(str_finale, " ");
    my_revstr(str_finale);
}

void format_zero_str(char *str_finale,
    formating_t *formating)
{
    format_esp_str(str_finale, formating);
}

void format_hash_str(char *str_finale,
    formating_t *formating)
{
    format_esp_str(str_finale, formating);
    return;
}
