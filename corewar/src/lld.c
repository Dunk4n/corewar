/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:39:54 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 16:25:50 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corwar.h"

int		lld(t_corewar *core, t_prog *prog)
{
	int		tab[8];
	int		tmp;
	t_data	data;

	tmp = prog->pc;
	prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
	if ((tab[4] == 1 && tab[0] < 0 && tab[0] >= REG_NUMBER) || (tab[5] == 1 &&
	tab[1] < 0 && tab[1] >= REG_NUMBER) || (tab[2] < 0 && tab[2] >= REG_NUMBER))
		return (1);
	prog->carry = 0;
	if (tab[4] == 2)
		prog->reg[tab[1] % REG_NUMBER] = tab[0];
	if (tab[4] == 2 && !prog->reg[tab[1] % REG_NUMBER])
		prog->carry = 1;
	if (tab[4] != 3)
		return (1);
	data.data[3] = core->map[modulo(tmp + tab[0])];
	data.data[2] = core->map[modulo(tmp + tab[0] + 1)];
	data.data[1] = core->map[modulo(tmp + tab[0] + 2)];
	data.data[0] = core->map[modulo(tmp + tab[0] + 3)];
	if (!(prog->reg[tab[1] % REG_NUMBER] = data.nb))
		prog->carry = 1;
	return (1);
}
