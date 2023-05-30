/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** aff
*/

#include "vm.h"

static void handle_carry(char reg_char, prog_t *prog)
{
    if (reg_char == 0)
        prog->carry = 1;
    else
        prog->carry = 0;
}

void my_aff(vm_t *vm, prog_t *prog)
{
    int prog_adress = get_prog_adress(prog);
    int args = get_inst_value(vm, prog_adress + 2, 1);
    char reg_char = args % 256;

    my_putchar(reg_char);
    update_pcounter(prog, 3);
    handle_carry(reg_char, prog);
    return;
}
