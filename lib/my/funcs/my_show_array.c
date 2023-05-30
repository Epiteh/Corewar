/*
** EPITECH PROJECT, 2023
** Base-project-for-C
** File description:
** my_show_array
*/

#include "../include/my.h"
#include <stddef.h>

void my_show_array(char **array)
{
    for (unsigned int i = 0; array[i] != NULL; i++) {
        my_putstr(array[i]);
        my_putchar('\n');
    }
}
