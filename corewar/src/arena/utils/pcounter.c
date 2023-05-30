/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** pcounter
*/

#include "vm.h"

void update_pcounter(prog_t *prog, int num)
{
    prog->pc += num;
    while (prog->pc < 0)
        prog->pc += MEM_SIZE;
}
