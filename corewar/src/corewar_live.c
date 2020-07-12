/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_live.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 13:51:32 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 13:52:14 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corwar.h"

void	win(t_corewar *core)
{
	ft_printf("Player %d (%s) won\n", core->prog[core->last_live].nb_name + 1,
	core->prog[core->last_live].name);
}

void	check_live_prog(t_corewar *core)
{
	size_t i;
	size_t nb;

	i = 0;
	nb = 0;
	while (i < core->nb_prog)
	{
		++i;
		if (core->prog[i - 1].daron != core->prog[i - 1].nb)
			continue;
		if (core->prog[core->prog[i - 1].daron].live == 0)
		{
			core->prog[core->prog[i - 1].daron].live = -1;
			core->prog[core->prog[i - 1].daron].tmp = -1;
		}
		if (core->prog[core->prog[i - 1].daron].live == 1)
		{
			core->prog[core->prog[i - 1].daron].live = 0;
			if (core->prog[i - 1].daron == core->prog[i - 1].nb)
				nb++;
		}
		i++;
	}
	++(core->max_check);
	core->nb_prog_live = nb;
}
