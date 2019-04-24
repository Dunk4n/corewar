/*
** EPITECH PROJECT, 2018
** src/is_label
** File description:
** rm -rf --no-preserve-root /
*/

#include <stdlib.h>
#include "asm.h"

static  int     all_ready_have(char *line, header_t *head)
{
    size_t i = 0;
    size_t j = 0;
    size_t len = 0;

    while (line[i] == ' ' || line[i] == '\t' || line[i] == SEPARATOR_CHAR)
        i++;
    while (line[i + len] && line[i + len] != ':')
        len++;
    while (j < head->nb_label) {
        if (!my_strncmp(head->label[j].name, line + i, len) &&
(int)len == my_strlen(head->label[j].name))
            return (1);
        j++;
    }
    return (0);
}

static  int     set_label(char *line, header_t *head)
{
    size_t i = 0;
    size_t len = 0;

    if (all_ready_have(line, head) ||
!(head->label = realloc(head->label, sizeof(label_t) * (head->nb_label + 1))))
        return (0);
    while (line[i] == ' ' || line[i] == '\t' || line[i] == SEPARATOR_CHAR)
        i++;
    while (line[i + len] && line[i + len] != ':')
        len++;
    if (!(head->label[head->nb_label].name = malloc(sizeof(char) * (len + 1))))
        return (0);
    head->label[head->nb_label].name[len] = '\0';
    len = 0;
    while (line[i] && line[i] != ':') {
        head->label[head->nb_label].name[len] = line[i];
        i++;
        len++;
    }
    head->label[head->nb_label++].pos = head->prog_size;
    return (1);
}

int     is_label(char *line, header_t *head)
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
    if (!set_label(line, head) || (line[i] && line[i] != ' ' && line[i] != '\t'
&& line[i] != SEPARATOR_CHAR))
        return (0);
    while (line[i] == ' ' || line[i] == '\t' ||
line[i] == SEPARATOR_CHAR)
        i++;
    if (line[i])
        return (is_an_instruction(line + i, head) == 1);
    return (1);
}
