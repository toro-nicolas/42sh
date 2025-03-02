/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The scripting.ini
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../include/myshell.h"
/*
Test(scripting1, full_gcorv)
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

Test(scripting2, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "if 1 ls\n");
    fprintf(file, "if 1 then\n");
    fprintf(file, "    ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(scripting3, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "if 1 then\n");
    fprintf(file, "    ls\n");
    fprintf(file, "else\n");
    fprintf(file, "    pwd\n");
    fprintf(file, "endif\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(scripting4, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "if 0 then\n");
    fprintf(file, "    ls\n");
    fprintf(file, "else\n");
    fprintf(file, "    pwd\n");
    fprintf(file, "endif\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(scripting5, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "if (0 > 1 || 0 > 2 || 0 < 1) then\n");
    fprintf(file, "    ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(scripting6, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "if 0 then\n");
    fprintf(file, "    ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(scripting7, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "else\n");
    fprintf(file, "    ls\n");
    fprintf(file, "pwd\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(scripting8, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "if (0) then\n");
    fprintf(file, "    echo \"1!\"\n");
    fprintf(file, "else if (((1 > 2) || (2 > 1)) && 1 + 1) then\n");
    fprintf(file, "    echo \"2!\"\n");
    fprintf(file, "else\n");
    fprintf(file, "    echo \"3!\"\n");
    fprintf(file, "endif\n");
    fprintf(file, "pwd\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(scripting9, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "if (0 > 1) then\n");
    fprintf(file, "    ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(scripting10, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "else\n");
    fprintf(file, "    ls\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(scripting11, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "if\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(scripting12, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "if 1\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(scripting13, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "endif\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(scripting14, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "endif 42sh\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(scripting15, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "if true\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(scripting16, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "foreach f (1 543 5) \\n echo $f \\n end\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(scripting17, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "foreach f (1) \\n if ($f) ls \\n end\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(scripting18, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "foreach f () \\n ls \\n end\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(scripting19, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "foreach\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(scripting20, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "foreach f f ( 1 ) ( 2 ) \\n ls \\n end\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}

Test(scripting21, full_gcorv)
{
    char **env = my_str_to_word_array_select("TERM=xterm ; PATH=/bin:/usr/bin", " ;");
    FILE *file = fopen("test_input.txt", "w");

    fprintf(file, "foreach (f) ( 2 ) \\n ls \\n end\n");
    fprintf(file, "exit\n");
    fclose(file);
    freopen("test_input.txt", "r", stdin);
    shell(env);
}
*/