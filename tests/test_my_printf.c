/*
** EPITECH PROJECT, 2023
** test_my_printf
** File description:
** Unit tests for each functionality of the my_printf
*/
/**
 * @file test_my_printf.c
 * @brief Unit tests for each function of the my_printf
 * @author Nicolas TORO
 */

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../lib/my/my_printf/myprintf.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, my_show_formating)
{
    formating_t formating;

    my_show_formating(&formating);
}

Test(my_printf, empty_format, .init = redirect_all_std)
{
    int len = my_printf("");

    cr_assert_stdout_eq_str("");
    cr_assert_eq(len, 0);
    my_fprintf(2, "");
}

Test(my_printf, simple_format, .init = redirect_all_std)
{
    int len = my_printf("hello world");

    cr_assert_stdout_eq_str("hello world");
    cr_assert_eq(len, 11);
    my_fprintf(2, "hello world");
}

Test(my_printf, wrong_flag_1, .init = redirect_all_std)
{
    int len = my_printf("hello %y");

    cr_assert_stdout_eq_str("hello %y");
    cr_assert_eq(len, 8);
    my_fprintf(2, "hello %y");
}

Test(my_printf, wrong_flag_2, .init = redirect_all_std)
{
    int len = my_printf("hello %+");
    cr_assert_stdout_eq_str("hello %+");
    cr_assert_eq(len, 8);
    my_fprintf(2, "hello %+");
}

Test(my_printf, wrong_flag_3, .init = redirect_all_std)
{
    int len = my_printf("hello %+y");
    cr_assert_stdout_eq_str("hello %+y");
    cr_assert_eq(len, 9);
    my_fprintf(2, "hello %");
}

Test(my_printf, one_flag_percent, .init = redirect_all_std)
{
    int len = my_printf("hello %%");
    cr_assert_stdout_eq_str("hello %");
    cr_assert_eq(len, 7);
    my_fprintf(2, "hello %%");
}

Test(my_printf, multiple_flag_percent_1, .init = redirect_all_std)
{
    int len = my_printf("hello %%%%%%");
    cr_assert_stdout_eq_str("hello %%%");
    cr_assert_eq(len, 9);
}

Test(my_printf, multiple_flag_percent_2, .init = redirect_all_std)
{
    int len = my_printf("hello %%%%%");
    cr_assert_stdout_eq_str("hello %%%");
    cr_assert_eq(len, 9);
}

Test(my_printf, one_flag_c, .init = redirect_all_std)
{
    int len = my_printf("hello %corld", 'w');
    cr_assert_stdout_eq_str("hello world");
    cr_assert_eq(len, 11);
}

Test(my_printf, multiple_flag_c, .init = redirect_all_std)
{
    int len = my_printf("hello %c%c%c%c%c", 'w', 'o', 'r', 'l', 'd');
    cr_assert_stdout_eq_str("hello world");
    cr_assert_eq(len, 11);
}

Test(my_printf, format_flag_c_1, .init = redirect_all_std)
{
    int len = my_printf("hello %2corld", 'w');
    cr_assert_stdout_eq_str("hello  world");
    cr_assert_eq(len, 12);
}

Test(my_printf, format_flag_c_2, .init = redirect_all_std)
{
    int len = my_printf("hello %#2corld", 'w');
    cr_assert_stdout_eq_str("hello  world");
    cr_assert_eq(len, 12);
}

Test(my_printf, format_flag_c_3, .init = redirect_all_std)
{
    int len = my_printf("hello %02corld", 'w');
    cr_assert_stdout_eq_str("hello 0world");
    cr_assert_eq(len, 12);
}

Test(my_printf, format_flag_c_4, .init = redirect_all_std)
{
    int len = my_printf("hello %+10corld", 'w');
    cr_assert_stdout_eq_str("hello          world");
    cr_assert_eq(len, 20);
}

Test(my_printf, format_flag_c_5, .init = redirect_all_std)
{
    int len = my_printf("hello %-10corld", 'w');
    cr_assert_stdout_eq_str("hello w         orld");
    cr_assert_eq(len, 20);
}

Test(my_printf, format_flag_c_6, .init = redirect_all_std)
{
    int len = my_printf("hello %#+2corld", 'w');
    cr_assert_stdout_eq_str("hello  world");
    cr_assert_eq(len, 12);
}

Test(my_printf, format_flag_c_7, .init = redirect_all_std)
{
    int len = my_printf("hello %#02corld", 'w');
    cr_assert_stdout_eq_str("hello  world");
    cr_assert_eq(len, 12);
}

Test(my_printf, format_flag_c_8, .init = redirect_all_std)
{
    int len = my_printf("hello %-#20corld", 'w');
    cr_assert_stdout_eq_str("hello %-#20corld");
    cr_assert_eq(len, 16);
}

Test(my_printf, format_flag_c_9, .init = redirect_all_std)
{
    int len = my_printf("hello %-+10corld", 'w');
    cr_assert_stdout_eq_str("hello w         orld");
    cr_assert_eq(len, 20);
}

