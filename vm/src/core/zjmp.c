/*
** EPITECH PROJECT, 2019
** src/zjmp
** File description:
** echo $?
*/

#include "corwar.h"

void    zjmp(corewar_t *core, prog_t *prog, menu_t *menu)
{
    int     tab[8] = {0};
    int     tmp = prog->pc;

    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    if (!prog->carry) {
        menu->color[prog->pc % MEM_SIZE] = colorrf2[(prog->daron + 1) % 5];
        return ;
    }
    prog->pc = MODU(tmp + tab[0] % IDX_MOD);
    menu->color[prog->pc % MEM_SIZE] = colorrf2[(prog->daron + 1) % 5];
}
