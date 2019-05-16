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

#define MODU(x) ((x < 0) ? (x % MEM_SIZE + MEM_SIZE) % MEM_SIZE : x % MEM_SIZE)

#define DEC "0123456789"
#define HEX "0123456789abcdef"

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
    size_t      daron;
    size_t      size;
    size_t      start;
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
    char        map[MEM_SIZE];
    int         who[MEM_SIZE];
    int         cycle_to_die;
    int         nb_live;
    size_t      segfault;
    size_t      nb_prog_live;
}               corewar_t;

char    *charge_cor(char *name, prog_t *prog);
char    **charge_all_cor(char **name, size_t size, prog_t **progs);
void    put_prog(char *map, int *who, prog_t *prog, char **instr);
void    corewar(corewar_t *core);
int     get_arg(char *map, int pc, int *tab);
int     get_value_arg(corewar_t *core, prog_t *prog, int value, int type);
int     get_value_arg_long(corewar_t *core, prog_t *prog, int value, int type);
int     get_nb(corewar_t *core);
void    dump(corewar_t *core);
void    put_fork_in_memory(corewar_t *core, int arg, prog_t *a, prog_t *b);

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
void    ldi(corewar_t *core, prog_t *prog);
void    sti(corewar_t *core, prog_t *prog);
void    my_fork(corewar_t *core, prog_t *prog);
void    lld(corewar_t *core, prog_t *prog);
void    lldi(corewar_t *core, prog_t *prog);
void    lfork(corewar_t *core, prog_t *prog);
void    aff(corewar_t *core, prog_t *prog);

/*
** bonus
*/

//bitwise not

#endif
