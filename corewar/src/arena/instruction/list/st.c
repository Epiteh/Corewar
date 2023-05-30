/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** my_st
*/

#include "vm.h"

void my_st(vm_t *vm, prog_t *prog)
{
    int next_instr_addr = get_prog_adress(prog);
    int type_args[MAX_ARGS_NUMBER] = {0};
    int args[MAX_ARGS_NUMBER] = {0};
    int regs_address = 0;

    get_args_types(vm, next_instr_addr, type_args);
    get_arg(vm, next_instr_addr, type_args, args);
    if (correct_reg_num(args, type_args) == -1) {
        prog->pc += 1;
        return;
    }
    regs_address = get_sti_args(args[1], type_args[1], prog);
    write_memory_int(vm->memory, get_correct_addr(next_instr_addr +
        regs_address % IDX_MOD),
        prog->regs[get_valid_register(args[0] - 1)]);
    prog->pc += get_inst_len(type_args, vm->memory[next_instr_addr]);
}
