/*
** EPITECH PROJECT, 2019
** src/fork
** File description:
** vim > emacs
*/

#include <stdlib.h>
#include "corwar.h"

int     get_nb(corewar_t *core)
{
    size_t i = 0;
    int tmp = -1;

    while (i < core->nb_prog) {
        if ((int)core->prog[i].nb > tmp)
            tmp = core->prog[i].nb;
        i++;
    }
    return (tmp + 1);
}

static  void    copy_prog(corewar_t *core, int *tab, prog_t *a, prog_t *b)
{
    size_t i = 1;

    a->daron = b->daron;
    a->size = b->size;
    a->start = MODU((int)b->start + tab[0] % IDX_MOD);
    a->tmp = 1;
    a->carry = b->carry;
    a->live = 0;
    a->to_exc = -1;
    my_strcpy(a->name, b->name);
    a->reg[0] = a->nb;
    while (i < REG_NUMBER)
        a->reg[i++] = 0;
}

void    my_fork(corewar_t *core, prog_t *prog)
{
    int     tab[8] = {0};
    int     ind = prog->nb;
    int     tmp = prog->pc;

    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    core->prog = realloc(core->prog, sizeof(prog_t) * (core->nb_prog + 1));
    if (!core->prog) {
        core->segfault = 1;
        return ;
    }
    core->prog[core->nb_prog].nb = get_nb(core);
    core->prog[core->nb_prog].pc = MODU(tmp + tab[0] % IDX_MOD);
    core->nb_prog++;
    copy_prog(core, tab, &(core->prog[core->nb_prog - 1]), &(core->prog[ind]));
}
