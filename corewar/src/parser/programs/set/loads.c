/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** set
*/

#include "vm.h"

static bool in_error(prog_t *tmp, int adr)
{
    int lim = (tmp->load_adress + tmp->size);
    int lim2 = (adr + tmp->size);

    for (int i = tmp->load_adress; i < lim; i++) {
        if (i >= adr && i <= lim2)
            return (false);
    }
    return (true);
}

static bool is_used(vm_t *corewar, prog_t *tmp, int ld_ad, int s_id)
{
    prog_t *tmp2 = corewar->prog;

    for (; tmp2; tmp2 = tmp2->next) {
        if (tmp2->load_adress == -1 || (s_id != INT16_MIN && tmp2->id == s_id))
            continue;
        if (!in_error(tmp, ld_ad))
            return (false);
    }
    return (true);
}

static void set_uprogs(vm_t *corewar, int dist)
{
    prog_t *tmp = corewar->prog;
    int ld_ad = 0;

    for (; tmp; tmp = tmp->next) {
        if (tmp->load_adress != -1)
            continue;
        while (!is_used(corewar, tmp, ld_ad, INT16_MIN) && ld_ad < MEM_SIZE)
            ld_ad += 1;
        if (ld_ad != 0)
            ld_ad += (dist - tmp->size);
        if (ld_ad >= MEM_SIZE)
            err_output("Error : unexpected wrong load adresses init.\n");
        set_mem(corewar, tmp, ld_ad);
        ld_ad += tmp->size;
    }
}

static void set_sprogs(vm_t *corewar)
{
    prog_t *tmp = corewar->prog;

    for (; tmp; tmp = tmp->next) {
        if (tmp->load_adress == -1)
            continue;
        if (!is_used(corewar, tmp, tmp->load_adress, tmp->id))
            err_output("Error : load adresses are colliding.\n");
        set_mem(corewar, tmp, tmp->load_adress);
    }
}

void set_loads(vm_t *corewar)
{
    int prog_nbr = corewar->prog_nbr;
    int dist = ((MEM_SIZE - get_fight_size(corewar->prog)) / prog_nbr);

    set_sprogs(corewar);
    set_uprogs(corewar, dist);
}