Test(my_printf, one_flag_s, .init = redirect_all_std)
{
    int len = my_printf("hello %s", "world");
    cr_assert_stdout_eq_str("hello world");
    cr_assert_eq(len, 11);
}

Test(my_printf, multiple_flag_s, .init = redirect_all_std)
{
    int len = my_printf("%s%s%s", "hello", " ", "world");
    cr_assert_stdout_eq_str("hello world");
    cr_assert_eq(len, 11);
}

Test(my_printf, invalid_flag_s, .init = redirect_all_std)
{
    int len = my_printf("hello %s", NULL);
    cr_assert_stdout_eq_str("hello ");
    cr_assert_eq(len, 6);
}

Test(my_printf, format_flag_s_1, .init = redirect_all_std)
{
    int len = my_printf("hello %2s", "world");
    cr_assert_stdout_eq_str("hello world");
    cr_assert_eq(len, 11);
}

Test(my_printf, format_flag_s_2, .init = redirect_all_std)
{
    int len = my_printf("hello %#2s", "world");
    cr_assert_stdout_eq_str("hello world");
    cr_assert_eq(len, 11);
}

Test(my_printf, format_flag_s_3, .init = redirect_all_std)
{
    int len = my_printf("hello %02s", "world");
    cr_assert_stdout_eq_str("hello world");
    cr_assert_eq(len, 11);
}

Test(my_printf, format_flag_s_4, .init = redirect_all_std)
{
    int len = my_printf("hello %+10s", "world");
    cr_assert_stdout_eq_str("hello      world");
    cr_assert_eq(len, 16);
}

Test(my_printf, format_flag_s_5, .init = redirect_all_std)
{
    int len = my_printf("hello %-10s", "world");
    cr_assert_stdout_eq_str("hello world     ");
    cr_assert_eq(len, 16);
}

Test(my_printf, format_flag_s_6, .init = redirect_all_std)
{
    int len = my_printf("hello %#+2s", "world");
    cr_assert_stdout_eq_str("hello world");
    cr_assert_eq(len, 11);
}

Test(my_printf, format_flag_s_7, .init = redirect_all_std)
{
    int len = my_printf("hello %#02s", "world");
    cr_assert_stdout_eq_str("hello world");
    cr_assert_eq(len, 11);
}

Test(my_printf, format_flag_s_8, .init = redirect_all_std)
{
    int len = my_printf("hello %-#20s", "world");
    cr_assert_stdout_eq_str("hello %-#20s");
    cr_assert_eq(len, 12);
}

Test(my_printf, format_flag_s_9, .init = redirect_all_std)
{
    int len = my_printf("hello %-+10s", "world");
    cr_assert_stdout_eq_str("hello world     ");
    cr_assert_eq(len, 16);
}

Test(my_printf, one_flag_bigs, .init = redirect_all_std)
{
    char *test[] = {"hello", "world", NULL};
    int len = my_printf("%S", test);
    cr_assert_stdout_eq_str("hello\nworld\n");
    cr_assert_eq(len, 12);
}

Test(my_printf, one_flag_i, .init = redirect_all_std)
{
    int len = my_printf("We are in %i", 2023);
    cr_assert_stdout_eq_str("We are in 2023");
    cr_assert_eq(len, 14);
}

Test(my_printf, one_flag_i_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %i", -2023);
    cr_assert_stdout_eq_str("We are in -2023");
    cr_assert_eq(len, 15);
}

Test(my_printf, multiple_flag_i, .init = redirect_all_std)
{
    int len = my_printf("We are in %i%i%i%i", 2, 0, 2, 3);
    cr_assert_stdout_eq_str("We are in 2023");
    cr_assert_eq(len, 14);
}

Test(my_printf, multiple_flag_i_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %i%i%i%i", -2, 0, 2, 3);
    cr_assert_stdout_eq_str("We are in -2023");
    cr_assert_eq(len, 15);
}

Test(my_printf, one_flag_d, .init = redirect_all_std)
{
    int len = my_printf("We are in %d", 2023);
    cr_assert_stdout_eq_str("We are in 2023");
    cr_assert_eq(len, 14);
}

Test(my_printf, one_flag_d_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %d", -2023);
    cr_assert_stdout_eq_str("We are in -2023");
    cr_assert_eq(len, 15);
}

Test(my_printf, multiple_flag_d, .init = redirect_all_std)
{
    int len = my_printf("We are in %d%d%d%d", 2, 0, 2, 3);
    cr_assert_stdout_eq_str("We are in 2023");
    cr_assert_eq(len, 14);
}

Test(my_printf, multiple_flag_d_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %d%d%d%d", -2, 0, 2, 3);
    cr_assert_stdout_eq_str("We are in -2023");
    cr_assert_eq(len, 15);
}

Test(my_printf, format_flag_d_1, .init = redirect_all_std)
{
    int len = my_printf("We are in %4.5d", 2023);
    cr_assert_stdout_eq_str("We are in 02023");
    cr_assert_eq(len, 15);
}

