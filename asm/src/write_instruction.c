/*
** EPITECH PROJECT, 2018
** src/write_instruction
** File description:
** epitech > 42
*/

#include <stdlib.h>
#include "asm.h"

int     get_indice(char *line, size_t len)
{
    size_t i = 0;

    while (op_tab[i].mnemonique) {
        if (!my_strncmp(op_tab[i].mnemonique, line, len) && (int)len ==
my_strlen(op_tab[i].mnemonique))
            return (i);
        i++;
    }
    return (-1);
}

static  int     is_instru(char *line)
{
    size_t i = 0;
    size_t j = 0;

    while (line[i] == ' ' || line[i] == '\t' || line[i] == SEPARATOR_CHAR)
        i++;
    if (!line[i] || line[i] == COMMENT_CHAR)
        return (0);
    while (good_name(line[i + j]))
        j++;
    if (line[i + j] == LABEL_CHAR)
        return (is_instru(line + i + j + 1));
    if ((get_indice(line + i, j)) == -1)
        return (0);
    return (1);
}

static  void    init_compil(compil_t *compil)
{
    size_t i = 0;

    compil->instr = malloc(sizeof(char) * (compil->prog_size + 1));
    if (!compil->instr)
        return ;
    compil->pos = 0;
    while (i <= compil->prog_size)
        compil->instr[i++] = '\0';
}

int     write_instruction(compil_t *compil, int fd)
{
    size_t  i = 0;

    init_compil(compil);
    if (!compil)
        return (0);
    while (compil->file[i]) {
        if (is_instru(compil->file[i]))
            compile_instruction(compil, compil->file[i]);
        i++;
    }
    write(fd, compil->instr, compil->pos);
    close(fd);
    return (1);
}
