/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** ld
*/

#include "vm.h"

static void handle_carry(prog_t *prog, int *args)
{
    if (prog->regs[get_valid_register(args[1])] == 0)
        prog->carry = 1;
    else
        prog->carry = 0;
}

static void load_value(int *type_args, int *args, prog_t *prog)
{
    if (type_args[0] == T_REG) {
        prog->regs[get_valid_register(args[1] - 1)] = prog->pc +
        prog->regs[get_valid_register(args[0] - 1)] % IDX_MOD;
    } else {
        prog->regs[get_valid_register(args[1] - 1)] =
        prog->pc + args[0] % IDX_MOD;
    }
    handle_carry(prog, args);
}

void my_ld(vm_t *vm, prog_t *prog)
{
    int next_instr_addr = get_prog_adress(prog);
    int type_args[MAX_ARGS_NUMBER] = {0};
    int args[MAX_ARGS_NUMBER] = {0};

    get_args_types(vm, next_instr_addr, type_args);
    get_arg(vm, next_instr_addr, type_args, args);
    load_value(type_args, args, prog);
    prog->pc += get_inst_len(type_args,
        vm->memory[next_instr_addr]);
}
