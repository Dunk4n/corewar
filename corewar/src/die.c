/*
** EPITECH PROJECT, 2019
** src/die
** File description:
** https://github.com/x4m3/vim-epitech
*/

#include "corwar.h"

void    die(corewar_t *core, prog_t *prog)
{
    int     tab[8] = {0};

    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    prog->live = -1;
    prog->tmp = -1;
}
