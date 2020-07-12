/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:01:51 by niduches          #+#    #+#             */
/*   Updated: 2020/07/10 15:29:35 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"

int			good_name(char c)
{
	size_t	i;
	char	*str;

	str = LABEL_CHARS;
	i = 0;
	if (!c)
		return (0);
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static int	get_indice_instruction(char *line, t_header *head)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (good_name(line[len]))
		len++;
	while (g_op_tab[i].mnemonique)
	{
		if (!ft_strncmp(g_op_tab[i].mnemonique, line, len) && len ==
		ft_strlen(g_op_tab[i].mnemonique))
		{
			head->prog_size += 1 + g_op_tab[i].oct_parametre;
			return (i);
		}
		i++;
	}
	return (-1);
}

int			is_an_instruction(char *line, t_header *head)
{
	size_t	i;
	int		code;

	i = 0;
	while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] !=
	LABEL_CHAR)
	{
		if (!good_name(line[i]))
			return (-1);
		i++;
	}
	if (i > 0 && line[i] == LABEL_CHAR && (line[i + 1] == ' ' ||
				line[i + 1] == '\t' || !line[i + 1]))
		return (0);
	if ((code = get_indice_instruction(line, head)) == -1)
		return (-1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (!check_arg(line + i, code, head))
		return (-1);
	return (1);
}

int			bad_instruction(char *line, t_compil *compil, size_t nb)
{
	size_t	i;
	int		tmp;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == SEPARATOR_CHAR)
		i++;
	if (!line[i] || line[i] == COMMENT_CHAR)
		return (0);
	tmp = is_an_instruction(line + i, &(compil->head));
	if ((tmp == 0 && !is_label(line, compil)) || tmp == -1)
		return (error(line, nb, "bad instruction") + 1);
	return (0);
}
