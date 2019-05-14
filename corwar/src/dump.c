/*
** EPITECH PROJECT, 2019
** dump.c
** File description:
** print_dump
*/

#include <string.h>
#include <stdlib.h>
#include "corwar.h"

static void print_padding(size_t i)
{
    char *str = my_calloc(sizeof(char) * (6 + 1), ' ');

    if (str == NULL)
        return;
    str = convert_base(my_itoa(i), DEC, HEX);
    for (size_t len = (size_t)my_strlen(str); len < 7; len++)
        str[len] = ' ';
    str[5] = ':';
    my_putstr(str);
    free(str);
}

static void display_dump_line(corewar_t *core, size_t i)
{
    char *str = convert_base(my_itoa((unsigned char)core->map[i]), DEC, HEX);
    size_t len = (size_t)my_strlen(str);

    if (len == 0) {
        my_putstr("00 ");
        free(str);
        return;
    }
    if (len == 1) {
        my_putchar('0');
        my_putchar(str[0]);
        my_putchar(' ');
        free(str);
        return;
    }
    for (size_t u = 0; str[u]; u++) {
        my_putchar(str[u]);
        if (u % 2 != 0)
            my_putchar(' ');
    }
    free(str);
}

void dump(corewar_t *core)
{
    for (size_t i = 0; i < MEM_SIZE; i++) {
        if (i == 0)
            my_putstr("0    : ");
        else if (i % 32 == 0) {
            my_putchar('\n');
            print_padding(i);
        }
        display_dump_line(core, i);
    }
    my_putchar('\n');
}
