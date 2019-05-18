/*
** EPITECH PROJECT, 2019
** src/rand
** File description:
** r/ProgrammerHumor
*/

#include <stdlib.h>
#include "corwar.h"

void    my_rand(corewar_t *core, prog_t *prog)
{
    int         tab[8] = {0};
    char        *rnd = malloc(sizeof(char));

    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    if (tab[0] < 0 || tab[0] >= REG_NUMBER ||
tab[1] < 0 || tab[1] >= REG_NUMBER)
        return ;
    prog->reg[tab[1] % REG_NUMBER] = (int)((long)rnd);
    free(rnd);
}
