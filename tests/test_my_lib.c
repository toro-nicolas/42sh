/*
** EPITECH PROJECT, 2023
** test_my_lib
** File description:
** Unit tests for each function of the my lib
*/
/**
 * @file test_my_lib.c
 * @brief Unit tests for each function of the my lib
 * @author Nicolas TORO
 */

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../include/my.h"

Test(my_compute_factorial_rec, full_covr)
{
    cr_assert_eq(my_compute_factorial_rec(3), 6);
    cr_assert_eq(my_compute_factorial_rec(15), 0);
}

Test(my_compute_power_rec, full_covr)
{
    cr_assert_eq(my_compute_power_rec(3, 2), 9);
    cr_assert_eq(my_compute_power_rec(21, 0), 1);
    cr_assert_eq(my_compute_power_rec(-4, -4), 0);
}

Test(my_compute_square_root, full_covr)
{
    cr_assert_eq(my_compute_square_root(25), 5);
    cr_assert_eq(my_compute_square_root(0), 0);
    cr_assert_eq(my_compute_square_root(-4), 0);
}

Test(my_concat_params, full_covr)
{
    int argc = 4;
    char *argv[] = {"unit_tests", "coucou", "ça", "va"};

    cr_assert(my_concat_params(argc, argv));
}

Test(my_convert_base, full_covr)
{
    cr_assert(my_convert_base("-10", "0123456789", "01"));
} // NE PASSE PAS CAR NE PRINT PAS LE DERNIER 0

Test(my_convert_base_unsigned, full_covr)
{
    cr_assert_str_eq(my_convert_base_unsigned("10", "0123456789", "01"), "1010");
    cr_assert_str_eq(my_convert_base_unsigned("10a10", "0123456789", "01"), "1010");
}

Test(my_find_prime_sup, full_covr)
{
    cr_assert_eq(my_find_prime_sup(9), 11);
    cr_assert(my_find_prime_sup(0));
    cr_assert(my_find_prime_sup(4));
}

Test(my_getnbr_base, full_covr)
{
    cr_assert_eq(my_getnbr_base("10", "0123456789"), 10);
    cr_assert(my_getnbr_base("a10", "0123456789"));
}

Test(my_getnbr, full_covr)
{
    cr_assert_eq(my_getnbr("-10"), -10);
    cr_assert_eq(my_getnbr("-2147483648"), -2147483648);
    cr_assert_eq(my_getnbr("a54"), 0);
    cr_assert_eq(my_getnbr("00012345667"), 0);
    cr_assert_eq(my_getnbr("42"), 42);
    cr_assert_eq(my_getnbr("-+21"), 21);
}

Test(my_isneg, full_covr)
{
    my_isneg(-10);
    my_isneg(10);
}

Test(my_is_prime, full_covr)
{
    cr_assert_eq(my_is_prime(0), 0);
    cr_assert_eq(my_is_prime(7), 1);
    cr_assert_eq(my_is_prime(9), 0);
}

Test(my_params_to_array, full_covr)
{
    char *test[] = {"unittests", "coucou"};

    cr_assert(my_params_to_array(0, test));
    cr_assert(my_params_to_array(1, test));
    //cr_assert(my_params_to_array(2, argv));
}

Test(my_print_combn, full_covr)
{
    my_print_combn(3);
}

Test(my_print_params, full_covr, .init = cr_redirect_stdout)
{
    char *argv[] = {"unit_tests", "coucou"};

    my_print_params(2, argv);
    cr_assert_stdout_eq_str("unit_tests\ncoucou\n");
}

Test(my_putnbr, fullcovr, .init = cr_redirect_stdout)
{
    my_putnbr(-2400934);
    cr_assert_stdout_eq_str("-2400934");
}

Test(my_putnbr, fullcovr_2, .init = cr_redirect_stdout)
{
    my_putnbr(-2147483648);
    cr_assert_stdout_eq_str("-2147483648");
}

Test(my_putnbr_base, fullcovr, .init = cr_redirect_stdout)
{
    my_putnbr_base(-10, "0123456789");
    cr_assert_stdout_eq_str("-10"); 
}

Test(my_putstr_error, full_covr)
{
    cr_assert_eq(my_putstr_error("ok"), 84);
}

