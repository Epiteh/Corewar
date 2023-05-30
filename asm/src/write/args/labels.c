/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** labels
*/

#include "asm.h"

const char *instruction[] = {"live", "ld", "st", "add", "sub", "and", "or",
    "xor", "zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff", NULL};

static int find_label_line(inst_t *inst)
{
    int num = 0;
    inst_t *tmp_inst = inst;
    args_t *tmp_arg = inst->args;

    for (int i = 0; instruction[i] && tmp_inst->str; i++)
        if ((my_strcmp(tmp_inst->str, instruction[i]) == 0)
            && !tmp_inst->is_label)
                num += 1;
    if (valid_code_byte(tmp_inst->str))
        num += 1;
    while (tmp_arg) {
            num += tmp_arg->size;
            if (valid_code_byte(tmp_arg->str))
                num += 1;
            tmp_arg = tmp_arg->next;
    }
    return (num);
}

static int find_label_pos(char *str, inst_t *ihead)
{
    int num = 0;
    inst_t *tmp_inst = ihead;

    if (str[0] == DIRECT_CHAR)
        str = &str[2];
    if (str[0] == LABEL_CHAR)
        str = &str[1];
    while ((tmp_inst->str && my_strcmp(tmp_inst->str, str) != 0)
        || (!tmp_inst->is_label)) {
        num += find_label_line(tmp_inst);
        tmp_inst = tmp_inst->next;
    }
    return (num);
}

static int find_label_adress(int line_nb, inst_t *ihead)
{
    int num = 0;
    inst_t *tmp_inst = ihead;

    while (tmp_inst->idx != line_nb) {
        num += find_label_line(tmp_inst);
        tmp_inst = tmp_inst->next;
    }
    return (num);
}

int find_label(char *str, int line_nb, inst_t *ihead)
{
    int label_pos = 0;
    int label_adress = 0;

    label_pos = find_label_pos(str, ihead);
    label_adress = find_label_adress(line_nb, ihead);
    return (label_pos - label_adress);
}
