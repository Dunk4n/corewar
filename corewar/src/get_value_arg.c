/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:39:45 by niduches          #+#    #+#             */
/*   Updated: 2020/07/11 21:05:21 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corwar.h"

int		get_value_arg_long(t_corewar *core, t_prog *prog, int value, int type)
{
	t_data	data;

	if (type == 3)
		return (value);
	if (type == 1)
		return (prog->reg[value % REG_NUMBER]);
	if (type != 2)
		return (0);
	data.data[3] = core->map[(prog->pc + value) % MEM_SIZE];
	data.data[2] = core->map[(prog->pc + value + 1) % MEM_SIZE];
	data.data[1] = core->map[(prog->pc + value + 2) % MEM_SIZE];
	data.data[0] = core->map[(prog->pc + value + 3) % MEM_SIZE];
	return (data.nb);
}

int		get_value_arg(t_corewar *core, t_prog *prog, int value, int type)
{
	t_data	data;

	if (type == 2)
		return (value);
	if (type == 1)
		return (prog->reg[value % REG_NUMBER]);
	if (type != 3)
		return (0);
	value %= IDX_MOD;
	data.data[3] = core->map[(prog->pc + value) % MEM_SIZE];
	data.data[2] = core->map[(prog->pc + value + 1) % MEM_SIZE];
	data.data[1] = core->map[(prog->pc + value + 2) % MEM_SIZE];
	data.data[0] = core->map[(prog->pc + value + 3) % MEM_SIZE];
	return (data.nb);
}
