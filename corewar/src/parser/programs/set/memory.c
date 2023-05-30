/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** memory
*/

#include "vm.h"

void set_mem(vm_t *corewar, prog_t *prog, int adr)
{
    for (int i = 0; i < prog->size; i++) {
        if ((adr + i) >= MEM_SIZE)
            err_output("Error : unexpected try to write out-memory\n");
        corewar->memory[adr + i] = prog->content[i];
    }
    prog->load_adress = adr;
}
