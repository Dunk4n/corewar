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

    tmp = (prog->pc + get_arg(core->map, prog->pc, tab)) % MEM_SIZE;
    prog->carry = !prog->carry;
    s = get_value_arg(core, prog, tab[0], tab[4]) +
get_value_arg(core, prog, tab[1], tab[5]);
    data.data[3] = core->map[(prog->pc + s) % MEM_SIZE];
    data.data[2] = core->map[(prog->pc + s + 1) % MEM_SIZE];
    data.data[1] = core->map[(prog->pc + s + 2) % MEM_SIZE];
    data.data[0] = core->map[(prog->pc + s + 3) % MEM_SIZE];
    prog->reg[tab[2] % REG_NUMBER] = data.nb;
    prog->pc = tmp;
}
