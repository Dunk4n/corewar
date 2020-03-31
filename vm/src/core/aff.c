/*
** EPITECH PROJECT, 2019
** src/aff
** File description:
** programmers start to count from 0
*/

#include "corwar.h"

void    aff(corewar_t *core, prog_t *prog, menu_t *menu)
{
    int     tab[8] = {0};

    (void)menu;
    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    menu->color[prog->pc % MEM_SIZE] = colorrf2[(prog->daron + 1) % 5];
    my_putchar(prog->reg[tab[0] % REG_NUMBER] % 256);
}
