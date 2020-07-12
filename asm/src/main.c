/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 12:59:29 by niduches          #+#    #+#             */
/*   Updated: 2020/07/10 15:31:35 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"

int		flag_h(char *name)
{
	ft_printf("%s%s", "USAGE\n    ./", name);
	ft_putstr_fd("[.s]\n\nDESCRIPTION\n    file_name\tfile in assembly \
language to be converted into file_name.cor, an\n\t\texecutable in the Virtual \
Machaine.\n", 1);
	return (0);
}

int		main(int ac, char **av)
{
	t_compil	compil;
	int			fd;

	if (ac != 2)
		return (0);
	if (!ft_strcmp(av[1], "-h"))
		return (flag_h(av[1]));
	if (!(compil.file = parse_head(av[1], &compil)))
		return (0);
	if (!write_head(&compil, &(compil.head), av[1], &fd))
		return (0);
	if (!write_instruction(&compil, fd))
		return (0);
	return (0);
}
