/*
** EPITECH PROJECT, 2019
** dump.c
** File description:
** print_dump
*/

#include <string.h>
#include <stdlib.h>
#include "corwar.h"

static void free_all(char *str1, char *str2)
{
    free(str1);
    free(str2);
    return;
}

static int print_padding(size_t i)
{
    char *str = my_calloc(sizeof(char) * (6 + 1), ' ');

    if (str == NULL)
        return 84;
    str = convert_base(my_itoa(i), DEC, HEX);
    for (size_t len = (size_t)my_strlen(str); len < 7; len++)
        str[len] = ' ';
    str[5] = ':';
    my_putstr(str);
    free(str);
    return 0;
}

static void execptionell_print(size_t len, char *str)
{
    if (len == 0) {
        my_putstr("00 ");
    } else if (len == 1) {
        my_putchar('0');
        my_putchar(str[0]);
        my_putchar(' ');
    } else
        return;
}

static int display_dump_line(corewar_t *core, size_t i)
{
    char *mem = my_itoa((unsigned char)core->map[i]);
    char *str = convert_base(mem, DEC, HEX);
    size_t len = (size_t)my_strlen(str);

    if (mem == NULL || str == NULL)
        return 84;
    execptionell_print(len, str);
    for (size_t u = 0; str[u]; u++) {
        my_putchar(str[u]);
        if (u % 2 != 0)
            my_putchar(' ');
    }
    free_all(str, mem);
    return 0;
}

int dump(corewar_t *core)
{
    for (size_t i = 0; i < MEM_SIZE; i++) {
        if (i == 0)
            my_putstr("0    : ");
        else if (i % 32 == 0) {
            my_putchar('\n');
            if (print_padding(i) == 84)
                return 84;
        }
        if (display_dump_line(core, i) == 84)
            return 84;
    }
    my_putchar('\n');
    return 0;
}
