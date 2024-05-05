/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Prints a formating structure (formating) in stdout
*/
/**
 * @file my_show_formating.c
 * @brief The file containing the my_show_formating function
 * @author Nicolas TORO
 */

#include "myprintf.h"

void my_show_formating(formating_t *formating)
{
    my_putstr("Le formatage du flag est le suivant :");
    my_putstr("\nFORMATAGE: ");
    my_putnbr(formating->id_ft);
    my_putstr("\nWIDHT: ");
    my_putnbr(formating->id_wd);
    my_putstr("\nPRECISION: ");
    my_putnbr(formating->id_prc);
    my_putstr("\nPRECISION NUMBER: ");
    my_putnbr(formating->id_nb);
    my_putstr("\nSPECIFIER: ");
    my_putnbr(formating->id_sp);
    my_putstr("\nFORMAT FINALE: ");
    my_putstr(formating->final_format);
    my_putstr("\nLE FLAG: ");
    my_putchar(formating->flag);
    my_putstr("\nNEXT CHARA: ");
    my_putchar(formating->next_chara);
    my_putchar('\n');
}
