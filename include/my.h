/*
** EPITECH PROJECT, 2023
** Libmy
** File description:
** The header file of the libmy
*/
/**
 * @file my.h
 * @brief The header file of the libmy
 * @author Nicolas TORO
 */

#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <dirent.h>
#include <signal.h>
#include <glob.h>

#ifndef MY_H_
    #define    MY_H_

// MACROS :

    // Constants :

    #define    MAX_INT 2147483647
    #define    MIN_INT -2147483648
    #define    MAX_LONG 9223372036854775807
    #define    MIN_LONG -9223372036854775808
    #define    MAX_SHORT 32767
    #define    MIN_SHORT -32768
    #define    MAX_SHORT_SHORT 127
    #define    MIN_SHORT_SHORT -128
    #define    MAX_SIZE_T 18446744073709551615

    // Basics macros :

    #define    ABS(value) ((value < 0) ? - value : value)
    #define    MAX(a, b) ((a > b) ? a : b)
    #define    MIN(a, b) ((a < b) ? a : b)
    #define    STR_CONTAINS(str, find) (my_strstr(str, find) != NULL) ? 1 : 0
    #define    NB number_settings_t

    // str_to_word_array macros :

    #define    STR2ARRAY(str) my_str_to_word_array(str)
    #define    STR2ARRAY_SEP(str, sep) my_str_to_word_array_select(str, sep)
    #define    STR2ARRAY_STR(str, sep) my_str_to_word_array_string(str, sep)

    // Free macros :

    #define    FREE(ptr) ptr = my_free_ptr(ptr)
    #define    FREE_WORD_ARRAY(ptr) my_free_array((void **)ptr)



// TYPEDEFS :

/* A reproduction of the boolean */
typedef enum my_bool {
    FALSE = 0, /* FALSE */
    TRUE = 1 /* TRUE */
} my_bool_t;

extern int my_errno; /* The error number */

/* The information of the my_params_to_array */
struct info_param {
    int length; /*The length of the string */
    char *str; /* The string */
    char *copy; /* The copy of the string */
    char **word_array; /* The array of words */
};

/* The settings of the my_super_number */
typedef struct number_settings_s {
    my_bool_t multiple_signe; /* Allow multiples signes in the string */
    my_bool_t letter_before; /* Allow letters before the number */
    my_bool_t letter_after; /* Allow letters after the number */
    my_bool_t overflow; /* Allow overflow in the number */
} number_settings_t;

    #define NB number_settings_t



// FUNCTIONS PROTOTYPES :

    // Write functions :

/**
 * @brief Prints a char (c) in the stdout
 * @param c The char to print
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_putchar(char c);

/**
 * @brief Prints 'P' if the number (n) is positive
 * or 'N' if the number (n) is negative
 * @param nb The number to check
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_isneg(int nb);

/**
 * @brief Prints a number (nb) in stdout
 * @param nb The number to print
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_putnbr(int nb);

/**
 * @brief Writes a string (str) in stdout
 * and returns the length of the printed string
 * @param str The string to print
 * @return <b>int</b> The length of the printed string
 * @author Nicolas TORO
 */
int my_putstr(char const *str);

/**
 * @brief Prints a string (str) but replaces
 * non-printable characters with their hexadecimal number
 * @param str The string to print
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_showstr(char const *str);

/**
 * @brief Prints a memory dump of a string (str) with a defined size
 * @param str The string to print
 * @param size The size of the string
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_showmem(char const *str, int size);

/**
 * @brief Prints all the numbers composed by (n) different digits numbers
 * All digits in the number are different and only the smallest
 * number composed by those digits are display
 * @param n The number of digits in the number
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_print_combn(int n);

/**
 * @brief Prints a number (nb) in the requested base (base) in stdout
 * @param nbr The number to print
 * @param base The base to use
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_putnbr_base(int nbr, char const *base);

/**
 * @brief Prints all word in an array (tab)
 * @param tab The array of words to print
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_show_word_array(char *const *tab);

/**
 * @brief Prints all the parameters of the program
 * @param argc The number of parameters
 * @param argv The array of parameters
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_print_params(int argc, char **argv);

/**
 * @brief Prints a string (str) in stderr
 * @param str The string to print
 * @return <b>int</b> <u>84</u>
 * @author Nicolas TORO
 */
