/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** Returns 0 if the strings (s1 and s2) are identical,
** otherwise it returns the difference
*/
/**
 * @file my_strcmp.c
 * @brief The file containing the my_strcmp function
 * @author Nicolas TORO
 */

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return 0 - s2[0];
    if (s2 == NULL)
        return s1[0] - 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}
