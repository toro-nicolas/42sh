/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** The file containing the about builtin
*/
/**
 * @file about.c
 * @brief The file containing the about builtin
 */

#include "../../include/myshell.h"

/**
 * @brief Print the informations about Arthur WARIN
 * @return <b>void</b>
 */
static void arthurwarin(void)
{
    my_printf("\033[1m\033[34m----------------------------------------------"
        "\033[0m\n");
    my_printf("👤 \033[1m\033[31mArthur WARIN\033[0m\n");
    my_printf("🎓 Student class of 2028\n");
    my_printf("🎒 Programme Grande Ecole\n");
    my_printf("📍 Epitech Nice\n");
    my_printf("📧 \033[4m\033[37marthur.warin@epitech.eu\033[0m\n");
}

/**
 * @brief Print the informations about Christophe VANDEVOIR
 * @return <b>void</b>
 */
static void christophevandevoir(void)
{
    my_printf("\033[1m\033[34m----------------------------------------------"
        "\033[0m\n");
    my_printf("👤 \033[1m\033[31mChristophe VANDEVOIR\033[0m\n");
    my_printf("🎓 Student class of 2028\n");
    my_printf("🎒 Programme Grande Ecole\n");
    my_printf("📍 Epitech Nice\n");
    my_printf("📧 \033[4m\033[37mchristophe.vandevoir@epitech.eu\033[0m\n");
}

/**
 * @brief Print the informations about Gianni TUERO
 * @return <b>void</b>
 */
static void giannituero(void)
{
    my_printf("\033[1m\033[34m----------------------------------------------"
        "\033[0m\n");
    my_printf("👤 \033[1m\033[31mGianni TUERO\033[0m\n");
    my_printf("🎓 Student class of 2028\n");
    my_printf("🎒 Programme Grande Ecole\n");
    my_printf("📍 Epitech Nice\n");
    my_printf("📧 \033[4m\033[37mgianni.tuero@epitech.eu\033[0m\n");
}

/**
 * @brief Print the informations about Nicolas TORO
 * @return <b>void</b>
 */
static void nicolastoro(void)
{
    my_printf("\033[1m\033[34m----------------------------------------------"
        "\033[0m\n");
    my_printf("👤 \033[1m\033[31mNicolas TORO\033[0m\n");
    my_printf("🎓 Student class of 2028\n");
    my_printf("🎒 Programme Grande Ecole\n");
    my_printf("📍 Epitech Nice\n");
    my_printf("📧 \033[4m\033[37mnicolas.toro@epitech.eu\033[0m\n");
}

/**
 * @brief Print the informations about Raphael ROSSIGNOL
 * @return <b>void</b>
 */
static void raphaelrossignol(void)
{
    my_printf("\033[1m\033[34m----------------------------------------------"
        "\033[0m\n");
    my_printf("👤 \033[1m\033[31mRaphael ROSSIGNOL\033[0m\n");
    my_printf("🎓 Student class of 2028\n");
    my_printf("🎒 Programme Grande Ecole\n");
    my_printf("📍 Epitech Nice\n");
    my_printf("📧 \033[4m\033[37mraphael.rossignol@epitech.eu\033[0m\n");
}

/**
 * @brief The about builtin
 * @param mysh The shell structure
 * @return <b>int</b> <u>0</u> if the command succeed, <u>1</u> otherwise
 */
int exec_about(mysh_t *mysh)
{
    if (mysh->args[1] != NULL) {
        my_printf("about: Too many arguments.\n");
        return 1;
    }
    my_printf("It is a simple shell that can execute commands.\n\n");
    my_printf("It was made by:\n");
    arthurwarin();
    christophevandevoir();
    giannituero();
    nicolastoro();
    raphaelrossignol();
    my_printf("\033[1m\033[34m----------------------------------------------"
        "\033[0m\n");
    return 0;
}
