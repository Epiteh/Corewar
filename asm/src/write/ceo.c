/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** ceo
*/

#include "asm.h"

int write_cor(char *cor_file, header_t *head, inst_t *inst)
{
    inst_t *tmp = inst;
    inst_t *ihead = inst;
    header_t *tmp_head = head;
    FILE *fd = fopen(cor_file, "w+");
    if (!fd)
        err_output("Error : Can't open file\n");
    if (inst)
        find_index(tmp);
    if (tmp_head->prog_name[0] == '\0')
        err_output("Error : Missing name or comment\n");
    write_header(head, tmp, fd);
    if (inst) {
        while (tmp) {
            write_instruction(tmp, fd);
            write_args(tmp, tmp->args, fd, ihead);
            tmp = tmp->next;
        }
    }
    fclose(fd);
    return (0);
}
