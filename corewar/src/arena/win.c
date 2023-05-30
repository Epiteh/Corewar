/*
** EPITECH PROJECT, 2023
** Corewar_-_28_mai
** File description:
** win
*/

#include "vm.h"

void champion_win(vm_t *vm)
{
    if (vm->winner.id == -1) {
        my_putstr("No winner for this game.\n");
        return;
    }
    my_putstr("The player ");
    my_put_nbr(vm->winner.id);
    my_putstr("(");
    my_putstr(vm->winner.name);
    my_putstr(")has won.\n");
}
