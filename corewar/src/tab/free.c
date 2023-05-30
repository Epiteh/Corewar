/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free
*/

#include "vm.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}