Test(my_putstr_sized, full_covr)
{
    cr_assert_eq(my_putstr_sized("ok", 2), 2);
}

Test(my_rev_params, full_covr, .init = cr_redirect_stdout)
{
    char *argv[] = {"unit_tests", "coucou"};

    my_rev_params(2, argv);
    cr_assert_stdout_eq_str("coucou\nunit_tests\n");
}

Test(my_rev_str, full_covr)
{
    char str[6] = "kayak\0";

    cr_assert(my_revstr(str));
}

Test(my_show_param, full_covr, .init = cr_redirect_stdout)
{
    char str[6] = "kayak\0";
    struct info_param struct1;
    struct info_param struct2;
    struct info_param par[2];

    struct1.length = my_strlen(str);
    struct1.str = str;
    struct1.copy = my_strdup(str);
    struct1.word_array = my_str_to_word_array(str);
    struct2.length = 0;
    struct2.str = "";
    struct2.copy = "";
    struct2.word_array = my_str_to_word_array("");
    par[0] = struct1;
    par[1] = struct2;
    my_show_param_array(par);
    cr_assert_stdout_eq_str("kayak\n5\nkayak\n");
}

Test(my_show_word_array, full_covr, .init = cr_redirect_stdout)
{
    char *test[] = {"unit_tests", "coucou"};

    my_show_word_array(test);
    cr_assert_stdout_eq_str("unit_tests\ncoucou\n");
}

Test(my_show_mem, full_covr)
{
    char str[8] = "hel\n\blo\0";
 
    my_showmem(str, my_strlen(str));
}

Test(my_show_str, full_covr)
{
    char str[8] = "hel\nl\bo\0";

    my_showstr(str);
}

Test(my_sort_int_array, full_covr)
{
    int tab_int[5] = {0, 5, 12, 42};

    my_sort_int_array(tab_int, 5);
    cr_assert_eq(tab_int[0], 0);
}

Test(my_sort_params, full_covr)
{
    char *argv1[] = {"unit_tests", "coucou", "wesh"};
    char *argv2[] = {"coucoulL", "coucou", "coucoul"};
    char *argv3[] = {"unit_tests", "unit_tests", "wesh"};

    my_sort_params(3, argv1);
    my_sort_params(3, argv2);
    my_sort_params(3, argv3);
    cr_assert_str_eq(argv1[2], "coucou");
    cr_assert_str_eq(argv2[0], "coucoulL");
    cr_assert_str_eq(argv3[2], "unit_tests");
} //ça tri mais à l'envers -> à fix

Test(my_str_is_alpha, full_covr)
{
    cr_assert_eq(my_str_isalpha("Coucou"), 1);
    cr_assert_eq(my_str_isalpha("124"), 0);
    cr_assert_eq(my_str_isalpha(""), 1);
}

Test(my_str_is_lower, full_covr)
{
    cr_assert_eq(my_str_islower("Coucou"), 0);
    cr_assert_eq(my_str_islower("124"), 0);
    cr_assert_eq(my_str_islower(""), 1);
    cr_assert_eq(my_str_islower("oui"), 1);
}

Test(my_str_is_num, full_covr)
{
    cr_assert_eq(my_str_isnum("Coucou"), 0);
    cr_assert_eq(my_str_isnum("124"), 1);
    cr_assert_eq(my_str_isnum(""), 1);
}

Test(my_str_is_printable, full_covr)
{
    char str[2];

    str[0] = 31;
    str[1] = '\0';
    cr_assert_eq(my_str_isprintable("Coucou"), 1);
    cr_assert_eq(my_str_isprintable(str), 0);
    cr_assert_eq(my_str_isprintable(""), 1);
}

Test(my_str_is_upper, full_covr)
{
    cr_assert_eq(my_str_isupper("Coucou"), 0);
    cr_assert_eq(my_str_isupper("9"), 0);
    cr_assert_eq(my_str_isupper("abc"), 0);
    cr_assert_eq(my_str_isupper(""), 1);
    cr_assert_eq(my_str_isupper("ABC"), 1);
}

Test(my_str_nbr, full_covr)
{
    cr_assert_str_eq(my_str_nbr(-12), "-12");
}

Test(my_str_nbr, full_covr_2, .init = cr_redirect_stdout)
{
    cr_assert_str_eq(my_str_nbr(-2147483648), "-2147483648");
}

