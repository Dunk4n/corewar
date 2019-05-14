/*
** EPITECH PROJECT, 2019
** src/get_value_arg
** File description:
** r/ProgrammerHumor
*/

#include "corwar.h"

int     get_value_arg_long(corewar_t *core, prog_t *prog, int value, int type)
{
    data_t  data;
    short_t sh;

    if (type == 3)
        return (value);
    if (type == 1)
        return (prog->reg[value % REG_NUMBER]);
    if (type != 2)
        return (0);
    if (op_tab[(int)core->map[prog->pc % MEM_SIZE]].dir_size == 2) {
        sh.data[1] = core->map[(prog->pc + value) % MEM_SIZE];
        sh.data[0] = core->map[(prog->pc + value + 1) % MEM_SIZE];
        return (sh.nb);
    }
    data.data[3] = core->map[(prog->pc + value) % MEM_SIZE];
    data.data[2] = core->map[(prog->pc + value + 1) % MEM_SIZE];
    data.data[1] = core->map[(prog->pc + value + 2) % MEM_SIZE];
    data.data[0] = core->map[(prog->pc + value + 3) % MEM_SIZE];
    return (data.nb);
}

int     get_value_arg(corewar_t *core, prog_t *prog, int value, int type)
{
    data_t  data;
    short_t sh;

    if (type == 2)
        return (value);
    if (type == 1)
        return (prog->reg[value % REG_NUMBER]);
    if (type != 3)
        return (0);
    if (op_tab[(int)core->map[prog->pc % MEM_SIZE]].dir_size == 2) {
        sh.data[0] = core->map[(prog->pc + value % IDX_MOD) % MEM_SIZE];
        sh.data[1] = core->map[(prog->pc + (value + 1) % IDX_MOD) % MEM_SIZE];
        return (sh.nb);
    }
    data.data[3] = core->map[(prog->pc + value % IDX_MOD) % MEM_SIZE];
    data.data[2] = core->map[(prog->pc + (value + 1) % IDX_MOD) % MEM_SIZE];
    data.data[1] = core->map[(prog->pc + (value + 2) % IDX_MOD) % MEM_SIZE];
    data.data[0] = core->map[(prog->pc + (value + 3) % IDX_MOD) % MEM_SIZE];
    return (data.nb);
}
