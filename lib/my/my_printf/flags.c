/*
** EPITECH PROJECT, 2024
** template
** File description:
** The flags.c
*/
/**
 * @file flags.c
 * @brief The file containing the flags function
 * @author Nicolas TORO
*/

#include "myprintf.h"

int (*FLAGS[])(va_list, formating_t *) = {
    &flag_d,
    &flag_i,
    &flag_c,
    &flag_s,
    &flag_p,
    &flag_o,
    &flag_u,
    &flag_x,
    &flag_bigx,
    &flag_e,
    &flag_bige,
    &flag_f,
    &flag_bigf,
    &flag_g,
    &flag_bigg,
    &flag_a,
    &flag_biga,
    &flag_b,
    &flag_bigs,
    &flag_bigd,
    &flag_percent,
    &flag_m
};
