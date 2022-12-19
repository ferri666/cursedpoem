/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:03:18 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/11/03 10:43:39 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tst;
	size_t	i;

	tst = malloc (size * count);
	if (!tst)
		return (0);
	i = 0;
	while (i < size * count)
	{
		*(unsigned char *)(tst + i) = 0;
		i++;
	}
	return (tst);
}

char	*ft_strchr(char *str, char to_find)
{
	size_t	n;

	n = 0;
	while (n < ft_strlen(str)+1)
	{
		if (str[n] == to_find)
		{
			return (&str[n]);
		}
		n++;
	}
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
	return (res);
}