Test(my_printf, format_flag_d_plus, .init = redirect_all_std)
{
    int len = my_printf("%-+10d", 2023);
    cr_assert_stdout_eq_str("+2023     ");
    cr_assert_eq(len, 10);
}

Test(my_printf, format_flag_d_2, .init = redirect_all_std)
{
    int len = my_printf("We are in %.0d", 0);
    cr_assert_stdout_eq_str("We are in ");
    cr_assert_eq(len, 10);
}

Test(my_printf, format_flag_d_3, .init = redirect_all_std)
{
    int len = my_printf("We are in %+7.4d", 2023);
    cr_assert_stdout_eq_str("We are in   +2023");
    cr_assert_eq(len, 17);
}

Test(my_printf, format_flag_d_4, .init = redirect_all_std)
{
    int len = my_printf("We are in %-7.4d", 2023);
    cr_assert_stdout_eq_str("We are in 2023   ");
    cr_assert_eq(len, 17);
}

Test(my_printf, format_flag_d_5, .init = redirect_all_std)
{
    int len = my_printf("We are in %#7.4d", 2023);
    cr_assert_stdout_eq_str("We are in    2023");
    cr_assert_eq(len, 17);
}

Test(my_printf, format_flag_d_6, .init = redirect_all_std)
{
    int len = my_printf("We are in %07d", 2023);
    cr_assert_stdout_eq_str("We are in 0002023");
    cr_assert_eq(len, 17);
}

Test(my_printf, format_flag_d_7, .init = redirect_all_std)
{
    int len = my_printf("We are in %lld", 2023);
    cr_assert_stdout_eq_str("We are in 2023");
    cr_assert_eq(len, 14);
}

Test(my_printf, format_flag_d_8, .init = redirect_all_std)
{
    int len = my_printf("We are in %+-10d", 2023);
    cr_assert_stdout_eq_str("We are in +2023     ");
    cr_assert_eq(len, 20);
}

Test(my_printf, format_flag_d_9, .init = redirect_all_std)
{
    int len = my_printf("We are in %0+10d", 2023);
    cr_assert_stdout_eq_str("We are in +000002023");
    cr_assert_eq(len, 20);
}

Test(my_printf, specifier_flag_d_1, .init = redirect_all_std)
{
    int len = my_printf("We are in %ld", 1);
    cr_assert_stdout_eq_str("We are in 1");
    cr_assert_eq(len, 11);
}

Test(my_printf, specifier_flag_d_2, .init = redirect_all_std)
{
    int len = my_printf("We are in %lld", 1);
    cr_assert_stdout_eq_str("We are in 1");
    cr_assert_eq(len, 11);
}

Test(my_printf, specifier_flag_d_3, .init = redirect_all_std)
{
    int len = my_printf("We are in %hd", 1);
    cr_assert_stdout_eq_str("We are in 1");
    cr_assert_eq(len, 11);
}

Test(my_printf, specifier_flag_d_4, .init = redirect_all_std)
{
    int len = my_printf("We are in %hhd", 1);
    cr_assert_stdout_eq_str("We are in 1");
    cr_assert_eq(len, 11);
}

Test(my_printf, specifier_flag_d_5, .init = redirect_all_std)
{
    int len = my_printf("We are in %zd", 1);
    cr_assert_stdout_eq_str("We are in 1");
    cr_assert_eq(len, 11);
}

Test(my_printf, format_flag_double_1, .init = redirect_all_std)
{
    int len = my_printf("%.5f", 10.123);
    cr_assert_stdout_eq_str("10.12300");
    cr_assert_eq(len, 8);
}

Test(my_printf, format_flag_double_plus, .init = redirect_all_std)
{
    int len = my_printf("%+12f", 10.123);
    cr_assert_stdout_eq_str("  +10.123000");
    cr_assert_eq(len, 12);
}

Test(my_printf, format_flag_double_width, .init = redirect_all_std)
{
    int len = my_printf("%12f", 10.123);
    cr_assert_stdout_eq_str("   10.123000");
    cr_assert_eq(len, 12);
}

Test(my_printf, format_flag_double_moins, .init = redirect_all_std)
{
    int len = my_printf("%-12f", 10.123);
    cr_assert_stdout_eq_str("10.123000   ");
    cr_assert_eq(len, 12);
}

Test(my_printf, format_flag_double_esp, .init = redirect_all_std)
{
    int len = my_printf("% f", 10.123);
    cr_assert_stdout_eq_str(" 10.123000");
    cr_assert_eq(len, 10);
}

Test(my_printf, format_flag_double_esp_a, .init = redirect_all_std)
{
    int len = my_printf("% 5a", 10.123);
    cr_assert_stdout_eq_str(" 0x1.43ef9db22d0e5p+3");
    cr_assert_eq(len, 21);
}

Test(my_printf, format_flag_double_zero, .init = redirect_all_std)
{
    int len = my_printf("%010f", 10.123);
    cr_assert_stdout_eq_str("010.123000");
    cr_assert_eq(len, 10);
}

