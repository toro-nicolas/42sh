/*
** EPITECH PROJECT, 2023
** my_putstr_fd
** File description:
** Writes a string (str) in a file descriptor (fd)
** and returns the length of the printed string
*/
/**
 * @file my_putstr_fd.c
 * @brief The file containing the my_putstr_fd function
 * @author Nicolas TORO
 */

#include "my.h"

int my_putstr_fd(char const *str, int fd)
{
    int len;

    if (str == NULL || fd < 0)
        return 0;
    len = my_strlen(str);
    write(fd, str, len);
    return len;
}
