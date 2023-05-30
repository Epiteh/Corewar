/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-vm-sasha.dupeyroux
** File description:
** get_args
*/
#include "vm.h"

int get_inst_len(int *type_args, int instr_addr)
{
    int length = 1 + is_direct_arg(instr_addr - 1);

    for (int i = 0; i < MAX_ARGS_NUMBER; i += 1) {
        if (type_args[i] == T_IND)
            length += IND_SIZE;
        if (type_args[i] == T_REG)
            length += 1;
        if (type_args[i] == T_DIR)
            length += DIR_SIZE;
    }
    return (length);
}
