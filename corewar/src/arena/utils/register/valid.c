/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-vm-sasha.dupeyroux
** File description:
** valid_register
*/
#include "vm.h"

int get_valid_register(int reg)
{
    if (reg < 0 || reg > REG_NUMBER - 1)
        return (15);
    return (reg);
}
