/*
** EPITECH PROJECT, 2019
** src/sti
** File description:
** rm -rf --no-preserve-root /
*/

#include "corwar.h"

void    sti(corewar_t *core, prog_t *prog)
{
    int     tab[8] = {0};
    int     tmp = prog->pc;
    int     s = 0;
    data_t  data;

    tmp = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    s = (get_value_arg(core, prog, tab[1], tab[5]) +
get_value_arg(core, prog, tab[2], tab[6])) % IDX_MOD;
    data.nb = prog->reg[tab[0] % REG_NUMBER];
    core->map[MODU(prog->pc + s)] = data.data[3];
    core->map[MODU(prog->pc + s + 1)] = data.data[2];
    core->map[MODU(prog->pc + s + 2)] = data.data[1];
    core->map[MODU(prog->pc + s + 3)] = data.data[0];
    core->who[MODU(prog->pc + s)] = prog->nb;
    core->who[MODU(prog->pc + s + 1)] = prog->nb;
    core->who[MODU(prog->pc + s + 2)] = prog->nb;
    core->who[MODU(prog->pc + s + 3)] = prog->nb;
    prog->pc = tmp;
}
