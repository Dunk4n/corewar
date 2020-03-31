/*
** EPITECH PROJECT, 2019
** src/corewar
** File description:
** M-x doctor
*/

#include <stdlib.h>
#include "corwar.h"

void    (*const instruction[])(corewar_t *core, prog_t *prog, menu_t *menu) =
{live, ld, st, add, sub, and, or, xor, zjmp, ldi, sti, my_fork, lld,
lldi, lfork, aff, not, rsht, lsht, mul, my_div, mod, my_rand, die, kill};

int     win(corewar_t *core)
{
    size_t   i = 0;
    size_t   tmp = 0;

    while (i < core->nb_prog) {
        if (core->prog[i].daron == core->prog[i].nb && core->prog[i].live >= 0)
            tmp = core->prog[i].daron;
        i++;
    }
    my_printf("The player %d(%s) has won.\n", tmp + 1, core->prog[tmp].name);
    return (tmp);
}

static  void    check_live_prog(corewar_t *core)
{
    size_t i = 0;
    size_t nb = 0;

    while (i < 4 && i < core->nb_prog) {
        if (core->prog[i].daron != core->prog[i].nb) {
            i++;
            continue ;
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

static  void    make_one_prog(corewar_t *core, size_t ind, menu_t *menu)
{
    if (core->prog[ind].tmp == 0) {
        if (core->prog[ind].to_exc >= 0 && core->prog[ind].to_exc < NB_INSTR) {
            instruction[core->prog[ind].to_exc](core, &(core->prog[ind]), menu);
            core->prog[ind].to_exc = -1;
            menu->stop = 1;
        }
        else {
            core->prog[ind].to_exc = (int)core->map[core->prog[ind].pc] - 1;
            core->prog[ind].tmp = op_tab[core->prog[ind].to_exc].nbr_cycles - 1;
        }
    }
    if (core->prog[ind].tmp > 0)
        core->prog[ind].tmp--;
}

static  void    all_prog(corewar_t *core, menu_t *menu)
{
    size_t i = 0;

    while (!core->segfault && i < core->nb_prog) {
        if (core->prog[i].live >= 0)
            make_one_prog(core, i, menu);
        i++;
    }
}

void    corewar(corewar_t *core, menu_t *menu)
{
    size_t  i = 0;
    int     to_die = 0;

    while (sfRenderWindow_isOpen(menu->window) &&
!core->segfault && core->nb_prog_live > 1 && core->cycle_to_die > 1) {
        all_prog(core, menu);
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
        if (!display_all_corewar(core, menu, i, to_die))
            return ;
    }
    display_win(core, menu, i);
}

void    corewar_tour(corewar_t *core, menu_t *menu)
{
    size_t  i = 0;
    int     to_die = 0;

    while (sfRenderWindow_isOpen(menu->window) &&
!core->segfault && core->nb_prog_live > 1 && core->cycle_to_die > 1) {
        if (!menu->stop) {
            all_prog(core, menu);
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
        if (menu->stop) {
            if (!display_all_corewar_tour(core, menu, i, to_die))
                return ;
        }
    }
    display_win(core, menu, i);
}
