/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-vm-sasha.dupeyroux
** File description:
** get_args
*/
#include "vm.h"

void get_arg(vm_t *vm, int prog_addr, int *type_args,
    int *args)
{
    int cursor = 1 +
        is_direct_arg(vm->memory[prog_addr] - 1);

    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        if (type_args[i] == T_REG) {
            args[i] = get_inst_value(vm, prog_addr + cursor, 1);
            cursor += 1;
        }
        if (type_args[i] == T_DIR) {
            args[i] = get_inst_value(vm, prog_addr + cursor, DIR_SIZE);
            cursor += DIR_SIZE;
        }
        if (type_args[i] == T_IND) {
            args[i] = get_inst_value(vm, prog_addr + cursor, IND_SIZE);
            cursor += IND_SIZE;
        }
    }
}
