/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:39:49 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 16:23:48 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corwar.h"

int		ld(t_corewar *core, t_prog *prog)
{
	int		tab[8];
	int		tmp;
	t_data	data;

	tmp = prog->pc;
	prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
	if (tab[1] < 0 && tab[1] >= REG_NUMBER)
		return (1);
	prog->carry = 0;
	if (tab[4] == 2)
	{
		prog->reg[tab[1] % REG_NUMBER] = tab[0];
		if (!prog->reg[tab[1] % REG_NUMBER])
			prog->carry = 1;
	}
	if (tab[4] != 3)
		return (1);
	data.data[3] = core->map[modulo(tmp + tab[0] % IDX_MOD)];
	data.data[2] = core->map[modulo(tmp + (tab[0] + 1) % IDX_MOD)];
	data.data[1] = core->map[modulo(tmp + (tab[0] + 2) % IDX_MOD)];
	data.data[0] = core->map[modulo(tmp + (tab[0] + 3) % IDX_MOD)];
	if (!(prog->reg[tab[1] % REG_NUMBER] = data.nb))
		prog->carry = 1;
	return (1);
}
