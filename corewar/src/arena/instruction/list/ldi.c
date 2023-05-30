/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** ldi
*/

#include "vm.h"

static void handle_carry(prog_t *prog, int *args)
{
    if (prog->regs[get_valid_register(args[2])] == 0)
        prog->carry = 1;
    else
        prog->carry = 0;
}

static void operation(prog_t *prog, vm_t *vm, int *args)
{
    prog->regs[get_valid_register(args[2])] +=
        vm->memory[get_memory_adress(prog->pc + args[0] % IDX_MOD)];
}

void my_ldi(vm_t *vm, prog_t *prog)
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
    operation(prog, vm, args);
    handle_carry(prog, args);
    prog->pc += get_inst_len(type_args, vm->memory[prog_adress]);
}
