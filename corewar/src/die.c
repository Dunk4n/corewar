/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:39:40 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 16:22:31 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corwar.h"

int		die(t_corewar *core, t_prog *prog)
{
	int		tab[8];

	prog->pc = (prog->pc + get_arg(core->map, prog->pc, tab) + 1) % MEM_SIZE;
	prog->live = -1;
	prog->tmp = -1;
	return (1);
}
