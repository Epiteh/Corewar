/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** reverse
*/

#include "asm.h"

void *reverse_int(void *ptr, size_t ptr_size)
{
    unsigned char *p = (unsigned char *)ptr;
    size_t i = ptr_size - 1;
    unsigned char tmp = 0;

    for (size_t j = 0; j < i; j++, i--) {
        tmp = p[j];
        p[j] = p[i];
        p[i] = tmp;
    }
    return (p);
}
