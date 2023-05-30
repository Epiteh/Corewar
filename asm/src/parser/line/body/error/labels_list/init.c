/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** init.c
*/

#include "asm.h"

void init_label_list(label_list_t *list)
{
    list->begin = NULL;
    list->end = NULL;
    list->length = 0;
}
