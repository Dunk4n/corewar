/*
** EPITECH PROJECT, 2019
** src/not
** File description:
** code on paper!
*/

#include "corwar.h"

void    not(corewar_t *core, prog_t *prog)
{
    int     tab[8] = {0};

    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    if ((tab[4] == 1 && (tab[0] < 0 || tab[0] >= REG_NUMBER)) ||
tab[1] < 0 || tab[1] >= REG_NUMBER)
        return ;
    prog->carry = 0;
    prog->reg[tab[1] % REG_NUMBER] = ~get_value_arg(core, prog, tab[0], tab[4]);
    if (!prog->reg[tab[1] % REG_NUMBER])
        prog->carry = 1;
}
