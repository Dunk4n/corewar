/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:10:41 by niduches          #+#    #+#             */
/*   Updated: 2020/07/10 13:13:05 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"

static int	get_code(t_compil *compil, char **line)
{
	size_t	i;
	int		code;

	i = 0;
	while (**line == ' ' || **line == '\t' || **line == SEPARATOR_CHAR)
		(*line)++;
	while (good_name((*line)[i]))
		i++;
	if ((*line)[i] == LABEL_CHAR)
		(*line) += i + 1;
	while (**line == ' ' || **line == '\t' || **line == SEPARATOR_CHAR)
		(*line)++;
	i = 0;
	while (good_name((*line)[i]))
		i++;
	code = get_indice(*line, i);
	compil->instr[compil->pos++] = code + 1;
	*line += i;
	while (**line == ' ' || **line == '\t' || **line == SEPARATOR_CHAR)
		(*line)++;
	return (code);
}

static int	set_byte_parameter(t_compil *compil, char *line, size_t i)
{
	char	tmp;

	tmp = 0;
	if (is_reg(line))
		tmp = 1;
	if (is_dir(line))
		tmp = 2;
	if (is_ind(line))
		tmp = 3;
	if (!tmp)
		return (0);
	tmp = tmp << 2 * (3 - (i % 4));
	compil->instr[compil->pos + i / 4] += tmp;
	return (1);
}

static void	parameter_byte(t_compil *compil, char *line)
{
	size_t	i;

	i = 0;
	while (*line && i < MAX_ARGS_NUMBER)
	{
		if (!set_byte_parameter(compil, line, i++))
		{
			compil->pos += 1;
			return ;
		}
		while (*line && *line != ' ' && *line != '\t' &&
				*line != SEPARATOR_CHAR)
			line++;
		while (*line == ' ' || *line == '\t' || *line == SEPARATOR_CHAR)
			line++;
		if (*line == COMMENT_CHAR)
		{
			compil->pos += 1;
			return ;
		}
	}
	compil->pos += 1;
}

void		compile_instruction(t_compil *compil, char *line)
{
	int		code;
	size_t	pos;

	pos = compil->pos;
	code = get_code(compil, &line);
	if (g_op_tab[code].oct_parametre)
		parameter_byte(compil, line);
	set_parameter(compil, line, code, pos);
}