Test(my_printf, format_flag_double_hash, .init = redirect_all_std)
{
    int len = my_printf("%#10f", 10.123);
    cr_assert_stdout_eq_str(" 10.123000");
    cr_assert_eq(len, 10);
}

Test(my_printf, format_flag_double_do_next, .init = redirect_all_std)
{
    int len = my_printf("%#+10f", 10.123);
    cr_assert_stdout_eq_str("+10.123000");
    cr_assert_eq(len, 10);
}

Test(my_printf, one_flag_u, .init = redirect_all_std)
{
    int len = my_printf("We are in %u", 2023);
    cr_assert_stdout_eq_str("We are in 2023");
    cr_assert_eq(len, 14);
}

Test(my_printf, one_flag_u_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %u", -2023);
    cr_assert_stdout_eq_str("We are in 4294965273");
    cr_assert_eq(len, 20);
}

Test(my_printf, multiple_flag_u, .init = redirect_all_std)
{
    int len = my_printf("We are in %u%u%u%u", 2, 0, 2, 3);
    cr_assert_stdout_eq_str("We are in 2023");
    cr_assert_eq(len, 14);
}

Test(my_printf, multiple_flag_u_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %u%u%u%u", -2, 0, 2, 3);
    cr_assert_stdout_eq_str("We are in 4294967294023");
    cr_assert_eq(len, 23);
}

Test(my_printf, specifier_flag_u_1, .init = redirect_all_std)
{
    int len = my_printf("We are in %lu", 1);
    cr_assert_stdout_eq_str("We are in 1");
    cr_assert_eq(len, 11);
}

Test(my_printf, specifier_flag_u_2, .init = redirect_all_std)
{
    int len = my_printf("We are in %llu", 1);
    cr_assert_stdout_eq_str("We are in 1");
    cr_assert_eq(len, 11);
}

Test(my_printf, specifier_flag_u_3, .init = redirect_all_std)
{
    int len = my_printf("We are in %hu", 1);
    cr_assert_stdout_eq_str("We are in 1");
    cr_assert_eq(len, 11);
}

Test(my_printf, specifier_flag_u_4, .init = redirect_all_std)
{
    int len = my_printf("We are in %hhu", 1);
    cr_assert_stdout_eq_str("We are in 1");
    cr_assert_eq(len, 11);
}

Test(my_printf, specifier_flag_u_5, .init = redirect_all_std)
{
    int len = my_printf("We are in %zu", 1);
    cr_assert_stdout_eq_str("We are in 1");
    cr_assert_eq(len, 11);
}

Test(my_printf, one_flag_b, .init = redirect_all_std)
{
    int len = my_printf("We are in %b", 2023);
    cr_assert_stdout_eq_str("We are in 11111100111");
    cr_assert_eq(len, 21);
}

Test(my_printf, one_flag_b_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %b", -2023);
    cr_assert_stdout_eq_str("We are in 11111111111111111111100000011001");
    cr_assert_eq(len, 42);
}

Test(my_printf, multiple_flag_b, .init = redirect_all_std)
{
    int len = my_printf("We are in %b%b%b%b", 2, 0, 2, 3);
    cr_assert_stdout_eq_str("We are in 1001011");
    cr_assert_eq(len, 17);
}

Test(my_printf, multiple_flag_b_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %b%b%b%b", -2, 0, 2, 3);
    cr_assert_stdout_eq_str("We are in 1111111111111111111111111111111001011");
    cr_assert_eq(len, 47);
}

Test(my_printf, format_flag_b_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %#b", 2023);
    cr_assert_stdout_eq_str("We are in 0b11111100111");
    cr_assert_eq(len, 23);
}

Test(my_printf, one_flag_o, .init = redirect_all_std)
{
    int len = my_printf("We are in %o", 2023);
    cr_assert_stdout_eq_str("We are in 3747");
    cr_assert_eq(len, 14);
}

Test(my_printf, one_flag_o_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %o", -2023);
    cr_assert_stdout_eq_str("We are in 37777774031");
    cr_assert_eq(len, 21);
}

Test(my_printf, multiple_flag_o, .init = redirect_all_std)
{
    int len = my_printf("We are in %o%o%o%o", 2, 0, 2, 3);
    cr_assert_stdout_eq_str("We are in 2023");
    cr_assert_eq(len, 14);
}

Test(my_printf, multiple_flag_o_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %o%o%o%o", -2, 0, 2, 3);
    cr_assert_stdout_eq_str("We are in 37777777776023");
    cr_assert_eq(len, 24);
}

Test(my_printf, format_flag_o, .init = redirect_all_std)
{
    int len = my_printf("We are in %#o", 2023);
    cr_assert_stdout_eq_str("We are in 03747");
    cr_assert_eq(len, 15);
}

Test(my_printf, one_flag_x, .init = redirect_all_std)
{
    int len = my_printf("We are in %x", 2023);
    cr_assert_stdout_eq_str("We are in 7e7");
    cr_assert_eq(len, 13);
}

