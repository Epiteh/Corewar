/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-vm-sasha.dupeyroux
** File description:
** get_args_type
*/
#include "vm.h"

static void handle_idx(int instr, int *args_types)
{
    if (instr == 0x0a) {
        args_types[0] = T_IND;
        args_types[1] = T_IND;
    } else if (instr == 0x0b) {
        args_types[1] = (args_types[1] == T_DIR) ? T_IND : T_REG;
        args_types[2] = (args_types[2] == T_DIR) ? T_IND : T_REG;
    }
    if (instr == 0x0c) {
        args_types[0] = T_IND;
    } else if (instr == 0x0e) {
        args_types[0] = T_IND;
        args_types[1] = T_IND;
    }
    if (instr == 0x0f) {
        args_types[0] = T_IND;
    }
}

void get_args_types(vm_t *vm, int prog_addr, int *args_types)
{
    int instr = vm->memory[prog_addr] - 1;
    int cursor = vm->memory[get_memory_adress(prog_addr + 1)];

    if (instr < 0 || instr > 15) {
        return;
    }
    if (!is_direct_arg(instr)) {
        for (unsigned int i = 0; i < MAX_ARGS_NUMBER; i += 1) {
            args_types[i] = op_tab[instr].type[i];
        }
        return;
    }
    for (int i = 0; i < 3; i += 1) {
        args_types[i] = (cursor >> (6 - 2 * i)) & 3;
    }
    handle_idx(instr + 1, args_types);
}