int my_putstr_error(char const *str);

/**
 * @brief Prints a string (str) in stdout with a defined size (size)
 * and returns the length of the printed string
 * @param str The string to print
 * @param size The size of the string
 * @return <b>int</b> The length of the printed string
 * @author Nicolas TORO
 */
int my_putstr_sized(char const *str, int size);

/**
 * @brief Writes a string (str) in a file descriptor (fd)
 * and returns the length of the printed string
 * @param str The string to print
 * @param fd The file descriptor to write in
 * @return <b>int</b> The number of printed characters
 * @author Nicolas TORO
 */
int my_putstr_fd(char const *str, int fd);

/**
 * @brief Writes a string (str) in a file descriptor (fd), free it
 * and returns the length of the printed string
 * @param str The string to print
 * @param fd The file descriptor to write in
 * @return <b>int</b> The number of printed characters
 * @author Nicolas TORO
 */
int my_putstr_fd_free(char *str, int fd);

/**
 * @brief Prints a string (format) with possible flags and format
 * in stdout and returns the length the printed string
 * @param format The string to print
 * @param ... The arguments to use with flags and format
 * @return <b>int</b> The number of printed characters
 * @author Nicolas TORO and Gianni TUERO
 */
int my_printf(char const *format, ...);

/**
 * @brief Writes a string (format) with possible flags and format
 * in a file descriptor (fd) and returns the length the printed string
 * @param format The string to print
 * @param ... The arguments to use with flags and format
 * @return <b>int</b> The number of printed characters
 * @author Nicolas TORO and Gianni TUERO
 */
int my_fprintf(int fd, char const *format, ...);



    // Char functions :

/**
 * @brief Checks if a char (c) is a letter
 * @param c The char to check
 * @return <b>int</b> <u>1</u> if the char is a letter, <u>0</u> otherwise
 * @author Nicolas TORO
 */
int my_char_is_alpha(char const c);

/**
 * @brief Checks if a char (c) is a number
 * @param c The char to check
 * @return <b>int</b> <u>1</u> if the char is a number, <u>0</u> otherwise
 * @author Nicolas TORO
 */
int my_char_is_num(char const c);

/**
 * @brief Checks if a char (c) is printable
 * @param c The char to check
 * @return <b>int</b> <u>1</u> if the char is printable, <u>0</u> otherwise
 * @author Nicolas TORO
 */
int my_char_is_printable(char const c);

/**
 * @brief Checks if a char (c) is in a list of chars (char_list)
 * @param c The char to check
 * @param char_list The list of chars to check
 * @return <b>int</b> <u>1</u> if the char is in the list, <u>0</u> otherwise
 * @author Nicolas TORO
 */
int my_char_is(char c, const char *char_list);

/**
 * @brief Adds a char (chr) at the end of a string (str)
 * @note The string must be allocated and have enough space
 * @param str The string to modify
 * @param chr The char to add
 * @return <b>char *</b> The modified string
 * @author Nicolas TORO
 */
char *my_add_chr(char *str, char chr);

/**
 * @brief Returns the last char of a string (str)
 * @param str The string to check
 * @return <b>char</b> The last char of the string
 * @author Nicolas TORO
 */
char my_get_last_char(char *str);



    // String functions :

/**
 * @brief Checks if a string (str) is alphabetical
 * @param str The string to check
 * @return <b>int</b> <u>1</u> if the string is alphabetical,
 * <u>0</u> otherwise
 * @author Nicolas TORO
 */
int my_str_isalpha(char const *str);

/**
 * @brief Checks if a string (str) is a number
 * @param str The string to check
 * @return <b>int</b> <u>1</u> if the string is a number, <u>0</u> otherwise
 * @author Nicolas TORO
 */
int my_str_isnum(char const *str);

