/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** count.c
*/
#include "asm.h"

static int args_nbr(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return (i);
}

bool check_args_validity(label_list_t *list, char **array, unsigned int i,
    unsigned int j)
{
    int args_len = args_nbr(array) - 1 - j;

    if (args_len != op_tab[i].nbr_args || args_len >= MAX_ARGS_NUMBER) {
        err_output("Error : invalid number of arguments\n");
    }
    if (!check_type(list, array, i, j))
        return (false);
    return (true);
}
