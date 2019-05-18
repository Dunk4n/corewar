/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** parsing_two.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "corwar.h"

int put_champion(char **av, int *arg, corewar_t *core)
{
    int index = 0;

    while (index < 4) {
        if (core->order[index] != NULL) {
            index++;
            continue;
        }
        else {
            core->order[index] = my_strdup(av[*arg]);
            return 1;
        }
    }
    return 0;
}

int count_cor(int ac, char **av, corewar_t *core)
{
    int index = 0;
    int arguments = 0;
    int champions = 0;
    int my_champions = 0;

    while (index < 4) {
        if (core->order[index] != NULL)
            my_champions++;
        index++;
    }
    while (arguments < ac) {
        if (my_strstr(av[arguments], ".cor"))
            champions++;
        arguments++;
    }
    core->champions = champions;
    if (champions == my_champions && my_champions <= 4)
        return 1;
    my_printf("Only 4 champions maximum allowed\n");
    return 0;
}