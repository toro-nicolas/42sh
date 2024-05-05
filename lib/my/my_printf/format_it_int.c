/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** The functions for apply format to an int
*/
/**
 * @file format_it_int.c
 * @brief The file containing the format_it_int function
 * @author Nicolas TORO
 */

#include "myprintf.h"

void format_it_int(char *str_finale, formating_t *formating, size_t nb)
{
    void (*format[])(char *, formating_t *, size_t) =
        {&format_moins_int, &format_plus_int,
        &format_esp_int, &format_hash_int, &format_zero_int};

    if (formating->id_ft == -1 && formating->id_wd != -1) {
        format[2](str_finale, formating, nb);
    }
    for (int i = 0; i < 5; i++) {
        if (formating->id_ft == i) {
            format[i](str_finale, formating, nb);
        }
    }
    return;
}
