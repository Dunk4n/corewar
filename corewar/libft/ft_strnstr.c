/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:10:24 by niduches          #+#    #+#             */
/*   Updated: 2020/07/11 21:32:40 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!needle[0])
		return ((char*)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] == needle[j] && i + j < len)
			{
				j++;
				if (!needle[j])
					return ((char*)haystack + i);
			}
		}
		i++;
	}
	return (NULL);
}

char	*ft_strstr(char const *str, char const *to_find)
{
	int		i;
	int		len;

	len = ft_strlen(to_find);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0] && ft_strncmp(&str[i], to_find, len) == 0)
			return (char*)(str + i);
		++i;
	}
	return (0);
}
