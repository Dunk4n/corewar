/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:39:57 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 21:12:19 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "corwar.h"

int		flag_h(char *nam)
{
	ft_putstr_fd("USAGE\n", 1);
	ft_printf("\t%s [-dump nbr_cycle] [[-n prog_number] [-a load_adress]", nam);
	ft_putstr_fd(" prog_name] ...\n\n", 1);
	ft_putstr_fd("DESCRIPTION\n", 1);
	ft_putstr_fd("\t-dump nbr_cycle dumps the memory after the nbr_cycle \
	executio", 1);
	ft_putstr_fd(
	"n (if the round isn't\n\t\t\talready over) with the following", 1);
	ft_putstr_fd(
	" format: 32 bytes/line in\n\t\t\thexadecimal (AOBCDEFE1DD3...)", 1);
	ft_putstr_fd("\n\t-n prog_number  sets the next program's number. By \
	default,", 1);
	ft_putstr_fd(" the first free number\n\t\t\tin the parameter order\n", 1);
	ft_putstr_fd(
	"\t-a load_adress  sets the next program's loading adress. When", 1);
	ft_putstr_fd(" no adress is\n\t\t\tspecified, optimize the addresses so \
	that ", 1);
	ft_putstr_fd("the processes are as far\n\t\t\taway from each other as", 1);
	ft_putstr_fd(" possible. The addresses are MEM_SIZE modulo\n", 1);
	return (0);
}

void	set_value(t_corewar *core)
{
	core->cycle_to_die = CYCLE_TO_DIE;
	core->nb_live = 0;
	core->nb_prog_live = core->nb_prog;
	core->max_check = 0;
	core->last_live = core->nb_prog - 1;
}

int		malloc_start(t_corewar *core, char ***instr)
{
	size_t	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		core->map[i] = 0;
		core->who[i++] = -1;
	}
	if (!(*instr = charge_all_cor(core->order, core->nb_prog, &(core->prog))))
		return (0);
	return (1);
}

void	free_order(t_corewar *core)
{
	int		i;

	i = 0;
	while (i <= MAX_ARGS_NUMBER)
		free(core->order[i++]);
}

int		main(int ac, char **av)
{
	t_corewar	core;
	char		**instr;

	if (ac == 2 && !ft_strcmp(av[1], "-h"))
		return (flag_h(av[1]));
	if (!parsing(ac, av, &core))
	{
		free_order(&core);
		return (0);
	}
	if (!malloc_start(&core, &instr))
	{
		free_order(&core);
		return (0);
	}
	set_value(&core);
	if (!put_prog(&core, instr))
	{
		free_order(&core);
		return (0);
	}
	corewar(&core);
	free(core.prog);
	free_order(&core);
	return (0);
}
