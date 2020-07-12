/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:39:51 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 16:32:03 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "corwar.h"

static void	long_copy_prog(int *tab, t_prog *a, t_prog *b)
{
	size_t	i;

	i = 1;
	a->daron = b->daron;
	a->size = b->size;
	a->start = modulo((int)b->start + tab[0]);
	a->tmp = 0;
	a->carry = b->carry;
	a->live = 0;
	a->to_exc = -1;
	ft_strcpy(a->name, b->name);
	a->reg[0] = a->nb;
	while (i < REG_NUMBER)
		a->reg[i++] = 0;
}

int			lfork(t_corewar *core, t_prog *prog)
{
	int		tab[8];
	int		ind;

	ind = prog->nb;
	prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
	core->prog = realloc(core->prog, sizeof(t_prog) * (core->nb_prog + 1));
	if (!core->prog)
		return (0);
	core->prog[core->nb_prog].nb = get_nb(core);
	core->prog[core->nb_prog].pc = modulo(core->prog[ind].pc + tab[0]);
	core->nb_prog++;
	long_copy_prog(tab, &(core->prog[core->nb_prog - 1]),
	&(core->prog[ind]));
	return (1);
}
