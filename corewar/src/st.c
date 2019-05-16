/*
** EPITECH PROJECT, 2019
** src/st
** File description:
** echo $?
*/

#include "corwar.h"

void    st(corewar_t *core, prog_t *prog)
{
    int     tab[8] = {0};
    int     tmp = prog->pc;
    data_t  data;

    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
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
    core->who[MODU(tmp + tab[1])] = prog->nb;
    core->who[MODU(tmp + tab[1] + 1)] = prog->nb;
    core->who[MODU(tmp + tab[1] + 2)] = prog->nb;
    core->who[MODU(tmp + tab[1] + 3)] = prog->nb;
}
