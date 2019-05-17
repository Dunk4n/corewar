/*
** EPITECH PROJECT, 2019
** src/rand
** File description:
** r/ProgrammerHumor
*/

#include "corwar.h"

void    my_rand(corewar_t *core, prog_t *prog)
{
    static  int n = 0;
    int         tab[8] = {0};

    prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
    if (tab[0] < 0 || tab[0] >= REG_NUMBER ||
tab[1] < 0 || tab[1] >= REG_NUMBER)
        return ;
    prog->reg[tab[1] % REG_NUMBER] =
(int)((((double)prog->reg[tab[0] % REG_NUMBER] + 3.3 + n * 2.2) *
(1.7 * (n + 2)) + (double)core->map[MODU(core->cycle_to_die)]) /
((double)core->nb_prog) + (double)core->map[MODU(core->nb_live)]);
    n++;
}