Test(my_str_nbr_base_long_long_int, full_covr_2)
{
    cr_assert(my_str_nbr_base_long_long_int(-12, "0123456789"));
}

Test(my_str_nbr_base_unsigned, full_covr)
{
    cr_assert(my_str_nbr_base_unsigned(12, "0123456789"));
}

Test(my_str_nbr_long_long, full_covr)
{
    cr_assert(my_str_nbr_long_long(-12));
}

Test(my_str_nbr_long_long, full_covr_2)
{
    cr_assert_str_eq(my_str_nbr_long_long(-9223372036854775807), "-9223372036854775807");
}

Test(my_str_nbr_size_t, full_covr)
{
    cr_assert(my_str_nbr_size_t(12));
}

Test(my_str_nbr_unsigned, full_covr)
{
    cr_assert(my_str_nbr_unsigned(12));
}

Test(my_str_nbr_unsigned_long, full_covr)
{
    cr_assert(my_str_nbr_unsigned_long(12));
}

Test(my_str_to_word_array, full_covr, .init = cr_redirect_stdout)
{
    char *str = "----hello 9coucou.çava/oui";
    char **test = my_str_to_word_array(str);

    my_show_word_array(test);
    cr_assert_stdout_eq_str("hello\n9coucou\nava\noui\n");
}

Test(my_strcapitalize, full_covr)
{
    char str[6] = "c cac\0";

    cr_assert_str_eq(my_strcapitalize(str), "C Cac");
}

Test(my_strcat, full_covr)
{
    char str[30] = "coucou";
    char src[5] = "caca\0";

    cr_assert(my_strcat(str, src));
    my_strcat(NULL, src);
    my_strcat(str, NULL);
}

Test(my_strcmp, full_covr)
{
    char str[7] = "cbbcbb\0";
    char src[7] = "caacaa\0";

    cr_assert_eq(my_strcmp(str, str), 0);
    cr_assert_eq(my_strcmp(str, src), 1);
    cr_assert_eq(my_strcmp(src, str), -1);
    cr_assert_eq(my_strcmp(NULL, NULL), 0);
    cr_assert_eq(my_strcmp(NULL, src), -99);
    cr_assert_eq(my_strcmp(str, NULL), 99);
}

Test(my_strcpy, full_covr)
{
    char str[7] = "coucou\0";
    char src[7];

    my_strcpy(src, str);
    cr_assert_eq(str[0], src[0]);
}

Test(my_strncmp, full_covr)
{
    char str[7] = "cbbcbb\0";
    char src[7] = "caacaa\0";

    cr_assert_eq(my_strncmp(str, str, 6), 0);
    cr_assert_eq(my_strncmp(src, str, 6), -1);
    cr_assert_eq(my_strncmp(str, src, 6), 1);
    cr_assert_eq(my_strncmp(NULL, NULL, 6), 0);
    cr_assert_eq(my_strncmp(NULL, src, 6), -99);
    cr_assert_eq(my_strncmp(str, NULL, 6), 99);
}

Test(my_strncat, full_covr)
{
    char str[30] = "coucou";
    char src[5] = "caca\0";

    cr_assert(my_strncat(str, src, 2));
    my_strncat(NULL, src, 2);
    my_strncat(str, NULL, 2);
}

Test(my_strlowcase, full_covr)
{
    char str[30] = "couCou";

    cr_assert(my_strlowcase(str));
}

Test(my_strncpy, full_covr)
{
    char str[7] = "coucou\0";
    char src[7];

    cr_assert(my_strncpy(src, str, 10));
}

Test(my_strstr, full_covr)
{
    char str[7] = "cbbcbb\0";
    char src[4] = "cbb\0";

    cr_assert(my_strstr(str, src));
    cr_assert(my_strstr(str, ""));
    cr_assert_eq(my_strstr(str, "la"), 0);
}

Test(my_strupcase, full_covr)
{
    char str[30] = "couCou";

    cr_assert(my_strupcase(str));
}

Test(my_swap, full_covr)
{
    int a = 5;
    int b = 10;

    my_swap(&a, &b);
    cr_assert_eq(b, 5);
}

Test(my_array_len, full_covr)
{
    char *tab[5] = {"a", "b", "c", "d", NULL};

    cr_assert_eq(my_array_len((void **)tab), 4);
    cr_assert_eq(my_array_len((void **)NULL), 0);
}

