/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:38:53 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 16:22:44 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corwar.h"

int		and(t_corewar *core, t_prog *prog)
{
	int	tab[8];

	prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
	if ((tab[4] == 1 && (tab[0] < 0 || tab[0] >= REG_NUMBER)) || (tab[5] == 1 &&
	(tab[1] < 0 || tab[1] >= REG_NUMBER)) || tab[2] < 0 || tab[2] >= REG_NUMBER)
		return (1);
	prog->carry = 0;
	prog->reg[tab[2] % REG_NUMBER] = get_value_arg(core, prog, tab[0], tab[4]) &
	get_value_arg(core, prog, tab[1], tab[5]);
	if (!prog->reg[tab[2] % REG_NUMBER])
		prog->carry = 1;
	return (1);
}
