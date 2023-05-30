/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** ids
*/

#include "vm.h"

static bool is_used(prog_t *progs, int to_find)
{
    prog_t *tmp = progs;

    for (; tmp; tmp = tmp->next)
        if (tmp->id == to_find)
            return (true);
    return (false);
}

void set_ids(prog_t *progs)
{
    prog_t *tmp = progs;
    int id = 1;

    for (; tmp; tmp = tmp->next) {
        if (tmp->id != -1)
            continue;
        for (; is_used(progs, id); id++)
            ;
        tmp->id = id;
        tmp->regs[0] = id;
    }
}
