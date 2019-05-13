/*
** EPITECH PROJECT, 2019
** src/lld
** File description:
** https://github.com/x4m3/vim-epitech
*/

#include "corwar.h"

void    lld(corewar_t *core, prog_t *prog)
{
    int     tab[8] = {0};
    int     tmp = prog->pc;
    data_t  data;

    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab)) % MEM_SIZE;
    prog->carry = !prog->carry;
    if (tab[4] == 2)
        prog->reg[tab[1] % REG_NUMBER] = tab[0];
    if (tab[4] != 3)
        return ;
    data.data[3] = core->map[(tmp + tab[0]) % MEM_SIZE];
    data.data[2] = core->map[(tmp + tab[0] + 1) % MEM_SIZE];
    data.data[1] = core->map[(tmp + tab[0] + 2) % MEM_SIZE];
    data.data[0] = core->map[(tmp + tab[0] + 3) % MEM_SIZE];
    prog->reg[tab[1] % REG_NUMBER] = data.nb;
}
