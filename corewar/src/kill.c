/*
** EPITECH PROJECT, 2019
** src/kill
** File description:
** hello world?
*/

#include "corwar.h"

void    kill(corewar_t *core, prog_t *prog)
{
    int tab[8] = {0};

    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    if (tab[0] < 0 || tab[0] >= (int)core->nb_prog)
        return ;
    if (core->prog[core->prog[tab[0] % core->nb_prog].daron %
core->nb_prog].live == -1)
        return ;
    core->prog[core->prog[tab[0] % core->nb_prog].daron %
core->nb_prog].live = -1;
    core->prog[core->prog[tab[0] % core->nb_prog].daron %
core->nb_prog].tmp = -1;
}
