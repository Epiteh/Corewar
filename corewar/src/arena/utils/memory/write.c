/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** write_int
*/

#include "vm.h"

void write_memory_int(int *memory, int addr, int value)
{
    memory[get_memory_adress(addr)] = (value >> 24) & 255;
    memory[get_memory_adress(addr + 1)] = (value >> 16) & 255;
    memory[get_memory_adress(addr + 2)] = (value >> 8) & 255;
    memory[get_memory_adress(addr + 3)] = value & 255;
}
