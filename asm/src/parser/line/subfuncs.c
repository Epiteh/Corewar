/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** subfuncs
*/

#include "asm.h"
#include <string.h>

bool is_header(char *line)
{
    if (my_strncmp(line, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)) == 0)
        return (true);
    if (my_strncmp(line, COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING))
        == 0)
        return (true);
    return (false);
}

bool is_instruction(char *line)
{
    char *instructions[] = {"live", "ld", "st", "add", "sub", "and", "or",
    "xor", "zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff", NULL};

    for (unsigned int j = 0; instructions[j] != NULL; j++) {
        if (my_strstr(line, instructions[j]) != NULL)
            return (true);
    }
    return (false);
}
