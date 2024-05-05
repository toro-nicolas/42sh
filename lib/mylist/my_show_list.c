/*
** EPITECH PROJECT, 2023
** my_show_list
** File description:
** Shows a linked list
*/
/**
 * @file my_show_list.c
 * @brief The file containing the my_show_list function
 * @author Nicolas TORO
 */

#include "mylist.h"

static int print_int(void *data, type_t type)
{
    if (type == SHORT_SHORT)
        return my_printf("%hhd", *((char *)data));
    if (type == SHORT)
        return my_printf("%hd", *((short *)data));
    if (type == INT)
        return my_printf("%d", *((int *)data));
    if (type == LONG)
        return my_printf("%ld", *((long *)data));
    if (type == LONG_LONG)
        return my_printf("%lld", *((long long *)data));
    return 0;
}

static int print_unsigned_int(void *data, type_t type)
{
    if (type == UNSIGNED_SHORT_SHORT)
        return my_printf("%hhu", *((unsigned char *)data));
    if (type == UNSIGNED_SHORT)
        return my_printf("%hu", *((unsigned short *)data));
    if (type == UNSIGNED_INT)
        return my_printf("%u", *((unsigned int *)data));
    if (type == UNSIGNED_LONG)
        return my_printf("%lu", *((unsigned long *)data));
    if (type == UNSIGNED_LONG_LONG)
        return my_printf("%llu", *((unsigned long long *)data));
    if (type == SIZE_T)
        return my_printf("%zu", *((size_t *)data));
    return 0;
}

static int print_other(void *data, type_t type)
{
    if (type == FLOAT)
        return my_printf("%f", *((float *)data));
    if (type == DOUBLE)
        return my_printf("%f", *((double *)data));
    if (type == CHAR)
        return my_printf("%c", *((char *)data));
    if (type == STRING)
        return my_printf("%s", (char *)data);
    if (type == ARRAY_OF_STRING)
        return my_printf("%S", ((char **)data));
    if (type == VOID)
        return my_printf("%p", data);
    return 0;
}

static int select_print(void *data, type_t type)
{
    int (*PRINT_FUNCTIONS[])(void *, type_t) = {
        &print_int, &print_unsigned_int, &print_other};

    if (type <= 4)
        return PRINT_FUNCTIONS[0](data, type);
    if (type <= 10)
        return PRINT_FUNCTIONS[1](data, type);
    else
        return PRINT_FUNCTIONS[2](data, type);
}

void my_show_list(node_t *list)
{
    my_printf("List:\nPrevious | Current | Next\n");
    for (node_t *tmp = list; tmp != NULL; tmp = tmp->next) {
        if (tmp->prev == NULL)
            my_printf("NULL");
        else
            select_print(tmp->prev->data, tmp->prev->type);
        my_printf(" ---> ");
        select_print(tmp->data, tmp->type);
        my_printf(" ---> ");
        if (tmp->next == NULL)
            my_printf("NULL");
        else
            select_print(tmp->next->data, tmp->next->type);
        write(1, "\n", 1);
    }
}
