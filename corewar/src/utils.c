/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:49:17 by niduches          #+#    #+#             */
/*   Updated: 2020/07/12 21:09:11 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corwar.h"

int		reverse_int(int n)
{
	return ((unsigned int)(((n & 0xFF) << 24) |
((n & 0xFF00) << 8) | ((n & 0xFF0000) >> 8) | ((n & 0xFF000000) >> 24)));
}

short	reverse_short(short n)
{
	return ((unsigned short)(((n & 0xFF) << 8) | ((n & 0xFF00) >> 8)));
}

int		modulo(int x)
{
	return ((x < 0) ? ((x) % MEM_SIZE + MEM_SIZE) % MEM_SIZE : (x) % MEM_SIZE);
}
