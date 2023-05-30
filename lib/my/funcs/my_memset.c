/*
** EPITECH PROJECT, 2023
** Base-project-for-C
** File description:
** my_memset
*/

#include "../include/my.h"
void *my_memset(void *ptr, int count, int size)
{
    char *byte = ptr;

    for (int i = 0; i < size; i++)
        byte[i] = count;
    return (byte);
}
