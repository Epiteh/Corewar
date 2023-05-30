/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** byte_code
*/

#include "asm.h"

static int add_byte_code(int byte_code, int type)
{
    if (type == T_IND)
        byte_code += 3;
    else
        byte_code += type;
    return (byte_code);
}

int get_byte_code(args_t *args)
{
    int byte_code = 0;

    for (int i = 0; i < T_IND; i++) {
        byte_code = byte_code << 2;
        if (args) {
            byte_code = add_byte_code(byte_code, args->type);
            args = args->next;
        }
    }
    return (byte_code);
}
