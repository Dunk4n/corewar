/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:40:08 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 16:28:48 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corwar.h"

int		st(t_corewar *core, t_prog *prog)
{
	int		tab[8];
	int		tmp;
	t_data	data;

	tmp = prog->pc;
	prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
	if (tab[5] == 1)
		prog->reg[tab[1] % REG_NUMBER] = prog->reg[tab[0] % REG_NUMBER];
	if (tab[5] != 3)
		return (1);
	data.nb = prog->reg[tab[0] % REG_NUMBER];
	tab[1] %= IDX_MOD;
	core->map[modulo(tmp + tab[1])] = data.data[3];
	core->map[modulo(tmp + tab[1] + 1)] = data.data[2];
	core->map[modulo(tmp + tab[1] + 2)] = data.data[1];
	core->map[modulo(tmp + tab[1] + 3)] = data.data[0];
	core->who[modulo(tmp + tab[1])] = prog->nb;
	core->who[modulo(tmp + tab[1] + 1)] = prog->nb;
	core->who[modulo(tmp + tab[1] + 2)] = prog->nb;
	core->who[modulo(tmp + tab[1] + 3)] = prog->nb;
	return (1);
}
