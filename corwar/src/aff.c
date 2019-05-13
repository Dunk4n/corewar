/*
** EPITECH PROJECT, 2019
** src/aff
** File description:
** programmers start to count from 0
*/

#include "corwar.h"

void    aff(corewar_t *core, prog_t *prog)
{
    int     tab[8] = {0};

    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab)) % MEM_SIZE;
    my_putchar(prog->reg[tab[0] % REG_NUMBER] % 256);
}
