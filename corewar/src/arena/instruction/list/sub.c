/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** sub
*/

#include "vm.h"

static void subtraction(prog_t *prog, int *args)
{
    prog->regs[get_valid_register(args[2])] =
        prog->regs[get_valid_register(args[1])] -
        prog->regs[get_valid_register(args[0])];
}

static void handle_carry(prog_t *prog, int *args)
{
    if (prog->regs[get_valid_register(args[2])] == 0)
        prog->carry = 1;
    else
        prog->carry = 0;
}

void my_sub(vm_t *vm, prog_t *prog)
{
    int prog_adress = get_prog_adress(prog);
    int args_type[MAX_ARGS_NUMBER] = {0};
    int args[MAX_ARGS_NUMBER] = {0};

    get_args_types(vm, prog_adress, args_type);
    get_arg(vm, prog_adress, args_type, args);
    if (correct_reg_num(args, args_type) == -1) {
        prog->pc += 1;
        return;
    }
    subtraction(prog, args);
    handle_carry(prog, args);
    prog->pc += get_inst_len(args_type, vm->memory[prog_adress]);
}
