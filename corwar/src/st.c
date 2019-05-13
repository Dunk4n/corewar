/*
** EPITECH PROJECT, 2019
** src/st
** File description:
** echo $?
*/

#include "corwar.h"

void    st(corewar_t *core, prog_t *prog)
{
    int     tab[8] = {0};
    int     tmp = prog->pc;
    data_t  data;

    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab)) % MEM_SIZE;
    if (tab[5] == 1)
        prog->reg[tab[1] % REG_NUMBER] = prog->reg[tab[0] % REG_NUMBER];
    if (tab[5] != 3)
        return ;
    data.nb = prog->reg[tab[0] % REG_NUMBER];
    core->map[((tmp + tab[1]) % IDX_MOD) % MEM_SIZE] = data.data[3];
    core->map[((tmp + tab[1] + 1) % IDX_MOD) % MEM_SIZE] = data.data[2];
    core->map[((tmp + tab[1] + 2) % IDX_MOD) % MEM_SIZE] = data.data[1];
    core->map[((tmp + tab[1] + 3) % IDX_MOD) % MEM_SIZE] = data.data[0];
}
