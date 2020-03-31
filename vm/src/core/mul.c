/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** mul.c
*/

#include "corwar.h"

void    mul(corewar_t *core, prog_t *prog, menu_t *menu)
{
    int     tab[8] = {0};

    (void)menu;
    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    if (tab[0] < 0 || tab[0] >= REG_NUMBER || tab[1] < 0 || tab[1] >=
REG_NUMBER || tab[2] < 0 || tab[2] >= REG_NUMBER)
        return ;
    prog->carry = 0;
    prog->reg[tab[2] % REG_NUMBER] = prog->reg[tab[0] % REG_NUMBER] *
prog->reg[tab[1] % REG_NUMBER];
    if (!prog->reg[tab[2] % REG_NUMBER])
        prog->carry = 1;
}
