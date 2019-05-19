/*
** EPITECH PROJECT, 2018
** error
** File description:
** don't forget to free at the end
*/

#include "asm.h"

static int   my_putchar_err(char c)
{
    write(2, &c, 1);
    return (1);
}

static void    my_putstr_err(char *s)
{
    for (int i = 0; s[i]; i++) {
        my_putchar_err(s[i]);
    }
}

static int     my_put_nbr_err(int nb)
{
    int n = (nb < 0) ? my_putchar_err('-') : 0;

    if (nb > 9 || nb < -9) {
        n += my_put_nbr_err((nb < 0) ? (-(nb / 10)) : (nb / 10));
        n += my_putchar_err(((nb < 0) ? (-(nb % 10)) : (nb % 10)) + '0');
        return (n);
    }
    n += my_putchar_err(((nb < 0) ? (-nb) : nb) + '0');
    return (n);
}

static void norm(char *err_msg)
{
    my_putstr_err(ANSI_COLOR_RED);
    my_putstr_err("asm :");
    my_putstr_err(ANSI_COLOR_MAGENTA);
    my_putstr_err(err_msg);
    my_putstr_err(ANSI_COLOR_RESET);
}

int     error(char *line, size_t nb, char *err_msg)
{
    if (!my_strcmp("failed to open file", err_msg) ||
    !my_strcmp("Undefined label", err_msg)) {
        norm(err_msg);
        return (0);
    }
    my_putstr_err(ANSI_COLOR_RED);
    my_putstr_err(err_msg);
    my_putstr_err(ANSI_COLOR_RESET);
    my_putstr_err(ANSI_COLOR_CYAN);
    my_putstr_err(" line ");
    my_put_nbr_err(nb + 1);
    my_putstr_err(ANSI_COLOR_RESET);
    my_putstr_err(": ");
    my_putstr_err(ANSI_COLOR_MAGENTA);
    my_putstr_err(line);
    my_putstr_err(ANSI_COLOR_RESET);
    my_putstr_err("\n");
    return (0);
}