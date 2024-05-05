/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The environnement.ini
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../include/myshell.h"

Test(environnement1, full_gcorv)
{
    char **env = my_str_to_word_array_select("PATH=/bin:/usr/bin ; export _=ls ; export LS_COLORS=RID ; export MYBG=4 ; export LVL=4 ; export NOTE=2", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "unsetenv _\n");
    fprintf(file, "unsetenv MYSH\n");
    fprintf(file, "unsetenv HOSTTYPE\n");
    fprintf(file, "unsetenv VENDOR\n");
    fprintf(file, "unsetenv OSTYPE\n");
    fprintf(file, "unsetenv MACHTYPE\n");
    fprintf(file, "unsetenv SHLVL\n");
    fprintf(file, "unsetenv PWD\n");
    fprintf(file, "unsetenv LOGNAME\n");
    fprintf(file, "unsetenv USER\n");
    fprintf(file, "unsetenv GROUP\n");
    fprintf(file, "unsetenv HOST\n");
    fprintf(file, "unsetenv REMOTEHOST\n");
    fprintf(file, "unsetenv LS_COLORS\n");
    fprintf(file, "unsetenv NOTE\n");
    fprintf(file, "setenv titi\n");
    fprintf(file, "setenv tata coucou\n");
    fprintf(file, "env\n");
    fprintf(file, "/usr/bin/env\n");
    fprintf(file, "unsetenv titi\n");
    fprintf(file, "env\n");
    fprintf(file, "/usr/bin/env\n");
    fprintf(file, "unsetenv tata\n");
    fprintf(file, "env\n");
    fprintf(file, "/usr/bin/env\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(environnement2, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "unsetenv _\n");
    fprintf(file, "unsetenv MYSH\n");
    fprintf(file, "unsetenv HOSTTYPE\n");
    fprintf(file, "unsetenv VENDOR\n");
    fprintf(file, "unsetenv OSTYPE\n");
    fprintf(file, "unsetenv MACHTYPE\n");
    fprintf(file, "unsetenv SHLVL\n");
    fprintf(file, "unsetenv PWD\n");
    fprintf(file, "unsetenv LOGNAME\n");
    fprintf(file, "unsetenv USER\n");
    fprintf(file, "unsetenv GROUP\n");
    fprintf(file, "unsetenv HOST\n");
    fprintf(file, "unsetenv REMOTEHOST\n");
    fprintf(file, "unsetenv LS_COLORS\n");
    fprintf(file, "unsetenv NOTE\n");
    fprintf(file, "env > my_env\n");
    fprintf(file, "cat my_env\n");
    fprintf(file, "rm my_env\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(environnement3, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "unsetenv _\n");
    fprintf(file, "unsetenv MYSH\n");
    fprintf(file, "unsetenv HOSTTYPE\n");
    fprintf(file, "unsetenv VENDOR\n");
    fprintf(file, "unsetenv OSTYPE\n");
    fprintf(file, "unsetenv MACHTYPE\n");
    fprintf(file, "unsetenv SHLVL\n");
    fprintf(file, "unsetenv PWD\n");
    fprintf(file, "unsetenv LOGNAME\n");
    fprintf(file, "unsetenv USER\n");
    fprintf(file, "unsetenv GROUP\n");
    fprintf(file, "unsetenv HOST\n");
    fprintf(file, "unsetenv REMOTEHOST\n");
    fprintf(file, "unsetenv LS_COLORS\n");
    fprintf(file, "unsetenv NOTE\n");
    fprintf(file, "setenv\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(environnement4, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "setenv PATH /\n");
    fprintf(file, "ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(environnement5, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "unsetenv _ HOSTTYPE VENDOR OSTYPE MACHTYPE SHLVL PWD LOGNAME USER GROUP HOST REMOTEHOST LS_COLORS NOTE MYSH\n");
    fprintf(file, "env\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(environnement6, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "env | grep PATH\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(environnement7, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "unsetenv *_*\n");
    fprintf(file, "env\n");
    fprintf(file, "unsetenv *\n");
    fprintf(file, "env\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(environnement8, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "setenv 42sh 42sh 42sh\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(environnement9, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "unsetenv\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(environnement10, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "setenv 42sh 42sh\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(environnement11, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "setenv sh:42 42\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

