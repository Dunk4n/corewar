/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_all_cor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:39:21 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 01:52:04 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "corwar.h"

static void	*free_all_cor(char **instr, t_prog *progs, size_t nb)
{
	free(progs);
	if (!instr)
		return (NULL);
	while (nb-- > 0)
		free(instr[nb]);
	free(instr);
	return (NULL);
}

void		set_reg(t_prog *prog)
{
	size_t	i;

	i = 1;
	prog->tmp = 0;
	prog->live = 0;
	prog->to_exc = -1;
	prog->carry = 0;
	prog->reg[0] = prog->nb;
	while (i < REG_NUMBER)
	{
		prog->reg[i] = 0;
		i++;
	}
}

static void	set_value_core(size_t nb, t_prog **progs, size_t size, size_t i)
{
	(*progs)[nb].nb = nb;
	(*progs)[nb].nb_name = i;
	(*progs)[nb].daron = nb;
	(*progs)[nb].pc = (int)nb * MEM_SIZE / size;
	(*progs)[nb].start = (*progs)[nb].pc;
	set_reg(&((*progs)[nb]));
}

char		**charge_all_cor(char **name, size_t size, t_prog **progs)
{
	size_t	i;
	size_t	nb;
	char	**instr;

	i = 0;
	if (!(*progs = malloc(sizeof(t_prog) * size)))
		return (NULL);
	if (!(instr = malloc(sizeof(char*) * (size + 1))))
	{
		free(*progs);
		return (NULL);
	}
	instr[size] = NULL;
	nb = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		i++;
		if (!name[i - 1])
			continue;
		if (!(instr[nb] = charge_cor(name[i - 1], &((*progs)[nb]))))
			return (free_all_cor(instr, *progs, nb));
		set_value_core(nb++, progs, size, i - 1);
	}
	return (instr);
}
