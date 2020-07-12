/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:39:53 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 16:24:50 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corwar.h"

int		live(t_corewar *core, t_prog *prog)
{
	int	tab[8];

	prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
	if (tab[0] < 0 || tab[0] >= (int)core->nb_prog)
		return (1);
	if (core->prog[core->prog[tab[0] % core->nb_prog].daron %
	core->nb_prog].live == -1)
		return (1);
	core->prog[core->prog[tab[0] % core->nb_prog].daron %
	core->nb_prog].live = 1;
	ft_printf("A process shows that player %d (%s) is alive\n",
	core->prog[tab[0] % core->nb_prog].nb_name + 1,
	core->prog[core->prog[tab[0] % core->nb_prog].daron % core->nb_prog].name);
	core->nb_live++;
	core->last_live = core->prog[tab[0] % core->nb_prog].daron % core->nb_prog;
	return (1);
}
