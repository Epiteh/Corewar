/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** sti
*/
#include "vm.h"

int get_sti_args(int arg, int type_arg, prog_t *prog)
{
    if (type_arg == T_REG)
        return (prog->regs[get_valid_register(arg - 1)]);
    else
        return (arg);
}

void my_sti(vm_t *vm, prog_t *prog)
{
    int prog_adress = get_prog_adress(prog);
    int type_args[MAX_ARGS_NUMBER] = {0};
    int args[MAX_ARGS_NUMBER] = {0};
    int register_addr = 0;

    get_args_types(vm, prog_adress, type_args);
    get_arg(vm, prog_adress, type_args, args);
    if (correct_reg_num(args, type_args) == -1) {
        prog->pc += 1;
        return;
    }
    register_addr = get_sti_args(args[2], type_args[2], prog);
    register_addr += get_sti_args(args[1], type_args[1], prog);
    write_memory_int(vm->memory, prog_adress + register_addr % IDX_MOD,
    prog->regs[get_valid_register(args[0] - 1)]);
    prog->pc += get_inst_len(type_args, vm->memory[prog_adress]);
}
