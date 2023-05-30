/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** separator.c
*/
#include "asm.h"

static int get_line_arg(char *line)
{
    char *instructions[] = {"live", "ld", "st", "add", "sub", "and", "or",
        "xor", "zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff",
        NULL};
    char sep[] = {SEPARATOR_CHAR, ' ', '\t', '\0'};
    char *str = my_strdup(line);
    char *first = my_strtok(str, sep);
    char *second = my_strtok(NULL, sep);

    if (first == NULL || second == NULL)
        return (-1);
    for (int j = 0; instructions[j] != NULL; j++) {
        if (my_strcmp(first, instructions[j]) == 0 ||
            my_strcmp(second, instructions[j]) == 0) {
            return (op_tab[j].nbr_args);
        }
    }
    return (-1);
}

void check_separator(char *line)
{
    int line_nbr = get_line_arg(my_strdup(line));
    int separator_nbr = 0;

    if (line_nbr == -1)
        return;
    for (unsigned int i = 0; line[i] != '\0' ; i++)
        if (line[i] == SEPARATOR_CHAR)
            separator_nbr ++;
    if ((line_nbr - 1) != separator_nbr)
        err_output("Invalid separator.\n");
}
