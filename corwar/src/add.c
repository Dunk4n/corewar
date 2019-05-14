/*
** EPITECH PROJECT, 2019
** src/add
** File description:
** :wq
*/

#include "corwar.h"

void    add(corewar_t *core, prog_t *prog)
{
    int     tab[8] = {0};

    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    if ((tab[0] < 0 && tab[0] >= REG_NUMBER) || (tab[1] < 0 && tab[1] >=
REG_NUMBER) || (tab[2] < 0 && tab[2] >= REG_NUMBER)) {
        prog->carry = 0;
        return ;
    }
    prog->carry = 1;
    prog->reg[tab[2] % REG_NUMBER] = prog->reg[tab[0] % REG_NUMBER] +
prog->reg[tab[1] % REG_NUMBER];
    prog->carry = !prog->carry;
}
