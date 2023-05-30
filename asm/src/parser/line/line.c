/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** line
*/

#include "asm.h"

void parse_line(label_list_t *list, char *line, inst_t **inst,
    header_t *head)
{
    static int idx_name = 0;
    if (line[0] == '\0' || line[0] == '\n')
        return;
    if (is_header(line)) {
        idx_name += 1;
        fill_header(line, head, idx_name);
        return;
    }
    if (is_instruction(line)) {
        idx_name += 1;
        add_instruction(list, inst, line, list->idx);
        return;
    }
    char *element = my_strtok(my_strdup(line), " \t\0");
    if (element[my_strlen(element) - 1] == LABEL_CHAR) {
        idx_name += 1;
        add_instruction(list, inst, line, list->idx + 1);
        return;
    }
    err_output("Invalid line.\n");
}
