/*
** EPITECH PROJECT, 2018
** corwar
** File description:
** no, real programmers use cat
*/

#ifndef CORWAR_H
#define CORWAR_H

#include "my.h"
#include "op.h"

#define REVERSE_INT(n) ((unsigned int) (((n & 0xFF) << 24) | \
((n & 0xFF00) << 8) | ((n & 0xFF0000) >> 8) | ((n & 0xFF000000) >> 24)))

typedef union   data_u
{
    int     nb;
    char    data[4];
}               data_t;

typedef struct  prog_s
{
    size_t      nb;
    size_t      size;
    int         tmp;
    int         reg[REG_NUMBER];
    int         carry;
    int         pc;
    int         live;
    int         to_exc;
    char        name[PROG_NAME_LENGTH + 1];
}               prog_t;

typedef struct  corewar_s
{
    prog_t      *prog;
    size_t      nb_prog;
    char        *map;
    size_t      cycle_to_die;
    size_t      nb_live;
    size_t      nb_prog_live;
}               corewar_t;

char    *charge_cor(char *name, prog_t *prog);
char    **charge_all_cor(char **name, size_t size, prog_t **progs);
void    put_prog(char *map, prog_t *prog, char **instr);
void    core_war(corewar_t *core);

/*
** instruction
*/

void    live(char *map, prog_t *prog, corewar_t *core);
void    ld(char *map, prog_t *prog, corewar_t *core);

#endif
