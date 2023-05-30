/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** show
*/

#include "vm.h"
#include <unistd.h>
#include <stdio.h>

void show_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putstr("\n");
    }
}
