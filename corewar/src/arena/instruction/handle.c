/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** handle
*/

#include "vm.h"

static const int cycle_instruction_number[16] = {10, 5, 5, 10, 10, 6, 6, 6, 20,
    25, 25, 800, 10, 50, 1000, 2};

int get_prog_adress(prog_t *prog)
{
    int actual_adress = (prog->pc + prog->load_adress);

    while (actual_adress < 0)
        actual_adress += MEM_SIZE;
    return (actual_adress % MEM_SIZE);
}

static int find_inst_cycle(prog_t *prog, int num_cycle)
{
    if ((num_cycle < 1) || (num_cycle > 16))
        return (-1);
    return (cycle_instruction_number[num_cycle - 1]);
}

static int get_remaining_cycle(vm_t *vm, prog_t *prog)
{
    int remaining_cycle = (vm->cycle - prog->death_cycle);

    if (remaining_cycle < 0)
        remaining_cycle *= -1;
    return (remaining_cycle);
}

static void loop_instruction(vm_t *vm, int num_cycle, int wait_cycle,
    int prog_adress)
{
    prog_t *prog = vm->prog;

    for (; prog; prog = prog->next) {
        if (prog->dead == true)
            continue;
        prog_adress = get_prog_adress(prog);
        num_cycle = find_inst_cycle(prog, vm->memory[prog_adress]);
        wait_cycle = get_remaining_cycle(vm, prog);
        if (num_cycle == -1)
            update_pcounter(prog, T_REG);
        if ((prog->death_cycle == -1) || (wait_cycle >= num_cycle))
            launch_instruction(vm, prog, vm->memory[prog_adress]);
    }
}

void handle_instruction(vm_t *vm)
{
    int num_cycle = -1;
    int wait_cycle = -1;
    int prog_adress = -1;

    loop_instruction(vm, num_cycle, wait_cycle, prog_adress);
}
