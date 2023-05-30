/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** structs
*/

#include "vm.h"

static int get_prog_nbr(vm_t *corewar)
{
    prog_t *tmp = corewar->prog;
    int i = 0;

    for (; tmp; i++, tmp = tmp->next)
        ;
    if (i <= 1)
        err_output("Error: Not enough champions, 2 minimum\n");
    return (i);
}

static bool my_str_is_number(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i += 1) {
        if (!my_isdigit(str[i]) && str[i] != '-') {
            str[i] = '\0';
            return (false);
        }
    }
    return (true);
}

static void handle_dump_error(char **av, int i)
{
    if (!av[i + 1]) {
        display_dump_error();
    }
    if (!my_str_is_number(av[i + 1]))
        display_dump_error();
}

static int get_dump(int ac, char **av)
{
    for (int i = 0; i < ac; i++) {
        if ((my_strcmp(av[i], "-dump") == 0 || my_strcmp(av[i], "-d") == 0)) {
            handle_dump_error(av, i);
            return (my_getnbr(av[i + 1]));
        }
    }
    return (-42);
}

void init_structs(vm_t *corewar, int ac, char **av)
{
    int converted_dump = get_dump(ac, av);

    if (converted_dump <= 0 && converted_dump != -42)
        display_dump_error();
    my_memset(corewar->memory, 0, MEM_SIZE);
    corewar->cycle_max = CYCLE_TO_DIE;
    corewar->cycle_dump = converted_dump;
    corewar->cycle = 0;
    corewar->prog_nbr = 0;
    corewar->live_call = -1;
    corewar->winner.id = -1;
    corewar->prog = NULL;
    get_progs(&corewar->prog, ac, av);
    set_ids(corewar->prog);
    corewar->prog_nbr = get_prog_nbr(corewar);
    set_loads(corewar);
}
