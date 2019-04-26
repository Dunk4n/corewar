/*
** EPITECH PROJECT, 2018
** src/write_head
** File description:
** rm -rf --no-preserve-root /
*/

#include <stdlib.h>
#include <fcntl.h>
#include "asm.h"

char    *new_name(const char *name)
{
    char    *new_name;
    size_t  len = my_strlen(name);
    size_t  size_malloc = len + 4;
    size_t  i = 0;

    if (len > 2 && name[len - 1] == 's' && name[len - 2] == '.') {
        size_malloc = len + 2;
        len -= 2;
    }
    if (!(new_name = malloc(sizeof(char) * (size_malloc + 1))))
        return (NULL);
    new_name[size_malloc] = '\0';
    while (i < len) {
        new_name[i] = name[i];
        i++;
    }
    new_name[i] = '.';
    new_name[i + 1] = 'c';
    new_name[i + 2] = 'o';
    new_name[i + 3] = 'r';
    return (new_name);
}

int     open_file(const char *old_name)
{
    int     fd;
    char    *name = new_name(old_name);

    if (!name)
        return (-1);
    if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC,
S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1) {
        free(name);
        return (-1);
    }
    free(name);
    return (fd);
}

int     write_head(header_t *head, const char *name, int *fd)
{
    int tmp = head->prog_size;

    *fd = open_file(name);
    if (*fd == -1)
        return (0);
    head->prog_size = little_endian(head->prog_size);
    write(*fd, head, sizeof(header_t));
    head->prog_size = tmp;
    return (1);
}
