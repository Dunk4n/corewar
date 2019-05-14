/*
** EPITECH PROJECT, 2019
** src/lldi
** File description:
** https://github.com/x4m3/vim-epitech
*/

#include "corwar.h"

void    lldi(corewar_t *core, prog_t *prog)
{
    int     tab[8] = {0};
    int     tmp = prog->pc;
    int     s;
    data_t  data;

    tmp = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    if ((tab[4] == 1 && tab[0] < 0 && tab[0] >= REG_NUMBER) || (tab[5] == 1 &&
tab[1] < 0 && tab[1] >= REG_NUMBER) || (tab[2] < 0 && tab[2] >= REG_NUMBER)) {
        prog->carry = 0;
        return ;
    }
    prog->carry = 1;
    s = get_value_arg_long(core, prog, tab[0], tab[4]) +
get_value_arg_long(core, prog, tab[1], tab[5]);
    data.data[3] = core->map[(prog->pc + s) % MEM_SIZE];
    data.data[2] = core->map[(prog->pc + s + 1) % MEM_SIZE];
    data.data[1] = core->map[(prog->pc + s + 2) % MEM_SIZE];
    data.data[0] = core->map[(prog->pc + s + 3) % MEM_SIZE];
    prog->reg[tab[2] % REG_NUMBER] = data.nb;
    prog->pc = tmp;
}
