/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:41:08 by niduches          #+#    #+#             */
/*   Updated: 2020/07/10 13:43:54 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"

int			get_indice(char *line, size_t len)
{
	size_t	i;

	i = 0;
	while (g_op_tab[i].mnemonique)
	{
		if (!ft_strncmp(g_op_tab[i].mnemonique, line, len) && len ==
				ft_strlen(g_op_tab[i].mnemonique))
			return (i);
		i++;
	}
	return (-1);
}

static int	is_instru(char *line)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == SEPARATOR_CHAR)
		i++;
	if (!line[i] || line[i] == COMMENT_CHAR)
		return (0);
	while (good_name(line[i + j]))
		j++;
	if (line[i + j] == LABEL_CHAR)
		return (is_instru(line + i + j + 1));
	if ((get_indice(line + i, j)) == -1)
		return (0);
	return (1);
}

static void	init_compil(t_compil *compil)
{
	size_t	i;

	i = 0;
	compil->instr = malloc(sizeof(char) * (compil->prog_size + 1));
	if (!compil->instr)
		return ;
	compil->pos = 0;
	while (i <= compil->prog_size)
		compil->instr[i++] = '\0';
}

void		free_compil(t_compil *compil)
{
	size_t	j;

	j = 0;
	while (j < compil->nb_label)
	{
		free(compil->label[j].name);
		j++;
	}
	free(compil->label);
}

int			write_instruction(t_compil *compil, int fd)
{
	size_t	i;

	i = 0;
	init_compil(compil);
	if (!compil)
		return (0);
	while (compil->file[i])
	{
		if (is_instru(compil->file[i]))
			compile_instruction(compil, compil->file[i]);
		free(compil->file[i]);
		i++;
	}
	free_compil(compil);
	free(compil->file);
	write(fd, compil->instr, compil->pos);
	free(compil->instr);
	close(fd);
	return (1);
}
