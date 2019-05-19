/*
** EPITECH PROJECT, 2019
** src/stop
** File description:
** no, real programmers use cat
*/

#include "corwar.h"

void    stop(corewar_t *core, prog_t *prog)
{
    int     tab[8] = {0};

    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    core->dump = -2;
}