Test(my, full_covr_for_null_return)
{
    cr_assert_eq(my_strlen(NULL), 0);
    my_strdup(NULL);
    cr_assert_eq(my_putstr_sized(NULL, 0), 0);
    cr_assert(my_putstr_error(NULL));
    cr_assert_eq(my_putstr(NULL), 0);
}

Test(my_char_is, full_covr)
{
    cr_assert_eq(my_char_is('a', "abc"), 1);
    cr_assert_eq(my_char_is('a', "bc"), 0);
}

Test(my_compute_power_rec_size_t, full_covr)
{
    cr_assert_eq(my_compute_power_rec_size_t(3, 2), 9);
    cr_assert_eq(my_compute_power_rec_size_t(21, 0), 1);
    cr_assert_eq(my_compute_power_rec_size_t(-4, -4), 0);
}

Test(my_convert_base_size_t, full_covr)
{
    cr_assert(my_convert_base_size_t("10", "0123456789", "01"));
    cr_assert(my_convert_base_size_t("10a10", "0123456789", "01"));
}

Test(my_find_nbr, full_covr)
{
    cr_assert_eq(my_find_nbr("10"), 10);
    my_find_nbr("a54");
    my_find_nbr("");
    my_find_nbr("abc");
    my_find_nbr("0");
}

Test(my_find_prime_inf, full_covr)
{
    my_find_prime_inf(9);
    my_find_prime_inf(0);
    my_find_prime_inf(4);
}

Test(my_free_ptr, full_covr)
{
    cr_assert_eq(my_free_ptr(NULL), NULL);
}

Test(my_str_contains, full_covr)
{
    cr_assert_eq(my_str_contains("coucou", "c"), 1);
    cr_assert_eq(my_str_contains("coucou", "a"), 0);
}

Test(my_strdup_word_array, full_covr)
{
    char *tab[5] = {"a", "b", "c", "d", NULL};

    char **test = my_strdup_word_array(tab);
    my_strdup_word_array(NULL);
    my_free_array((void **)test);
    my_free_array((void **)NULL);
}

Test(my_strerror, full_covr)
{
    cr_assert(my_strerror(0));
    cr_assert(my_strerror(1));
    my_strerror(-2);
}

Test(my_str_nbr_short, full_covr)
{
    cr_assert(my_str_nbr_short(12));
    cr_assert(my_str_nbr_short(-12));
    cr_assert(my_str_nbr_short(-32768));
}

Test(my_str_nbr_short_short, full_covr)
{
    cr_assert(my_str_nbr_short_short(12));
    cr_assert(my_str_nbr_short_short(-12));
    cr_assert(my_str_nbr_short_short(-128));
}

Test(my_str_nbr_base_unsigned_short, full_covr)
{
    cr_assert(my_str_nbr_base_unsigned_short(12, "0123456789"));
}

Test(my_str_nbr_base_unsigned_short_short, full_covr)
{
    cr_assert(my_str_nbr_base_unsigned_short_short(12, "0123456789"));
}

Test(my_str_nbr_base_unsigned_size_t, full_covr)
{
    cr_assert(my_str_nbr_base_unsigned_size_t(12, "0123456789"));
}

Test(my_str_nbr_base_unsigned_long, full_covr)
{
    cr_assert(my_str_nbr_base_unsigned_long(12, "0123456789"));
}

Test(my_getnbr_float, full_covr)
{
    my_getnbr_float("12.5");
    my_getnbr_float("12.5a");
    my_getnbr_float("a12.5");
    my_getnbr_float("12.5a12.5");
    my_getnbr_float("-12.5");
    my_getnbr_float("-10");
    my_getnbr_float("-2147483648");
    my_getnbr_float("a54");
    my_getnbr_float("00012345667");
    my_getnbr_float("42");
    my_getnbr_float("-+21");
}

