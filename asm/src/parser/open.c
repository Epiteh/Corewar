/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** open
*/

#include "asm.h"

inst_t *open_file(char *filepath, header_t *head, inst_t *inst)
{
    char *buffer = NULL;
    FILE *fd = fopen(filepath, "r");

    if (!fd)
        err_output("Error : File not found.\n");
    else
        inst = read_file(fd, inst, head);
    free(buffer);
    return (inst);
}
