/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** utils
*/

#include "asm.h"

int find_quotes(char *buffer)
{
    unsigned int i = 0;

    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\"')
            break;
    }
    return (i);
}

static int find_end(char *buffer)
{
    unsigned int i = 0;
    unsigned int quote = 0;

    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\"')
            quote += 1;
        if (quote == 2) {
            i += 1;
            break;
        }
    }
    return (i);
}

void check_between_name(char *buffer, char *name)
{
    unsigned int i = my_strlen(name);

    for (; buffer[i] != '\"'; i++) {
        if ((buffer[i] != ' ')
            && (buffer[i] != '\t')
                && (buffer[i] != '\n'))
            err_output("Invalid comment.");
    }
}

void check_end(char *buffer)
{
    unsigned int i = find_end(buffer);

    for (; buffer[i] != '\0'; i++) {
        if ((buffer[i] != ' ')
            && (buffer[i] != '\t')
                && (buffer[i] != '\n'))
            err_output("Invalid quote(s).");
    }
}
