/*
** EPITECH PROJECT, 2019
** src/main
** File description:
** fireplace 4k
*/

#include <stdlib.h>
#include "corwar.h"

int    flag_h(char *nam)
{
    my_putstr("USAGE\n");
    my_printf("\t%s [-dump nbr_cycle] [[-n prog_number] [-a load_adress]", nam);
    my_putstr(" prog_name] ...\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\t-dump nbr_cycle dumps the memory after the nbr_cycle \
executio");
    my_putstr("n (if the round isn't\n\t\t\talready over) with the following");
    my_putstr(" format: 32 bytes/line in\n\t\t\thexadecimal (AOBCDEFE1DD3...)");
    my_putstr("\n\t-n prog_number  sets the next program's number. By \
default,");
    my_putstr(" the first free number\n\t\t\tin the parameter order\n");
    my_putstr("\t-a load_adress  sets the next program's loading adress. When");
    my_putstr(" no adress is\n\t\t\tspecified, optimize the addresses so \
that ");
    my_putstr("the processes are as far\n\t\t\taway from each other as");
    my_putstr(" possible. The addresses are MEM_SIZE modulo\n");
    return 0;
}

void    set_value(corewar_t *core)
{
    core->cycle_to_die = CYCLE_TO_DIE;
    core->nb_live = 0;
    core->segfault = 0;
    core->nb_prog_live = core->nb_prog;
}

int     malloc_start(corewar_t *core, char ***instr)
{
    size_t      i = 0;

    while (i < MEM_SIZE) {
        core->map[i] = 0;
        core->who[i++] = -1;
    }
    if (!(*instr = charge_all_cor(core->order, core->nb_prog, &(core->prog))))
        return (84);
    return (0);
}

int     main(int ac, char **av)
{
    corewar_t   core;
    char        **instr;

    if (ac == 2 && !my_strcmp(av[1], "-h"))
        return (flag_h(av[1]));
    if (!parsing(ac, av, &core))
        return 84;
    if (malloc_start(&core, &instr) == 84)
        return (84);
    set_value(&core);
    if (!put_prog(&core, instr))
        return 84;
    corewar(&core);
    if (core.segfault)
        return (84);
    free(core.prog);
    for (int i = 0; i <= 4; i++)
        free(core.order[i]);
    return (0);
}
