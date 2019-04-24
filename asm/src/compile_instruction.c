/*
** EPITECH PROJECT, 2018
** src/compile_instruction
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h>
#include "asm.h"

static  int     get_code(compil_t *compil, char **line)
{
    size_t  i = 0;
    int     code;

    while (**line == ' ' || **line == '\t' || **line == SEPARATOR_CHAR)
        (*line)++;
    while (good_name((*line)[i]))
        i++;
    if ((*line)[i] == LABEL_CHAR)
        (*line) += i + 1;
    while (**line == ' ' || **line == '\t' || **line == SEPARATOR_CHAR)
        (*line)++;
    i = 0;
    while (good_name((*line)[i]))
        i++;
    code = get_indice(*line, i);
    compil->instr[compil->pos++] = code + 1;
    *line += i;
    while (**line == ' ' || **line == '\t' || **line == SEPARATOR_CHAR)
        (*line)++;
    return (code);
}

static  int     set_byte_parameter(compil_t *compil, char *line, size_t i)
{
    char    tmp = 0;

    if (is_reg(line))
        tmp = 1;
    if (is_dir(line))
        tmp = 2;
    if (is_ind(line))
        tmp = 3;
    if (!tmp)
        return (0);
    tmp = tmp << 2 * (3 - (i % 4));
    compil->instr[compil->pos + i / 4] += tmp;
    return (1);
}

static  void    parameter_byte(compil_t *compil, char *line)
{
    size_t  i = 0;

    while (*line && i < MAX_ARGS_NUMBER) {
        if (!set_byte_parameter(compil, line, i++))
            return ;
        while (*line &&
*line != ' ' && *line != '\t' && *line != SEPARATOR_CHAR)
            line++;
        while (*line == ' ' || *line == '\t' || *line == SEPARATOR_CHAR)
            line++;
        if (*line == COMMENT_CHAR)
            return ;
    }
    compil->pos += (i + 1) / 4 + (((double)i / 4.0 > i) ? 1 : 0);
}

void    compile_instruction(compil_t *compil, char *line)
{
    int     code;
    size_t  pos = compil->pos;

    code = get_code(compil, &line);
    if (nb_oct[code])
        parameter_byte(compil, line);
    set_parameter(compil, line, code, pos);
}
