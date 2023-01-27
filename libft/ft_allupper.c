/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:09:11 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/01/27 13:30:50 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_allupper(char *s)
{
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s);
	i = 0;
	while (i < slen)
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}