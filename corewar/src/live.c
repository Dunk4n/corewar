/*
** EPITECH PROJECT, 2019
** src/live
** File description:
** C-x C-c
*/

#include "corwar.h"

void    live(corewar_t *core, prog_t *prog)
{
    int tab[8] = {0};

    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    if (core->prog[tab[0] % core->nb_prog].live != -1)
        core->prog[tab[0] % core->nb_prog].live = 1;
    my_printf("The player %d(%s) is alive\n", core->prog[tab[0] %
core->nb_prog].nb + 1, core->prog[tab[0] % core->nb_prog].name);
    core->nb_live++;
}
