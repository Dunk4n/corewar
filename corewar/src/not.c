/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:40:01 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 16:27:28 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corwar.h"

int		not(t_corewar *core, t_prog *prog)
{
	int		tab[8];

	prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
	if ((tab[4] == 1 && (tab[0] < 0 || tab[0] >= REG_NUMBER)) ||
	tab[1] < 0 || tab[1] >= REG_NUMBER)
		return (1);
	prog->carry = 0;
	prog->reg[tab[1] % REG_NUMBER] = ~get_value_arg(core, prog, tab[0], tab[4]);
	if (!prog->reg[tab[1] % REG_NUMBER])
		prog->carry = 1;
	return (1);
}
