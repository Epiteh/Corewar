/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** my_memcpy
*/

#include "../include/my.h"
#include <stddef.h>

void *my_memcpy(void* dest, const void* src, size_t nbr_bytes)
{
    char *tmp_dest = (char *) dest;
    const char *tmp_src = (const char *) src;

    for (size_t i = 0; i < nbr_bytes; i++) {
        tmp_dest[i] = tmp_src[i];
    }
    return (dest);
}
