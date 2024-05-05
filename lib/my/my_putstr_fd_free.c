/*
** EPITECH PROJECT, 2024
** my_putstr_fd_free
** File description:
** Write a string (str) in a file descriptor (fd), free it
** and returns the length of the printed string
*/
/**
 * @file my_putstr_fd_free.c
 * @brief The file containing the my_putstr_fd_free function
 * @author Nicolas TORO
 */

#include "my.h"

int my_putstr_fd_free(char *str, int fd)
{
    int len;

    if (str == NULL || fd < 0)
        return 0;
    len = my_strlen(str);
    write(fd, str, len);
    FREE(str);
    return len;
}
