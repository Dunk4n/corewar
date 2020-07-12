/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:40:06 by niduches          #+#    #+#             */
/*   Updated: 2020/07/11 21:45:31 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "corwar.h"

int		put_prog(t_corewar *core, char **instr)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (instr[i])
	{
		j = 0;
		if (core->adress[i] != -1)
			core->prog[i].pc = core->adress[i];
		while (j < core->prog[i].size)
		{
			if (core->who[(core->prog[i].pc + j) % MEM_SIZE] != -1)
			{
				write(2, "overlap detected\n", 17);
				return (0);
			}
			core->map[(core->prog[i].pc + j) % MEM_SIZE] = instr[i][j];
			core->who[(core->prog[i].pc + j) % MEM_SIZE] = core->prog[i].nb;
			j++;
		}
		free(instr[i]);
		i++;
	}
	free(instr);
	return (1);
}
