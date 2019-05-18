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
        core->adress[i] = 0;
    for (int i = 0; i < 4; i++)
        core->number[i] = 0;
    core->champions = 0;
    return 1;
}

void sort_name(corewar_t *core)
{
    char *tmp[5] = {NULL};
    int tmp_a[4] = {0};

    for (int index = 0; index <= 4; index++) {
        if (core->number[index] > 0) {
            tmp[core->number[index] - 1] = core->order[index];    
            tmp_a[core->number[index] - 1] = core->adress[index];
        }
    }
    for (int index = 0; index <= 4; index++) {
        if (core->number[index] == 0) {
            for (int i = 0; i < 4; i++) {
                if (tmp[i] == NULL) {
                    tmp[i] = core->order[index]; 
                    tmp_a[i] = core->adress[index];
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 4; i++)
        core->order[i] = tmp[i];
    for (int i = 0; i < 4; i++)
        core->adress[i] = tmp_a[i];
}