Test(my_printf, one_flag_x_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %x", -2023);
    cr_assert_stdout_eq_str("We are in fffff819");
    cr_assert_eq(len, 18);
}

Test(my_printf, multiple_flag_x, .init = redirect_all_std)
{
    int len = my_printf("We are in %x%x%x%x", 2, 0, 2, 3);
    cr_assert_stdout_eq_str("We are in 2023");
    cr_assert_eq(len, 14);
}

Test(my_printf, multiple_flag_x_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %x%x%x%x", -2, 0, 2, 3);
    cr_assert_stdout_eq_str("We are in fffffffe023");
    cr_assert_eq(len, 21);
}

Test(my_printf, format_flag_x, .init = redirect_all_std)
{
    int len = my_printf("We are in %#x", 2023);
    cr_assert_stdout_eq_str("We are in 0x7e7");
    cr_assert_eq(len, 15);
}

Test(my_printf, one_flag_bigx, .init = redirect_all_std)
{
    int len = my_printf("We are in %X", 2023);
    cr_assert_stdout_eq_str("We are in 7E7");
    cr_assert_eq(len, 13);
}

Test(my_printf, one_flag_bigx_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %X", -2023);
    cr_assert_stdout_eq_str("We are in FFFFF819");
    cr_assert_eq(len, 18);
}

Test(my_printf, multiple_flag_bigx, .init = redirect_all_std)
{
    int len = my_printf("We are in %X%X%X%X", 2, 0, 2, 3);
    cr_assert_stdout_eq_str("We are in 2023");
    cr_assert_eq(len, 14);
}

Test(my_printf, multiple_flag_bigx_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %X%X%X%X", -2, 0, 2, 3);
    cr_assert_stdout_eq_str("We are in FFFFFFFE023");
    cr_assert_eq(len, 21);
}

Test(my_printf, format_flag_bigx, .init = redirect_all_std)
{
    int len = my_printf("We are in %#X", 2023);
    cr_assert_stdout_eq_str("We are in 0X7E7");
    cr_assert_eq(len, 15);
}

Test(my_printf, one_flag_p, .init = redirect_all_std)
{
    int len;
    cr_assert(my_printf("We are in %p", &len));
}

Test(my_printf, one_flag_e_zero, .init = redirect_all_std)
{
    int len = my_printf("We are in %e", 0.0);
    cr_assert_stdout_eq_str("We are in 0.000000e+00");
    cr_assert_eq(len, 22);
}

Test(my_printf, one_flag_e, .init = redirect_all_std)
{
    int len = my_printf("We are in %e", 20.23);
    cr_assert_stdout_eq_str("We are in 2.023000e+01");
    cr_assert_eq(len, 22);
}

Test(my_printf, one_flag_e_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %e", -20.23);
    cr_assert_stdout_eq_str("We are in -2.023000e+01");
    cr_assert_eq(len, 23);
}

Test(my_printf, one_flag_e_decimal, .init = redirect_all_std)
{
    int len = my_printf("We are in %e", 0.02023);
    cr_assert_stdout_eq_str("We are in 2.023000e-02");
    cr_assert_eq(len, 22);
}

Test(my_printf, one_flag_e_neg_decimal, .init = redirect_all_std)
{
    int len = my_printf("We are in %e", -0.02023);
    cr_assert_stdout_eq_str("We are in -2.023000e-02");
    cr_assert_eq(len, 23);
}

Test(my_printf, one_flag_e_max, .init = redirect_all_std)
{
    int len = my_printf("We are in %e", 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002023);
    cr_assert_stdout_eq_str("We are in 2.023000e-100");
    cr_assert_eq(len, 23);
}

Test(my_printf, one_flag_bige_zero, .init = redirect_all_std)
{
    int len = my_printf("We are in %E", 0.0);
    cr_assert_stdout_eq_str("We are in 0.000000E+00");
    cr_assert_eq(len, 22);
}

Test(my_printf, one_flag_bige, .init = redirect_all_std)
{
    int len = my_printf("We are in %E", 20.23);
    cr_assert_stdout_eq_str("We are in 2.023000E+01");
    cr_assert_eq(len, 22);
}

Test(my_printf, one_flag_bige_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %E", -20.23);
    cr_assert_stdout_eq_str("We are in -2.023000E+01");
    cr_assert_eq(len, 23);
}

Test(my_printf, one_flag_bige_decimal, .init = redirect_all_std)
{
    int len = my_printf("We are in %E", 0.02023);
    cr_assert_stdout_eq_str("We are in 2.023000E-02");
    cr_assert_eq(len, 22);
}

Test(my_printf, one_flag_bige_neg_decimal, .init = redirect_all_std)
{
    int len = my_printf("We are in %E", -0.02023);
    cr_assert_stdout_eq_str("We are in -2.023000E-02");
    cr_assert_eq(len, 23);
}

