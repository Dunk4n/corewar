/*
** EPITECH PROJECT, 2018
** src/is_label
** File description:
** rm -rf --no-preserve-root /
*/

#include <stdlib.h>
#include "asm.h"

static  int     all_ready_have(char *line, compil_t *compil)
{
    size_t i = 0;
    size_t j = 0;
    size_t len = 0;

    while (line[i] == ' ' || line[i] == '\t' || line[i] == SEPARATOR_CHAR)
        i++;
    while (line[i + len] && line[i + len] != LABEL_CHAR)
        len++;
    while (j < compil->nb_label) {
        if (!my_strncmp(compil->label[j].name, line + i, len) &&
(int)len == my_strlen(compil->label[j].name))
            return (1);
        j++;
    }
    return (0);
}

static  int     set_label(char *line, compil_t *compil)
{
    size_t i = 0;
    size_t len = 0;

    if (all_ready_have(line, compil) || !(compil->label = realloc(compil->label,
sizeof(label_t) * (compil->nb_label + 1))))
        return (0);
    while (line[i] == ' ' || line[i] == '\t' || line[i] == SEPARATOR_CHAR)
        i++;
    while (line[i + len] && line[i + len] != LABEL_CHAR &&
line[i + len] != COMMENT_CHAR)
        len++;
    if (!(compil->label[compil->nb_label].name = malloc(sizeof(char) *
(len + 1))))
        return (0);
    compil->label[compil->nb_label].name[len] = '\0';
    len = 0;
    while (line[i] && line[i] != LABEL_CHAR)
        compil->label[compil->nb_label].name[len++] = line[i++];
    compil->label[compil->nb_label++].pos = compil->head.prog_size;
    return (1);
}

int     is_label(char *line, compil_t *compil)
{
    size_t i = 0;

    while (line[i] == ' ' || line[i] == '\t' || line[i] == SEPARATOR_CHAR)
        i++;
    while (line[i] && line[i] != LABEL_CHAR) {
        if (!good_name(line[i]))
            return (0);
        i++;
    }
    if (line[i] != LABEL_CHAR)
        return (0);
    i++;
    if (!set_label(line, compil) || (line[i] && line[i] != ' ' &&
line[i] != '\t' && line[i] != SEPARATOR_CHAR && line[i] != COMMENT_CHAR))
        return (0);
    while (line[i] == ' ' || line[i] == '\t' ||
line[i] == SEPARATOR_CHAR)
        i++;
    if (line[i] != COMMENT_CHAR && line[i])
        return (is_an_instruction(line + i, &(compil->head)) == 1);
    return (1);
}
