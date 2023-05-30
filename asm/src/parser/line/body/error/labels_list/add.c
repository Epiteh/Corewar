/*
** EPITECH PROJECT, 2023
** 42sh - 14 mai
** File description:
** add.c
*/
#include "asm.h"

static void edit_list(label_list_t *list, node_label_t *element)
{
    element->next = NULL;
    element->prev = NULL;
    if (list->length == 0) {
        list->begin = element;
        list->end = element;
    } else {
        if (list->end) {
            list->end->next = element;
        }
        element->prev = list->end;
        list->end = element;
    }
    list->length += 1;
}

void add_label_var(label_list_t *list, char *label)
{
    node_label_t *element;

    element = my_calloc(sizeof(node_label_t), 1);
    element->label = my_strdup(label);
    element->is_init = false;
    edit_list(list, element);
}
