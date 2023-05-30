/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** browse.c
*/

#include "asm.h"

void browse_label_list(label_list_t *list, char *element, bool is_init)
{
    node_label_t *tmp;
    char sep[4] = {LABEL_CHAR, DIRECT_CHAR, SEPARATOR_CHAR, '\0'};

    element = my_strtok(my_strdup(element), sep);
    if (list->length == 0) {
        add_label_var(list, element);
        list->begin->is_init = is_init;
        return;
    }
    tmp = list->begin;
    while (tmp != NULL) {
        if (my_strcmp(tmp->label, element) == 0) {
            tmp->is_init = is_init ? true : tmp->is_init;
            return;
        }
        tmp = tmp->next;
    }
    add_label_var(list, element);
}