/**
 * @brief Checks if a string (str) is lowercase
 * @param str The string to check
 * @return <b>int</b> <u>1</u> if the string is lowercase, <u>0</u> otherwise
 * @author Nicolas TORO
 */
int my_str_islower(char const *str);

/**
 * @brief Checks if a string (str) is uppercase
 * @param str The string to check
 * @return <b>int</b> <u>1</u> if the string is uppercase, <u>0</u> otherwise
 * @author Nicolas TORO
 */
int my_str_isupper(char const *str);

/**
 * @brief Checks if a string (str) is printable
 * @param str The string to check
 * @return <b>int</b> <u>1</u> if the string is printable, <u>0</u> otherwise
 * @author Nicolas TORO
 */
int my_str_isprintable(char const *str);

/**
 * @brief Checks if a string (str) is composed of characters
 * in the characters list (char_list) or 0 if not
 * @param str The string to check
 * @return <b>int</b> <u>1</u> if the string is composed of characters
 * in the characters list (char_list), <u>0</u> otherwise
 * @author Nicolas TORO
 */
int my_str_is(char *str, const char *char_list);

/**
 * @brief Checks if a string (str) contains a character
 * in a list of characters (char_list)
 * @param str The string to check
 * @param char_list The list of characters to check
 * @return <b>int</b> <u>1</u> if the string contains a character in the list,
 * <u>0</u> otherwise
 * @author Nicolas TORO
 */
int my_str_contains(char *str, char *char_list);

/**
 * @brief Returns the length of a string (str)
 * @param str The string to check
 * @return <b>int</b> The length of the string
 * @author Nicolas TORO
 */
int my_strlen(char const *str);

/**
 * @brief Copies a string (src) and paste it on another string (dest)
 * @note The destination string must be allocated
 * @param dest The destination string
 * @param src The source string
 * @param n The size of the string
 * @return <b>char*</b> The destination string
 * @author Nicolas TORO
 */
char *my_strcpy(char *dest, char const *src);

/**
 * @brief Copies a string (src) and paste it on another string (dest)
 * with a defined size (n)
 * @note The destination string must be allocated
 * @param dest The destination string
 * @param src The source string
 * @param n The size of the string
 * @return <b>char*</b> The destination string
 * @author Nicolas TORO
 */
char *my_strncpy(char *dest, char const *src, int n);

/**
 * @brief Reverses the characters in a string (str)
 * and returns the string (str)
 * @param str The string to reverse
 * @return <b>char*</b> The reversed string
 * @author Nicolas TORO
 */
char *my_revstr(char *str);

/**
 * @brief Search a string (to_find) on another (str)
 * and returns the address of the first occurrence
 * @param str The string to be scanned
 * @param to_find The string to search in
 * @return <b>char*</b> The address of the <u>first occurrence</u>
 * of the string to_find in the string str, <u>NULL</u> otherwise
 * @author Nicolas TORO
 */
char *my_strstr(char *str, char const *to_find);

/**
 * @brief Compares two strings (s1) and (s2)
 * @param s1 The first string to compare
 * @param s2 The second string to compare
 * @return <b>int</b> <u>0</u> if the strings are identical, otherwise
 * the difference between the first different characters in the strings
 * @author Nicolas TORO
 */
int my_strcmp(char const *s1, char const *s2);

/**
 * @brief Compares two strings (s1) and (s2) with a defined size (n)
 * @param s1 The first string to compare
 * @param s2 The second string to compare
 * @param n The size of the strings to compare
 * @return <b>int</b> <u>0</u> if the strings are identical, otherwise
 * the difference between the first different characters in the strings
 * @author Nicolas TORO
 */
int my_strncmp(char const *s1, char const *s2, int n);

/**
 * @brief Replaces lowcase by upcase of a string (str)
 * @param str The string to modify
 * @return <b>char*</b> The modified string
 * @author Nicolas TORO
 */
char *my_strupcase(char *str);

/**
 * @brief Replaces upcase by lowcase of a string (str)
 * @param str The string to modify
 * @return <b>char*</b> The modified string
 * @author Nicolas TORO
 */
