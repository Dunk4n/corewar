/*
** EPITECH PROJECT, 2018
** src/set_parameter
** File description:
** check your malloc!
*/

#include <stdlib.h>
#include "asm.h"

static  int     get_pos_label(compil_t *compil, char *line)
{
    size_t i = 0;
    size_t len = 0;

    while (line[len] && line[len] != ' ' && line[len] != '\t' &&
line[len] != SEPARATOR_CHAR && line[len] != COMMENT_CHAR)
        len++;
    while (i < compil->nb_label) {
        if (!my_strncmp(compil->label[i].name, line, len) &&
(int)len == my_strlen(compil->label[i].name))
            return (compil->label[i].pos);
        i++;
    }
    return (0);
}

static  void    set_ind(compil_t *compil, char *line, int arg, int pos)
{
    short_t sh;

    if (arg == 1)
        sh.nb = my_getnbr(line);
    else
        sh.nb = get_pos_label(compil, line + 1) - pos;
    compil->instr[compil->pos++] = sh.data[1];
    compil->instr[compil->pos++] = sh.data[0];
}

static  void    set_dir(compil_t *compil, char *line, int arg, int *tab)
{
    short_t sh;
    data_t  data;

    if (tab[0] <= 7 || tab[0] == 12) {
        if (arg == 1)
            data.nb = my_getnbr(line + 1);
        else
            data.nb = get_pos_label(compil, line + 2) - tab[1];
        compil->instr[compil->pos++] = data.data[3];
        compil->instr[compil->pos++] = data.data[2];
        compil->instr[compil->pos++] = data.data[1];
        compil->instr[compil->pos++] = data.data[0];
        return ;
    }
    if (arg == 1)
        sh.nb = my_getnbr(line + 1);
    else
        sh.nb = get_pos_label(compil, line + 2) - tab[1];
    compil->instr[compil->pos++] = sh.data[1];
    compil->instr[compil->pos++] = sh.data[0];
}

static  void    set_one_parameter(compil_t *compil, char *line, int code,
int pos)
{
    int arg;
    int tab[] = {code, pos};

    if (is_reg(line))
        compil->instr[compil->pos++] = my_getnbr(line + 1);
    if ((arg = is_dir(line)))
        set_dir(compil, line, arg, tab);
    if ((arg = is_ind(line)))
        set_ind(compil, line, arg, pos);
}

void    set_parameter(compil_t *compil, char *line, int code, int pos)
{
    size_t  i = 0;

    while (*line && i < MAX_ARGS_NUMBER) {
        set_one_parameter(compil, line, code, pos);
        while (*line && *line != ' ' && *line != '\t' && *line != SEPARATOR_CHAR
&& *line != COMMENT_CHAR)
            line++;
        while (*line == ' ' || *line == '\t' || *line == SEPARATOR_CHAR)
            line++;
        if (*line == COMMENT_CHAR)
            return ;
        i++;
    }
}
