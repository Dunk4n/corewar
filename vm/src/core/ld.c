/*
** EPITECH PROJECT, 2019
** src/ld
** File description:
** don't forget to free at the end
*/

#include "corwar.h"

void    ld(corewar_t *core, prog_t *prog, menu_t *menu)
{
    int     tab[8] = {0};
    int     tmp = prog->pc;
    data_t  data;

    (void)menu;
    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    menu->color[prog->pc % MEM_SIZE] = colorrf2[(prog->daron + 1) % 5];
    if (tab[1] < 0 && tab[1] >= REG_NUMBER)
        return ;
    prog->carry = 0;
    if (tab[4] == 2) {
        prog->reg[tab[1] % REG_NUMBER] = tab[0];
        if (!prog->reg[tab[1] % REG_NUMBER])
            prog->carry = 1;
    }
    if (tab[4] != 3)
        return ;
    data.data[3] = core->map[MODU(tmp + tab[0] % IDX_MOD)];
    data.data[2] = core->map[MODU(tmp + (tab[0] + 1) % IDX_MOD)];
    data.data[1] = core->map[MODU(tmp + (tab[0] + 2) % IDX_MOD)];
    data.data[0] = core->map[MODU(tmp + (tab[0] + 3) % IDX_MOD)];
    if (!(prog->reg[tab[1] % REG_NUMBER] = data.nb))
        prog->carry = 1;
}
