/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** ceo
*/

#include "asm.h"

void err_output(char *msg)
{
    my_putstr(msg);
    exit(84);
}