char *my_strlowcase(char *str);

/**
 * @brief Capitalizes the first letter of each word in a string (str)
 * and lowercase the other letters
 * @param str The string to modify
 * @return <b>char*</b> The modified string
 * @author Nicolas TORO
 */
char *my_strcapitalize(char *str);

/**
 * @brief Concatenates two strings (dest) and (src)
 * @note The destination string must be allocated and have enough space
 * @param dest The destination string
 * @param src The source string
 * @return <b>char*</b> The destination string
 * @author Nicolas TORO
 */
char *my_strcat(char *dest, char const *src);

/**
 * @brief Concatenates two strings (dest) and (src) with a defined size (nb)
 * @note The destination string must be allocated and have enough space
 * @param dest The destination string
 * @param src The source string
 * @param nb The size of the string
 * @return <b>char*</b> The destination string
 * @author Nicolas TORO
 */
char *my_strncat(char *dest, char const *src, int nb);

/**
 * @brief Duplicates a string (src) and returns the new string
 * @param src The string to duplicate
 * @return <b>char*</b> The duplicated string
 * @author Nicolas TORO
 */
char *my_strdup(const char *src);

/**
 * @brief Duplicates a string (src) with a defined size (n)
 * and returns the new string
 * @param src The string to duplicate
 * @param n The size of the string
 * @return <b>char*</b> The duplicated string
 * @author Nicolas TORO
 */
char *my_strndup(const char *src, int n);

/**
 * @brief Duplicates a word array (array) and returns the new array
 * @param array The word array to duplicate
 * @return <b>char**</b> The duplicated word array
 * @author Nicolas TORO
 */
char **my_strdup_word_array(char **array);

/**
 * @brief Returns the error message of the error number (error)
 * @param error The error number (errno)
 * @return <b>char**</b> The error message of the error number
 * @author Nicolas TORO
 */
const char *my_strerror(int error);

/**
 * @brief Counts the number of times a letter (c) is in a string (str)
 * @param str The string to check
 * @param c The letter to count
 * @return <b>int</b> The number of times the letter is in the string
 * @author Nicolas TORO
 */
int my_count_letter(char const *str, char c);

/**
 * @brief Get the index of a char in a str according to its occurrence
 * @param str The string to check
 * @param c The letter to find
 * @param occurrence The occurrence of the letter to find
 * @return <b>int</b> <u>-1</u> if the letter is not found, otherwise
 * the index of the letter in the string
 */
int my_get_char_index(char *str, char c, int occurrence);

/**
 * @brief Replace a char in a string by another char
 * @param str The string to modify
 * @param to_replace The char to replace
 * @param replace_by The char to replace by
 * @return <b>void</b>
 */
void my_replace_char(char *str, char to_replace, char replace_by);



    // Int functions :

/**
 * @brief Returns the length of a number (nb)
 * @param nb The number to check
 * @return <b>int</b> The length of the number
 * @author Nicolas TORO
 */
int my_nbrlen(int nb);

/**
 * @brief Swaps two integers (a) and (b)
 * @param a The first integer
 * @param b The second integer
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_swap(int *a, int *b);

/**
 * @brief Sorts an array (array) with a defined size (size)
 * of integers in ascending order
 * @param tab The array to sort
 * @param size The size of the tab
 * @author Nicolas TORO
 */
void my_sort_int_array(int *tab, int size);

/**
 * @brief Returns the result of the conversion of a number (nbr)
 * in a specific base (base_from) to another base (base_to)
 * @param nbr The number to convert
 * @param base_from The base of the number
 * @param base_to The base to convert the number
 * @return <b>char*</b> The converted number in the new base
 * @author Nicolas TORO
 */
char *my_convert_base(char const *nbr,
    char const *base_from, char const *base_to);

/**
 * @brief Returns the result of the conversion of a unsigned number (nbr)
 * in a specific base (base_from) to another base (base_to)
 * @param nbr The number to convert
 * @param base_from The base of the number
 * @param base_to The base to convert the number
 * @return <b>char*</b> The converted number in the new base
 * @author Nicolas TORO
 */
