/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:08:24 by niduches          #+#    #+#             */
/*   Updated: 2020/07/10 13:10:25 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"

static int	is_good_label(char *line, t_compil *compil)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (good_name(line[len]))
		len++;
	while (i < compil->nb_label)
	{
		if (!ft_strncmp(line, compil->label[i].name, len) &&
		len == ft_strlen(compil->label[i].name))
			return (1);
		i++;
	}
	return (0);
}

int			check_label(char **file, t_compil *compil)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j] && file[i][j] != COMMENT_CHAR &&
		file[i][j] != LABEL_CHAR)
			j++;
		if (file[i][j] == LABEL_CHAR && good_name(file[i][j + 1]) &&
		!is_good_label(file[i] + j + 1, compil))
		{
			error(file[i], i, "Undefined label :");
			return (-1);
		}
		i++;
	}
	return (1);
}
