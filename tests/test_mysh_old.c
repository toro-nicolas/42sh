/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The test_mysh_old.c
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../include/myshell.h"

Test(test1, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "pwd\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test2, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "pwd\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test3, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cat /etc/resolv.conf\n");
    fprintf(file, "ls -l /bin\n");
    fprintf(file, "pwd\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test5, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cd ..\n");
    fprintf(file, "ls -l\n");
    fprintf(file, "cd /usr\n");
    fprintf(file, "ls -l\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test6, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test7, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test8, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test9, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test10, full_gcorv)
{
    char **env = my_str_to_word_array_select("VAR1=VALEUR1 ; OLDPATH=$PATH ; PATH=/random", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "setenv | /bin/grep VAR1\n");
    fprintf(file, "/bin/ls | cd /usr\n");
    fprintf(file, "ls -l\n");
    fprintf(file, "exit 45|cat /etc/resolv.conf\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test11, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls | cat | grep mysh\n");
    fprintf(file, "fsdfsdf | ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test12, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls | cat | grep dfsdfsdfsdfsdf\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test13, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls > .testlolmdr\n");
    fprintf(file, "echo bite\n");
    fprintf(file, "/bin/grep mysh .testlolmdr >> .testlolmdr\n");
    fprintf(file, "/bin/grep sh .testlolmdr >> .testlolmdr\n");
    fprintf(file, "cat .testlolmdr\n");
    fprintf(file, "rm .testlolmdr\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test14, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cat salut\n");
    fprintf(file, "< salut wc -l\n");
    fprintf(file, "wc <salut -l\n");
    fprintf(file, "grep -i LO < salut\n");
    fprintf(file, "grep -i LO < salut | wc -l\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test15, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cat < Makefile\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test16, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "< Makefile cat|>.lol wc -l\n");
    fprintf(file, "cat .lol\n");
    fprintf(file, "rm .lol\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test17, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cat << a\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test18, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cat < Makefile > .lol\n");
    fprintf(file, "cat .lol\n");
    fprintf(file, "rm .lol\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test23, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls | cat < Makefile > .lol\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test24, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls | cat -e > .lol\n");
    fprintf(file, "cat .lol\n");
    fprintf(file, "rm .lol\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test27, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test28, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "\"\"\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test29, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "lol\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test30, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls |\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test31, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "| ;\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test32, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls ||||| cat\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test33, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test34, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test35, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "id\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test36, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls\n");
    fprintf(file, "pwd\n");
    fprintf(file, "ls -l\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test37, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "Sahel est con\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test38, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "/ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test39, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "/usr/bin/ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test40, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "setenv PATH caca\n");
    fprintf(file, "ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test41, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "setenv PATH /usr/bin:\n");
    fprintf(file, "ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test42, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "setenv PATH /usr/bi\n");
    fprintf(file, "ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test43, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "setenv ok ok ok\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test44, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cd ..\n");
    fprintf(file, "ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test45, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cd ok ok ok\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test46, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cd /root\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test47, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cd ..\n");
    fprintf(file, "ls\n");
    fprintf(file, "cd -\n");
    fprintf(file, "ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test48, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "env | grep XDG\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test49, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls | cat -e | grep Ma\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test50, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls >\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test51, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls >> out; ls | ls |ls | ls ; ls\n");
    fprintf(file, "rm out\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test52, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "unsetenv OLDPWD\n");
    fprintf(file, "cd\n");
    fprintf(file, "cd -\n");
    fprintf(file, "ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test53, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls | ;\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test54, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls | ls > ;\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test55, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls ; ls > out\n");
    fprintf(file, "rm out\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test56, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, ";ls>out\n");
    fprintf(file, "rm out\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test59, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls ; ; ; \n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test60, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls ; ; ; | ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test61, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls | > z\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test62, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "sdf > a\n");
    fprintf(file, "ls\n");
    fprintf(file, "rm a\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test63, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cat -e << a | grep b\n");
    fprintf(file, "zert\n");
    fprintf(file, "zea\n");
    fprintf(file, "b\n");
    fprintf(file, "a\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test64, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, " \n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test65, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test66, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test67, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test68, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, ";;;;\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test69, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "||||\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test70, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test71, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test72, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "id\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test73, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cat Makefile > .toto\n");
    fprintf(file, "cat -e << a >> .toto\n");
    fprintf(file, "OLALA\n");
    fprintf(file, "Really\n");
    fprintf(file, "a\n");
    fprintf(file, "cat .toto\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test74, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, " ; ; ; ; \n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test75, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, " | | | | \n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test76, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test77, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test78, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls | cat -e < Makefile\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test79, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "unsetenv SHLVL\n");
    fprintf(file, "unsetenv HOST\n");
    fprintf(file, "unsetenv _\n");
    fprintf(file, "unsetenv HOSTTYPE\n");
    fprintf(file, "unsetenv VENDOR\n");
    fprintf(file, "unsetenv OSTYPE\n");
    fprintf(file, "unsetenv MACHTYPE\n");
    fprintf(file, "unsetenv GROUP\n");
    fprintf(file, "setenv\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test80, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "unsetenv SHLVL\n");
    fprintf(file, "unsetenv HOST\n");
    fprintf(file, "unsetenv _\n");
    fprintf(file, "unsetenv HOSTTYPE\n");
    fprintf(file, "unsetenv VENDOR\n");
    fprintf(file, "unsetenv OSTYPE\n");
    fprintf(file, "unsetenv MACHTYPE\n");
    fprintf(file, "unsetenv GROUP\n");
    fprintf(file, "setenv PATH\n");
    fprintf(file, "setenv PATH lol\n");
    fprintf(file, "setenv PATH caca\n");
    fprintf(file, "setenv PATH ls\n");
    fprintf(file, "setenv\n");
    fprintf(file, "ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test81, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "./42sh\n");
    fprintf(file, "ls\n");
    fprintf(file, "ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test82, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "sdf sdf sdf\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test83, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cat Makefile > ..\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test84, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "rm -rf .sdfsdf\n");
    fprintf(file, "cat < .sdfsdf\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test85, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cat Makefile | grep b | grep i\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test86, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "setenv =\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test87, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "setenv ae%9\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test88, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "./Makefile\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test89, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "./include\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test90, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "enve\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test91, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cdenve -\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test92, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "			 ls		\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test93, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "/ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test94, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cat -e < olala | grep b\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test95, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cd .. | ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test96, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "env | grep PATH\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test97, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "< zert cat\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test98, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "< Makefile cat -e\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test99, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "< Makefile cat >> .lol -e\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test100, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "THE END | GG\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test101, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "42sh\n");
    fprintf(file, "ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test102, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test103, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "where ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test104, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "where ls grep ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test105, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "where sdf ls grep sdf\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test106, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "where sdf\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test107, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "alias ls ls -l\n");
    fprintf(file, "ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test108, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "alias a ls\n");
    fprintf(file, "a\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test109, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "alias ls ll\n");
    fprintf(file, "ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test110, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "repeat 4 ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test111, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "repeat 4e ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test112, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "repeat 2 sdf\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test113, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test114, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test115, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test116, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test117, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test118, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test119, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test120, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test122, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test123, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test124, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test125, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test126, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test130, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test131, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test134, full_gcorv)
{
    char **env = my_str_to_word_array_select("", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test135, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test136, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls /etc\n");
    fprintf(file, "cat /etc/resolv.conf\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test137, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "pwd\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test138, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "pwd\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test139, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cat /etc/resolv.conf\n");
    fprintf(file, "ls -l /etc\n");
    fprintf(file, "pwd\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test141, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cd ..\n");
    fprintf(file, "ls -l\n");
    fprintf(file, "cd /usr\n");
    fprintf(file, "ls -l\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test142, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test143, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test144, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "pwd\n");
    fprintf(file, "cd -\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test145, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cd ..\n");
    fprintf(file, "cd -\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test146, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "cd ..\n");
    fprintf(file, "cd -\n");
    fprintf(file, "ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test147, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test148, full_gcorv)
{
    char **env = my_str_to_word_array_select("VAR1=VALEUR1 ; OLDPATH=$PATH ; PATH=/random", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "setenv | /bin/grep VAR1\n");
    fprintf(file, "/bin/ls | cd /usr\n");
    fprintf(file, "ls -l\n");
    fprintf(file, "exit 45|cat /etc/resolv.conf\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test149, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls -l ; pwd ; ls -l ; ls -l\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test150, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls -l && pwd && ls -l && ls -l\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test151, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls -l || pwd || ls -l || ls -l\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test152, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls -l && pwd || ls -l && ls -l\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test153, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test154, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test155, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test156, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "ls > a > \n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test157, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "lala >> b << a > \n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(test158, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "lala >>  << a > \n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}
