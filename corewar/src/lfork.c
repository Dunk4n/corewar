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
    prog_t  tmp_prog;

    my_memcpy(&tmp_prog, prog, sizeof(prog_t));
    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    core->prog = realloc(core->prog, sizeof(prog_t) * (core->nb_prog + 1));
    if (!core->prog) {
        core->prog = NULL;
        core->segfault = 1;
        return ;
    }
    core->prog[core->nb_prog].nb = get_nb(core);
    core->nb_prog++;
    core->prog[core->nb_prog - 1].pc = (tmp + tab[0]) % MEM_SIZE;
    copy_prog(core->map, &(core->prog[core->nb_prog - 1]), &tmp_prog);
    core->nb_prog_live++;
}