char *my_convert_base_unsigned(char const *nbr,
    char const *base_from, char const *base_to);

/**
 * @brief Returns the result of the conversion of a size_t number (nbr)
 * in a specific base (base_from) to another base (base_to)
 * @param nbr The number to convert
 * @param base_from The base of the number
 * @param base_to The base to convert the number
 * @return <b>char*</b> The converted number in the new base
 * @author Nicolas TORO
 */
char *my_convert_base_size_t(char const *nbr,
    char const *base_from, char const *base_to);

/**
 * @brief Modify a string (float) and round it
 * @param float_nb The float number to round
 * @param last_char The last character of the float number
 * @param i The index of the float number
 * @param enable The enable of the round
 * @return <b>void</b>
 */
void my_round_float_str(char *float_nb, char last_char, int i, int enable);



    // Array functions :

/**
 * @brief Returns the length of an array (array)
 * @param array The array to check
 * @return <b>int</b> The length of the array
 * @author Nicolas TORO
 */
int my_array_len(void **array);

/**
 * @brief Returns an array of words from a string (str)
 * @param str The string to convert
 * @return <b>char**</b> The array of words
 * @author Nicolas TORO
 */
char **my_str_to_word_array(char const *str);

/**
 * @brief Returns an array of words delimited
 * by a list of separator (separator) from a string (str)
 * @param str The string to convert
 * @param separator The separator to use
 * @return <b>char**</b> The array of words
 * @author Nicolas TORO
 */
char **my_str_to_word_array_select(char const *str, char const *separator);

/**
 * @brief Returns an array of words delimited by a separator (separator)
 * from a string (str)
 * @param str The string to convert
 * @param separator The separator to use
 * @return <b>char**</b> The array of words
 * @author Nicolas TORO
 */
char **my_str_to_word_array_string(char const *str, char const *separator);

/**
 * @brief Returns an array of words delimited
 * by a list of separator (separator) from a string (str)
 * @param str The string to convert
 * @param sep The separator to use
 * @return <b>char**</b> The array of words
 * @author Gianni TUERO
 */
char **my_super_array(char *str, char *sep);

/**
 * @brief Frees an array (array)
 * @param array The array to free
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_free_array(void **array);

/**
 * @brief Frees a pointer (ptr)
 * @param ptr The pointer to free
 * @return <b>void *</b> Always <u>NULL</u>
 * @author Nicolas TORO
 */
void *my_free_ptr(void *ptr);



    // Get number functions :

/**
 * @brief Returns an int number starting from a string number (str)
 * @note Returns 0 if the string is not a number or if the number overflow
 * @note The function accept only -0123456789
 * @param str The string to convert
 * @return <b>int</b> The number found in the string
 * @author Nicolas TORO
 */
int my_getnbr(char const *str);

/**
 * @brief Find the first number (number) found in a string
 * @note Returns -1 if the string does not contain a number
 * @note The program function overflow
 * @param str The string to convert
 * @return <b>int</b> The number found in the string
 * @author Nicolas TORO
 */
int my_find_nbr(char const *str);

/**
 * @brief Returns a float number starting from a string number (str)
 * @note Returns 0 if the string is not a number
 * @note The function accept only -0123456789.
 * @note The function accept only one point in the string
 * @param str The string to convert
 * @return <b>float</b> The number found in the string
 * @author Nicolas TORO
 */
float my_getnbr_float(char const *str);

/**
 * @brief Returns a number starting from a string number (str)
 * in the requested base (base)
 * @note Returns 0 if the string is not a number
 * @note The function accept multiple signes in the string
 * @param str The string to convert
 * @param base The base of the number
 * @return <b>int</b> The number found in the string
 * @author Nicolas TORO
 */
int my_getnbr_base(char const *str, char const *base);

