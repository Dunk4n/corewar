/*
** EPITECH PROJECT, 2019
** src/put_prog
** File description:
** xkcd.com/378
*/

#include <stdlib.h>
#include "corwar.h"

void    put_prog(char *map, int *who, prog_t *prog, char **instr)
{
    size_t i = 0;
    size_t j;

    while (instr[i]) {
        j = 0;
        while (j < prog[i].size) {
            map[(prog[i].pc + j) % MEM_SIZE] = instr[i][j];
            who[(prog[i].pc + j) % MEM_SIZE] = prog[i].nb;
            j++;
        }
        i++;
    }
    free(instr);
}
