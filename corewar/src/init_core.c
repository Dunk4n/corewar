/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:39:46 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 16:47:53 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "corwar.h"

void		init_core(t_corewar *core)
{
	int		index;
	int		i;

	index = 0;
	while (index < MAX_ARGS_NUMBER)
	{
		core->order[index] = NULL;
		index++;
	}
	core->order[MAX_ARGS_NUMBER] = NULL;
	i = 0;
	while (i < MAX_ARGS_NUMBER)
		core->adress[i++] = -1;
	i = 0;
	while (i < MAX_ARGS_NUMBER)
		core->number[i++] = 0;
	core->champions = -1;
	core->dump = -1;
}

static void	put_theme(char ***tmp, int **tmp_a, t_corewar *core, int index)
{
	int		i;

	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		if ((*tmp)[i] == NULL)
		{
			(*tmp)[i] = core->order[index];
			(*tmp_a)[i] = core->adress[index];
			break ;
		}
		++i;
	}
}

static void	put_tmp_in_core(t_corewar *core, char **tmp, int *tmp_a)
{
	int		i;

	i = 0;
	while (i <= MAX_ARGS_NUMBER)
	{
		if (core->number[i] == 0)
			put_theme(&tmp, &tmp_a, core, i);
		++i;
	}
	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		core->order[i] = tmp[i];
		++i;
	}
	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		core->adress[i] = tmp_a[i];
		++i;
	}
}

void		sort_name(t_corewar *core)
{
	char	*tmp[MAX_ARGS_NUMBER + 1];
	int		tmp_a[MAX_ARGS_NUMBER];
	int		i;

	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		tmp[i] = NULL;
		tmp_a[i++] = -1;
	}
	tmp[MAX_ARGS_NUMBER] = NULL;
	i = 0;
	while (i <= MAX_ARGS_NUMBER)
	{
		if (core->number[i] > 0)
		{
			tmp[core->number[i] - 1] = core->order[i];
			tmp_a[core->number[i] - 1] = core->adress[i];
		}
		++i;
	}
	put_tmp_in_core(core, tmp, tmp_a);
}
