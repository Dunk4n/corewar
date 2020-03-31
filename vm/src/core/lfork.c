/*
** EPITECH PROJECT, 2019
** src/fork
** File description:
** vim > emacs
*/

#include <stdlib.h>
#include "corwar.h"

static  void    long_copy_prog(int *tab, prog_t *a, prog_t *b)
{
    size_t i = 1;

    a->daron = b->daron;
    a->size = b->size;
    a->start = MODU((int)b->start + tab[0]);
    a->tmp = 0;
    a->carry = b->carry;
    a->live = 0;
    a->to_exc = -1;
    my_strcpy(a->name, b->name);
    a->reg[0] = a->nb;
    while (i < REG_NUMBER)
        a->reg[i++] = 0;
}

void    lfork(corewar_t *core, prog_t *prog, menu_t *menu)
{
    int     tab[8] = {0};
    int     ind = prog->nb;

    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    menu->color[prog->pc % MEM_SIZE] = colorrf2[(prog->daron + 1) % 5];
    core->prog = realloc(core->prog, sizeof(prog_t) * (core->nb_prog + 1));
    if (!core->prog) {
        core->segfault = 1;
        return ;
    }
    core->prog[core->nb_prog].nb = get_nb(core);
    core->prog[core->nb_prog].pc = MODU(core->prog[ind].pc + tab[0]);
    core->nb_prog++;
    long_copy_prog(tab, &(core->prog[core->nb_prog - 1]),
&(core->prog[ind]));
    menu->color[core->prog[core->nb_prog - 1].pc % MEM_SIZE] =
colorrf2[(core->prog[core->nb_prog - 1].daron + 1) % 5];
}
