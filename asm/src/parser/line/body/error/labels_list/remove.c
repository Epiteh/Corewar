/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** remove.c
*/

#include "asm.h"
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

void clear_label_list(label_list_t *list)
{
    node_label_t *tmp = list->begin;
    node_label_t *tmp_next;

    if (list->length == 0) {
        return;
    }
    while (tmp != NULL) {
        tmp_next = tmp->next;
        free(tmp->label);
        free(tmp);
        tmp = tmp_next;
    }
    list->begin = NULL;
    list->end = NULL;
    list->length = 0;
    return;
}
