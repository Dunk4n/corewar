/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:39:44 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 13:24:31 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corwar.h"

static int		get_int(char *map, int pc)
{
	t_data	data;

	data.data[0] = map[pc];
	data.data[1] = map[pc + 1];
	data.data[2] = map[pc + 2];
	data.data[3] = map[pc + 3];
	return (reverse_int(data.nb));
}

static int		get_short(char *map, int pc)
{
	t_short	data;

	data.data[0] = map[pc];
	data.data[1] = map[pc + 1];
	return ((short)reverse_short(data.nb));
}

static int		get_one_param(char *map, int pc, int *tab, char *instr)
{
	if (instr[1] == 1)
	{
		*tab = (int)map[pc] - 1;
		return (1);
	}
	if (instr[1] == 3 ||
	(instr[1] == 2 && g_op_tab[(int)instr[0]].dir_size == 2))
	{
		*tab = get_short(map, pc);
		return (2);
	}
	if (instr[1] == 2)
	{
		*tab = get_int(map, pc);
		return (4);
	}
	return (0);
}

static int		get_arg_first(char *instr, char *map, int pc, int *tab)
{
	instr[1] = (g_op_tab[(int)instr[0]].type[0] == 4) ? 3 :
	g_op_tab[(int)instr[0]].type[0];
	return (get_one_param(map, pc, tab, instr));
}

int				get_arg(char *map, int pc, int *tab)
{
	char	instr[2];
	char	param;
	size_t	i;
	size_t	pool;

	instr[0] = map[pc++ % MEM_SIZE] - 1;
	instr[1] = 0;
	param = 0;
	i = 0;
	pool = 1;
	if (g_op_tab[(int)instr[0]].nbr_args > 4)
		return (0);
	if ((int)g_op_tab[(int)instr[0]].oct_parametre)
		param = map[pc % MEM_SIZE];
	else
		return (get_arg_first(instr, map, pc, tab));
	while (i < 4 && i < (size_t)g_op_tab[(int)instr[0]].nbr_args)
	{
		instr[1] = (param & (3 << 2 * (3 - (i % 4)))) >> 2 * (3 - (i % 4));
		tab[i + 4] = instr[1];
		pool += get_one_param(map, pc + pool, &(tab[i]), instr);
		i++;
	}
	return (pool);
}
