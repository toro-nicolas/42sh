/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** The functions for apply format to a double
*/
/**
 * @file format_it_double.c
 * @brief The file containing the format_it_double function
 * @author Nicolas TORO
 */

#include "myprintf.h"

void format_it_double(char *str_finale,
    formating_t *formating, double nb)
{
    void (*format[])(char *, formating_t *, double) =
        {&format_moins_double, &format_plus_double,
        &format_esp_double, &format_hash_double, &format_zero_double};

    if (formating->id_wd != -1 && formating->id_ft == -1) {
        format[2](str_finale, formating, nb);
    }
    for (int i = 0; i < 5; i++) {
        if (formating->id_ft == i) {
            format[i](str_finale, formating, nb);
        }
    }
    return;
}
