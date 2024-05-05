/*
** EPITECH PROJECT, 2023
** my_getnbr_base
** File description:
** Returns an int number starting from a string number (str)
** in the requested base (base)
*/
/**
 * @file my_getnbr_base.c
 * @brief The file containing the my_getnbr_base function
 * @author Nicolas TORO
 */

#include "my.h"

static int is_valid(char c, char const *base)
{
    for (int i = 0; i < my_strlen(base); i++) {
        if (c == base[i])
            return 1;
    }
    if (c == '-' || c == '+')
        return 1;
    return 0;
}

static int calculate_base(char const *str, char const *base,
    int *index, int **ptr)
{
    if (is_valid(str[index[0]], base) == 1) {
        if (str[index[0]] == '-') {
            *(ptr[0]) = - *(ptr[0]);
            return 0;
        }
        if (str[index[0]] == base[index[1]]) {
            return index[1] * my_compute_power_rec(my_strlen(base),
            my_strlen(str) - index[0] - 1);
        }
    } else {
        *(ptr[1]) = 1;
    }
    return 0;
}

int my_getnbr_base(char const *str, char const *base)
{
    int result = 0;
    int signe_save = 0;
    int signe = 1;
    int error = 0;
    int index[2];
    int *ptr[2];

    for (int i = my_strlen(str) - 1; i >= 0; i--) {
        for (int j = 0; j < my_strlen(base) && error == 0 && signe == 1; j++) {
            index[0] = i;
            index[1] = j;
            ptr[0] = &signe;
            ptr[1] = &error;
            result = result + calculate_base(str, base, index, ptr);
        }
        signe_save = signe;
        signe = 1;
    }
    return result * signe_save;
}
