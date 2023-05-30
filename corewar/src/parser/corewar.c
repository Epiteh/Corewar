/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** vm
*/

#include "vm.h"

static void free_list(prog_t *prog)
{
    prog_t *tmp = prog;
    prog_t *next = NULL;

    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

int corewar(int ac, char **av)
{
    vm_t corewar;

    init_structs(&corewar, ac, av);
    arena_loop(&corewar);
    free_list(corewar.prog);
    return (0);
}
