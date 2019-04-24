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

void    write_name(int fd, header_t *head)
{
    size_t i = my_strlen(head->prog_name);
    data_t data;

    while (i < PROG_NAME_LENGTH) {
        head->prog_name[i] = '\0';
        i++;
    }
    write(fd, head->prog_name, PROG_NAME_LENGTH);
    write(fd, "\0\0\0\0", 4);
    data.nb = head->prog_size;
    write(fd, &(data.data[3]), 1);
    write(fd, &(data.data[2]), 1);
    write(fd, &(data.data[1]), 1);
    write(fd, &(data.data[0]), 1);
    i = my_strlen(head->comment);
    while (i < COMMENT_LENGTH) {
        head->comment[i] = '\0';
        i++;
    }
    write(fd, head->comment, COMMENT_LENGTH);
    write(fd, "\0\0\0\0", 4);
}

int     write_head(header_t *head, const char *name, int *fd)
{
    *fd = open_file(name);
    data_t data;

    if (*fd == -1)
        return (0);
    data.nb = head->magic;
    write(*fd, &(data.data[3]), 1);
    write(*fd, &(data.data[2]), 1);
    write(*fd, &(data.data[1]), 1);
    write(*fd, &(data.data[0]), 1);
    write_name(*fd, head);
    return (1);
}
