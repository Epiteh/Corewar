/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** get
*/

#include "vm.h"

static bool is_valid(int ac, char **av, int i)
{
    if (ac <= 1 || i <= 0 || av == NULL || (*av) == NULL)
        return (true);
    if (av[i][0] == '-')
        return (true);
    if (i - 1 > 0 && av[i - 1][0] == '-')
        return (true);
    return (false);
}

static int get_prog_args(char **av, int i, char *find1, char *find2)
{
    if (i <= 0)
        return (-1);
    if ((i - 2) > 0 && my_strcmp(av[i - 2], find1) == 0
        && my_isdigit(av[i - 1][0]))
        return (my_getnbr(av[i - 1]));
    else if ((i - 4) > 0 && my_strcmp(av[i - 2], find2) == 0
        && my_isdigit(av[i - 3][0]) && my_strcmp(av[i - 4], find1) == 0)
        return (my_getnbr(av[i - 3]));
    return (-1);
}

void get_progs(prog_t **progs, int ac, char **av)
{
    prog_t *tmp = NULL;
    int load_adr = -1;
    int id = -1;

    for (int i = 0; i < ac; i++) {
        if (is_valid(ac, av, i))
            continue;
        id = get_prog_args(av, i, "-n", "-a");
        load_adr = get_prog_args(av, i, "-a", "-n");
        create_prog(&tmp, av[i], id, load_adr);
        add_prog(progs, tmp);
    }
}
