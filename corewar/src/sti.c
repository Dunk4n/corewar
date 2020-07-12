/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:40:09 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 16:29:03 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corwar.h"

int		sti(t_corewar *core, t_prog *prog)
{
	int		tab[8];
	int		tmp;
	int		s;
	t_data	data;

	tmp = prog->pc;
	s = 0;
	tmp = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
	s = (get_value_arg(core, prog, tab[1], tab[5]) +
	get_value_arg(core, prog, tab[2], tab[6])) % IDX_MOD;
	data.nb = prog->reg[tab[0] % REG_NUMBER];
	core->map[modulo(prog->pc + s)] = data.data[3];
	core->map[modulo(prog->pc + s + 1)] = data.data[2];
	core->map[modulo(prog->pc + s + 2)] = data.data[1];
	core->map[modulo(prog->pc + s + 3)] = data.data[0];
	core->who[modulo(prog->pc + s)] = prog->nb;
	core->who[modulo(prog->pc + s + 1)] = prog->nb;
	core->who[modulo(prog->pc + s + 2)] = prog->nb;
	core->who[modulo(prog->pc + s + 3)] = prog->nb;
	prog->pc = tmp;
	return (1);
}
