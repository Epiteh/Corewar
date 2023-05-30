/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** len
*/

#include "vm.h"

int len_tab(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; ++i);
    return (i);
}