Test(my_strict, full_covr)
{
    my_strict_getnbr("");
    my_strict_getnbr("12.5");
    my_strict_getnbr("12.5a");
    my_strict_getnbr("a12.5");
    my_strict_getnbr("12.5a12.5");
    my_strict_getnbr("-12.5");
    my_strict_getnbr("-10");
    my_strict_getnbr("-2147483648");
    my_strict_getnbr("a54");
    my_strict_getnbr("00012345667");
    my_strict_getnbr("42");
    my_strict_getnbr("-+21");
    my_strict_getnbr_float("");
    my_strict_getnbr_float("12.5");
    my_strict_getnbr_float("12.5a");
    my_strict_getnbr_float("a12.5");
    my_strict_getnbr_float("12.5a12.5");
    my_strict_getnbr_float("-12.5");
    my_strict_getnbr_float("-10");
    my_strict_getnbr_float("-2147483648");
    my_strict_getnbr_float("a54");
    my_strict_getnbr_float("00012345667");
    my_strict_getnbr_float("42");
    my_strict_getnbr_float("-+21");
    my_strict_find_nbr("");
    my_strict_find_nbr("12.5");
    my_strict_find_nbr("12.5a");
    my_strict_find_nbr("a12.5");
    my_strict_find_nbr("12.5a12.5");
    my_strict_find_nbr("-12.5");
    my_strict_find_nbr("-10");
    my_strict_find_nbr("-2147483648");
    my_strict_find_nbr("a54");
    my_strict_find_nbr("00012345667");
    my_strict_find_nbr("42");
    my_strict_find_nbr("-+21");
}

Test(my_round_float_str, full_covr)
{
    char str[6] = "12.5\0";
    char str2[6] = "12.4\0";
    char str3[6] = "0.6\0";
    char str4[6] = "9.9\0";
    char str5[6] = "-9.9\0";
    char str6[2] = "-\0";

    my_round_float_str(str5, '-', 0, 1);
    my_round_float_str(str5, '-', 4, 1);
    my_round_float_str(str6, '-', 0, 0);
    my_round_float_str(str, '5', 2, 1);
    my_round_float_str(str2, '5', 2, 1);
    my_round_float_str(str3, '8', 2, 1);
    my_round_float_str(str4, '9', 1, 1);
    my_round_float_str(str4, '9', 1, 1);
    my_round_float_str(str4, '9', 2, 1);
    my_round_float_str(str4, '9', 0, 1);
}

Test(my_str_to_word_array_select, full_covr, .init = cr_redirect_stdout)
{
    char *str = "----hello 9coucou.çava/oui";
    char **test = my_str_to_word_array_select(str, " -");

    my_show_word_array(test);
}

Test(my_str_to_word_array_string, full_covr, .init = cr_redirect_stdout)
{
    char *str = "  ----hello  9coucou.çava/oui";
    char **test = my_str_to_word_array_string(str, " ");

    my_show_word_array(test);
}

Test(my_super_array, full_covr)
{
    cr_assert(my_super_array("coucou", "c"));
}

Test(my_str_is, full_covr)
{
    cr_assert_eq(my_str_is("coucou", "coucou"), 1);
    cr_assert_eq(my_str_is("coucou", "a"), 0);
}

Test(my_putstr_fd, full_covr)
{
    my_putstr_fd(NULL, 1);
    my_putstr_fd_free(NULL, 1);
}

Test(my_strndup, full_covr)
{
    cr_assert(my_strndup("coucou", 3));
    my_strndup(NULL, 0);
}

Test(my_super_number, full_covr)
{
    cr_assert(my_super_number("12", (NB){0, 0, 1, 0}));
    cr_assert(my_super_number("12", (NB){0, 0, 1, 1}));
    cr_assert(my_super_number("-12", (NB){0, 0, 1, 1}));
    cr_assert(my_super_number("szz12", (NB){0, 1, 0, 0}));
    my_super_number("szz12", (NB){0, 0, 0, 0});
    cr_assert(my_super_number("12zxxz", (NB){0, 0, 1, 0}));
    cr_assert(my_super_number("12zxxz", (NB){0, 0, 0, 0}));
    cr_assert(my_super_number("-12", (NB){0, 0, 1, 1}));
    my_super_number("+-+---12", (NB){0, 0, 1, 1});
    cr_assert(my_super_number("+-+---12", (NB){1, 0, 1, 1}));
    my_super_number("", (NB){0, 0, 0, 0});
    my_super_number("-12+", (NB){0, 0, 0, 0});

}

Test(my_count_letter, full_covr)
{
    cr_assert_eq(my_count_letter("coucou", 'c'), 2);
}
