/*
** EPITECH PROJECT, 2019
** src/core_war
** File description:
** segmentation fault (core dumped)
*/

#include <stdlib.h>
#include "corwar.h"

#include <stdio.h>

void    (*const instruction[16])(corewar_t *core, prog_t *prog) =
{live, ld, st, add, sub, and, or, xor, zjmp, ldi, sti, my_fork, lld,
lldi, lfork, aff};

//===============================================
size_t glob = 0;
//===============================================
//

static  void    one_prog(corewar_t *core, size_t j)
{
    if (core->prog[j].tmp == 0) {
        if (core->prog[j].to_exc >= 0 && core->prog[j].to_exc < 16) {
            printf("nb = %ld(%s), exec = %d, tour = %ld\n",
core->prog[j].nb + 1, core->prog[j].name, core->prog[j].to_exc, glob + 1);
            instruction[core->prog[j].to_exc](core, &(core->prog[j]));
            core->prog[j].tmp = 1;
            core->prog[j].to_exc = -1;
        }
        else {
            core->prog[j].to_exc = (int)core->map[core->prog[j].pc] - 1;
            core->prog[j].tmp = op_tab[core->prog[j].to_exc].nbr_cycles - 1;
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ nb = %ld(%s), exec = %d, \
ici = %d, tour = %ld\n", core->prog[j].nb + 1, core->prog[j].name,
core->prog[j].to_exc, core->prog[j].pc, glob + 1);
        }
    }
    core->prog[j].tmp--;
}

static  void    all_prog(corewar_t *core, size_t *to_die)
{
    size_t  j = 0;

    while (!core->segfault && core->nb_prog_live > 1 && j < core->nb_prog) {
        (core->prog[j].tmp >= 0) ? one_prog(core, j) : 0;
        if (core->prog[j].tmp >= 0 && *to_die >= core->cycle_to_die &&
core->prog[j].live != 1) {
            core->prog[j].tmp = -1;
            core->nb_prog_live--;
        }
        if (*to_die >= core->cycle_to_die + 1)
            core->prog[j].live = 0;
        j++;
    }
    if (*to_die >= core->cycle_to_die + 1)
        *to_die = 0;
}

static  void    win(corewar_t *core)
{
    size_t   i = 0;
    size_t   tmp = 0;

    while (i < core->nb_prog) {
        printf("%ld name = [%s], %d\n", i + 1, core->prog[i].name, core->prog[i].live);
        if (core->prog[i].live > 0)
            tmp = core->prog[i].nb;
        i++;
    }
    my_printf("The player %d(%s) has won.\n", tmp + 1, core->prog[tmp].name);
}

void    core_war(corewar_t *core)
{
    size_t  to_die = 0;
    size_t  i = 0;

    dump(core);
    while (!core->segfault && core->nb_prog_live > 1 && core->cycle_to_die > 1) {
        all_prog(core, &to_die);
        if (core->segfault)
            return ;
        if (core->nb_live == NBR_LIVE) {
            core->cycle_to_die -= CYCLE_DELTA;
            core->nb_live = 0;
        }
        to_die++;
        i++;
        glob = i;
    }
    printf("\n\ni = %ld\n", i);
    win(core);
}
