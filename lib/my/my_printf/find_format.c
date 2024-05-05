/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** The file that contains functions for find all format
*/
/**
 * @file find_format.c
 * @brief The file that contains functions for find all format
 * @author Nicolas TORO
 */

#include "myprintf.h"

formating_t *find_specifier(user_t *user,
    int *i, formating_t *formating)
{
    char str[5] = {0};
    formating_t *copy2 = formating;
    char *specifier[] = {"l", "ll", "h", "hh", "j", "z", "t", "L", NULL};

    str[0] = user->str[*i];
    if (user->str[*i + 1] == 'l' || user->str[*i + 1] == 'h')
        str[1] = user->str[*i + 1];
    for (; specifier[copy2->id_sp] != NULL; (copy2->id_sp)++) {
        if (my_strcmp(str, specifier[copy2->id_sp]) == 0) {
            my_strcat((copy2->final_format), str);
            return copy2;
        }
    }
    formating = copy2;
    formating->id_sp = -1;
    return formating;
}

static int check_star_prc(user_t *user,
    formating_t *formating, formating_t *copy2, int nb)
{
    char str[1000] = {0};

    if (formating->index_user == '*') {
        nb = va_arg(*(formating->liste), int);
        my_strcat(str, my_str_nbr(nb));
        my_strcat((copy2->final_format), str);
        formating->id_nb = nb;
        return 1;
    }
    return 0;
}

formating_t *find_numbers(user_t *user, int *i,
    formating_t *formating)
{
    char str[1000] = {0};
    formating_t *copy2 = formating;
    int nb = 0;

    for (; NUMBERS[copy2->id_nb] != '\0'; (copy2->id_nb)++) {
        formating->index_user = user->str[*i];
        if (check_star_prc(user, formating, copy2, nb) == 1)
            return copy2;
        if (user->str[*i] == NUMBERS[copy2->id_nb]) {
            nb = my_getnbr(&user->str[*i]);
            my_strcat(str, my_str_nbr(nb));
            my_strcat((copy2->final_format), str);
            formating->id_nb = nb;
            return copy2;
        }
    }
    formating = copy2;
    formating->id_nb = -1;
    return formating;
}

formating_t *find_precision(user_t *user,
    int *i, formating_t *formating)
{
    char str[5] = {0};
    formating_t *copy2 = formating;

    for (; PRECISION[copy2->id_prc] != '\0'; (copy2->id_prc)++) {
        if (user->str[*i] == PRECISION[copy2->id_prc]) {
            str[0] = user->str[*i];
            my_strcat((copy2->final_format), str);
            return copy2;
        }
    }
    formating = copy2;
    formating->id_prc = -1;
    return formating;
}

static int check_star_wd(user_t *user,
    formating_t *formating, formating_t *copy2, int nb)
{
    char str[1000] = {0};

    if (formating->index_user == '*') {
        nb = va_arg(*(formating->liste), int);
        my_strcat(str, my_str_nbr(nb));
        my_strcat((copy2->final_format), str);
        formating->id_wd = nb;
        return 1;
    }
    return 0;
}

formating_t *find_width(user_t *user,
    int *i, formating_t *formating)
{
    char str[1000] = {0};
    formating_t *copy2 = formating;
    int nb = 0;

    for (; WIDTH[copy2->id_wd] != '\0'; (copy2->id_wd)++) {
        formating->index_user = user->str[*i];
        if (check_star_wd(user, formating, copy2, nb) == 1)
            return copy2;
        if (user->str[*i] == WIDTH[copy2->id_wd]) {
            nb = ABS(my_getnbr(&(user->str[*i])));
            my_strcat(str, my_str_nbr(nb));
            my_strcat((copy2->final_format), str);
            formating->id_wd = nb;
            return copy2;
        }
    }
    formating = copy2;
    formating->id_wd = -1;
    return formating;
}

static void check_nextesp(formating_t *copy2, formating_t *formating)
{
    if (formating->next_chara == '+')
        my_strcat(copy2->final_format, "+");
    if (formating->next_chara == '-')
        my_strcat(copy2->final_format, "-");
}

formating_t *find_first(user_t *user,
    int *i, formating_t *formating)
{
    char str[5] = {0};
    formating_t *copy2 = formating;

    for (; FORMATAGE[copy2->id_ft] != '\0'; (copy2->id_ft)++) {
        if (user->str[*i] == FORMATAGE[copy2->id_ft]) {
            str[0] = user->str[*i];
            formating->next_chara = (user->str[*i + 1]);
            my_strcat((copy2->final_format), str);
            check_nextesp(copy2, formating);
            return copy2;
        }
    }
    formating = copy2;
    formating->id_ft = -1;
    return formating;
}
