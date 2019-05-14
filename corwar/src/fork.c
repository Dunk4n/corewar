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

void    copy_prog(char *map, prog_t *a, prog_t *b)
{
    size_t i = 1;

    a->size = b->size;
    a->tmp = 0;
    a->carry = 0;
    a->live = 0;
    a->to_exc = -1;
    a->instr = b->instr;
    my_strcpy(a->name, b->name);
    a->reg[0] = a->nb;
    while (i < REG_NUMBER)
        a->reg[i++] = 0;
    i = 0;
    while (i < a->size) {
        map[a->pc + i] = a->instr[i];
        i++;
    }
}

void    my_fork(corewar_t *core, prog_t *prog)
{
    int     tab[8] = {0};
    int     tmp = prog->pc;

    tmp = (get_arg(core->map, prog->pc, tab) + 1);
    printf("%dnb == %d, %d\n", core->nb_prog, core->prog[0].nb, core->prog[1].nb);
    core->prog = realloc(core->prog, sizeof(prog_t) * (core->nb_prog + 1));
    if (!core->prog) {
        core->prog = NULL;
        core->segfault = 1;
        return ;
    }
    printf("%dbn == %d, %d\n", core->prog[0].nb, core->prog[1].nb);
    core->prog[core->nb_prog].nb = get_nb(core);
    core->nb_prog++;
    core->prog[core->nb_prog - 1].pc = (prog->pc + tab[0] % IDX_MOD) % MEM_SIZE;
    copy_prog(core->map, &(core->prog[core->nb_prog - 1]), prog);
    prog->pc = (prog->pc + tmp) % MEM_SIZE;
    core->nb_prog_live++;
}
