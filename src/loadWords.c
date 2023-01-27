/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadWords.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:48:01 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/01/27 13:21:25 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/cursed.h"

static char	**ft_free_matrix(char **matrix, size_t len_matrix)
{
	while (len_matrix--)
		free((void *)matrix[len_matrix]);
	free(matrix);
	return (NULL);
}

t_word	*new_word(char *word, char g, char t)
{
	t_word	*n_word;
	char	*n_text;

	n_word = (t_word *)malloc(sizeof(t_word));
	n_text = (char *)malloc(sizeof(char) * ft_strlen(word));
	ft_strlcpy(n_text, word, ft_strlen(word)+1);
	n_word->text = n_text;
	n_word->gender = g;
	n_word->type = t;
	return (n_word);
}

t_word	**load_words(void)
{
	t_word	**list_words;
	char	*line;
	char	**sline;
	size_t	i;
	int		fd;

	i = 0;
	list_words = (t_word **)malloc(sizeof(t_word *) * 50);
	fd = open("dictionary", O_RDONLY);
	while (i < 50)
	{
		line = get_next_line(fd);
		sline = ft_split(line, ';');
		list_words[i] = new_word(sline[0], sline[1][0], sline[2][0]);
		ft_free_matrix(sline, 2);
		i++;
	}
	return (list_words);
}
