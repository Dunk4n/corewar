/*
** EPITECH PROJECT, 2019
** src/live
** File description:
** C-x C-c
*/

#include "corwar.h"

void    live(char *map, prog_t *prog, corewar_t *core)
{
    prog_t *tmp = &(core->prog[(int)map[(prog->pc + 1) % MEM_SIZE]]);

    my_printf("The player %d(%s) is alive\n", tmp->nb + 1, tmp->name);
    tmp->live = 1;
    prog->pc = (prog->pc + 2) % MEM_SIZE;
    prog->tmp = op_tab[0].nbr_cycles;
}
