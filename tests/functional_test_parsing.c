/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The parsing.ini
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../include/myshell.h"

Test(parsing1, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(parsing2, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "			 ls		\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(parsing3, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, " \n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(parsing4, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "\\t\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(parsing5, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(parsing6, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "\"\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(parsing7, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "\"\"\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(parsing8, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}
