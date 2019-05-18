/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** is_num.c
*/

#include "corwar.h"

static int number_ok(char c)
{
    if (c < '0' || c > '9')
        return -1;
    return 0;
}

int is_number(char *str)
{
    for (size_t index = 0; str; index++) {
        if ((str[index]) == '\0')
            break;
        if (number_ok(str[index]) == 0)
            continue;
        else
            return(0);
    }
    return 1;
}