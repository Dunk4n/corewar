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

    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab)) % MEM_SIZE;
    prog->reg[tab[2] % REG_NUMBER] = prog->reg[tab[0] % REG_NUMBER] ^
prog->reg[tab[1] % REG_NUMBER];
    prog->carry = !prog->carry;
}
