/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** list
*/

#include "vm.h"

void add_prog(prog_t **progs, prog_t *new)
{
    prog_t *tmp = (*progs);

    if (!tmp) {
        (*progs) = new;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}
