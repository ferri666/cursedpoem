/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:41:40 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/01/27 13:18:48 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/cursed.h"

void	show_word(t_word *word)
{
	ft_putendl_fd(word->text, 1);
}

int	main(void)
{
	t_word	**words;
	int		i;

	i = 0;
	words = load_words();
	while (i < 50)
	{
		show_word(*(words + i));
		i++;
	}
	free(words);
	return (0);
}
