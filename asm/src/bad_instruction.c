/*
** EPITECH PROJECT, 2018
** bad_instruction
** File description:
** vim > emacs
*/

#include <stdlib.h>
#include "asm.h"

const   int     nb_oct[16] = {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1};

int     good_name(char c)
{
    size_t i = 0;
    char    *str = LABEL_CHARS;

    if (!c)
        return (0);
    while (str[i]) {
        if (c == str[i])
            return (1);
        i++;
    }
    return (0);
}

static  int     get_indice_instruction(char *line, header_t *head)
{
    size_t i = 0;
    size_t len = 0;

    while (good_name(line[len]))
        len++;
    while (op_tab[i].mnemonique) {
        if (!my_strncmp(op_tab[i].mnemonique, line, len) && (int)len ==
my_strlen(op_tab[i].mnemonique)) {
            head->prog_size += 1 + nb_oct[i];
            return (i);
        }
        i++;
    }
    return (-1);
}

int     is_an_instruction(char *line, header_t *head)
{
    size_t i = 0;
    int    code;

    while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] !=
LABEL_CHAR) {
        if (!good_name(line[i]))
            return (-1);
        i++;
    }
    if (i > 0 && line[i] == LABEL_CHAR && (line[i + 1] == ' ' ||
line[i + 1] == '\t' || !line[i + 1]))
        return (0);
    if ((code = get_indice_instruction(line, head)) == -1)
        return (-1);
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    if (!check_arg(line + i, code, head))
        return (-1);
    return (1);
}

int     bad_instruction(char *line, header_t *head)
{
    size_t  i = 0;
    int     tmp;

    while (line[i] == ' ' || line[i] == '\t' || line[i] == SEPARATOR_CHAR)
        i++;
    if (!line[i] || line[i] == COMMENT_CHAR)
        return (0);
    tmp = is_an_instruction(line + i, head);
    if (tmp == 0 && !is_label(line, head))
        return (1);
    if (tmp == -1)
        return (1);
    return (0);
}