Test(my_printf, one_flag_bige_max, .init = redirect_all_std)
{
    int len = my_printf("We are in %E", 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002023);
    cr_assert_stdout_eq_str("We are in 2.023000E-100");
    cr_assert_eq(len, 23);
}

Test(my_printf, one_flag_f, .init = redirect_all_std)
{
    int len = my_printf("We are in %f", 20.23);
    cr_assert_stdout_eq_str("We are in 20.230000");
    cr_assert_eq(len, 19);
}

Test(my_printf, one_flag_f_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %f", -20.23);
    cr_assert_stdout_eq_str("We are in -20.230000");
    cr_assert_eq(len, 20);
}

Test(my_printf, one_flag_f_decimal, .init = redirect_all_std)
{
    int len = my_printf("We are in %f", 0.02023);
    cr_assert_stdout_eq_str("We are in 0.020230");
    cr_assert_eq(len, 18);
}

Test(my_printf, one_flag_f_neg_decimal, .init = redirect_all_std)
{
    int len = my_printf("We are in %F", -0.02023);
    cr_assert_stdout_eq_str("We are in -0.020230");
    cr_assert_eq(len, 19);
}

Test(my_printf, one_flag_bigf, .init = redirect_all_std)
{
    int len = my_printf("We are in %f", 20.23);
    cr_assert_stdout_eq_str("We are in 20.230000");
    cr_assert_eq(len, 19);
}

Test(my_printf, one_flag_bigf_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %F", -20.23);
    cr_assert_stdout_eq_str("We are in -20.230000");
    cr_assert_eq(len, 20);
}

Test(my_printf, one_flag_bigf_decimal, .init = redirect_all_std)
{
    int len = my_printf("We are in %F", 0.02023);
    cr_assert_stdout_eq_str("We are in 0.020230");
    cr_assert_eq(len, 18);
}

Test(my_printf, one_flag_bigf_neg_decimal, .init = redirect_all_std)
{
    int len = my_printf("We are in %F", -0.02023);
    cr_assert_stdout_eq_str("We are in -0.020230");
    cr_assert_eq(len, 19);
}

Test(my_printf, one_flag_g_zero, .init = redirect_all_std)
{
    int len = my_printf("We are in %g", 0.0);
    cr_assert_stdout_eq_str("We are in 0");
    cr_assert_eq(len, 11);
}

Test(my_printf, one_flag_g, .init = redirect_all_std)
{
    int len = my_printf("We are in %g", 20.23);
    cr_assert_stdout_eq_str("We are in 20.23");
    cr_assert_eq(len, 15);
}

Test(my_printf, one_flag_g_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %g", -20.23);
    cr_assert_stdout_eq_str("We are in -20.23");
    cr_assert_eq(len, 16);
}

Test(my_printf, one_flag_g_decimal, .init = redirect_all_std)
{
    int len = my_printf("We are in %g", 0.02023);
    cr_assert_stdout_eq_str("We are in 0.02023");
    cr_assert_eq(len, 17);
}

Test(my_printf, one_flag_g_neg_decimal, .init = redirect_all_std)
{
    int len = my_printf("We are in %g", -0.02023);
    cr_assert_stdout_eq_str("We are in -0.02023");
    cr_assert_eq(len, 18);
}

Test(my_printf, one_flag_g_max, .init = redirect_all_std)
{
    int len = my_printf("We are in %g", -0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002023);
    cr_assert_stdout_eq_str("We are in -2.023e-100");
    cr_assert_eq(len, 21);
}

Test(my_printf, one_flag_bigg_zero, .init = redirect_all_std)
{
    int len = my_printf("We are in %G", 0.0);
    cr_assert_stdout_eq_str("We are in 0");
    cr_assert_eq(len, 11);
}

Test(my_printf, one_flag_bigg, .init = redirect_all_std)
{
    int len = my_printf("We are in %G", 20.23);
    cr_assert_stdout_eq_str("We are in 20.23");
    cr_assert_eq(len, 15);
}

Test(my_printf, one_flag_bigg_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %G", -20.23);
    cr_assert_stdout_eq_str("We are in -20.23");
    cr_assert_eq(len, 16);
}

Test(my_printf, one_flag_bigg_decimal, .init = redirect_all_std)
{
    int len = my_printf("We are in %G", 0.02023);
    cr_assert_stdout_eq_str("We are in 0.02023");
    cr_assert_eq(len, 17);
}

Test(my_printf, one_flag_bigg_neg_decimal, .init = redirect_all_std)
{
    int len = my_printf("We are in %G", -0.02023);
    cr_assert_stdout_eq_str("We are in -0.02023");
    cr_assert_eq(len, 18);
}

Test(my_printf, one_flag_bigg_max, .init = redirect_all_std)
{
    int len = my_printf("We are in %G", -0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002023);
    cr_assert_stdout_eq_str("We are in -2.023E-100");
    cr_assert_eq(len, 21);
}

Test(my_printf, one_flag_a_zero, .init = redirect_all_std)
{
    int len = my_printf("We are in %a", 0.0);
    cr_assert_stdout_eq_str("We are in 0x0p+0");
    cr_assert_eq(len, 16);
}

