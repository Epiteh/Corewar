/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** write
*/

#include "asm.h"

const char *opt[] = {"live", "ld", "st", "add", "sub", "and", "or", "xor",
    "zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff", NULL};

static void find_instruction(inst_t *inst, FILE *fd)
{
    inst_t *tmp = inst;
    int hex_code = 0;
    int byte_code = 0;

    for (int i = 0; opt[i] && tmp->str; i++) {
        if (my_strcmp(opt[i], tmp->str) == 0 && !tmp->is_label) {
            hex_code = i + 1;
            put_big_endian(&hex_code, 1, fd);
        }
        if (my_strcmp(opt[i], tmp->str) == 0
            && valid_code_byte(tmp->str)
                && !tmp->is_label) {
            byte_code = get_byte_code(tmp->args);
            put_big_endian(&byte_code, 1, fd);
        }
    }
}

void write_instruction(inst_t *inst, FILE *fd)
{
    inst_t *tmp = inst;
    find_instruction(tmp, fd);
}
