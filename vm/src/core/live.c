/*
** EPITECH PROJECT, 2019
** src/live
** File description:
** C-x C-c
*/

#include "corwar.h"

void    live(corewar_t *core, prog_t *prog, menu_t *menu)
{
    int tab[8] = {0};

    (void)menu;
    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    menu->color[prog->pc % MEM_SIZE] = colorrf2[(prog->daron + 1) % 5];
    if (tab[0] < 0 || tab[0] >= (int)core->nb_prog)
        return ;
    if (core->prog[core->prog[tab[0] % core->nb_prog].daron %
core->nb_prog].live == -1)
        return ;
    core->prog[core->prog[tab[0] % core->nb_prog].daron %
core->nb_prog].live = 1;
    my_printf("The player %d(%s) is alive\n", core->prog[tab[0] %
core->nb_prog].daron + 1, core->prog[core->prog[tab[0] % core->nb_prog].daron %
core->nb_prog].name);
    menu->color[prog->pc % MEM_SIZE] = colorrf2[(prog->daron + 1) % 5];
    core->nb_live++;
}
