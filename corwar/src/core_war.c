/*
** EPITECH PROJECT, 2019
** src/core_war
** File description:
** segmentation fault (core dumped)
*/

#include <stdlib.h>
#include "corwar.h"

void    (*const instruction[16])(char *map, prog_t *prog, corewar_t *core) =
{live, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
NULL, NULL, NULL};

static  void    one_prog(corewar_t *core, size_t j)
{
    if (core->prog[j].tmp == 0) {
        if (core->prog[j].to_exc >= 0 && core->prog[j].to_exc == 0)
            instruction[core->prog[j].to_exc](core->map, &(core->prog[j]),
core);
        core->prog[j].tmp = op_tab[(int)core->map[core->prog[j].pc] - 1].
nbr_cycles;
        core->prog[j].to_exc = (int)core->map[core->prog[j].pc] - 1;
    }
    core->prog[j].tmp--;
}

static  void    all_prog(corewar_t *core, size_t *to_die)
{
    size_t  j = 0;

    while (core->nb_prog_live > 1 && j < core->nb_prog) {
        (core->prog[j].tmp >= 0) ? one_prog(core, j) : 0;
        if (*to_die >= core->cycle_to_die && core->prog[j].live != 1) {
            core->prog[j].tmp = -1;
            core->nb_prog_live--;
        }
        if (*to_die >= core->cycle_to_die) {
            core->prog[j].live = 0;
            *to_die = 0;
        }
        j++;
    }
}

static  void    win(corewar_t *core)
{
    size_t   i = 0;
    size_t   tmp = 0;

    while (i < core->nb_prog) {
        if (core->prog[i].tmp >= 0)
            tmp = i;
        i++;
    }
    my_printf("The player %d(%s) has won.\n", tmp + 1, core->prog[tmp].name);
}

void    core_war(corewar_t *core)
{
    size_t  to_die = 0;
    size_t  i = 0;

    while (core->nb_prog_live > 1 && core->cycle_to_die > 1) {
        all_prog(core, &to_die);
        if (core->nb_live == NBR_LIVE) {
            core->cycle_to_die -= CYCLE_DELTA;
            core->nb_live = 0;
        }
        to_die++;
        i++;
    }
    win(core);
}
