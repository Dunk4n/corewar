/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:39:50 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 16:25:10 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corwar.h"

int		ldi(t_corewar *core, t_prog *prog)
{
	int		tab[8];
	int		tmp;
	int		s;
	t_data	data;

	tmp = prog->pc;
	tmp = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
	if ((tab[4] == 1 && tab[0] < 0 && tab[0] >= REG_NUMBER) || (tab[5] == 1 &&
	tab[1] < 0 && tab[1] >= REG_NUMBER) || (tab[2] < 0 && tab[2] >= REG_NUMBER))
		return (1);
	prog->carry = 0;
	s = (get_value_arg(core, prog, tab[0], tab[4]) +
			get_value_arg(core, prog, tab[1], tab[5])) % IDX_MOD;
	data.data[3] = core->map[modulo(prog->pc + s)];
	data.data[2] = core->map[modulo(prog->pc + s + 1)];
	data.data[1] = core->map[modulo(prog->pc + s + 2)];
	data.data[0] = core->map[modulo(prog->pc + s + 3)];
	prog->reg[tab[2] % REG_NUMBER] = data.nb;
	prog->pc = tmp;
	if (!prog->reg[tab[2] % REG_NUMBER])
		prog->carry = 1;
	return (1);
}
