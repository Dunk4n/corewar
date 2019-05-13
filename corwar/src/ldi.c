/*
** EPITECH PROJECT, 2019
** src/ldi
** File description:
** no, real programmers use cat
*/

#include "corwar.h"

void    ldi(corewar_t *core, prog_t *prog)
{
    int     tab[8] = {0};
    int     tmp = prog->pc;
    int     s;
    data_t  data;

    tmp = (prog->pc + get_arg(core->map, prog->pc, tab)) % MEM_SIZE;
    prog->carry = !prog->carry;
    s = get_value_arg(core, prog, tab[0], tab[4]) +
get_value_arg(core, prog, tab[1], tab[5]);
    data.data[3] = core->map[((prog->pc + s) % IDX_MOD) % MEM_SIZE];
    data.data[2] = core->map[((prog->pc + s + 1) % IDX_MOD) % MEM_SIZE];
    data.data[1] = core->map[((prog->pc + s + 2) % IDX_MOD) % MEM_SIZE];
    data.data[0] = core->map[((prog->pc + s + 3) % IDX_MOD) % MEM_SIZE];
    prog->reg[tab[2] % REG_NUMBER] = data.nb;
    prog->pc += tmp;
}
