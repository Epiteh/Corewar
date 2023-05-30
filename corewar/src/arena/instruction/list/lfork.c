/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** lfork
*/

#include "vm.h"

void my_lfork(vm_t *vm, prog_t *prog)
{
    prog_t *new = my_prog_cpy(prog);
    int prog_adress = get_prog_adress(prog);
    int args = get_inst_value(vm, prog_adress + 1, IND_SIZE);

    new->load_adress = prog_adress + prog->size + (args);
    new->pc = prog->pc + (args);
    add_memory_prog(new, vm, new->load_adress);
    add_prog(&vm->prog, new);
    update_pcounter(prog, 3);
}
