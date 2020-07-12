/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 13:44:21 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 13:47:27 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corwar.h"

int			option_a(int ac, char **av, int *arg, t_corewar *core)
{
	int		index;

	index = 0;
	if (*arg == ac || !is_number(av[*arg + 1]))
		return (0);
	(*arg)++;
	while (index < MAX_ARGS_NUMBER)
	{
		if (core->order[index] == NULL)
			break ;
		index++;
	}
	if (!ft_strcmp(av[*arg + 1], "-n"))
	{
		core->number[index] = ft_getnbr(av[*arg + 2]);
		core->adress[index] = ft_getnbr(av[*arg]);
		*arg += 2;
	}
	else
	{
		core->number[index] = 0;
		core->adress[index] = ft_getnbr(av[*arg]);
	}
	return (1);
}

static void	option_n_exec(int index, char **av, int *arg, t_corewar *core)
{
	while (index < MAX_ARGS_NUMBER)
	{
		if (core->order[index] == NULL)
			break ;
		index++;
	}
	if (!ft_strcmp(av[*arg + 1], "-a"))
	{
		core->adress[index] = ft_getnbr(av[*arg + 2]);
		core->number[index] = ft_getnbr(av[*arg]);
		*arg += 2;
	}
	else
	{
		core->adress[index] = -1;
		core->number[index] = ft_getnbr(av[*arg]);
	}
}

int			option_n(int ac, char **av, int *arg, t_corewar *core)
{
	int		index;

	index = 0;
	if (*arg == ac)
		return (0);
	if (is_number(av[*arg + 1]))
	{
		(*arg)++;
		option_n_exec(index, av, arg, core);
		return (1);
	}
	write(2, "-n must be a valide positive value betwenn [1-4]\n", 49);
	return (0);
}

int			option_dump(int ac, char **av, int *arg, t_corewar *core)
{
	if (*arg == ac)
		return (0);
	if (is_number(av[*arg + 1]))
	{
		core->dump = ft_getnbr(av[*arg + 1]);
		(*arg)++;
		return (1);
	}
	return (0);
}
