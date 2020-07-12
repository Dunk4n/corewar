/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:05:24 by niduches          #+#    #+#             */
/*   Updated: 2020/07/10 13:08:07 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"

static int	good_arg(char *line, int code, int nb_arg, t_header *head)
{
	size_t	tmp;

	tmp = 0;
	if (is_reg(line))
	{
		tmp = 1;
		head->prog_size += 1;
	}
	if (is_dir(line))
	{
		tmp = 2;
		head->prog_size += g_op_tab[code].dir_size;
	}
	if (is_ind(line))
	{
		tmp = 4;
		head->prog_size += IND_SIZE;
	}
	if (tmp & g_op_tab[code].type[nb_arg])
		return (1);
	return (0);
}

int			check_arg(char *line, int code, t_header *head)
{
	size_t	nb_arg;
	size_t	i;

	nb_arg = 0;
	i = 0;
	while (nb_arg < (size_t)g_op_tab[code].nbr_args)
	{
		if (!good_arg(line + i, code, nb_arg++, head))
			return (0);
		while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] !=
				COMMENT_CHAR && line[i] != SEPARATOR_CHAR)
			i++;
		while (line[i] == ' ' || line[i] == '\t' || line[i] == SEPARATOR_CHAR)
			i++;
		if (!line[i] || line[i] == COMMENT_CHAR)
			break ;
	}
	if (nb_arg != (size_t)g_op_tab[code].nbr_args)
		return (0);
	while (line[i] == ' ' || line[i] == '\t' || line[i] == SEPARATOR_CHAR)
		i++;
	if (line[i] && line[i] != COMMENT_CHAR)
		return (0);
	return (1);
}
