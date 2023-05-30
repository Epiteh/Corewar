/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** check.c
*/
#include "asm.h"

void check_label_initialisation(label_list_t *list)
{
    node_label_t *temp;

    temp = list->begin;
    while (temp != NULL) {
        if (!temp->is_init) {
            my_putstr("Error : Label \'");
            my_putstr(temp->label);
            err_output("\' is not initialised.\n");
        }
        temp = temp->next;
    }
}
