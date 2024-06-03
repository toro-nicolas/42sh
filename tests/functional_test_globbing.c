/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The globbing.ini
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../include/myshell.h"

Test(globbing1, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls /usr/bin/*\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(globbing2, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls /usr/bin/b*\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(globbing3, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls /usr/bin/?b*\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(globbing4, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls /usr/bin/linux[0-9][0-9]\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(globbing5, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls /usr/bin/[Aa-Yy]*\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(globbing6, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cd src ; ls *.{c,o}\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}