Test(my_printf, one_flag_a, .init = redirect_all_std)
{
    int len = my_printf("We are in %a", 100.020);
    cr_assert_stdout_eq_str("We are in 0x1.90147ae147ae1p+6");
    cr_assert_eq(len, 30);
}

Test(my_printf, one_flag_a_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %a", -100.020);
    cr_assert_stdout_eq_str("We are in -0x1.90147ae147ae1p+6");
    cr_assert_eq(len, 31);
}

Test(my_printf, one_flag_a_decimal, .init = redirect_all_std)
{
    int len = my_printf("We are in %a", 0.10020);
    cr_assert_stdout_eq_str("We are in 0x1.9a6b50b0f27bbp-4");
    cr_assert_eq(len, 30);
}

Test(my_printf, one_flag_a_neg_decimal, .init = redirect_all_std)
{
    int len = my_printf("We are in %a", -0.10020);
    cr_assert_stdout_eq_str("We are in -0x1.9a6b50b0f27bbp-4");
    cr_assert_eq(len, 31);
}

Test(my_printf, one_flag_a_max, .init = redirect_all_std)
{
    int len = my_printf("We are in %a", 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002023);
    cr_assert_stdout_eq_str("We are in 0x1.c519b147ec1ebp-332");
    cr_assert_eq(len, 32);
}

Test(my_printf, one_flag_biga_zero, .init = redirect_all_std)
{
    int len = my_printf("We are in %A", 0.0);
    cr_assert_stdout_eq_str("We are in 0X0P+0");
    cr_assert_eq(len, 16);
}

Test(my_printf, one_flag_biga, .init = redirect_all_std)
{
    int len = my_printf("We are in %A", 100.020);
    cr_assert_stdout_eq_str("We are in 0X1.90147AE147AE1P+6");
    cr_assert_eq(len, 30);
}

Test(my_printf, one_flag_biga_neg, .init = redirect_all_std)
{
    int len = my_printf("We are in %A", -100.020);
    cr_assert_stdout_eq_str("We are in -0X1.90147AE147AE1P+6");
    cr_assert_eq(len, 31);
}

Test(my_printf, one_flag_biga_decimal, .init = redirect_all_std)
{
    int len = my_printf("We are in %A", 0.10020);
    cr_assert_stdout_eq_str("We are in 0X1.9A6B50B0F27BBP-4");
    cr_assert_eq(len, 30);
}

Test(my_printf, one_flag_biga_neg_decimal, .init = redirect_all_std)
{
    int len = my_printf("We are in %A", -0.10020);
    cr_assert_stdout_eq_str("We are in -0X1.9A6B50B0F27BBP-4");
    cr_assert_eq(len, 31);
}

Test(my_printf, one_flag_biga_max, .init = redirect_all_std)
{
    int len = my_printf("We are in %A", 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002023);
    cr_assert_stdout_eq_str("We are in 0X1.C519B147EC1EBP-332");
    cr_assert_eq(len, 32);
}

Test(my_printf, one_flag_n, .init = redirect_all_std)
{
    int test = 0;
    cr_assert_eq(my_printf("We are%n in 2023", &test), 14);
    cr_assert_eq(test, 6);
    my_fprintf(2, "We are in %n", &test);
}

Test(my_printf, specifier_flag_n_l, .init = redirect_all_std)
{
    int test = 0;
    cr_assert_eq(my_printf("We are%ln in 2023", &test), 14);
    cr_assert_eq(test, 6);
}

Test(my_printf, specifier_flag_n_ll, .init = redirect_all_std)
{
    int test = 0;
    cr_assert_eq(my_printf("We are%lln in 2023", &test), 14);
    cr_assert_eq(test, 6);
}

Test(my_printf, specifier_flag_n_h, .init = redirect_all_std)
{
    int test = 0;
    cr_assert_eq(my_printf("We are%hn in 2023", &test), 14);
    cr_assert_eq(test, 6);
}

Test(my_printf, specifier_flag_n_hh, .init = redirect_all_std)
{
    int test = 0;
    cr_assert_eq(my_printf("We are%hhn in 2023", &test), 14);
    cr_assert_eq(test, 6);
}

Test(my_printf, specifier_flag_n_z, .init = redirect_all_std)
{
    int test = 0;
    cr_assert_eq(my_printf("We are%zn in 2023", &test), 14);
    cr_assert_eq(test, 6);
}

Test(my_printf, specifier_flag_n_j, .init = redirect_all_std)
{
    int test = 0;
    cr_assert_eq(my_printf("We are%jn in 2023", &test), 14);
    cr_assert_eq(test, 6);
}

Test(my_printf, specifier_flag_n_t, .init = redirect_all_std)
{
    int test = 0;
    cr_assert_eq(my_printf("We are%tn in 2023", &test), 14);
    cr_assert_eq(test, 6);
}

