/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** pcounter
*/

#include "vm.h"

int get_memory_adress(int prog_address)
{
    int returned_value = 0;

    while (prog_address >= MEM_SIZE)
        prog_address -= MEM_SIZE;
    while (prog_address < 0)
        prog_address += MEM_SIZE;
    returned_value = prog_address % MEM_SIZE;
    return (returned_value);
}
