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

#define REVERSE_SHORT(n) ((unsigned short) (((n & 0xFF) << 8) | \
((n & 0xFF00) >> 8)))

typedef union   data_u
{
    int     nb;
    char    data[4];
}               data_t;

typedef union   short_u
{
    short   nb;
    char    data[2];
}               short_t;

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
int     get_arg(char *map, int pc, int *tab);

/*
** instruction
*/

void    live(corewar_t *core, prog_t *prog);
void    ld(corewar_t *core, prog_t *prog);
void    st(corewar_t *core, prog_t *prog);
void    add(corewar_t *core, prog_t *prog);
void    sub(corewar_t *core, prog_t *prog);
void    and(corewar_t *core, prog_t *prog);
void    or(corewar_t *core, prog_t *prog);
void    xor(corewar_t *core, prog_t *prog);
void    zjmp(corewar_t *core, prog_t *prog);
//ldi
//sti
//fork
//lld
//lldi
//lfork
//aff

/*
** bonus
*/

//bitwise not

#endif
