/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:40:04 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 21:13:28 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "corwar.h"

int			parse(int ac, char **av, int *arg, t_corewar *core)
{
	if (ft_strcmp(av[*arg], "-dump") == 0)
		return (option_dump(ac, av, arg, core));
	if (ft_strcmp(av[*arg], "-a") == 0)
		return (option_a(ac, av, arg, core));
	if (ft_strcmp(av[*arg], "-n") == 0)
		return (option_n(ac, av, arg, core));
	if (ft_strstr(av[*arg], ".cor"))
	{
		if (!put_champion(av, arg, core))
			return (0);
		return (1);
	}
	write(2, &av[*arg][0], ft_strlen(av[*arg]));
	write(2, ": command not found\n", 21);
	return (0);
}

int			parsing(int ac, char **av, t_corewar *core)
{
	int		arg;

	srand(time(NULL));
	arg = 1;
	init_core(core);
	if (ac == arg)
		return (0);
	while (arg < ac)
	{
		if (!parse(ac, av, &arg, core))
			return (0);
		if ((ac - 1) == arg)
			break ;
		arg++;
	}
	sort_name(core);
	if (!count_cor(ac, av, core))
		return (0);
	return (1);
}
