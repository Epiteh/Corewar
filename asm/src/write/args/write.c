/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** write
*/

#include "asm.h"
#include <stdbool.h>

static void write_dir_arg(inst_t *inst[2], char *str, int size[2], FILE *fd)
{
    int num = 0;

    if (str[1] == LABEL_CHAR) {
        num = find_label(&str[2], size[1], inst[1]);
    } else
        num = my_getnbr(&str[1]);
    put_big_endian(&num, size[0], fd);

}

static void write_indir_arg(inst_t *inst[2], char *str, int size[2], FILE *fd)
{
    int num = 0;

    if (str[0] == LABEL_CHAR) {
        num = find_label(&str[1], size[1], inst[1]);
    } else
        num = my_getnbr(str);
    put_big_endian(&num, size[0], fd);
}

static int write_reg_arg(args_t **tmp_arg, int *num, FILE *fd)
{
    if ((*tmp_arg)->str[0] == 'r') {
        *num = my_getnbr(&(*tmp_arg)->str[1]);
        put_big_endian(num, (*tmp_arg)->size, fd);
        if ((*tmp_arg)->next)
            *tmp_arg = (*tmp_arg)->next;
        else
            return (1);
    }
    return (0);
}

void write_args(inst_t *inst, args_t *args, FILE *fd, inst_t *ihead)
{
    args_t *tmp_arg = args;
    inst_t *tmp_inst = inst;
    int num = 0;

    while (tmp_arg) {
    if (write_reg_arg(&tmp_arg, &num, fd) == 1)
        return;
    if (tmp_arg->str[0] == DIRECT_CHAR) {
        write_dir_arg(((inst_t*[2]){inst, ihead}), tmp_arg->str,
        ((int[2]){tmp_arg->size, tmp_inst->idx}), fd);
    } else {
        write_indir_arg(((inst_t*[2]){inst, ihead}), tmp_arg->str,
            ((int[2]){tmp_arg->size, tmp_inst->idx}), fd);
    }
        tmp_arg = tmp_arg->next;
    }
}
