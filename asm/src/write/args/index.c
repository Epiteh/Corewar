/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** index
*/

#include "asm.h"

static const char *inst_idx[] = {"ldi", "lldi", "sti", "zjmp",
    "fork", "lfork", NULL};
static const int args_idx[6][2] = {{0, 1}, {0, 1}, {1, 2}, {0, -42},
    {0, -42}, {0, -42}};

static void change_inst_size(args_t *tmp_arg, const int idx[2])
{
    args_t *args = tmp_arg;

    for (int i = 0; i < idx[0]; i++)
        args = args->next;
    if (args->size != T_REG)
        args->size = IND_SIZE;
    if (idx[1] == -42)
        return;
    args = tmp_arg;
    for (int i = 0; i < idx[1]; i++)
        tmp_arg = tmp_arg->next;
    if (idx[1] != -42 && tmp_arg->size != T_REG)
        tmp_arg->size = IND_SIZE;
    else
        return;
}

static void change_args_size(inst_t *tmp)
{
    for (int i = 0; inst_idx[i]; i++) {
        if (my_strcmp(inst_idx[i], tmp->str) == 0 && !tmp->is_label) {
            change_inst_size(tmp->args, args_idx[i]);
        }
    }
}

void find_index(inst_t *inst)
{
    inst_t *tmp = inst;

    while (tmp) {
        change_args_size(tmp);
        tmp = tmp->next;
    }
}
