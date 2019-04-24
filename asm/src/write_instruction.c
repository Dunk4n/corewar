/*
** EPITECH PROJECT, 2018
** src/write_instruction
** File description:
** epitech > 42
*/

#include <stdlib.h>
#include "asm.h"

static  char    *malloc_instruction(int prog_size)
{
    char    *instr = malloc(sizeof(char) * (prog_size + 1));
    int     i = 0;

    if (!instr)
        return (NULL);
    while (i <= prog_size)
        instr[i++] = '\0';
    return (instr);
}

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

static  compil_t        *init_compil(char **file, label_t *label, int prog_size,
int nb_label)
{
    compil_t *compil = malloc(sizeof(compil_t));

    if (!compil)
        return (NULL);
    if (!(compil->instr = malloc_instruction(prog_size))) {
        free(compil);
        return (NULL);
    }
    compil->file = file;
    compil->prog_size = (size_t)prog_size;
    compil->nb_label = nb_label;
    compil->label = label;
    compil->pos = 0;
    return (compil);
}

int     write_instruction(char **file, header_t *head, int prog_size,
int fd)
{
    size_t  i = 0;
    compil_t *compil = init_compil(file, head->label, prog_size,
head->nb_label);

    if (!compil)
        return (0);
    while (file[i]) {
        if (is_instru(file[i]))
            compile_instruction(compil, file[i]);
        i++;
    }
    write(fd, compil->instr, compil->pos);
    close(fd);
    return (1);
}
