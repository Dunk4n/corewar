/*
** EPITECH PROJECT, 2019
** src/put_prog
** File description:
** xkcd.com/378
*/

#include <stdlib.h>
#include "corwar.h"

void    put_prog(corewar_t *core, char **instr)
{
    size_t i = 0;
    size_t j;

    while (instr[i]) {
        j = 0;
        while (j < core->prog[i].size) {
            core->map[(core->prog[i].pc + j + core->adress[i]) % MEM_SIZE] = instr[i][j];
            core->who[(core ->prog[i].pc + j + core->adress[i]) % MEM_SIZE] = core->prog[i].nb;
            j++;
        }
        i++;
    }
    free(instr);
}
