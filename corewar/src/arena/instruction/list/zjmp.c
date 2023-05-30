/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** zjump
*/

#include "vm.h"

void my_zjmp(vm_t *vm, prog_t *prog)
{
    int prog_adress = get_prog_adress(prog);
    int arg = get_inst_value(vm, prog_adress + 1, 2);

    if (prog->carry == 1)
        update_pcounter(prog, arg % IDX_MOD);
    else
        update_pcounter(prog, 3);
}
