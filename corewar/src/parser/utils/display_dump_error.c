/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** display_dump_error.c
*/

#include "vm.h"

void display_dump_error(void)
{
    my_putstr("Error: dump value must be positive\n");
    exit(84);
}
