/*
** EPITECH PROJECT, 2019
** src/sti
** File description:
** rm -rf --no-preserve-root /
*/

#include "corwar.h"

void    sti(corewar_t *core, prog_t *prog, menu_t *menu)
{
    int     tab[8] = {0};
    int     tmp = prog->pc;
    int     s = 0;
    data_t  data;

    (void)menu;
    tmp = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    s = (get_value_arg(core, prog, tab[1], tab[5]) +
get_value_arg(core, prog, tab[2], tab[6])) % IDX_MOD;
    data.nb = prog->reg[tab[0] % REG_NUMBER];
    core->map[MODU(prog->pc + s)] = data.data[3];
    core->map[MODU(prog->pc + s + 1)] = data.data[2];
    core->map[MODU(prog->pc + s + 2)] = data.data[1];
    core->map[MODU(prog->pc + s + 3)] = data.data[0];
    core->who[MODU(prog->pc + s)] = prog->daron;
    core->who[MODU(prog->pc + s + 1)] = prog->daron;
    core->who[MODU(prog->pc + s + 2)] = prog->daron;
    core->who[MODU(prog->pc + s + 3)] = prog->daron;
    menu->color[MODU(prog->pc + s)] = colorrf2[(prog->daron + 1) % 5];
    menu->color[MODU(prog->pc + s + 1)] = colorrf2[(prog->daron + 1) % 5];
    menu->color[MODU(prog->pc + s + 2)] = colorrf2[(prog->daron + 1) % 5];
    menu->color[MODU(prog->pc + s + 3)] = colorrf2[(prog->daron + 1) % 5];
    prog->pc = tmp;
    menu->color[prog->pc % MEM_SIZE] = colorrf2[(prog->daron + 1) % 5];
}
