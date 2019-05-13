/*
** EPITECH PROJECT, 2019
** src/get_value_arg
** File description:
** r/ProgrammerHumor
*/

#include "corwar.h"

int     get_value_arg(corewar_t *core, prog_t *prog, int value, int type)
{
    data_t  data;

    if (type == 3)
        return (value);
    if (type == 1)
        return (prog->reg[value % REG_NUMBER]);
    if (type != 2)
        return (0);
    data.data[3] = core->map[(prog->pc + value) % IDX_MOD];
    data.data[2] = core->map[(prog->pc + value + 1) % IDX_MOD];
    data.data[1] = core->map[(prog->pc + value + 2) % IDX_MOD];
    data.data[0] = core->map[(prog->pc + value + 3) % IDX_MOD];
    return (data.nb);
}
