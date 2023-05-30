/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** main
*/

#include "asm.h"

static int help(void)
{
    my_putstr("USAGE\n"
            "./asm file_name[.s]\n"
            "DESCRIPTION\n"
            "file_name file in assembly language to be converted into"
            "file_name.cor, an\nexecutable in the Virtual Machine.");
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        err_output("Invalid number of arguments.\n");
    } else if (my_strcmp(av[1], "-h") == 0) {
        return (help());
    } else {
        parse_file(av[1]);
    }
    return (0);
}
