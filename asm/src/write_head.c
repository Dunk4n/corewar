/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:36:15 by niduches          #+#    #+#             */
/*   Updated: 2020/07/10 13:40:52 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "asm.h"

char	*new_name(const char *name)
{
	char	*new_name;
	size_t	len;
	size_t	size_malloc;
	size_t	i;

	len = ft_strlen(name);
	size_malloc = len + 4;
	if (len > 2 && name[len - 1] == 's' && name[len - 2] == '.')
	{
		size_malloc = len + 2;
		len -= 2;
	}
	if (!(new_name = malloc(sizeof(char) * (size_malloc + 1))))
		return (NULL);
	new_name[size_malloc] = '\0';
	i = 0;
	while (i < len)
	{
		new_name[i] = name[i];
		++i;
	}
	ft_strcpy(new_name + i, ".cor");
	return (new_name);
}

int		open_file(const char *old_name)
{
	int		fd;
	char	*name;

	name = new_name(old_name);
	if (!name)
		return (-1);
	if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC,
S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	{
		free(name);
		return (-1);
	}
	free(name);
	return (fd);
}

int		write_head(t_compil *compil, t_header *head, const char *name, int *fd)
{
	int	tmp;

	tmp = head->prog_size;
	compil->prog_size = tmp;
	*fd = open_file(name);
	if (*fd == -1)
		return (0);
	head->prog_size = little_endian(head->prog_size);
	write(*fd, head, sizeof(t_header));
	head->prog_size = tmp;
	return (1);
}
