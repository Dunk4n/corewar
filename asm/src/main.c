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
    compil_t    *compil;
    int         fd;

    if (ac != 2)
        return (84);
    if (!my_strcmp(av[1], "-h"))
        return (flag_h(av[1]));
    if (!(compil = malloc(sizeof(compil_t))))
        return (84);
    if (!(compil->file = parse_head(av[1], compil)))
        return (84);
    if (!write_head(&(compil->head), av[1], &fd))
        return (84);
    if (!write_instruction(compil, fd))
        return (84);
    return (0);
}
