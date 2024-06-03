/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The alias.ini
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../include/myshell.h"

Test(alias1, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "alias a ls\n");
    fprintf(file, "a\n");
    fprintf(file, "alias a ls -l\n");
    fprintf(file, "a\n");
    fprintf(file, "alias a \"ls -l\"\n");
    fprintf(file, "a\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(alias2, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "alias ls ls -l\n");
    fprintf(file, "ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(alias3, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "unalias ls\n");
    fprintf(file, "ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(alias4, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "unalias clearLmod\n");
    fprintf(file, "unalias clearMT\n");
    fprintf(file, "unalias egrep\n");
    fprintf(file, "unalias fgrep\n");
    fprintf(file, "unalias gawklibpath_append\n");
    fprintf(file, "unalias gawklibpath_default\n");
    fprintf(file, "unalias gawklibpath_prepend\n");
    fprintf(file, "unalias gawkpath_append\n");
    fprintf(file, "unalias gawkpath_default\n");
    fprintf(file, "unalias gawkpath_prepend\n");
    fprintf(file, "unalias grep\n");
    fprintf(file, "unalias l.\n");
    fprintf(file, "unalias ll\n");
    fprintf(file, "unalias ls\n");
    fprintf(file, "unalias ml\n");
    fprintf(file, "unalias module\n");
    fprintf(file, "unalias xzegrep\n");
    fprintf(file, "unalias xzfgrep\n");
    fprintf(file, "unalias zegrep\n");
    fprintf(file, "unalias zfgrep\n");
    fprintf(file, "unalias zgrep\n");
    fprintf(file, "alias\n");
    fprintf(file, "alias ls ls -l\n");
    fprintf(file, "alias\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(alias5, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "unalias clearLmod\n");
    fprintf(file, "unalias clearMT\n");
    fprintf(file, "unalias egrep\n");
    fprintf(file, "unalias fgrep\n");
    fprintf(file, "unalias gawklibpath_append\n");
    fprintf(file, "unalias gawklibpath_default\n");
    fprintf(file, "unalias gawklibpath_prepend\n");
    fprintf(file, "unalias gawkpath_append\n");
    fprintf(file, "unalias gawkpath_default\n");
    fprintf(file, "unalias gawkpath_prepend\n");
    fprintf(file, "unalias grep\n");
    fprintf(file, "unalias l.\n");
    fprintf(file, "unalias ll\n");
    fprintf(file, "unalias ls\n");
    fprintf(file, "unalias ml\n");
    fprintf(file, "unalias module\n");
    fprintf(file, "unalias xzegrep\n");
    fprintf(file, "unalias xzfgrep\n");
    fprintf(file, "unalias zegrep\n");
    fprintf(file, "unalias zfgrep\n");
    fprintf(file, "unalias zgrep\n");
    fprintf(file, "alias\n");
    fprintf(file, "alias l ls -l\n");
    fprintf(file, "alias a ls -a\n");
    fprintf(file, "alias g grep --color=auto\n");
    fprintf(file, "alias\n");
    fprintf(file, "unalias l a g\n");
    fprintf(file, "alias\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(alias6, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "alias \"my ls\" \"ls -la --color=auto\"\n");
    fprintf(file, "my\\ ls\n");
    fprintf(file, "unalias \"my ls\"\n");
    fprintf(file, "alias ls \"ls --color=auto\"\n");
    fprintf(file, "ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(alias7, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "unalias *\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(alias8, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "unalias\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}
