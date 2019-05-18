/*
** EPITECH PROJECT, 2019
** src/my_dump
** File description:
** r/ProgrammerHumor
*/

#include <stdlib.h>
#include "corwar.h"

static  void    display_char(unsigned char c)
{
    char    *hex = "0123456789ABCDEF";
    char    to_print[] = "00";

    to_print[1] = hex[c % my_strlen(hex)];
    if (c >= 16) {
        c /= my_strlen(hex);
        to_print[0] = hex[c % my_strlen(hex)];
    }
    my_putstr(to_print);
}

static  void    print_beffor(int start)
{
    char    beffor[] = "0    : ";
    char    *hex = "0123456789ABCDEF";
    int     tmp = start;
    size_t  j = 0;

    if (start > 0) {
        while (tmp > 0) {
            tmp /= my_strlen(hex);
            j++;
        }
        j--;
        while (start > 0) {
            beffor[j % my_strlen(beffor)] = hex[start % my_strlen(hex)];
            start /= my_strlen(hex);
            j--;
        }
    }
    my_putstr(beffor);
}

static  void    display_line(char *map, int start)
{
    size_t  i = 0;

    print_beffor(start);
    while (i < 32) {
        display_char((unsigned char)map[i]);
        if (i < 31)
            my_putchar(' ');
        i++;
    }
    my_putchar('\n');
}

void    dump(char *map)
{
    size_t  i = 0;

    while (i < MEM_SIZE / 32) {
        display_line(map + 32 * i, 32 * i);
        i++;
    }
}
