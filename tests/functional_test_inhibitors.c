/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The inhibitors.ini
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../include/myshell.h"

Test(inhibitors1, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls > \"test file\"\n");
    fprintf(file, "ls >> \"test file\"\n");
    fprintf(file, "\"test file\"\n");
    fprintf(file, "ls | grep *test*file*\n");
    fprintf(file, "cat \"test file\"\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(inhibitors2, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls > \'test file\'\n");
    fprintf(file, "ls >> \'test file\'\n");
    fprintf(file, "\'test file\'\n");
    fprintf(file, "ls | grep *test*file*\n");
    fprintf(file, "cat \'test file\'\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(inhibitors3, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls > test\\ file\n");
    fprintf(file, "ls >> test\\ file\n");
    fprintf(file, "test\\ file\n");
    fprintf(file, "ls | grep *test*file*\n");
    fprintf(file, "cat test\\ file\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(inhibitors4, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls > \"test\\ file\"\n");
    fprintf(file, "ls >> \"test\\ file\"\n");
    fprintf(file, "\"test\\ file\"\n");
    fprintf(file, "ls | grep *test*file*\n");
    fprintf(file, "cat \"test\\ file\"\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(inhibitors5, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls > \\\"test\\ file\\\"\n");
    fprintf(file, "ls >> \\\"test\\ file\\\"\n");
    fprintf(file, "\\\"test\\ file\\\"\n");
    fprintf(file, "ls | grep *test*file*\n");
    fprintf(file, "cat \\\"test\\ file\\\"\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(inhibitors6, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls > \"test;;;file\"\n");
    fprintf(file, "ls >> \"test;;;file\"\n");
    fprintf(file, "\"test;;;file\"\n");
    fprintf(file, "ls | grep *test*file*\n");
    fprintf(file, "cat \"test;;;file\"\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(inhibitors7, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls > \"test&&&file\"\n");
    fprintf(file, "ls >> \"test&&&file\"\n");
    fprintf(file, "\"test&&&file\"\n");
    fprintf(file, "ls | grep *test*file*\n");
    fprintf(file, "cat \"test&&&file\"\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(inhibitors8, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls > \"test|||file\"\n");
    fprintf(file, "ls >> \"test|||file\"\n");
    fprintf(file, "\"test|||file\"\n");
    fprintf(file, "ls | grep *test*file*\n");
    fprintf(file, "cat \"test|||file\"\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(inhibitors9, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls > \"test|file\"\n");
    fprintf(file, "ls >> \"test|file\"\n");
    fprintf(file, "\"test|file\"\n");
    fprintf(file, "ls | grep *test*file*\n");
    fprintf(file, "cat \"test|file\"\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(inhibitors10, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls > \"test<file\"\n");
    fprintf(file, "ls >> \"test<file\"\n");
    fprintf(file, "\"test<file\"\n");
    fprintf(file, "ls | grep *test*file*\n");
    fprintf(file, "cat \"test<file\"\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(inhibitors11, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls > \"test>file\"\n");
    fprintf(file, "ls >> \"test>file\"\n");
    fprintf(file, "\"test>file\"\n");
    fprintf(file, "ls | grep *test*file*\n");
    fprintf(file, "cat \"test>file\"\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(inhibitors12, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls > \"test\"\\ \\\'file\\\' \n");
    fprintf(file, "ls >> \"test\"\\ \\\'file\\\' \n");
    fprintf(file, "\"test\"\\ \\\'file\\\' \n");
    fprintf(file, "ls | grep *test*file*\n");
    fprintf(file, "cat \"test\"\\ \\\'file\\\' \n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(inhibitors13, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls > \\ \"test|file\"\"here\"\\ \n");
    fprintf(file, "ls >> \\ \"test|file\"\"here\"\\ \n");
    fprintf(file, "\\ \"test|file\"\"here\"\\ \n");
    fprintf(file, "ls | grep *test*file*\n");
    fprintf(file, "cat \\ \"test|file\"\"here\"\\ \n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(inhibitors14, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls > \"test\\\"file\"\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

