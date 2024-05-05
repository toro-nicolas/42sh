/*
** EPITECH PROJECT, 2023
** my_fprintf
** File description:
** Writes a string (format) with possible flags and format
** in a file descriptor (fd) and returns the length the printed string
*/
/**
 * @file my_fprintf.c
 * @brief The file containing the my_fprintf function
 * @author Nicolas TORO
 */

#include "./my_printf/myprintf.h"

static void find_format(user_t *user,
    flags_t *flgs, formating_t *formating)
{
    int copy = user->i + 1;

    formating->nb_format = 0;
    format_first(user, flgs, formating, &copy);
    copy = user->i + 1 + formating->nb_format;
    format_width(user, flgs, formating, &copy);
    copy = user->i + 1 + formating->nb_format;
    format_precision(user, flgs, formating, &copy);
    copy = user->i + 1 + formating->nb_format;
    format_numbers(user, flgs, formating, &copy);
    copy = user->i + 1 + formating->nb_format;
    format_specifier(user, flgs, formating, &copy);
    copy = user->i + 1 + formating->nb_format;
    formating->flag = user->str[copy];
}

static void not_a_flag(formating_t *formating, user_t *user)
{
    write(formating->fd, "%", 1);
    user->total_len = user->total_len + 1;
    if (my_strcmp(formating->final_format, "\0") != 0)
        user->total_len = user->total_len +
            my_putstr_fd(formating->final_format, formating->fd);
    if (formating->flag != '\0') {
        write(formating->fd, &formating->flag, 1);
        user->total_len = user->total_len + 1;
    }
}

static void find_flags(user_t *user, va_list list,
    formating_t *formating, int *index)
{
    flags_t flgs = {.str = "dicspouxXeEfFgGaAbSD%m", .index_flag = 0};
    int copi;

    find_format(user, &flgs, formating);
    copi = user->i + my_strlen(formating->final_format) + 1;
    user->i = user->i + (my_strlen(formating->final_format)) + 1;
    for (; flgs.index_flag < my_strlen(flgs.str); flgs.index_flag++) {
        if (user->str[copi] == 'n') {
            flag_n(list, formating, user->total_len);
            return;
        }
        if (user->str[copi] == flgs.str[flgs.index_flag]) {
            *index = flgs.index_flag;
            return;
        }
    }
    not_a_flag(formating, user);
    *index = -1;
}

static void select_display(int fd, user_t *user, va_list *liste)
{
    int index_flag = -1;
    formating_t formating = {.fd = fd, .liste = liste};

    if (user->str[user->i] == '%')
        find_flags(user, *liste, &formating, &index_flag);
    if (index_flag != -1)
        user->total_len += FLAGS[index_flag](*liste, &formating);
    if (user->str[user->i] != '%' && user->str[user->i] != '\0'
        && (user->str[user->i] != formating.flag)) {
        write(fd, &user->str[user->i], 1);
        (user->total_len)++;
    }
}

int my_fprintf(int fd, char const *format, ...)
{
    va_list liste;
    user_t user = {.str = format, .total_len = 0};

    va_start(liste, format);
    for (user.i = 0; user.i < my_strlen(user.str); (user.i)++)
        select_display(fd, &user, &liste);
    va_end(liste);
    return user.total_len;
}
