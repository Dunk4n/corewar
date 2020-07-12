/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:39:48 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 16:30:40 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corwar.h"

int		kill(t_corewar *core, t_prog *prog)
{
	int	tab[8];

	prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
	if (tab[0] < 0 || tab[0] >= (int)core->nb_prog)
		return (1);
	if (core->prog[core->prog[tab[0] % core->nb_prog].daron %
	core->nb_prog].live == -1)
		return (1);
	core->prog[core->prog[tab[0] % core->nb_prog].daron %
		core->nb_prog].live = -1;
	core->prog[core->prog[tab[0] % core->nb_prog].daron %
		core->nb_prog].tmp = -1;
	return (1);
}
