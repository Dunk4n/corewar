/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:40:07 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 16:28:06 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "corwar.h"

int		my_rand(t_corewar *core, t_prog *prog)
{
	int		tab[8];

	prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
	if (tab[0] < 0 || tab[0] >= REG_NUMBER ||
	tab[1] < 0 || tab[1] >= REG_NUMBER)
		return (1);
	prog->reg[tab[1] % REG_NUMBER] = rand();
	return (1);
}
