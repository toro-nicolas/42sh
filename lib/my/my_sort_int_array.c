/*
** EPITECH PROJECT, 2023
** my_sort_int_array
** File description:
** Sorts an array (array) with a defined size (size)
** of integers in ascending order
*/
/**
 * @file my_sort_int_array.c
 * @brief The file containing the my_sort_int_array function
 * @author Nicolas TORO
 */

#include "my.h"

static void sort_tab(int *array, int temp, int i, int j)
{
    if (array[j] < array[i]) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void my_sort_int_array(int *array, int size)
{
    int temp = 0;

    for (int i = 0; i <= size; i++) {
        for (int j = i + 1; j < size; j++) {
            sort_tab(array, temp, i, j);
        }
    }
}
