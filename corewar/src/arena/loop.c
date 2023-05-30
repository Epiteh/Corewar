/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-corewar-sasha.dupeyroux
** File description:
** loop
*/

#include "vm.h"

static bool live_champion(vm_t *vm)
{
    prog_t *prog = vm->prog;
    int num = 0;

    for (; prog; prog = prog->next)
        if (prog->dead == false)
            num += 1;
    if (num < 1)
        return (false);
    if ((vm->cycle_dump != -1)
        && (vm->cycle_dump < vm->cycle))
        return (false);
    return (true);
}

static void update_cycle(vm_t *vm)
{
    if (vm->live_call >= NBR_LIVE) {
        vm->cycle_max -= CYCLE_DELTA;
        while (vm->live_call >= NBR_LIVE)
            vm->live_call -= NBR_LIVE;
    }
}

static void check_champion_death(vm_t *vm)
{
    prog_t *prog = vm->prog;
    int gap = vm->cycle - prog->call_live;

    for (; prog; prog = prog->next) {
        if (gap < 0)
            gap = gap * -1;
        if ((prog->pc > prog->size)
            || (gap > vm->cycle_max))
            prog->dead = true;
    }
}

void arena_loop(vm_t *vm)
{
    prog_t *prog = vm->prog;

    for (; live_champion(vm); vm->cycle += 1) {
        sort_champion_id(&vm);
        handle_instruction(vm);
        update_cycle(vm);
        check_champion_death(vm);
    }
    champion_win(vm);
}