/**
 * @brief Returns an int number starting from a string number (str)
 * @note The function does not accept signes in the string and overflow
 * @note Returns -1 if the string is invalid
 * @param str The string to convert
 * @return <b>int</b> The number found in the string
 * @author Nicolas TORO
 */
int my_strict_getnbr(char const *str);

/**
 * @brief Returns a float number starting from a string number (str)
 * @note The function does not accept signes in the string and overflow
 * @note Returns -1 if the string is invalid
 * @param str The string to convert
 * @return <b>float</b> The number found in the string
 * @author Nicolas TORO
 */
float my_strict_getnbr_float(char const *str);

/**
 * @brief Find the first number (number) found in a string
 * @note The function does not accept signes in the string and overflow
 * @note Returns -1 if the string does not contain a number
 * @param str The string to convert
 * @return <b>int</b> The number found in the string
 * @author Nicolas TORO
 */
int my_strict_find_nbr(char const *str);

/**
 * @brief Returns an int number starting from a string number (number)
 * and change my_errno if an error occurs depending on the settings (settings)
 * @note The function will change <u>my_errno</u> by 1 if an error occurs
 * depending on the settings you choose with the <b>settings</b> parameter
 * @param number The string to convert
 * @param settings The settings of the function
 * @return <b>int</b> The number found in the string
 * @author Nicolas TORO
 */
int my_super_number(char *number, number_settings_t settings);



    // Calculs functions :

/**
 * @brief Returns the power (p) of the number (nb)
 * @note Returns 0 if the power is negative
 * @param nb The number to calculate
 * @param power The power of the number
 * @author Nicolas TORO
 */
int my_compute_power_rec(int nb, int power);

/**
 * @brief Returns the power (p) of the number (nb)
 * @note Returns 0 if the power is negative
 * @param nb The number to calculate
 * @param power The power of the number
 * @return <b>size_t</b> The result of the power
 * @author Nicolas TORO
 */
size_t my_compute_power_rec_size_t(int nb, int p);

/**
 * @brief Returns the square root of a number (nb)
 * @param nb The number to calculate
 * @return <b>int</b> The square root of the number
 * @author Nicolas TORO
 */
int my_compute_square_root(int nb);

/**
 * @brief Returns the factorial of a number (nb)
 * @note Returns 0 if the number is negative or greater than 12
 * @param nb The number to calculate
 * @return <b>int</b> The factorial of the number
 * @author Nicolas TORO
 */
int my_compute_factorial_rec(int nb);

/**
 * @brief Returns 1 if the number (nb) is prime and 0 otherwise
 * @param nb The number to check
 * @return <b>int</b> <u>1</u> if the number is prime, <u>0</u> otherwise
 * @author Nicolas TORO
 */
int my_is_prime(int nb);

/**
 * @brief Returns the next prime number after a number (nb)
 * @param nb The number to check
 * @return <b>int</b> The next prime number after the number
 * or the number if it is prime
 * @author Nicolas TORO
 */
int my_find_prime_sup(int nb);

/**
 * @brief Returns the previous prime number before a number (nb)
 * @param nb The number to check
 * @return <b>int</b> The previous prime number before the number
 * or the number if it is prime
 * @author Nicolas TORO
 */
int my_find_prime_inf(int nb);



    // Params functions :

/**
 * @brief Returns a info_params struct of the argc (ac) and the argv (av)
 * @param ac The number of parameters
 * @param av The array of parameters
 * @return <b>struct info_param*</b> The information of the parameters
 * @author Nicolas TORO
 */
struct info_param *my_params_to_array(int ac, char **av);

/**
 * @brief Prints the information of a parameter array (par)
 * @param par The information of the parameters
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_show_param_array(struct info_param const *par);

/**
 * @brief Prints all the arguments (argc and argv) in reverse order
 * @param par The information of the parameters
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_rev_params(int argc, char **argv);

/**
 * @brief Sorts the parameters (argc and argv) in ascending order
 * @param argc The number of parameters
 * @param argv The array of parameters
 * @return <b>void</b>
 * @author Nicolas TORO
 */
void my_sort_params(int argc, char **argv);

