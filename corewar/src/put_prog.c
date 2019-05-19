/*
** EPITECH PROJECT, 2019
** src/put_prog
** File description:
** xkcd.com/378
*/

#include <stdlib.h>
#include "corwar.h"

int    put_prog(corewar_t *core, char **instr)
{
    size_t i = 0;
    size_t j;

    while (instr[i]) {
        j = 0;
        if (core->adress[i] != -1)
            core->prog[i].pc = core->adress[i];
        while (j < core->prog[i].size) {
            if (core->who[(core->prog[i].pc + j) % MEM_SIZE] != -1) {
                write(2, "overlap detected\n", 17);
                return (0);
            }
            core->map[(core->prog[i].pc + j) % MEM_SIZE] = instr[i][j];
            core->who[(core->prog[i].pc + j) % MEM_SIZE] = core->prog[i].nb;
            j++;
        }
        i++;
    }
    free(instr);
    return (1);
}
