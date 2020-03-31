/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** init_core.c
*/

#include <stdlib.h>
#include "corwar.h"

int init_core(corewar_t *core)
{
    int index = 0;

    while (index < 4) {
        core->order[index] = NULL;
        index++;
    }
    core->order[4] = NULL;
    for (int i = 0; i < 4; i++)
        core->adress[i] = -1;
    for (int i = 0; i < 4; i++)
        core->number[i] = 0;
    core->champions = -1;
    core->dump = -1;
    return 1;
}

void put_theme(char ***tmp, int **tmp_a, corewar_t *core, int index)
{
    for (int i = 0; i < 4; i++) {
        if ((*tmp)[i] == NULL) {
            (*tmp)[i] = core->order[index];
            (*tmp_a)[i] = core->adress[index];
            break;
        }
    }
}

void free_tmp(char ***tmp, int **tmp_a)
{
    free(*tmp);
    free(*tmp_a);
}

void sort_name(corewar_t *core)
{
    char **tmp = malloc(sizeof(char *) * 5);
    int *tmp_a = malloc(sizeof(int) * 4);

    for (int i = 0; i < 4; i++) {
        tmp[i] = NULL;
        tmp_a[i] = -1;
    }
    tmp[4] = NULL;
    for (int index = 0; index <= 4; index++) {
        if (core->number[index] > 0) {
            tmp[core->number[index] - 1] = core->order[index];
            tmp_a[core->number[index] - 1] = core->adress[index];
        }
    } for (int index = 0; index <= 4; index++) {
        if (core->number[index] == 0)
            put_theme(&tmp, &tmp_a, core, index);
    } for (int i = 0; i < 4; i++)
        core->order[i] = tmp[i];
    for (int i = 0; i < 4; i++)
        core->adress[i] = tmp_a[i];
    free_tmp(&tmp, &tmp_a);
}
