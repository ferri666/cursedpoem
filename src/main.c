/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:41:40 by ffons-ti          #+#    #+#             */
/*   Updated: 2023/11/02 16:04:35 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/cursed.h"

void	ft_free_matrix(void **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	show_word(t_word *word)
{
	char	*pal;

	pal = ft_allupper(zalgo(word->text));
	ft_putstr_fd(pal, 1);
	free(pal);
}

t_word	*spec_word(char g, char t, t_word **l_words)
{
	char	g2;
	char	t2;
	int		rn;
	t_word	*ret;

	g2 = 'n';
	t2 = 'x';
	while (g != g2 || t != t2)
	{
		rn = rand() % MAX_WORDS;
		ret = *(l_words + rn);
		g2 = ret->gender;
		t2 = ret->type;
	}
	return (ret);
}

t_word	*gender_word(char g, t_word	**l_words)
{
	char	g2;
	int		rn;
	t_word	*ret;

	g2 = 'n';
	while (g != g2)
	{
		rn = rand() % MAX_WORDS;
		ret = *(l_words + rn);
		g2 = ret->gender;
	}
	return (ret);
}

t_word	*type_word(char t, t_word	**l_words)
{
	char	t2;
	int		rn;
	t_word	*ret;

	t2 = 'f';
	while (t != t2)
	{
		rn = rand() % MAX_WORDS;
		ret = *(l_words + rn);
		t2 = ret->type;
	}
	return (ret);
}

t_word	*get_word(t_word **l_words)
{
	int		rn;
	t_word	*ret;

	rn = rand() % MAX_WORDS;
	ret = *(l_words + rn);
	return (ret);
}

void frase(void)
{
	t_word	**words;
	t_word	*first_w;

	words = load_words();
	first_w = type_word('n', words);
	if (first_w->gender == 'f')
		ft_putstr_fd(zalgo("LA "), 1);
	else
		ft_putstr_fd(zalgo("EL "), 1);
	show_word(first_w);
	ft_putstr_fd(" ", 1);
	show_word(spec_word(first_w->gender, 'a', words));
	ft_putstr_fd(" ", 1);
	show_word(spec_word('p', 'v', words));
	ft_putstr_fd("\n", 1);
	first_w = type_word('n', words);
	if (first_w->gender == 'f')
		ft_putstr_fd(zalgo("EN LA "), 1);
	else
		ft_putstr_fd(zalgo("EN EL "), 1);
	show_word(first_w);
	ft_putstr_fd(" ", 1);
	show_word(spec_word(first_w->gender, 'a', words));
	ft_putstr_fd(zalgo(" Y "), 1);
	show_word(spec_word(first_w->gender, 'a', words));
	ft_putstr_fd(".\n", 1);
	free(words);
}

void	versos(int n)
{
	t_word	**words;
	int		i;
	int		r;
	t_word	*first_w;
	t_word	*first_a, *second_a;

	i = 0;
	words = load_words();
	ft_putstr_fd("\n", 1);
	while (i < n)
	{
		r = rand() % 4;
		while (r > 0)
		{
			ft_putstr_fd(" ", 1);
			r--;
		}
		first_w = type_word('n', words);
		if (first_w->gender == 'f')
			ft_putstr_fd(zalgo("LA "), 1);
		else
			ft_putstr_fd(zalgo("EL "), 1);
		show_word(first_w);
		ft_putstr_fd(" ", 1);
		first_a = spec_word(first_w->gender, 'a', words);
		show_word(first_a);
		ft_putstr_fd(zalgo(" Y "), 1);
		second_a = spec_word(first_w->gender, 'a', words);
		while (first_a->text == second_a->text)
			second_a = spec_word(first_w->gender, 'a', words);
		show_word(second_a);
		ft_putstr_fd("\n", 1);
		r = rand() % 4;
		while (r > 0)
		{
			ft_putstr_fd(" ", 1);
			r--;
		}
		first_w = type_word('n', words);
		if (first_w->gender == 'f')
			ft_putstr_fd(zalgo("EN LA "), 1);
		else
			ft_putstr_fd(zalgo("EN EL "), 1);
		show_word(first_w);
		ft_putstr_fd(" ", 1);
		first_a = spec_word(first_w->gender, 'a', words);
		show_word(first_a);
		ft_putstr_fd(zalgo(" Y "), 1);
		second_a = spec_word(first_w->gender, 'a', words);
		while (first_a->text == second_a->text)
			second_a = spec_word(first_w->gender, 'a', words);
		show_word(second_a);
		ft_putstr_fd("\n", 1);
		i++;
	}
	free(words);
}
/*
void	show_all_words(void)
{
	int		i;
	t_word	**words;
	t_word	*palabra;

	i = 0;
	words = load_words();
	while (i < MAX_WORDS)
	{
		palabra = *(words + i);
		show_word(palabra);
		printf (", %c, %c\n", palabra->gender, palabra->type);
		free (*(words + i));
		i++;
	}
}

int main(void)
{
	show_all_words();
	show_all_words();
}
*/

int	main(int argc, char **argv)
{
	int		i;

	if (argc != 2)
		i = 3;
	else
		i = atoi(argv[1]);
	if (i == 0)
		i = 1;
	srand(time(NULL));
	ft_putstr_fd("  _,,  , ,_   _,  _,  ,_      ,_  _,  _, , , \n /  |  | |_) (_, /_,  | \\,    |_)/ \\,/_,|\\/| \n'\\_'\\__|'| \\  _)'\\_  _|_/    '| '\\_/'\\_ | `| \n   `   ` '  `'     `'         '  '     `'  ` \n                                             \n", 1);
	versos(i);
	return (0);
}
