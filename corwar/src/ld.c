/*
** EPITECH PROJECT, 2019
** src/ld
** File description:
** don't forget to free at the end
*/

#include "corwar.h"

void    ld(corewar_t *core, prog_t *prog)
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
    data.data[0] = core->map[(tmp + tab[0]) % IDX_MOD];
    data.data[1] = core->map[(tmp + tab[0] + 1) % IDX_MOD];
    data.data[2] = core->map[(tmp + tab[0] + 2) % IDX_MOD];
    data.data[3] = core->map[(tmp + tab[0] + 3) % IDX_MOD];
    prog->reg[tab[1] % REG_NUMBER] = REVERSE_INT(data.nb);
}