/**
 * @brief Returns a string with all the arguments (argc and argv) concatenated
 * @param argc The number of parameters
 * @param argv The array of parameters
 * @return <b>char*</b> The concatenated string of the parameters
 * @author Nicolas TORO
 */
char *my_concat_params(int argc, char **argv);



    // Str nbr functions :

/**
 * @brief Returns the string conversion of a number (nb)
 * @param nb The number to convert
 * @return <b>char*</b> The string conversion of the number
 * @author Nicolas TORO
 */
char *my_str_nbr(int nb);

/**
 * @brief Returns the string conversion of a short number (nb)
 * @param nb The number to convert
 * @return <b>char*</b> The string conversion of the number
 * @author Nicolas TORO
 */
char *my_str_nbr_short(short int nb);

/**
 * @brief Returns the string conversion of a short short number (nb)
 * @param nb The number to convert
 * @return <b>char*</b> The string conversion of the number
 * @author Nicolas TORO
 */
char *my_str_nbr_short_short(signed char nb);

/**
 * @brief Returns the string conversion of
 * an unsigned number (nbr) in specific base (base)
 * @param nbr The number to convert
 * @param base The base to use
 * @return <b>char*</b> The string conversion of the number
 * @author Nicolas TORO
 */
char *my_str_nbr_base_unsigned(unsigned int nbr, char const *base);

/**
 * @brief Returns the string conversion of
 * an unsigned short number (nbr) in specific base (base)
 * @param nb The number to convert
 * @param base The base to use
 * @return <b>char*</b> The string conversion of the number
 * @author Nicolas TORO
 */
char *my_str_nbr_base_unsigned_short(unsigned short nbr, char const *base);

/**
 * @brief Returns the string conversion of
 * an unsigned short short number (nbr) in specific base (base)
 * @param nb The number to convert
 * @param base The base to use
 * @return <b>char*</b> The string conversion of the number
 * @author Nicolas TORO
 */
char *my_str_nbr_base_unsigned_short_short(unsigned char nbr,
    char const *base);

/**
 * @brief Returns the string conversion of
 * an size_t number (nbr) in specific base (base)
 * @param nb The number to convert
 * @param base The base to use
 * @return <b>char*</b> The string conversion of the number
 * @author Nicolas TORO
 */
char *my_str_nbr_base_unsigned_size_t(size_t nbr, char const *base);

/**
 * @brief Returns the string conversion of
 * an unsigned long number (nbr) in specific base (base)
 * @param nb The number to convert
 * @param base The base to use
 * @return <b>char*</b> The string conversion of the number
 * @author Nicolas TORO
 */
char *my_str_nbr_base_unsigned_long(unsigned long nbr, char const *base);

/**
 * @brief Returns the string conversion of
 * an long long number (nbr) in specific base (base)
 * @param nb The number to convert
 * @param base The base to use
 * @return <b>char*</b> The string conversion of the number
 * @author Nicolas TORO
 */
char *my_str_nbr_base_long_long_int(long long int nbr, char const *base);

/**
 * @brief Returns the string conversion of an unsigned number (nb)
 * @param nb The number to convert
 * @return <b>char*</b> The string conversion of the number
 * @author Nicolas TORO
 */
char *my_str_nbr_unsigned(unsigned int nb);

/**
 * @brief Returns the string conversion of an unsigned long number (nb)
 * @param nb The number to convert
 * @return <b>char*</b> The string conversion of the number
 * @author Nicolas TORO
 */
char *my_str_nbr_unsigned_long(unsigned long int nb);

/**
 * @brief Returns the string conversion of an long long number (nb)
 * @param nb The number to convert
 * @return <b>char*</b> The string conversion of the number
 * @author Nicolas TORO
 */
char *my_str_nbr_long_long(long long nb);

/**
 * @brief Returns the string conversion of an size_t number (nb)
 * @param nb The number to convert
 * @return <b>char*</b> The string conversion of the number
 * @author Nicolas TORO
 */
char *my_str_nbr_size_t(size_t nb);

#endif /* MY_H_ */
