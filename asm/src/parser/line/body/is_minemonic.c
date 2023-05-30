/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** is_minemonic.c
*/
#include "asm.h"

bool is_minemonic(char *element)
{
    unsigned int i = 0;

    while (op_tab[i].mnemonique != 0) {
        if (my_strcmp(element, op_tab[i].mnemonique) == 0)
            return (true);
        i++;
    }
    return (false);
}
