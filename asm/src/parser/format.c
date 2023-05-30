/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** format
*/

#include "asm.h"

void check_format(char *filepath)
{
    if (my_strlen(filepath) < 3)
        err_output("Wrong file format, filepath[.s] needed\n");
    for (unsigned int i = 0; filepath[i] != '\0'; i++) {
        if (filepath[i] == '.' && filepath[i + 1] == 's' &&
            filepath[i + 2] == '\0')
            return;
    }
    err_output("Wrong file format, filepath[.s] needed\n");
}
