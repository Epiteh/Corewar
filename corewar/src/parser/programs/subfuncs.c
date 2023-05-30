/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** subfuncs
*/

#include "vm.h"

void check_magic(FILE *fd)
{
    uint32_t magic = 0;

    fread(&magic, sizeof(uint32_t), 1, fd);
    magic = ((magic & 0xFF) << 24) | ((magic & 0xFF00) << 8) |
        ((magic & 0xFF0000) >> 8) | ((magic >> 24) & 0xFF);
    if (magic != COREWAR_EXEC_MAGIC)
        err_output("Invalid file (non-corresponding magic nb)\n");
    fseek(fd, 0, SEEK_SET);
}

int get_fight_size(prog_t *prog)
{
    prog_t *tmp = prog;
    int i = 0;

    while (tmp) {
        i += tmp->size;
        tmp = tmp->next;
    }
    return (i);
}
