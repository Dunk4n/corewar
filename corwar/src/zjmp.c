/*
** EPITECH PROJECT, 2019
** src/zjmp
** File description:
** echo $?
*/

#include "corwar.h"

void    zjmp(corewar_t *core, prog_t *prog)
{
    int     tab[8] = {0};
    int     tmp = prog->pc;

    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    if (!prog->carry)
        return ;
    prog->pc = (tmp + tab[0] % IDX_MOD) % MEM_SIZE;
}
