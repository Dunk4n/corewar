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

#define MODU(x) ((x < 0) ? ((x) % MEM_SIZE + MEM_SIZE) % MEM_SIZE : \
(x) % MEM_SIZE)

#define DEC "0123456789"
#define HEX "0123456789ABCDEF"

#define NB_INSTR 25

const   sfColor colorrf[5];
const   sfColor colorrf2[5];

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
    int         segfault;
    size_t      nb_prog_live;
    int dump;
    char *order[5];
    int adress[4];
    int number[4];
    int champions;
}               corewar_t;

char    *charge_cor(char *name, prog_t *prog);
char    **charge_all_cor(char **name, size_t size, prog_t **progs);
int    put_prog(corewar_t *core, char **instr);
void    corewar(corewar_t *core, menu_t *menu);
int     get_arg(char *map, int pc, int *tab);
int     get_value_arg(corewar_t *core, prog_t *prog, int value, int type);
int     get_value_arg_long(corewar_t *core, prog_t *prog, int value, int type);
int     get_nb(corewar_t *core);
void    put_fork_in_memory(corewar_t *core, int arg, prog_t *a, prog_t *b);
void    dump(char *map);
int     display_all_corewar(corewar_t *core, menu_t *menu, size_t i, int end);
int     init_img(menu_t *menu, corewar_t *core);
int     display_text(corewar_t *core, menu_t *menu, size_t i, int to_die);
void    display_win(corewar_t *core, menu_t *menu, size_t i);
int     win(corewar_t *core);
int     display_all_corewar_tour(corewar_t *core, menu_t *menu, size_t i,
int to_die);
void    corewar_tour(corewar_t *core, menu_t *menu);
int parsing(int ac, char **av, corewar_t *core);
int count_cor(int ac, char **av, corewar_t *core);
int put_champion(char **av, int *arg, corewar_t *core);
int is_number(char *str);
int init_core(corewar_t *core);
void sort_name(corewar_t *core);

/*
** instruction
*/

void    live(corewar_t *core, prog_t *prog, menu_t *menu);
void    ld(corewar_t *core, prog_t *prog, menu_t *menu);
void    st(corewar_t *core, prog_t *prog, menu_t *menu);
void    add(corewar_t *core, prog_t *prog, menu_t *menu);
void    sub(corewar_t *core, prog_t *prog, menu_t *menu);
void    and(corewar_t *core, prog_t *prog, menu_t *menu);
void    or(corewar_t *core, prog_t *prog, menu_t *menu);
void    xor(corewar_t *core, prog_t *prog, menu_t *menu);
void    zjmp(corewar_t *core, prog_t *prog, menu_t *menu);
void    ldi(corewar_t *core, prog_t *prog, menu_t *menu);
void    sti(corewar_t *core, prog_t *prog, menu_t *menu);
void    my_fork(corewar_t *core, prog_t *prog, menu_t *menu);
void    lld(corewar_t *core, prog_t *prog, menu_t *menu);
void    lldi(corewar_t *core, prog_t *prog, menu_t *menu);
void    lfork(corewar_t *core, prog_t *prog, menu_t *menu);
void    aff(corewar_t *core, prog_t *prog, menu_t *menu);

/*
** bonus
*/

void    not(corewar_t *core, prog_t *prog, menu_t *menu);
void    rsht(corewar_t *core, prog_t *prog, menu_t *menu);
void    lsht(corewar_t *core, prog_t *prog, menu_t *menu);
void    mul(corewar_t *core, prog_t *prog, menu_t *menu);
void    my_div(corewar_t *core, prog_t *prog, menu_t *menu);
void    mod(corewar_t *core, prog_t *prog, menu_t *menu);
void    my_rand(corewar_t *core, prog_t *prog, menu_t *menu);
void    die(corewar_t *core, prog_t *prog, menu_t *menu);
void    kill(corewar_t *core, prog_t *prog, menu_t *menu);

#endif
