/*
** EPITECH PROJECT, 2019
** src/charge_all_cor
** File description:
** epitech > 42
*/

#include <unistd.h>
#include <stdlib.h>
#include "corwar.h"

static  void    free_all_cor(char **instr, prog_t *progs, size_t nb)
{
    free(progs);
    if (!instr)
        return ;
    while (nb-- > 0)
        free(instr[nb]);
    free(instr);
}

void    set_reg(prog_t *prog)
{
    size_t i = 1;

    prog->tmp = 0;
    prog->live = 0;
    prog->to_exc = -1;
    prog->carry = 0;
    prog->reg[0] = prog->nb;
    while (i < REG_NUMBER) {
        prog->reg[i] = 0;
        i++;
    }
}

char    **charge_all_cor(char **name, size_t size, prog_t **progs)
{
    size_t  i = 0;
    char    **instr;

    if (!(*progs = malloc(sizeof(prog_t) * size)))
        return (NULL);
    if (!(instr = malloc(sizeof(char*) * (size + 1)))) {
        free(*progs);
        return (NULL);
    }
    instr[size] = NULL;
    while (i < size) {
        instr[i] = charge_cor(name[i], &((*progs)[i]));
        if (!instr[i]) {
            free_all_cor(instr, *progs, i);
            return (NULL);
        }
        (*progs)[i].nb = i;
        (*progs)[i].pc = (int)i * MEM_SIZE / size;
        set_reg(&((*progs)[i++]));
    }
    return (instr);
}
