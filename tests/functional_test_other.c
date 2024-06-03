/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The other.ini
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../include/myshell.h"

Test(other1, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(other2, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "echo \"ls\" > source_me\n");
    fprintf(file, "source source_me\n");
    fprintf(file, "rm source_me\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(other3, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "source\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(other4, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "echo Hello World\n");
    fprintf(file, "echo $?\n");
    fprintf(file, "echo *\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(other5, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "echo test && (env | grep PATH)\n");
    fprintf(file, "(env | grep HOME) && echo 42sh\n");
    fprintf(file, "cd /etc; (cd / && ls); ls\n");
    fprintf(file, "(ls && cd /random) || pwd\n");
    fprintf(file, "(ls ; pwd) > test\n");
    fprintf(file, "cat test\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(other6, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "set TEST1=42sh; set TEST2=mysh; set | grep TEST; unset TEST1; set | grep TEST\n");
    fprintf(file, "set TEST21=42sh; set | grep TEST; set TEST21=mysh; set | grep TEST\n");
    fprintf(file, "set TEST31=42sh; set TEST32=mysh; set TEST31=mysh; set | grep TEST; unset TEST32\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(other7, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "echo \"echo Hello World\" > script\n");
    fprintf(file, "echo \"ls ; pwd\" >> script\n");
    fprintf(file, "./script\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}
