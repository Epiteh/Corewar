/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-vm-sasha.dupeyroux
** File description:
** live
*/

#include "vm.h"

static void display_infos(vm_t *vm, prog_t *prog, int prog_id)
{
    if (prog_id != prog->id)
        return;
    my_putstr("The player ");
    my_put_nbr(prog_id);
    my_putstr("(");
    my_putstr(prog->header.name);
    my_putstr(")is alive.\n");
    vm->winner.id = prog_id;
    my_strcpy(prog->header.name, vm->winner.name);
}

void my_live(vm_t *vm, prog_t *prog)
{
    int next_instr_addr = get_prog_adress(prog);
    int arg = get_inst_value(vm, next_instr_addr + 1, 4);
    prog_t *tmp = vm->prog;

    for (; tmp; tmp = tmp->next) {
        if (tmp->id == arg) {
            tmp->call_live = vm->cycle;
            break;
        }
    }
    display_infos(vm, prog, arg);
    update_pcounter(prog, 5);
    vm->live_call++;
}
