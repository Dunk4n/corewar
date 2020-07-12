/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:39:43 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 16:32:11 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "corwar.h"

int				get_nb(t_corewar *core)
{
	size_t	i;
	int		tmp;

	i = 0;
	tmp = -1;
	while (i < core->nb_prog)
	{
		if ((int)core->prog[i].nb > tmp)
			tmp = core->prog[i].nb;
		++i;
	}
	return (tmp + 1);
}

static void		copy_prog(int *tab, t_prog *a, t_prog *b)
{
	size_t i;

	i = 1;
	a->daron = b->daron;
	a->size = b->size;
	a->nb_name = b->nb_name;
	a->start = modulo((int)b->start + tab[0] % IDX_MOD);
	a->tmp = 1;
	a->carry = b->carry;
	a->live = 0;
	a->to_exc = -1;
	ft_strcpy(a->name, b->name);
	a->reg[0] = a->nb;
	while (i < REG_NUMBER)
		a->reg[i++] = 0;
}

int				my_fork(t_corewar *core, t_prog *prog)
{
	int		tab[8];
	int		ind;
	int		tmp;

	ind = prog->nb;
	tmp = prog->pc;
	prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
	core->prog = realloc(core->prog, sizeof(t_prog) * (core->nb_prog + 1));
	if (!core->prog)
		return (0);
	core->prog[core->nb_prog].nb = get_nb(core);
	core->prog[core->nb_prog].pc = modulo(tmp + tab[0] % IDX_MOD);
	core->nb_prog++;
	copy_prog(tab, &(core->prog[core->nb_prog - 1]), &(core->prog[ind]));
	return (1);
}
