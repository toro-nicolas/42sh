/*
** EPITECH PROJECT, 2024
** test_mylist_lib
** File description:
** Unit tests for each function of the mylist lib
*/
/**
 * @file test_mylist_lib.c
 * @brief Unit tests for each function of the mylist lib
 * @author Nicolas TORO
 */

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include "../lib/mylist/mylist.h"

Test(my_concat_list, my_concat_list)
{
    node_t *list1 = NULL;
    node_t *list2 = NULL;
    node_t *list3 = NULL;

    my_push_back(&list1, "Hello", STRING);
    my_push_back(&list1, "World", STRING);
    my_push_back(&list1, "World", STRING);
    my_push_back(&list1, "World", STRING);
    my_push_back(&list1, "World", STRING);
    my_push_back(&list1, "World", STRING);
    my_push_back(&list2, "Bonjour", STRING);
    my_push_back(&list2, "Monde", STRING);
    my_concat_list(&list1, list2);
    my_concat_list(&list3, list2);
}

Test(my_delete_nodes, my_delete_nodes)
{
    node_t *list = NULL;
    int nodes_deleted = 0;
    char *str1 = my_strdup("World");
    char *str2 = my_strdup("Hellow");
    char *str3 = my_strdup("World");

    my_push_back(&list, str1, STRING);
    my_push_back(&list, str2, STRING);
    my_push_back(&list, str3, STRING);
    my_delete_nodes(&list, "World", my_strcmp);
    nodes_deleted = my_delete_nodes(&list, "World", my_strcmp);
}

Test(my_find_node, my_find_node)
{
    node_t *list = NULL;
    node_t *node = NULL;
    char *str1 = my_strdup("World");
    char *str2 = my_strdup("Hellow");
    char *str3 = my_strdup("World");

    my_push_back(&list, str1, STRING);
    my_push_back(&list, str2, STRING);
    my_push_back(&list, str3, STRING);
    node = my_find_node(list, "World", my_strcmp);
    node = my_find_node(list, "Helloooo", my_strcmp);
}

Test(my_list_size, my_list_size)
{
    node_t *list = NULL;
    int size = 0;
    char *str1 = my_strdup("World");
    char *str2 = my_strdup("Hellow");
    char *str3 = my_strdup("World");

    my_push_back(&list, str1, STRING);
    my_push_back(&list, str2, STRING);
    my_push_back(&list, str3, STRING);
    size = my_list_size(list);
}

Test(my_list_to_array, my_list_to_array)
{
    node_t *list = NULL;
    char **array = NULL;
    char *str1 = my_strdup("World");
    char *str2 = my_strdup("Hellow");
    char *str3 = my_strdup("World");

    my_push_back(&list, str1, STRING);
    my_push_back(&list, str2, STRING);
    my_push_back(&list, str3, STRING);
    array = (char **)my_list_to_array(list);
    array = (char **)my_list_to_array(list);
}

Test(my_merge_list, my_merge_list)
{
    node_t *list1 = NULL;
    node_t *list2 = NULL;
    node_t *list3 = NULL;
    char *str1 = my_strdup("World");
    char *str2 = my_strdup("Hellow");
    char *str3 = my_strdup("World");
    char *str4 = my_strdup("World!");

    my_push_back(&list1, str1, STRING);
    my_push_back(&list1, str2, STRING);
    my_push_back(&list1, str3, STRING);
    my_push_back(&list2, str1, STRING);
    my_push_back(&list2, str2, STRING);
    my_push_back(&list2, str4, STRING);
    my_merge_list(&list1, list2, my_strcmp);
    my_merge_list(&list3, list2, my_strcmp);
}

Test(my_params_to_list, my_params_to_list)
{
    node_t *list = NULL;
    char *av[] = {"Hello", "World", "Bonjour", "Monde"};
    int ac = 4;

    list = my_params_to_list(ac, av);
    list = my_params_to_list(ac, av);
}

