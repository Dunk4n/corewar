/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_cor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:39:30 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 21:06:02 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "corwar.h"

static int	good_file(char *buff, int *size)
{
	t_data	data;

	if (*size != sizeof(t_header))
		return (0);
	data.data[0] = buff[0];
	data.data[1] = buff[1];
	data.data[2] = buff[2];
	data.data[3] = buff[3];
	if (reverse_int(data.nb) != COREWAR_EXEC_MAGIC)
		return (0);
	*size = 0;
	return (1);
}

static int	charge_head(int fd, t_prog *prog)
{
	t_data	data;
	char	buff[sizeof(t_header) + 1];
	int		size;

	size = read(fd, buff, sizeof(t_header));
	buff[size] = '\0';
	good_file(buff, &size);
	while (size < PROG_NAME_LENGTH)
	{
		prog->name[size] = buff[size + 4];
		size++;
	}
	prog->name[size] = '\0';
	data.data[0] = buff[PROG_NAME_LENGTH + 8];
	data.data[1] = buff[PROG_NAME_LENGTH + 9];
	data.data[2] = buff[PROG_NAME_LENGTH + 10];
	data.data[3] = buff[PROG_NAME_LENGTH + 11];
	prog->size = reverse_int(data.nb);
	if (prog->size > CHAMP_MAX_SIZE)
		return (0);
	return (1);
}

char		*charge_cor(char *name, t_prog *prog)
{
	char	*instr;
	int		fd;
	int		size;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (!charge_head(fd, prog) || !(instr = malloc(sizeof(char) *
	(prog->size + 1))))
	{
		close(fd);
		return (NULL);
	}
	size = read(fd, instr, prog->size + 1);
	instr[prog->size] = '\0';
	close(fd);
	if (size != (int)prog->size)
	{
		free(instr);
		return (NULL);
	}
	return (instr);
}
