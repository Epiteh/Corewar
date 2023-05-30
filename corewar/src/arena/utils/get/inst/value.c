/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** pcounter
*/

#include "vm.h"

int get_inst_value(vm_t *vm, int addr, int val_len)
{
    int *memory = vm->memory;
    int ret_value = 0;

    for (unsigned int i = 0; i < (unsigned int) val_len; i ++)
        ret_value = (ret_value << 8) |
            memory[get_memory_adress(addr + i) % MEM_SIZE];
    if (val_len == 2)
        ret_value = (short) ret_value;
    else if (val_len == 1)
        ret_value = (char) ret_value;
    return (ret_value);
}
