/*
** EPITECH PROJECT, 2018
** src/check_label
** File description:
** fireplace 4k
*/

#include <stdlib.h>
#include "asm.h"

int     is_good_label(char *line, header_t *head)
{
    size_t i = 0;
    size_t len = 0;

    while (good_name(line[len]))
        len++;
    while (i < head->nb_label) {
        if (!my_strncmp(line, head->label[i].name, len) &&
(int)len == my_strlen(head->label[i].name))
            return (1);
        i++;
    }
    return (0);
}

int     check_label(char **file, header_t *head)
{
    size_t i = 0;
    size_t j;

    while (file[i]) {
        j = 0;
        while (file[i][j] && file[i][j] != COMMENT_CHAR &&
file[i][j] != LABEL_CHAR)
            j++;
        if (file[i][j] == LABEL_CHAR && good_name(file[i][j + 1]) &&
!is_good_label(file[i] + j + 1, head))
            return (-1);
        i++;
    }
    return (1);
}
