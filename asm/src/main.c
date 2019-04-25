/*
** EPITECH PROJECT, 2018
** src/main
** File description:
** fireplace 4k
*/

#include <stdlib.h>
#include "asm.h"

int     flag_h(char *name)
{
    my_printf("%s%s", "USAGE\n    ./", name);
    my_putstr("[.s]\n\nDESCRIPTION\n    file_name\tfile in assembly language to\
 be converted into file_name.cor, an\n\t\texecutable in the Virtual Machaine.\
\n");
    return (0);
}

int     main(int ac, char **av)
{
    header_t    *head;
    char        **file;
    int         fd;

    if (ac != 2)
        return (84);
    if (!my_strcmp(av[1], "-h"))
        return (flag_h(av[1]));
    if (!(head = malloc(sizeof(header_t))))
        return (84);
    //TODO: in arg check if an label exist
    if (!(file = parse_head(av[1], head)))
        return (84);
    if (!write_head(head, av[1], &fd))
        return (84);
    if (!write_instruction(file, head, head->prog_size, fd))
        return (84);
    return (0);
}
