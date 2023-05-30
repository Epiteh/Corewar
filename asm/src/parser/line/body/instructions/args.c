/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** args
*/

#include "asm.h"

static int get_arg_type(char *arg)
{
    if (arg[0] == 'r')
        return (T_REG);
    if (arg[0] == DIRECT_CHAR)
        return (T_DIR);
    return (T_IND);
}

static int get_arg_size(char *arg)
{
    if (arg[0] == 'r')
        return (1);
    if (arg[0] == DIRECT_CHAR)
        return (4);
    return (2);
}

static void add_arg(char *arg, args_t **arg_l, args_t **head)
{
    args_t *new = my_calloc(1, sizeof(args_t));

    if (!new)
        err_output("Malloc failed.\n");
    new->str = my_strdup(arg);
    new->type = get_arg_type(arg);
    new->size = get_arg_size(arg);
    new->next = NULL;
    if (!(*arg_l)) {
        (*arg_l) = new;
        (*head) = (*arg_l);
        return;
    }
    if ((*arg_l)->next != NULL) {
        while ((*arg_l)->next) {
            (*arg_l) = (*arg_l)->next;
        }
    }
    (*arg_l)->next = my_calloc(1, sizeof(args_t));
    (*arg_l)->next = new;
}

bool no_label(char *arg)
{
    if (arg[my_strlen(arg) - 1] == LABEL_CHAR)
        return (true);
    return (false);
}

args_t *get_args(char *line)
{
    args_t *arg_l = NULL;
    args_t *head = NULL;
    char *arg = my_strdup(line);
    arg = my_strtok(arg, ", \t");

    while (arg) {
        if (get_instruction(arg) == NULL && !no_label(arg)) {
            add_arg(arg, &arg_l, &head);
        }
        arg = my_strtok(NULL, ", \t");
    }
    return (head);
}
