/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** lauch
*/

#include "vm.h"

static const inst_t instructions[] = {
    {&my_live}, {&my_ld}, {&my_st}, {&my_add}, {&my_sub}, {&my_and}, {&my_or},
    {&my_xor}, {&my_zjmp}, {&my_ldi}, {&my_sti}, {&my_fork}, {&my_lld},
    {&my_lldi}, {&my_lfork}, {&my_aff},
};

void launch_instruction(vm_t *vm, prog_t *prog, int instruction)
{
    if (instruction < 1 || instruction > 16) {
        update_pcounter(prog, T_REG);
        return;
    }
    instructions[instruction - 1].func(vm, prog);
    prog->death_cycle = vm->cycle;
}
