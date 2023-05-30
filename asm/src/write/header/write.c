/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** write
*/

#include "asm.h"
#include <stdbool.h>

static const char *instructions[] = {"live", "ld", "st", "add", "sub", "and",
    "or", "xor", "zjmp", "ldi", "sti", "fork", "lld", "lldi",
        "lfork", "aff", NULL};

static int get_args_size(inst_t *tmp, args_t *args)
{
    int size = 0;

    for (int i = 0; instructions[i]; i++)
        if (my_strcmp(tmp->str, instructions[i]) == 0 && !tmp->is_label) {
            size += 1;
        }
    if (valid_code_byte(tmp->str)) {
        size += 1;
    }
    while (args) {
        size += args->size;
        if (valid_code_byte(args->str)) {
            size += 1;
        }
        args = args->next;
    }
    return (size);
}

static int get_prog_size(inst_t *inst)
{
    int size = 0;
    inst_t *tmp = inst;

    while (tmp) {
        size += get_args_size(tmp, tmp->args);
        tmp = tmp->next;
    }
    return (size);
}

void write_header(header_t *head, inst_t *inst, FILE *fd)
{
    head->magic = COREWAR_EXEC_MAGIC;
    reverse_int(&head->magic, sizeof(int));
    head->prog_size = get_prog_size(inst);
    reverse_int(&head->prog_size, sizeof(int));
    fwrite(head, sizeof(header_t), 1, fd);
}
