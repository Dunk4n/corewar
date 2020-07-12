/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_getnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:28:01 by niduches          #+#    #+#             */
/*   Updated: 2020/07/10 13:28:45 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_getnbr_long(char const *str)
{
	int			i;
	long long	nb;
	int			neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (str[i] != '\0' && (str[i] <= 32 || str[i] == 43 || str[i] == 45))
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	return (nb * neg);
}
