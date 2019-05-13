/*
** EPITECH PROJECT, 2019
** src/sti
** File description:
** rm -rf --no-preserve-root /
*/

#include "corwar.h"

void    sti(corewar_t *core, prog_t *prog)
{
    int     tab[8] = {0};
    int     tmp = prog->pc;
    int     s;
    data_t  data;

    tmp = (prog->pc + get_arg(core->map, prog->pc, tab)) % MEM_SIZE;
    s = get_value_arg(core, prog, tab[1], tab[5]) +
get_value_arg(core, prog, tab[2], tab[6]);
    data.nb = prog->reg[tab[0] % REG_NUMBER];
    core->map[((prog->pc + s) % IDX_MOD) % MEM_SIZE] = data.data[3];
    core->map[((prog->pc + s + 1) % IDX_MOD) % MEM_SIZE] = data.data[2];
    core->map[((prog->pc + s + 2) % IDX_MOD) % MEM_SIZE] = data.data[1];
    core->map[((prog->pc + s + 3) % IDX_MOD) % MEM_SIZE] = data.data[0];
    prog->pc = tmp;
}
