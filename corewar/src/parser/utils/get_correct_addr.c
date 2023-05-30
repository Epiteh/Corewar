/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** get_correct_addr.c
*/

#include "vm.h"

int get_correct_addr(int addr)
{
    while (addr >= MEM_SIZE)
        addr -= MEM_SIZE;
    while (addr < 0)
        addr += MEM_SIZE;
    return (addr);
}
