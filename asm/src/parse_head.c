/*
** EPITECH PROJECT, 2018
** src/parse_head
** File description:
** r/ProgrammerHumor
*/

#include <stdlib.h>
#include <fcntl.h>
#include "asm.h"

void    free_file(char **file)
{
    size_t i = 0;

    if (!file)
        return ;
    while (file[i]) {
        free(file[i]);
        i++;
    }
    free(file);
}

char    **parse_head(char const *name, header_t *head)
{
    int     fd;
    int     head_or_comment = 0;
    char    **file;

    head->label = NULL;
    head->nb_label = 0;
    if (!(fd = open(name, O_RDONLY)))
        return (NULL);
    head->magic = COREWAR_EXEC_MAGIC;
    if (!(file = get_file(fd, 0, head, &head_or_comment))) {
        close(fd);
        return (NULL);
    }
    if (head_or_comment == -1) {
        free_file(file);
        return (NULL);
    }
    close(fd);
    return (file);
}
