/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** and
*/

#include "vm.h"

static void handle_carry(prog_t *prog, int value)
{
    if (prog->regs[get_valid_register(value - 1)] == 0)
        prog->carry = 1;
    else
        prog->carry = 0;
}

static void handle_and(vm_t *vm, prog_t *prog, int *args, int *type_args)
{
    int value1 = 0;
    int value2 = 0;
    int value3 = 0;

    if (type_args[0] == T_REG)
        value1 = prog->regs[get_valid_register(args[0] - 1)];
    else
        value1 = args[0];
    if (type_args[1] == T_REG)
        value2 = prog->regs[get_valid_register(args[1] - 1)];
    else
        value2 = args[1];
    value3 = args[2];
    prog->regs[get_valid_register(value3 - 1)] = value1 & value2;
    handle_carry(prog, value3);
    prog->pc += get_inst_len(type_args, vm->memory[get_prog_adress(prog)]);
}

void my_and(vm_t *vm, prog_t *prog)
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
    handle_and(vm, prog, args, type_args);
}
