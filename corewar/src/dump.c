/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:39:43 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 01:39:03 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "corwar.h"

static void		display_char(unsigned char c)
{
	char	to_print[3];

	to_print[0] = '0';
	to_print[1] = HEX[c % ft_strlen(HEX)];
	to_print[2] = '\0';
	if (c >= 16)
	{
		c /= ft_strlen(HEX);
		to_print[0] = HEX[c % ft_strlen(HEX)];
	}
	ft_putstr_fd(to_print, 1);
}

static void		print_beffor(int start)
{
	char	beffor[8];
	int		tmp;
	size_t	j;

	ft_strcpy(beffor, "0    : ");
	tmp = start;
	j = 0;
	if (start > 0)
	{
		while (tmp > 0)
		{
			tmp /= ft_strlen(HEX);
			++j;
		}
		--j;
		while (start > 0)
		{
			beffor[j % ft_strlen(beffor)] = HEX[start % ft_strlen(HEX)];
			start /= ft_strlen(HEX);
			--j;
		}
	}
	ft_putstr_fd(beffor, 1);
}

static void		display_line(char *map, int start)
{
	size_t	i;

	i = 0;
	print_beffor(start);
	while (i < 32)
	{
		display_char((unsigned char)map[i]);
		if (i < 31)
			ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

void			dump(char *map)
{
	size_t	i;

	i = 0;
	while (i < MEM_SIZE / 32)
	{
		display_line(map + 32 * i, 32 * i);
		i++;
	}
}
