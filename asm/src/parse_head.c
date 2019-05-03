/*
** EPITECH PROJECT, 2018
** src/parse_head
** File description:
** r/ProgrammerHumor
*/

#include <stdlib.h>
#include <fcntl.h>
#include "asm.h"

void    free_file(char **file, int fd)
{
    size_t i = 0;

    if (!file)
        return ;
    while (file[i]) {
        free(file[i]);
        i++;
    }
    free(file);
    close(fd);
}

int     little_endian(int nb)
{
    int tab[4] = {0};

    tab[0] = (nb & 0x000000ff) << 24;
    tab[1] = (nb & 0x0000ff00) << 8;
    tab[2] = (nb & 0x00ff0000) >> 8;
    tab[3] = (nb & 0xff000000) >> 24;
    return (tab[0] | tab[1] | tab[2] | tab[3]);
}

char    **parse_head(char const *name, compil_t *compil)
{
    int     fd;
    int     head_or_comment = -2;
    char    **file;

    compil->label = NULL;
    compil->nb_label = 0;
    if ((fd = open(name, O_RDONLY)) == -1)
        return (NULL);
    compil->head.magic = little_endian(COREWAR_EXEC_MAGIC);
    if (!(file = get_file(fd, 0, compil, &head_or_comment))) {
        close(fd);
        return (NULL);
    }
    if (head_or_comment >= 0)
        head_or_comment = check_label(file, compil);
    if (head_or_comment < 0) {
        free_file(file, fd);
        return (NULL);
    }
    close(fd);
    return (file);
}
