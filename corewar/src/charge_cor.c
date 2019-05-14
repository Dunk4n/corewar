/*
** EPITECH PROJECT, 2019
** charge_cor
** File description:
** epitech > 42
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "corwar.h"

static  int     good_file(char *buff, int *size)
{
    data_t  data;

    if (*size != sizeof(header_t))
        return (0);
    data.data[0] = buff[0];
    data.data[1] = buff[1];
    data.data[2] = buff[2];
    data.data[3] = buff[3];
    if (REVERSE_INT(data.nb) != COREWAR_EXEC_MAGIC)
        return (0);
    *size = 0;
    return (1);
}

static  int     charge_head(int fd, prog_t *prog)
{
    data_t  data;
    char    buff[sizeof(header_t) + 1];
    int     size;

    size = read(fd, buff, sizeof(header_t));
    buff[size] = '\0';
    good_file(buff, &size);
    while (size < PROG_NAME_LENGTH) {
        prog->name[size] = buff[size + 4];
        size++;
    }
    prog->name[size] = '\0';
    data.data[0] = buff[PROG_NAME_LENGTH + 8];
    data.data[1] = buff[PROG_NAME_LENGTH + 9];
    data.data[2] = buff[PROG_NAME_LENGTH + 10];
    data.data[3] = buff[PROG_NAME_LENGTH + 11];
    prog->size = REVERSE_INT(data.nb);
    return (1);
}

char    *charge_cor(char *name, prog_t *prog)
{
    char    *instr;
    int     fd = open(name, O_RDONLY);
    int     size;

    if (fd == -1)
        return (NULL);
    if (!charge_head(fd, prog) || !(instr = malloc(sizeof(char) *
(prog->size + 1)))) {
        close(fd);
        return (NULL);
    }
    size = read(fd, instr, prog->size + 1);
    instr[prog->size] = '\0';
    close(fd);
    if (size != (int)prog->size) {
        free(instr);
        return (NULL);
    }
    return (instr);
}
