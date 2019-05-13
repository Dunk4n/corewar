/*
** EPITECH PROJECT, 2019
** src/fork
** File description:
** vim > emacs
*/

#include <stdlib.h>
#include "corwar.h"

void    lfork(corewar_t *core, prog_t *prog)
{
    int     tab[8] = {0};
    int     tmp = prog->pc;

    tmp = (prog->pc + get_arg(core->map, prog->pc, tab)) % MEM_SIZE;
    core->nb_prog++;
    core->prog = realloc(core->prog, core->nb_prog);
    core->prog[core->nb_prog - 1].nb = get_nb(core);
    core->prog[core->nb_prog - 1].pc = (prog->pc + tab[0]) % MEM_SIZE;
    copy_prog(core->map, &(core->prog[core->nb_prog - 1]), prog);
    prog->pc = tmp;
}
