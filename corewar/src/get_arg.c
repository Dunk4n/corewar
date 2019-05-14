/*
** EPITECH PROJECT, 2019
** src/get_arg
** File description:
** fireplace 4k
*/

#include "corwar.h"

static  int     get_int(char *map, int pc)
{
    data_t data;

    data.data[0] = map[pc];
    data.data[1] = map[pc + 1];
    data.data[2] = map[pc + 2];
    data.data[3] = map[pc + 3];
    return (REVERSE_INT(data.nb));
}

static  int     get_short(char *map, int pc)
{
    short_t data;

    data.data[0] = map[pc];
    data.data[1] = map[pc + 1];
    return ((short)REVERSE_SHORT(data.nb));
}

static  int     get_one_param(char *map, int pc, int *tab, char *instr)
{
    if (instr[1] == 1) {
        *tab = (int)map[pc] - 1;
        return (1);
    }
    if (instr[1] == 3 ||
(instr[1] == 2 && op_tab[(int)instr[0]].dir_size == 2)) {
        *tab = get_short(map, pc);
        return (2);
    }
    if (instr[1] == 2) {
        *tab = get_int(map, pc);
        return (4);
    }
    return (0);
}

int     get_arg(char *map, int pc, int *tab)
{
    char    instr[2] = {map[pc++ % MEM_SIZE] - 1, 0};
    char    param = 0;
    size_t  i = 0;
    size_t  pool = 1;

    if (op_tab[(int)instr[0]].nbr_args > 4)
        return (0);
    if ((int)op_tab[(int)instr[0]].oct_parametre)
        param = map[pc % MEM_SIZE];
    else {
        instr[1] = (op_tab[(int)instr[0]].type[0] == 4) ? 3 :
op_tab[(int)instr[0]].type[0];
        return (get_one_param(map, pc, tab, instr));
    }
    while (i < (size_t)op_tab[(int)instr[0]].nbr_args) {
        instr[1] = (param & (3 << 2 * (3 - (i % 4)))) >> 2 * (3 - (i % 4));
        tab[i + 4] = instr[1];
        pool += get_one_param(map, pc + pool, &(tab[i]), instr);
        i++;
    }
    return (pool);
}
