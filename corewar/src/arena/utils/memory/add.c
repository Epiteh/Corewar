/*
** EPITECH PROJECT, 2023
** Corewar - 28 mai
** File description:
** add_pro_in_memory.c
*/

#include "vm.h"

static int convert_adress(int num)
{
    while (num < 0)
        num += MEM_SIZE;
    return (num % MEM_SIZE);
}

void add_memory_prog(prog_t *prog, vm_t *vm, int adress)
{
    for (int i = 0; i < prog->size ; i += 1)
        vm->memory[convert_adress(adress + i)] = prog->content[i];
    prog->load_adress = adress;
}
