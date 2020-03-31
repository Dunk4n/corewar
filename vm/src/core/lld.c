/*
** EPITECH PROJECT, 2019
** src/lld
** File description:
** https://github.com/x4m3/vim-epitech
*/

#include "corwar.h"

void    lld(corewar_t *core, prog_t *prog, menu_t *menu)
{
    int     tab[8] = {0};
    int     tmp = prog->pc;
    data_t  data;

    (void)menu;
    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    menu->color[prog->pc % MEM_SIZE] = colorrf2[(prog->daron + 1) % 5];
    if ((tab[4] == 1 && tab[0] < 0 && tab[0] >= REG_NUMBER) || (tab[5] == 1 &&
tab[1] < 0 && tab[1] >= REG_NUMBER) || (tab[2] < 0 && tab[2] >= REG_NUMBER))
        return ;
    prog->carry = 0;
    if (tab[4] == 2)
        prog->reg[tab[1] % REG_NUMBER] = tab[0];
    if (tab[4] == 2 && !prog->reg[tab[1] % REG_NUMBER])
        prog->carry = 1;
    if (tab[4] != 3)
        return ;
    data.data[3] = core->map[MODU(tmp + tab[0])];
    data.data[2] = core->map[MODU(tmp + tab[0] + 1)];
    data.data[1] = core->map[MODU(tmp + tab[0] + 2)];
    data.data[0] = core->map[MODU(tmp + tab[0] + 3)];
    if (!(prog->reg[tab[1] % REG_NUMBER] = data.nb))
        prog->carry = 1;
}
