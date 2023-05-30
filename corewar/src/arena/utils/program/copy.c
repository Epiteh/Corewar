/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** prog_cpy
*/

#include "vm.h"
static proghead_t header_cpy(proghead_t header)
{
    proghead_t *new = malloc(sizeof(proghead_t));

    my_strcpy(header.name, new->name);
    my_strcpy(header.comment, new->comment);
    return ((*new));
}

static void content_cpy(prog_t *prog, prog_t *new)
{
    for (unsigned int i = 0; i < prog->size; i += 1) {
        new->content[i] = prog->content[i];
    }
}

static void reg_cpy(prog_t *prog, prog_t *new)
{
    for (unsigned int i = 0; i < REG_NUMBER; i += 1) {
        new->regs[i] = prog->regs[i];
    }
}

prog_t *my_prog_cpy(prog_t *prog)
{
    prog_t *new = malloc(sizeof(prog_t));

    new->header = header_cpy(prog->header);
    new->id = prog->id;
    new->load_adress = 0;
    new->size = prog->size;
    new->pc = 0;
    new->death_cycle = prog->death_cycle;
    new->call_live = prog->call_live;
    new->dead = false;
    content_cpy(prog, new);
    reg_cpy(prog, new);
    new->carry = prog->carry;
    new->next = NULL;
    return (new);
}
