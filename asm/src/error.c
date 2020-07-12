/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:13:24 by niduches          #+#    #+#             */
/*   Updated: 2020/07/10 13:15:35 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_putchar_err(char c)
{
	write(2, &c, 1);
	return (1);
}

static void	ft_putstr_err(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar_err(s[i++]);
}

static int	ft_put_nbr_err(int nb)
{
	int n;

	n = (nb < 0) ? ft_putchar_err('-') : 0;
	if (nb > 9 || nb < -9)
	{
		n += ft_put_nbr_err((nb < 0) ? (-(nb / 10)) : (nb / 10));
		n += ft_putchar_err(((nb < 0) ? (-(nb % 10)) : (nb % 10)) + '0');
		return (n);
	}
	n += ft_putchar_err(((nb < 0) ? (-nb) : nb) + '0');
	return (n);
}

static void	norm(char *err_msg)
{
	ft_putstr_err(ANSI_COLOR_RED);
	ft_putstr_err("asm : ");
	ft_putstr_err(ANSI_COLOR_MAGENTA);
	ft_putstr_err(err_msg);
	ft_putstr_err(ANSI_COLOR_RESET);
}

int			error(char *line, size_t nb, char *err_msg)
{
	if (!ft_strcmp("failed to open file\n", err_msg))
	{
		norm(err_msg);
		return (0);
	}
	ft_putstr_err(ANSI_COLOR_RED);
	ft_putstr_err(err_msg);
	ft_putstr_err(ANSI_COLOR_RESET);
	if (!line)
		return (0);
	ft_putstr_err(ANSI_COLOR_CYAN);
	ft_putstr_err(" line ");
	ft_put_nbr_err(nb + 1);
	ft_putstr_err(ANSI_COLOR_RESET);
	ft_putstr_err(": ");
	ft_putstr_err(ANSI_COLOR_MAGENTA);
	ft_putstr_err(line);
	ft_putstr_err(ANSI_COLOR_RESET);
	ft_putstr_err("\n");
	return (0);
}
