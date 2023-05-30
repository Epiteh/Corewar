/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** valid_code_byte
*/

#include "asm.h"

const char *coding_byte[] = {"ld", "st", "add", "sub", "and", "or", "xor",
    "ldi", "sti", "lld", "lldi", "aff", NULL};

bool valid_code_byte(char *str)
{
    if (!str)
        return (false);
    for (int i = 0; coding_byte[i]; i++)
        if (my_strcmp(str, coding_byte[i]) == 0)
            return (true);
    return (false);
}
