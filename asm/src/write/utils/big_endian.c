/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** put_big_endian
*/

#include "asm.h"

void put_big_endian(void *ptr, int size, FILE *output)
{
    unsigned char *buff = (unsigned char *)ptr;
    int i = size - 1;

    for (; i >= 0; i--)
        fwrite(&buff[i], 1, 1, output);
}
