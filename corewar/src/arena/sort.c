/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** sort
*/

#include "vm.h"

static void handle_find_element(prog_t **find_element,
    prog_t **new)
{
    while ((*find_element)->next != NULL &&
        (*find_element)->next->id <= (*new)->id)
            (*find_element) = (*find_element)->next;
    (*new)->next = (*find_element)->next;
    (*find_element)->next = (*new);
}

void sort_champion_id(vm_t **vm)
{
    prog_t *sort_id = NULL;
    prog_t *find_element = NULL;
    prog_t *next_element = NULL;
    prog_t *new = (*vm)->prog;

    for (; new; new = next_element) {
        next_element = new->next;
        if ((sort_id == NULL)
            || (sort_id->id >= new->id)) {
            new->next = sort_id;
            sort_id = new;
        } else {
            find_element = sort_id;
            handle_find_element(&find_element, &new);
        }
    }
    (*vm)->prog = sort_id;
}