Test(my_printf, specifier_flag_n_L, .init = redirect_all_std)
{
    int test = 0;
    cr_assert_eq(my_printf("We are%Ln in 2023", &test), 14);
    cr_assert_eq(test, 6);
}

Test(my_printf, one_flag_m, .init = redirect_all_std)
{
    cr_assert(my_printf("We are in %m"));
}

Test(my_printf, one_flag_bigd, .init = redirect_all_std)
{
    cr_assert(my_printf("We are in %D"));
}

Test(my_printf, all_formats_1, .init = redirect_all_std)
{
    int len = my_printf("We are in %#1.2lld", 2023);
    cr_assert_stdout_eq_str("We are in 2023");
    cr_assert_eq(len, 14);
}

Test(my_printf, all_formats_2, .init = redirect_all_std)
{
    int len = my_printf("We are in %#+1.2ld", 2023);
    cr_assert_stdout_eq_str("We are in +2023");
    cr_assert_eq(len, 15);
}

Test(my_printf, all_formats_star_prc, .init = redirect_all_std)
{
    int len = my_printf("%.*d", 6, 10);
    cr_assert_stdout_eq_str("000010");
    cr_assert_eq(len, 6);
}

Test(my_printf, all_formats_star_width, .init = redirect_all_std)
{
    int len = my_printf("%*d", 6, 10);
    cr_assert_stdout_eq_str("    10");
    cr_assert_eq(len, 6);
}

Test(my_printf, flag_a_prc_zero, .init = redirect_all_std)
{
    int len = my_printf("%.4a", 0.0);
    cr_assert_stdout_eq_str("0x0.0000p+0");
    cr_assert_eq(len, 11);

}

Test(my_printf, flag_a_prc_x, .init = redirect_all_std)
{
    int len = my_printf("%.14a", 10.123);
    cr_assert_stdout_eq_str("0x1.43ef9db22d0e50p+3");
    cr_assert_eq(len, 21);
}

Test(my_printf, flag_biga_prc_zero, .init = redirect_all_std)
{
    int len = my_printf("%.4A", 0.0);
    cr_assert_stdout_eq_str("0X0.0000P+0");
    cr_assert_eq(len, 11);
}

Test(my_printf, flag_biga_prc_x, .init = redirect_all_std)
{
    int len = my_printf("%.14A", 10.123);
    cr_assert_stdout_eq_str("0X1.43EF9DB22D0E50P+3");
    cr_assert_eq(len, 21);
}

Test(my_printf, flag_g_prc_zero, .init = redirect_all_std)
{
    int len = my_printf("%.4g", 1000000.123);
    cr_assert_stdout_eq_str("1e+06");
    cr_assert_eq(len, 5);
}

Test(my_printf, flag_bigg_prc_zero, .init = redirect_all_std)
{
    int len = my_printf("%.4G", 1000000.123);
    cr_assert_stdout_eq_str("1E+06");
    cr_assert_eq(len, 5);
}

Test(my_printf, flag_g_prc_x, .init = redirect_all_std)
{
    cr_assert(my_printf("%.1g",  123.456));
}

Test(my_printf, flag_bigg_prc_x, .init = redirect_all_std)
{
    cr_assert(my_printf("%.1G",  123.456));
}

Test(my_printf, flag_a_prc, .init = redirect_all_std)
{
    cr_assert(my_printf("The number is %.1a", 123.456));
}

Test(my_printf, flag_a_prc_2, .init = redirect_all_std)
{
    cr_assert(my_printf("The number is %a", 0.1));
}

Test(my_printf, flag_a_prc_3, .init = redirect_all_std)
{
    cr_assert(my_printf("The number is %.0a", 1));
}

Test(my_printf, flag_a_prc_4, .init = redirect_all_std)
{
    cr_assert(my_printf("The number is %.10a", 1.2345679));
}

Test(my_printf, flag_a_prc_5, .init = redirect_all_std)
{
    cr_assert(my_printf("The number is %.5a", 999.57835));
}

Test(my_printf, flag_a_prc_6, .init = redirect_all_std)
{
    cr_assert(my_printf("The number is %.8a", 138567983.64656757654664965785));
}

Test(my_printf, flag_biga_prc, .init = redirect_all_std)
{
    cr_assert(my_printf("The number is %.1A", 123.456));
}

Test(my_printf, flag_biga_prc_2, .init = redirect_all_std)
{
    cr_assert(my_printf("The number is %A", 0.1));
}

Test(my_printf, flag_biga_prc_3, .init = redirect_all_std)
{
    cr_assert(my_printf("The number is %.0A", 1));
}

Test(my_printf, flag_biga_prc_4, .init = redirect_all_std)
{
    cr_assert(my_printf("The number is %.10A", 1.2345679));
}

Test(my_printf, flag_biga_prc_5, .init = redirect_all_std)
{
    cr_assert(my_printf("The number is %.5A", 999.57835));
}

Test(my_printf, flag_biga_prc_6, .init = redirect_all_std)
{
    cr_assert(my_printf("The number is %.8A", 138567983.64656757654664965785));
}
