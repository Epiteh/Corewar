/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** main
*/

#include "vm.h"
#include <stdbool.h>

static int help(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        my_putstr("USAGE\n"
        "./corewar [-dump nbr_cycle] [[-n prog_number]"
        "[-a load_address] prog_name] ...\n"
        "DESCRIPTION\n"
        "-dump nbr_cycle dumps the memory after the nbr_cycle execution"
        "(if the round isn't\n"
        "already over) with the following format: 32 bytes/line\n"
        "in hexadecimal (A0BCDEFE1DD3...)\n"
        "-n prog_number sets the next program's number."
        "By default, the first free number\n"
        "in the parameter order\n"
        "-a load_address sets the next program's loading address."
        "When no address is\n"
        "specified, optimize the addresses so that the processes are as far\n"
        "away from each other as possible."
        "The addresses are MEM_SIZE modulo.\n");
        return (true);
    }
    return (false);
}

int main(int ac, char **av)
{
    if (ac == 1)
        err_output("Error: too few arguments.\n");
    if (help(ac, av))
        return (0);
    else
        return (corewar(ac, av));
    return (0);
}
