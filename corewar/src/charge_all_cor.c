/*
** EPITECH PROJECT, 2019
** src/charge_all_cor
** File description:
** epitech > 42
*/

#include <unistd.h>
#include <stdlib.h>
#include "corwar.h"

static  void    *free_all_cor(char **instr, prog_t *progs, size_t nb)
{
    free(progs);
    if (!instr)
        return (NULL);
    while (nb-- > 0)
        free(instr[nb]);
    free(instr);
    return (NULL);
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
    size_t  nb = 0;
    char    **instr;

    if (!(*progs = malloc(sizeof(prog_t) * size)))
        return (NULL);
    if (!(instr = malloc(sizeof(char*) * (size + 1)))) {
        free(*progs);
        return (NULL);
    }
    instr[size] = NULL;
    while (i < 4) {
        if (!name[i]) {
            i++;
            continue;
        }
        instr[nb] = charge_cor(name[i], &((*progs)[nb]));
        if (!instr[nb])
            return (free_all_cor(instr, *progs, nb));
        (*progs)[nb].nb = nb;
        (*progs)[nb].nb_name = i;
        printf("%d, %d\n", i, nb);
        (*progs)[nb].daron = nb;
        (*progs)[nb].pc = (int)nb * MEM_SIZE / size;
        (*progs)[nb].start = (*progs)[nb].pc;
        set_reg(&((*progs)[nb++]));
        i++;
    }
    return (instr);
}
