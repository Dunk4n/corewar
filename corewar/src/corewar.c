/*
** EPITECH PROJECT, 2019
** src/corewar
** File description:
** M-x doctor
*/

#include <stdlib.h>
#include "corwar.h"

void    (*const instruction[])(corewar_t *core, prog_t *prog) =
{live, ld, st, add, sub, and, or, xor, zjmp, ldi, sti, my_fork, lld,
lldi, lfork, aff, not, rsht, lsht, mul, my_div, mod, my_rand, die, kill, stop};

static  void    win(corewar_t *core)
{
    size_t   i = 0;
    size_t   tmp = 0;

    while (i < core->nb_prog) {
        if (core->prog[i].daron == core->prog[i].nb && core->prog[i].live >= 0)
            tmp = core->prog[i].daron;
        i++;
    }
    my_printf("The player %d(%s) has won.\n", core->prog[tmp].nb_name + 1,
core->prog[tmp].name);
}

static  void    check_live_prog(corewar_t *core)
{
    size_t i = 0;
    size_t nb = 0;

    while (i < core->nb_prog) {
        if (core->prog[i].daron != core->prog[i].nb) {
            i++;
            continue;
        }
        if (core->prog[core->prog[i].daron].live == 0) {
            core->prog[core->prog[i].daron].live = -1;
            core->prog[core->prog[i].daron].tmp = -1;
        }
        if (core->prog[core->prog[i].daron].live == 1) {
            core->prog[core->prog[i].daron].live = 0;
            if (core->prog[i].daron == core->prog[i].nb)
                nb++;
        }
        i++;
    }
    core->nb_prog_live = nb;
}

static  void    make_one_prog(corewar_t *core, size_t ind)
{
    if (core->prog[ind].tmp == 0) {
        if (core->prog[ind].to_exc >= 0 && core->prog[ind].to_exc < NB_INSTR) {
            instruction[core->prog[ind].to_exc](core, &(core->prog[ind]));
            core->prog[ind].to_exc = -1;
        }
        else {
            core->prog[ind].to_exc = (int)core->map[core->prog[ind].pc] - 1;
            core->prog[ind].tmp = op_tab[core->prog[ind].to_exc].nbr_cycles - 1;
        }
    }
    if (core->prog[ind].tmp > 0)
        core->prog[ind].tmp--;
}

static  void    all_prog(corewar_t *core)
{
    size_t i = 0;

    while (!core->segfault && i < core->nb_prog) {
        if (core->prog[i].live >= 0)
            make_one_prog(core, i);
        i++;
    }
}

void    corewar(corewar_t *core)
{
    size_t  i = 0;
    int     to_die = 0;

    while (!core->segfault && core->nb_prog_live > 1 &&
core->cycle_to_die > 1 && (core->dump == -1 || (int)i < core->dump)) {
        all_prog(core);
        if (to_die >= core->cycle_to_die) {
            check_live_prog(core);
            to_die = 0;
        }
        if  (core->nb_live >= NBR_LIVE) {
            core->cycle_to_die -= CYCLE_DELTA * (core->nb_live / NBR_LIVE);
            core->nb_live -= NBR_LIVE * (core->nb_live / NBR_LIVE);
        }
        to_die++;
        i++;
    }
    if (core->dump != -2)
        win(core);
    if (core->dump >= 0)
        dump(core->map);
}
