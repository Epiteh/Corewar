/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** pcounter
*/

#include "vm.h"

int correct_reg_num(int *arg, int *args_type)
{
    for (unsigned int i = 0; i < MAX_ARGS_NUMBER; i += 1)
        if (arg[i] > 15 && args_type[i] == T_REG)
            return (-1);
    return (0);
}
