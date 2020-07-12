/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:39:47 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 14:07:07 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corwar.h"

int			is_number(char *str)
{
	int		nb;
	char	*tmp;

	if (!str)
		return (0);
	tmp = str;
	while (*tmp)
	{
		if (*tmp < '0' || *tmp > '9')
			return (0);
		++tmp;
	}
	nb = ft_atoi(str);
	if (nb <= 0 || nb > MAX_ARGS_NUMBER)
		return (0);
	return (1);
}
