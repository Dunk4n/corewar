/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** parsing.c
*/

#include <string.h>
#include "corwar.h"

int option_a(int ac, char **av, int *arg, corewar_t *core)
{
    int index = 0;

    if (*arg == ac)
        return 0;
    if (is_number(av[*arg + 1])) {
        (*arg)++;
        while (index < 4) {
            if (core->order[index] == NULL)
                break;
        index++;
        } if (!my_strcmp(av[*arg + 1], "-n")) {
            core->number[index] = my_getnbr(av[*arg + 2]);
            core->adress[index] = my_getnbr(av[*arg]);
            *arg += 2;
        } else {
            core->number[index] = 0;
            core->adress[index] = my_getnbr(av[*arg]);
        }
        return 1;
    }
    return 0;
}

int option_n(int ac, char **av, int *arg, corewar_t *core)
{
    int index = 0;

    if (*arg == ac)
        return 0;
    if (is_number(av[*arg + 1])) {
        (*arg)++;
        while (index < 4) {
            if (core->order[index] == NULL)
                break;
        index++;
        } if (!my_strcmp(av[*arg + 1], "-a")) {
            core->adress[index] = my_getnbr(av[*arg + 2]);
            core->number[index] = my_getnbr(av[*arg]);
            *arg += 2;
        } else {
            core->adress[index] = -1;
            core->number[index] = my_getnbr(av[*arg]);
        }
        return 1;
    } write(2, "-n must be a valide positive value between [1-4]\n", 49);
    return 0;
}

int option_dump(int ac, char **av, int *arg, corewar_t *core)
{
    if (*arg == ac)
        return 0;
    if (is_number(av[*arg + 1])) {
        core->dump = my_getnbr(av[*arg + 1]);
        (*arg)++;
        return 1;
    }
    return 0;
}

int parse(int ac, char **av, int *arg, corewar_t *core)
{
    if (my_strcmp(av[*arg], "-dump") == 0) {
        if (option_dump(ac, av, arg, core))
            return 1;
        else
            return 0;
    } if (my_strcmp(av[*arg], "-a") == 0) {
        if (option_a(ac, av, arg, core))
            return 1;
        else
            return 0;
    } if (my_strcmp(av[*arg], "-n") == 0) {
        if (option_n(ac, av, arg, core))
            return 1;
        else
            return 0;
    } if (my_strstr(av[*arg], ".cor")) {
        put_champion(av, arg, core);
        return 1;
    } write(2, &av[*arg][0], my_strlen(av[*arg]));
    write (2, ": command not found\n", 21);
    return 0;
}

int parsing(int ac, char **av, corewar_t *core)
{
    int arg = 1;

    if (!init_core(core))
        return 0;
    if (ac == arg)
        return 0;
    while (arg < ac) {
        if (!parse(ac, av, &arg, core))
            return 0;
        if ((ac - 1) == arg)
            break;
        arg++;
    }
    sort_name(core);
    if (!count_cor(ac, av, core))
        return 0;
    return 1;
}
