/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** The functions for apply format to a string
*/
/**
 * @file format_it_str.c
 * @brief The file containing the format_it_str function
 * @author Nicolas TORO
 */

#include "myprintf.h"

void format_it_str(char *str_finale,
    formating_t *formating)
{
    void (*format[])(char *, formating_t *) =
        {&format_moins_str, &format_plus_str,
        &format_esp_str, &format_hash_str, &format_zero_str};

    if (formating->id_ft == -1 && formating->id_wd != -1)
        format[2](str_finale, formating);
    for (int i = 0; i < 5; i++) {
        if (formating->id_ft == i)
            format[i](str_finale, formating);
    }
    return;
}
