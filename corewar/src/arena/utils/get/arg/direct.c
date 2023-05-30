/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** is_instr_not_direct_args
*/
#include "vm.h"

bool is_direct_arg(int cmd)
{
    int inst[] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 12, 13, 15, -1};

    if ((cmd < 0) || (cmd > 15))
        return (false);
    for (int i = 0; inst[i] != -1; i ++)
        if (cmd == inst[i])
            return (true);
    return (false);
}
