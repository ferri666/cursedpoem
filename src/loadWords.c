/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadWords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:48:01 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/11/28 19:26:04 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/cursed.h"

t_word	*new_word(char *word, char g, char t)
{
	t_word	*n_word;

	n_word = (t_word *)malloc(sizeof(t_word));
	n_word->text = word;
	n_word->gender = g;
	n_word->type = t;
	return (n_word);
}

t_word	*load_words(void)
{
	t_word	**list_words;
	char	*line;
	size_t	i;
	int		fd;

	list_words = (t_word **)malloc(sizeof(t_word));
	fd = open("dictionary", O_RDONLY);
	while (i < 100)
	{
		line = get_next_line(fd);
		*list_words = ;
		*list_words++;
	}
	return (*list_words);
}
