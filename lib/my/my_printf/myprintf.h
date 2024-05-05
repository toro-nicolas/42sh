/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** The header of all formats and flags
*/
/**
 * @file myprintf.h
 * @brief The file containing the header of all formats and flags
 * @author Nicolas TORO
 */

#include "../my.h"

#ifndef MYPRINTF_H_
    #define MYPRINTF_H_

    #define FORMATAGE "-+ #0"
    #define WIDTH "0123456789"
    #define PRECISION "."
    #define NUMBERS "0123456789"

typedef struct formating_s {
    int fd;
    int id_ft;
    int id_wd;
    int id_prc;
    int id_nb;
    int id_sp;
    int nb_format;
    char final_format[10];
    char next_chara;
    va_list *liste;
    int index_user;
    int id_us;
    char flag;
} formating_t;

typedef struct flags_s {
    char *str;
    int index_flag;
} flags_t;

typedef struct user_s {
    char const *str;
    int total_len;
    int i;
} user_t;

/* Round functions */
void round_a(char *float_nb, int precision, char last_char, int i);
void round_biga(char *float_nb, int precision, char last_char, int i);

/* Find functions */
formating_t *find_first(user_t *user, int *i,
    formating_t *formating);
formating_t *find_width(user_t *user, int *i,
    formating_t *formating);
formating_t *find_precision(user_t *user, int *i,
    formating_t *formating);
formating_t *find_numbers(user_t *user, int *i,
    formating_t *formating);
formating_t *find_specifier(user_t *user, int *i,
    formating_t *formating);

/* Format functions */
void format_first(user_t *user, flags_t *flags,
    formating_t *formating, int *copy);
void format_width(user_t *user, flags_t *flags,
    formating_t *formating, int *copy);
void format_precision(user_t *user, flags_t *flags,
    formating_t *formating, int *copy);
void format_numbers(user_t *user, flags_t *flags,
    formating_t *formating, int *copy);
void format_specifier(user_t *user, flags_t *flags,
    formating_t *formating, int *copy);
void my_show_formating(formating_t *formating);

void format_plus_double(char *str_finale, formating_t *formating, double nb);
void format_moins_double(char *str_finale, formating_t *formating, double nb);
void format_esp_double(char *str_finale, formating_t *formating, double nb);
void format_hash_double(char *str_finale, formating_t *formating, double nb);
void format_zero_double(char *str_finale, formating_t *formating, double nb);
void format_it_double(char *str_finale,
    formating_t *formating, double partie_d);
void precise_it_double(char *str_finale,
    formating_t *formating, double partie_d);

void format_plus_int(char *str_finale,
    formating_t *formating, size_t nb);
void format_moins_int(char *str_finale,
    formating_t *formating, size_t nb);
void format_esp_int(char *str_finale,
    formating_t *formating, size_t nb);
void format_hash_int(char *str_finale,
    formating_t *formating, size_t nb);
void format_zero_int(char *str_finale,
    formating_t *formating, size_t nb);
void format_it_int(char *str_finale,
    formating_t *formating, size_t nb);
void precise_it_int(char *str_finale,
    formating_t *formating, size_t nb);

void format_plus_char(char *str_finale, formating_t *formating, char c);
void format_moins_char(char *str_finale, formating_t *formating, char c);
void format_esp_char(char *str_finale, formating_t *formating, char c);
void format_hash_char(char *str_finale, formating_t *formating, char c);
void format_zero_char(char *str_finale, formating_t *formating, char c);
void format_it_char(char *str_finale,
    formating_t *formating, char c);

void format_plus_str(char *str_finale, formating_t *formating);
void format_moins_str(char *str_finale, formating_t *formating);
void format_esp_str(char *str_finale, formating_t *formating);
void format_hash_str(char *str_finale, formating_t *formating);
void format_zero_str(char *str_finale, formating_t *formating);
void format_it_str(char *str_finale,
    formating_t *formating);

/* Specify functions */
char *specify_it_int(formating_t *formating, size_t temp);
char *specify_it_base(formating_t *formating, size_t temp, char *);

/* Flag functions */
int flag_c(va_list list, formating_t *);
int flag_s(va_list list, formating_t *);
int flag_d(va_list list, formating_t *);
int flag_i(va_list list, formating_t *);
int flag_p(va_list list, formating_t *);
int flag_o(va_list list, formating_t *);
int flag_u(va_list list, formating_t *);
int flag_x(va_list list, formating_t *);
int flag_bigx(va_list list, formating_t *);
int flag_e(va_list list, formating_t *);
int flag_bige(va_list list, formating_t *);
int flag_f(va_list list, formating_t *);
int flag_bigf(va_list list, formating_t *);
int flag_g(va_list list, formating_t *);
int flag_bigg(va_list list, formating_t *);
int flag_a(va_list list, formating_t *);
int flag_biga(va_list list, formating_t *);
int flag_n(va_list list, formating_t *, int len);
int flag_m(va_list list, formating_t *);
int flag_b(va_list list, formating_t *);
int flag_bigs(va_list list, formating_t *);
int flag_bigd(va_list list, formating_t *);
int flag_percent(va_list list, formating_t *);

extern int (*FLAGS[])(va_list, formating_t *);

#endif /* MYPRINTF_H_ */
