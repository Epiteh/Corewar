/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** count
*/

#include "asm.h"

int count_element(char *buffer, char separator)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == separator)
            count += 1;
    }
    return (count);
}
