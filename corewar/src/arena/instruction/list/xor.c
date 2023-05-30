/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** xor
*/

#include "vm.h"

static void exec_xor_operation(prog_t *prog, int *type_args, int *args)
{
    if (type_args[0] == T_REG && type_args[1] != T_REG) {
        prog->regs[get_valid_register(args[2] - 1)] = args[1] ^
        prog->regs[get_valid_register(args[0] - 1)];
        return;
    } else if (type_args[0] != T_REG && type_args[1] == T_REG) {
        prog->regs[get_valid_register(args[2] - 1)] =
        prog->regs[get_valid_register(args[1] - 1)] ^
        args[0];
        return;
    }
    if (type_args[0] != T_REG && type_args[1] != T_REG) {
        prog->regs[get_valid_register(args[2] - 1)] =
        args[1] ^ args[0];
    } else if (type_args[0] == T_REG && type_args[1] != T_REG) {
        prog->regs[get_valid_register(args[2] - 1)] =
        prog->regs[get_valid_register(args[1] - 1)] ^
        prog->regs[get_valid_register(args[0] - 1)];
    }
}

static void handle_carry(prog_t *prog, int *args)
{
    if (prog->regs[get_valid_register(args[2])] == 0)
        prog->carry = 1;
    else
        prog->carry = 0;
}

void my_xor(vm_t *vm, prog_t *prog)
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
    exec_xor_operation(prog, type_args, args);
    handle_carry(prog, args);
    prog->pc += get_inst_len(type_args, vm->memory[prog_adress]);
}
