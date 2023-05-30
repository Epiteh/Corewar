/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** ceo
*/

#include "asm.h"

int parse_file(char *filepath)
{
    char *cor_file = NULL;
    header_t *head = my_calloc(1, sizeof(header_t));
    inst_t *inst = NULL;

    check_format(filepath);
    inst = open_file(filepath, head, inst);
    cor_file = output_cor(filepath);
    write_cor(cor_file, head, inst);
    return (0);
}
