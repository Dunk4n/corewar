/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:39:39 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 17:26:06 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "corwar.h"

int				(*const g_instruction[])(t_corewar *core, t_prog *prog) =
{
	live, ld, st, add, sub, and, or, xor, zjmp, ldi, sti, my_fork, lld, lldi,
	lfork, aff, not, rsht, lsht, mul, my_div, mod, my_rand, die, kill, stop
};

static int		make_one_prog(t_corewar *core, int ind)
{
	if (core->prog[ind].tmp == 0)
	{
		if (core->prog[ind].to_exc >= 0 && core->prog[ind].to_exc < NB_INSTR)
		{
			if (!g_instruction[core->prog[ind].to_exc](core,
			&(core->prog[ind])))
				return (0);
			core->prog[ind].to_exc = -1;
		}
		else
		{
			core->prog[ind].to_exc = (int)core->map[core->prog[ind].pc] - 1;
			core->prog[ind].tmp =
			g_op_tab[core->prog[ind].to_exc].nbr_cycles - 1;
		}
	}
	if (core->prog[ind].tmp > 0)
		core->prog[ind].tmp--;
	return (1);
}

static int		all_prog(t_corewar *core)
{
	int i;

	i = core->nb_prog;
	while (i > 0)
	{
		--i;
		if (core->prog[i].live >= 0 && !make_one_prog(core, i))
			return (0);
	}
	return (1);
}

static int		corewar_turn(t_corewar *core, int *to_die)
{
	if (!all_prog(core))
		return (0);
	if (*to_die >= core->cycle_to_die)
	{
		check_live_prog(core);
		*to_die = 0;
	}
	if (core->nb_live >= NBR_LIVE)
	{
		core->max_check = 0;
		core->cycle_to_die -= CYCLE_DELTA * (core->nb_live / NBR_LIVE);
		core->nb_live -= NBR_LIVE * (core->nb_live / NBR_LIVE);
	}
	if (core->max_check >= MAX_CHECKS)
		--(core->cycle_to_die);
	return (1);
}

int				corewar(t_corewar *core)
{
	size_t	i;
	int		to_die;

	i = 0;
	to_die = 0;
	while (core->nb_prog_live > 0 &&
	core->cycle_to_die > 1 && (core->dump == -1 || (int)i < core->dump))
	{
		if (!corewar_turn(core, &to_die))
			return (0);
		to_die++;
		i++;
	}
	if (core->dump != -2)
		win(core);
	if (core->dump >= 0)
		dump(core->map);
	return (1);
}
