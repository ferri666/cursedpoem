/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zalgo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:12:23 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/03/13 12:53:03 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/cursed.h"

size_t	z_strlen(const char *str)
{
	size_t	i;
	size_t	z;

	i = 0;
	z = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			z++;
		i++;
	}
	return ((z * 3) + (i - z));
}

char	*zalgo(char *str)
{
	char	*ret;
	size_t	i;
	size_t	b;
	int		r;

	ret = (char *)malloc(sizeof(char) * z_strlen(str) + 1);
	i = 0;
	b = 0;
	while (i < z_strlen(str))
	{
		ret[i] = str[b];
		i++;
		if ((str[b] >= 'a' && str[b] <= 'z') || (str[b] >= 'A' && str[b] <= 'Z'))
		{
			r = rand() % 10;
			ret[i++] = (char)-52;
			r = rand() % 10;
			ret[i++] = (char) -70 - r;
		}
		b++;
	}
	ret[i] = '\0';
	return (ret);
}
