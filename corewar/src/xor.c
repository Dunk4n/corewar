/*
** EPITECH PROJECT, 2019
** src/xor
** File description:
** M-x doctor
*/

#include "corwar.h"

void    xor(corewar_t *core, prog_t *prog)
{
    int     tab[8] = {0};

    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    if ((tab[4] == 1 && tab[0] < 0 && tab[0] >= REG_NUMBER) || (tab[5] == 1 &&
tab[1] < 0 && tab[1] >= REG_NUMBER) || (tab[2] < 0 && tab[2] >= REG_NUMBER))
        return ;
    prog->carry = 0;
    prog->reg[tab[2] % REG_NUMBER] = get_value_arg(core, prog, tab[0], tab[4]) ^
get_value_arg(core, prog, tab[1], tab[5]);
    if (!prog->reg[tab[2] % REG_NUMBER])
        prog->carry = 1;
}
