/*
** EPITECH PROJECT, 2019
** src/st
** File description:
** echo $?
*/

#include "corwar.h"

void    st(corewar_t *core, prog_t *prog, menu_t *menu)
{
    int     tab[8] = {0};
    int     tmp = prog->pc;
    data_t  data;

    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    menu->color[prog->pc % MEM_SIZE] = colorrf2[(prog->daron + 1) % 5];
    if (tab[5] == 1)
        prog->reg[tab[1] % REG_NUMBER] = prog->reg[tab[0] % REG_NUMBER];
    if (tab[5] != 3)
        return ;
    data.nb = prog->reg[tab[0] % REG_NUMBER];
    tab[1] %= IDX_MOD;
    core->map[MODU(tmp + tab[1])] = data.data[3];
    core->map[MODU(tmp + tab[1] + 1)] = data.data[2];
    core->map[MODU(tmp + tab[1] + 2)] = data.data[1];
    core->map[MODU(tmp + tab[1] + 3)] = data.data[0];
    core->who[MODU(tmp + tab[1])] = prog->daron;
    core->who[MODU(tmp + tab[1] + 1)] = prog->daron;
    core->who[MODU(tmp + tab[1] + 2)] = prog->daron;
    core->who[MODU(tmp + tab[1] + 3)] = prog->daron;
    menu->color[MODU(tmp + tab[1])] = colorrf2[(prog->daron + 1) % 5];
    menu->color[MODU(tmp + tab[1] + 1)] = colorrf2[(prog->daron + 1) % 5];
    menu->color[MODU(tmp + tab[1] + 2)] = colorrf2[(prog->daron + 1) % 5];
    menu->color[MODU(tmp + tab[1] + 3)] = colorrf2[(prog->daron + 1) % 5];
}