Test(my_pop_back, my_pop_back)
{
    node_t *list = NULL;
    node_t *node = NULL;
    node_t *list2 = NULL;
    char *str1 = my_strdup("World");
    char *str2 = my_strdup("Hellow");
    char *str3 = my_strdup("World");

    my_push_back(&list, str1, STRING);
    my_push_back(&list, str2, STRING);
    my_push_back(&list, str3, STRING);
    node = my_pop_back(&list);
    node = my_pop_back(&list);
    my_pop_back(&list2);
    my_push_back(&list2, str1, STRING);
    my_pop_back(&list2);
}

Test(my_pop_front, my_pop_front)
{
    node_t *list = NULL;
    node_t *node = NULL;
    char *str1 = my_strdup("World");
    char *str2 = my_strdup("Hellow");
    char *str3 = my_strdup("World");

    my_push_back(&list, str1, STRING);
    my_push_back(&list, str2, STRING);
    my_push_back(&list, str3, STRING);
    node = my_pop_front(&list);
    node = my_pop_front(&list);
    list = NULL;
    my_pop_front(&list);
}

Test(my_pop_node, my_pop_node)
{
    node_t *list = NULL;
    node_t *node = NULL;
    char *str1 = my_strdup("World");
    char *str2 = my_strdup("Hellow");
    char *str3 = my_strdup("World");
    char *str4 = my_strdup("Hello!");

    my_push_back(&list, str1, STRING);
    my_push_back(&list, str2, STRING);
    my_push_back(&list, str3, STRING);
    my_push_back(&list, str4, STRING);
    node = my_pop_node(&list, "Hello!", my_strcmp);
    node = my_pop_node(&list, "World", my_strcmp);
    node = my_pop_node(&list, "Hello", my_strcmp);
}

Test(my_rev_list, my_rev_list)
{
    node_t *list = NULL;
    char *str1 = my_strdup("World");
    char *str2 = my_strdup("Hellow");
    char *str3 = my_strdup("World");

    my_push_back(&list, str1, STRING);
    my_push_back(&list, str2, STRING);
    my_push_back(&list, str3, STRING);
    my_rev_list(&list);
}

Test(my_show_list, my_show_list)
{
    node_t *list = NULL;
    char c = 42;
    char *str = my_strdup("World");
    int nb1 = 42;
    short nb2 = 42;
    char nb3 = 42;
    long nb4 = 42;
    long long nb5 = 42;
    unsigned char nb6 = 42;
    unsigned short nb7 = 42;
    unsigned int nb8 = 42;
    unsigned long nb9 = 42;
    unsigned long long nb10 = 42;
    size_t nb11 = 42;
    float nb12 = 42.42;
    double nb13 = 42.42;
    void *ptr = NULL;
    char **array = NULL;

    my_push_back(&list, str, STRING);
    my_push_back(&list, &c, CHAR);
    my_push_back(&list, &nb1, INT);
    my_push_back(&list, &nb2, SHORT);
    my_push_back(&list, &nb3, SHORT_SHORT);
    my_push_back(&list, &nb4, LONG);
    my_push_back(&list, &nb5, LONG_LONG);
    my_push_back(&list, &nb6, UNSIGNED_SHORT_SHORT);
    my_push_back(&list, &nb7, UNSIGNED_SHORT);
    my_push_back(&list, &nb8, UNSIGNED_INT);
    my_push_back(&list, &nb9, UNSIGNED_LONG);
    my_push_back(&list, &nb10, UNSIGNED_LONG_LONG);
    my_push_back(&list, &nb11, SIZE_T);
    my_push_back(&list, &nb12, FLOAT);
    my_push_back(&list, &nb13, DOUBLE);
    my_push_back(&list, &ptr, VOID);
    my_push_back(&list, &array, ARRAY_OF_STRING);
    my_push_back(&list, &ptr, UNKNOWN);
    my_show_list(list);
}

Test(my_sort_list, my_sort_list)
{
    node_t *list = NULL;
    char *str1 = my_strdup("World");
    char *str2 = my_strdup("Hellow");
    char *str3 = my_strdup("World");

    my_push_back(&list, str1, STRING);
    my_push_back(&list, str2, STRING);
    my_push_back(&list, str3, STRING);
    my_sort_list(&list, my_strcmp);
}
