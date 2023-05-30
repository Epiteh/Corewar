/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** check.c
*/
#include "asm.h"

bool check_type(label_list_t *list, char **array, unsigned int type_index,
    unsigned int j)
{
    int counter = 0;
    int y = 0;
    for (; y < op_tab[type_index].nbr_args; y += 1) {
        if ((T_REG & op_tab[type_index].type[y]) &&
            is_register(array[1 + j + y]))
                counter += 1;
        if ((T_DIR & op_tab[type_index].type[y]) &&
            is_direct(list, array[1 + j + y]))
                counter += 1;
        if ((T_IND & op_tab[type_index].type[y]) &&
            is_indirect(list, array[1 + j + y]))
                counter += 1;
    }
    if (counter != op_tab[type_index].nbr_args) {
        err_output("Error : invalid argument type.\n");
    }
    return (true);
}
