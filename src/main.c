/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:41:40 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/01/27 13:46:21 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/cursed.h"

void	show_word(t_word *word)
{
	ft_putstr_fd(ft_allupper(word->text), 1);
}

int	main(void)
{
	t_word	**words;
	int		i;
	int		rn;

	i = 0;
	srand(time(NULL));
	words = load_words();
	while (i < 50)
	{
		rn = rand() % 50;
		show_word(*(words + rn));
		if ((i + 1) % 5 == 0)
			ft_putchar_fd('\n', 1);
		else
			ft_putstr_fd(" ", 1);
		i++;
	}
	free(words);
	return (0);
}
