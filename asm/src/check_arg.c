/*
** EPITECH PROJECT, 2018
** src/check_arg
** File description:
** epitech > epita
*/

#include <stdlib.h>
#include "asm.h"

static  int     good_arg(char *line, int code, int nb_arg, header_t *head)
{
    size_t tmp = 0;

    if (is_reg(line)) {
        tmp = 1;
        head->prog_size += 1;
    }
    if (is_dir(line)) {
        tmp = 2;
        head->prog_size += (code <= 7 || code == 12) ? DIR_SIZE : 2;
    }
    if (is_ind(line)) {
        tmp = 4;
        head->prog_size += IND_SIZE;
    }
    if (tmp & op_tab[code].type[nb_arg])
        return (1);
    return (0);
}

int     check_arg(char *line, int code, header_t *head)
{
    size_t nb_arg = 0;
    size_t i = 0;

    while (nb_arg < (size_t)op_tab[code].nbr_args) {
        if (!good_arg(line + i, code, nb_arg++, head))
            return (0);
        while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] !=
COMMENT_CHAR && line[i] != SEPARATOR_CHAR)
            i++;
        while (line[i] == ' ' || line[i] == '\t' || line[i] == SEPARATOR_CHAR)
            i++;
        if (!line[i] || line[i] == COMMENT_CHAR)
            break;
    }
    if (nb_arg != (size_t)op_tab[code].nbr_args)
        return (0);
    while (line[i] == ' ' || line[i] == '\t' || line[i] == SEPARATOR_CHAR)
        i++;
    if (line[i] && line[i] != COMMENT_CHAR)
        return (0);
    return (1);
}
