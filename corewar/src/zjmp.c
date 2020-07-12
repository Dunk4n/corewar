/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:40:13 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 16:30:08 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corwar.h"

int		zjmp(t_corewar *core, t_prog *prog)
{
	int		tab[8];
	int		tmp;

	tmp = prog->pc;
	prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
	if (!prog->carry)
		return (1);
	prog->pc = modulo(tmp + tab[0] % IDX_MOD);
	return (1);
}
