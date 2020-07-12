/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:40:05 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 17:22:13 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "corwar.h"

int		put_champion(char **av, int *arg, t_corewar *core)
{
	int		index;

	index = 0;
	while (index < MAX_ARGS_NUMBER)
	{
		if (core->order[index] != NULL)
		{
			index++;
			continue ;
		}
		else
		{
			core->order[index] = ft_strdup(av[*arg]);
			if (!core->order[index])
				return (0);
			return (1);
		}
	}
	return (0);
}

void	count_champ(t_corewar *core, int *index, int *my_champions)
{
	*index = 0;
	*my_champions = 0;
	while (*index < MAX_ARGS_NUMBER)
	{
		if (core->order[*index] != NULL)
			(*my_champions)++;
		(*index)++;
	}
}

int		count_cor(int ac, char **av, t_corewar *core)
{
	int		index;
	int		arguments;
	int		champions;
	int		my_champions;

	arguments = 0;
	champions = 0;
	count_champ(core, &index, &my_champions);
	while (arguments < ac)
	{
		if (ft_strstr(av[arguments], ".cor"))
			champions++;
		arguments++;
	}
	core->champions = champions;
	if (champions == my_champions && my_champions <= MAX_ARGS_NUMBER)
	{
		core->nb_prog = champions;
		return (1);
	}
	ft_printf("Only %d champions maximum allowed\n", MAX_ARGS_NUMBER);
	return (0);
}
