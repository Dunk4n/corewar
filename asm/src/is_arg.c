/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:22:45 by niduches          #+#    #+#             */
/*   Updated: 2020/07/10 13:24:39 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	is_label_arg(char *line)
{
	size_t	i;

	i = 0;
	if (!line[i])
		return (0);
	while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] !=
COMMENT_CHAR && line[i] != SEPARATOR_CHAR)
	{
		if (!good_name(line[i]))
			return (0);
		i++;
	}
	return (2);
}

int			is_reg(char *line)
{
	size_t	i;

	i = 0;
	if (line[i++] != 'r' || ft_getnbr(line + 1) <= 0 || ft_getnbr(line + 1) >
REG_NUMBER)
		return (0);
	while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] !=
COMMENT_CHAR && line[i] != SEPARATOR_CHAR)
	{
		if (line[i] < '0' || line[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int			is_ind(char *line)
{
	size_t	i;

	i = 0;
	if (line[0] == LABEL_CHAR)
		return (is_label_arg(line + 1));
	if (line[i] == '-')
		i++;
	while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] !=
COMMENT_CHAR && line[i] != SEPARATOR_CHAR)
	{
		if (line[i] < '0' || line[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int			is_dir(char *line)
{
	size_t	i;

	i = 0;
	if (line[i++] != DIRECT_CHAR)
		return (0);
	if (line[i] == LABEL_CHAR)
		return (is_label_arg(line + i + 1));
	if (line[i] == '-')
		i++;
	while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] !=
COMMENT_CHAR && line[i] != SEPARATOR_CHAR)
	{
		if (line[i] < '0' || line[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
