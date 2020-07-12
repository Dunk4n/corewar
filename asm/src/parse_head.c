/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:30:41 by niduches          #+#    #+#             */
/*   Updated: 2020/07/10 15:31:41 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "asm.h"

void	free_file(char **file, int fd)
{
	size_t	i;

	i = 0;
	if (!file)
		return ;
	while (file[i])
	{
		free(file[i]);
		i++;
	}
	free(file);
	close(fd);
}

int		little_endian(int nb)
{
	int tab[4];

	tab[0] = (nb & 0x000000ff) << 24;
	tab[1] = (nb & 0x0000ff00) << 8;
	tab[2] = (nb & 0x00ff0000) >> 8;
	tab[3] = (nb & 0xff000000) >> 24;
	return (tab[0] | tab[1] | tab[2] | tab[3]);
}

int		error_file(char **file, t_compil *compil, int *head_or_comment, int fd)
{
	if (*head_or_comment >= 0)
		*head_or_comment = check_label(file, compil);
	if (*head_or_comment < 0)
	{
		free_file(file, fd);
		return (0);
	}
	return (1);
}

char	**parse_head(char const *name, t_compil *compil)
{
	int		fd;
	int		head_or_comment;
	char	**file;

	ft_bzero(&compil->head, sizeof(t_header));
	head_or_comment = -2;
	compil->label = NULL;
	compil->nb_label = 0;
	if ((fd = open(name, O_RDONLY)) == -1)
	{
		error(NULL, 0, "failed to open file\n");
		return (NULL);
	}
	compil->head.magic = little_endian(COREWAR_EXEC_MAGIC);
	if (!(file = get_file(fd, 0, compil, &head_or_comment)))
	{
		close(fd);
		return (NULL);
	}
	if (!error_file(file, compil, &head_or_comment, fd))
		return (NULL);
	close(fd);
	return (file);
}
