/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** lldi
*/

#include "vm.h"

static void handle_carry(prog_t *prog, int *args)
{
    if (prog->regs[get_valid_register(args[2])] == 0)
        prog->carry = 1;
    else
        prog->carry = 0;
}

static void handle_ldi(vm_t *vm, prog_t *prog, int *args, int *type_args)
{
    int num = prog->regs[get_valid_register(args[2])];

    num += vm->memory[get_prog_adress(prog) + (args[0] + args[1])];
    prog->regs[get_valid_register(args[2])] = num;
    handle_carry(prog, args);
    prog->pc += get_inst_len(type_args, vm->memory[get_prog_adress(prog)]);
}

void my_lldi(vm_t *vm, prog_t *prog)
{
    int prog_adress = get_prog_adress(prog);
    int type_args[MAX_ARGS_NUMBER] = {0};
    int args[MAX_ARGS_NUMBER] = {0};

    get_args_types(vm, prog_adress, type_args);
    get_arg(vm, prog_adress, type_args, args);
    if (correct_reg_num(args, type_args) == -1) {
        prog->pc += 1;
        return;
    }
    handle_ldi(vm, prog, args, type_args);
}
