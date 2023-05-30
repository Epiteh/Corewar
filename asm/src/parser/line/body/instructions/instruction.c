/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** instruction
*/

#include "asm.h"

const hex_t hex_s[] = {{"live", 0x01}, {"ld", 0x02}, {"st", 0x03},
    {"add", 0x04}, {"sub", 0x05}, {"and", 0x06}, {"or", 0x07}, {"xor", 0x08},
    {"zjmp", 0x09}, {"ldi", 0x0a}, {"sti", 0x0b}, {"fork", 0x0c},
    {"lld", 0x0d}, {"lldi", 0x0e}, {"lfork", 0x0f}, {"aff", 0x10},
    {NULL, 0}
};

char *get_instruction(char *tmp)
{
    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (my_strncmp(tmp, op_tab[i].mnemonique,
            my_strlen(tmp)) == 0) {
            return (op_tab[i].mnemonique);
        }
    }
    return (NULL);
}

void add_label(inst_t **inst, char *line,
    unsigned int idx)
{
    inst_t *new = my_calloc(1, sizeof(inst_t));
    inst_t *tmp = *inst;
    char *label_str = my_strdup(line);

    label_str[my_strlen(label_str) - 1] = '\0';
    new->str = label_str;
    new->is_label = true;
    new->idx = idx;
    new->args = NULL;
    new->next = NULL;
    if (*inst == NULL)
        *inst = new;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
}

int fill_node(inst_t *new, char *line, unsigned int idx, inst_t **instr)
{
    char *inst = my_strtok(my_strdup(line), ", \t\n");

    if (no_label(inst)) {
        add_label(instr, inst, idx);
        inst = my_strtok(NULL, ", \t");
    }
    if (inst == NULL)
        return (1);
    new->str = my_strdup(get_instruction(inst));
    new->idx = idx;
    new->is_label = false;
    new->args = get_args(line);
    new->next = NULL;
    return (0);
}

void add_instruction(label_list_t *list, inst_t **inst, char *line,
    unsigned int idx)
{
    inst_t *new = my_calloc(1, sizeof(inst_t));
    inst_t *tmp = *inst;

    if (new == NULL)
        err_output("Memory allocation failure.\n");
    if (!check_line_validity(line, list))
        err_output("Invalid instruction.\n");
    if (fill_node(new, line, idx, inst) == 1) {
        free(new);
        return;
    }
    tmp = *inst;
    if (*inst == NULL)
        *inst = new;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
}
